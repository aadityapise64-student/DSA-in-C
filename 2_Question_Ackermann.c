#include <stdio.h>

/*
 * ============================================================================
 * QUESTION: Ackermann Function using Recursion
 * ============================================================================
 *
 * The Ackermann function is a classic recursive function that grows very fast.
 * It is commonly used to demonstrate recursion and computational complexity.
 *
 * Definition:
 * A(0, n) = n + 1
 * A(m, 0) = A(m - 1, 1)
 * A(m, n) = A(m - 1, A(m, n - 1))
 * ============================================================================
 */

int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    }

    if (n == 0) {
        return ackermann(m - 1, 1);
    }

    return ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
    int m = 2;
    int n = 3;

    printf("Ackermann function A(%d, %d) = %d\n", m, n, ackermann(m, n));
    return 0;
}
