#include <stdio.h>

int main() {
    double result;
    // Define a sample expression (2 + 3 * 4 / (1 - 5) ^ 2 ^ 3)
    double a = 2, b = 3, c = 4, d = 1, e = 5, f = 2, g = 3;

    // Perform operations according to PEMDAS
    result = a + b * c / (d - e) / f / g;

    printf("The result of the expression is: %lf\n", result);
    return 0;
}

