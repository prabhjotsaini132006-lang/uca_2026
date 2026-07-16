#include <stdio.h>

void reverse_string(char *str) {
    int start = 0;
    int end = 0;

    while (str[end] != '\0') {
        end++;
    }
    end--;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char str[] = "Data Structures";

    reverse_string(str);

    printf("%s\n", str);

    return 0;
}
