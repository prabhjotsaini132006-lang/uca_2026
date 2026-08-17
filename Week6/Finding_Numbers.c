#include <stdio.h>

int findNumber(int arr[], int n) {
    int result = 0;

    for (int bit = 0; bit < 32; bit++) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] & (1 << bit)) {
                count++;
            }
        }

        if (count % 3 != 0) {
            result |= (1 << bit);
        }
    }

    return result;
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
	scanf("%d", &arr[i]);
    }

    int answer = findNumber(arr, n);

    printf("Result: %d\n", answer);

    return 0;
}
