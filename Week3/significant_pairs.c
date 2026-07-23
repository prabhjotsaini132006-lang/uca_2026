#include <stdio.h>

int cnt = 0;

void merge(int a[], int l, int m, int r) {
    int j = m + 1;

    for (int i = l; i <= m; i++) {
        while (j <= r && (long long)a[i] > 2LL * a[j])
            j++;
        cnt += j - (m + 1);
    }

    int temp[r - l + 1];
    int i = l, k = 0;
    j = m + 1;

    while (i <= m && j <= r)
        temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int l, int r) {
    if (l >= r)
        return;

    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergeSort(a, 0, n - 1);

    printf("%d", cnt);

    return 0;
}
