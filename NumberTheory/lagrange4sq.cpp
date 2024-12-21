#include <cmath>

bool isPerfectSquare(int n) {
    int rt = sqrt(n);
    return rt * rt == n;
}

// Function to compute the minimum number of perfect squares
int numSquares(int n) {
    // Case 1:
    if (isPerfectSquare(n)) return 1;

    // Case 2: Check if n can be expressed as the sum of two perfect squares
    for (int i = 1; i * i <= n; i++) {
        int d = n - i * i;
        if (isPerfectSquare(d)) return 2;
    }

    // Case 3:
    // If n can be reduced to the form 4^a * (8b + 7), then it requires 4 squares
    int m = n;
    while (m % 4 == 0) m /= 4;
    if (m % 8 == 7) return 4;

    // Case 4:
    return 3;
}