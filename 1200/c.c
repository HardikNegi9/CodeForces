#include <stdio.h>

// Function to be solved
double f(double x, double y) {
    return x + y;
}

// Runge-Kutta method
void rungeKutta(double x0, double y0, double x, double h) {
    int n = (int)((x - x0) / h);
    double k1, k2, k3, k4, k;

    double y = y0;
    for (int i = 0; i < n; i++) {
        k1 = h * f(x0, y);
        k2 = h * f(x0 + 0.5 * h, y + 0.5 * k1);
        k3 = h * f(x0 + 0.5 * h, y + 0.5 * k2);
        k4 = h * f(x0 + h, y + k3);

        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        y = y + k;
        x0 = x0 + h;
    }

    printf("The value of y at x is: %lf\n", y);
}

int main() {
    double x0 = 0, y0 = 1, x = 2, h = 0.2;
    rungeKutta(x0, y0, x, h);
    return 0;
}