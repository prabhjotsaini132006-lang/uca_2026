#include <stdio.h>
#include <string.h>

char table[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void base64Encode(char input[]) {
  int len = strlen(input);

  for (int i = 0; i < len; i += 3) {
    int a = input[i];
    int b = (i + 1 < len) ? input[i + 1] : 0;
    int c = (i + 2 < len) ? input[i + 2] : 0;

    int x = a >> 2;
    int y = ((a & 3) << 4) | (b >> 4);
    int z = ((b & 15) << 2) | (c >> 6);
    int w = c & 63;

    printf("%c", table[x]);
    printf("%c", table[y]);

    if (i + 1 < len)
      printf("%c", table[z]);
    else
      printf("=");

    if (i + 2 < len)
      printf("%c", table[w]);
    else
      printf("=");
  }

  printf("\n");
}

int getValue(char ch) {
  if (ch >= 'A' && ch <= 'Z')
    return ch - 'A';

  if (ch >= 'a' && ch <= 'z')
    return ch - 'a' + 26;

  if (ch >= '0' && ch <= '9')
    return ch - '0' + 52;

  if (ch == '+')
    return 62;

  if (ch == '/')
    return 63;

  return -1;
}

void base64Decode(char input[]) {
  int len = strlen(input);

  for (int i = 0; i < len; i += 4) {
    int a = getValue(input[i]);
    int b = getValue(input[i + 1]);
    int c = (input[i + 2] == '=') ? 0 : getValue(input[i + 2]);
    int d = (input[i + 3] == '=') ? 0 : getValue(input[i + 3]);

    int x = (a << 2) | (b >> 4);
    int y = ((b & 15) << 4) | (c >> 2);
    int z = ((c & 3) << 6) | d;

    printf("%c", x);

    if (input[i + 2] != '=')
      printf("%c", y);

    if (input[i + 3] != '=')
      printf("%c", z);
  }

  printf("\n");
}

int main() {
  char input[1000];
  int choice;

  printf("1. Encode\n");
  printf("2. Decode\n");
  printf("Enter choice: ");
  scanf("%d", &choice);

  getchar();

  printf("Enter input: ");
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';

  if (choice == 1)
    base64Encode(input);
  else if (choice == 2)
    base64Decode(input);
  else
    printf("Invalid choice\n");

  return 0;
}
