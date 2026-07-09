#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define LOG_FILE   "auditlog.log"
#define BUF_SIZE   4096

static void write_str(int fd, const char *s) {
    write(fd, s, strlen(s));
}

static void write_uint(int fd, unsigned int n) {
    char tmp[16];
    int i = 0;

    if (n == 0) {
        write(fd, "0", 1);
        return;
    }

    while (n > 0 && i < (int)sizeof(tmp)) {
        tmp[i++] = (char)('0' + (n % 10));
        n /= 10;
    }

    while (i > 0) {
        i--;
        write(fd, &tmp[i], 1);
    }
}

static int cmd_add(const char *message) {
    int fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        write_str(2, "Error: could not open log file for writing.\n");
        return 1;
    }

    write_str(fd, message);
    write_str(fd, "\n");

    close(fd);
    return 0;
}

static int cmd_view(void) {
    int fd = open(LOG_FILE, O_RDONLY);
    if (fd < 0) {
        return 0;
    }

    char buf[BUF_SIZE];
    ssize_t bytes_read;

    unsigned int line_num = 1;
    int at_line_start = 1;

    while ((bytes_read = read(fd, buf, BUF_SIZE)) > 0) {
        for (ssize_t i = 0; i < bytes_read; i++) {
            if (at_line_start) {
                write_uint(1, line_num);
                write_str(1, ": ");
                at_line_start = 0;
            }

            write(1, &buf[i], 1);

            if (buf[i] == '\n') {
                line_num++;
                at_line_start = 1;
            }
        }
    }

    close(fd);
    return 0;
}

static void print_usage(void) {
    write_str(2, "Usage:\n");
    write_str(2, "  auditlog --add \"message\"\n");
    write_str(2, "  auditlog --view\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    if (strcmp(argv[1], "--add") == 0) {
        if (argc < 3) {
            write_str(2, "Error: --add requires a message argument.\n");
            return 1;
        }
        return cmd_add(argv[2]);
    } else if (strcmp(argv[1], "--view") == 0) {
        return cmd_view();
    } else {
        print_usage();
        return 1;
    }
}
