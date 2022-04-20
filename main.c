#include <math.h>
#include <stdio.h>

double func(double x, double y)
{
    return 3 * pow(x, 2) * y; // can be changed
}

int main()
{
    FILE* out;
    out = fopen("output.txt", "w");
    double a = 0, b = 1, h = 0.05;
    double k1, k2, k3, k4;
    int n = (b - a) / h;
    double x[n + 1];
    double y[n + 1];
    x[0] = a;
    y[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        x[i] = a + i * h;
        k1 = h * func(x[i - 1], y[i - 1]);
        k2 = h * func(x[i - 1] + h / 2, y[i - 1] + k1 / 2.0);
        k3 = h * func(x[i - 1] + h / 2, y[i - 1] + k2 / 2);
        k4 = h * func(x[i - 1] + h, y[i - 1] + k3);
        y[i] = y[i - 1] + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    }
    for (int i = 0; i <= n; i++)
    {
        fprintf(out, "%.2lf %.6lf\n", x[i], y[i]);
    }
    return 0;
}