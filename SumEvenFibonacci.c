#include <stdio.h>

long long bruteForce(long long n) {
    long long a = 1, b = 1;
    long long sum = 0;

    while (a <= n) {
        if (a % 2 == 0)
            sum += a;

        long long c = a + b;
        a = b;
        b = c;
    }

    return sum;
}

long long optimized(long long n) {
    if (n < 2)
        return 0;

    long long sum = 0;
    long long e1 = 2;
    long long e2 = 8;

    while (e1 <= n) {
        sum += e1;
        long long e3 = 4 * e2 + e1;
        e1 = e2;
        e2 = e3;
    }

    return sum;
}

int main() {
    long long n;

    scanf("%lld", &n);

    printf("Brute Force: %lld\n", bruteForce(n));
    printf("Optimized: %lld\n", optimized(n));

    return 0;
}
