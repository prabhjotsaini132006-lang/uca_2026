#include <stdio.h>

int main() {
    int c, d;

    while ((c = getchar()) != EOF) {
        if (c == '"') {
            putchar(c);
            while ((c = getchar()) != EOF) {
                putchar(c);
                if (c == '\\') {
                    c = getchar();
                    if (c == EOF) break;
                    putchar(c);
                } else if (c == '"') {
                    break;
                }
            }
        } else if (c == '\'') {
            putchar(c);
            while ((c = getchar()) != EOF) {
                putchar(c);
                if (c == '\\') {
                    c = getchar();
                    if (c == EOF) break;
                    putchar(c);
                } else if (c == '\'') {
                    break;
                }
            }
        } else if (c == '/') {
            d = getchar();

            if (d == '/') {
                while ((c = getchar()) != EOF && c != '\n');
                if (c == '\n')
                    putchar('\n');
            } else if (d == '*') {
                int prev = 0;
                while ((c = getchar()) != EOF) {
                    if (prev == '*' && c == '/')
                        break;
                    prev = c;
                }
            } else {
                putchar(c);
                if (d != EOF)
                    putchar(d);
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}
