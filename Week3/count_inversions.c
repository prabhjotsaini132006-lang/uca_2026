#include <stdio.h>

int merge(int a[], int l, int mid, int h, int temp[]) {
    int i = l, j = mid + 1, k = l;
    int c = 0;

    while (i <= mid && j <= h) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            c += mid - i + 1;
        }
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= h)
        temp[k++] = a[j++];

    for (k = l; k <= h; k++)
        a[k] = temp[k];

    return c;
}

int merge_sort(int a[], int l, int h, int temp[]) {
    if (l >= h)
        return 0;

    int mid = (l + h) / 2;
    int c = 0;

    c += merge_sort(a, l, mid, temp);
    c += merge_sort(a, mid + 1, h, temp);
    c += merge(a, l, mid, h, temp);

    return c;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], temp[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d", merge_sort(arr, 0, n - 1, temp));
}
