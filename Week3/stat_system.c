#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    struct stat file;

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &file) == -1) {
        perror("stat");
        return 1;
    }

    printf("=== File Attributes for: %s ===\n", argv[1]);

    if (S_ISREG(file.st_mode))
        printf("File Type:            Regular File\n");
    else if (S_ISDIR(file.st_mode))
        printf("File Type:            Directory\n");
    else if (S_ISCHR(file.st_mode))
        printf("File Type:            Character Device\n");
    else if (S_ISBLK(file.st_mode))
        printf("File Type:            Block Device\n");
    else if (S_ISFIFO(file.st_mode))
        printf("File Type:            FIFO\n");
    else if (S_ISLNK(file.st_mode))
        printf("File Type:            Symbolic Link\n");
    else if (S_ISSOCK(file.st_mode))
        printf("File Type:            Socket\n");
    else
        printf("File Type:            Unknown\n");

    printf("Permissions:          %04o\n", file.st_mode & 0777);
    printf("File Size:            %ld bytes\n", file.st_size);
    printf("Hard Links Count:     %ld\n", file.st_nlink);
    printf("Owner (UID):          %d\n", file.st_uid);
    printf("Group (GID):          %d\n", file.st_gid);
    printf("Last Access Time:     %s", ctime(&file.st_atime));
    printf("Last Modification:    %s", ctime(&file.st_mtime));
    printf("Status Change Time:   %s", ctime(&file.st_ctime));

    return 0;
}
