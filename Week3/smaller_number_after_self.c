#include <stdio.h>

typedef struct {
    int val;
    int idx;
} Node;

void merge(Node a[], int l, int m, int r, int ans[]) {
    Node temp[r - l + 1];
    int i = l, j = m + 1, k = 0, right = 0;

    while (i <= m && j <= r) {
        if (a[j].val < a[i].val) {
            temp[k++] = a[j++];
            right++;
        } else {
            ans[a[i].idx] += right;
            temp[k++] = a[i++];
        }
    }

    while (i <= m) {
        ans[a[i].idx] += right;
        temp[k++] = a[i++];
    }

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

void mergeSort(Node a[], int l, int r, int ans[]) {
    if (l >= r)
        return;

    int m = (l + r) / 2;
    mergeSort(a, l, m, ans);
    mergeSort(a, m + 1, r, ans);
    merge(a, l, m, r, ans);
}

int main() {
    int n;
    scanf("%d", &n);

    Node a[n];
    int ans[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].val);
        a[i].idx = i;
        ans[i] = 0;
    }

    mergeSort(a, 0, n - 1, ans);

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}
