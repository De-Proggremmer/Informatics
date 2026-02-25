#include <iostream>
#include <cmath>

double simpson_rule(double (*f)(double), double a, double b, int n) {
    if (n % 2 == 1) n++; // Делаем n четным
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2)
        sum += 4 * f(a + i * h);

    for (int i = 2; i < n - 1; i += 2)
        sum += 2 * f(a + i * h);

    return (h / 3) * sum;
}

double function_A(double x) {
    return (x * x * x) - 12*(x * x) + 4; // Интегрируемая функция
}

double function_B(double x) {
    return -1*(x * x * x) + (x * x) - 4; // Интегрируемая функция
}

int main() {
    int N = 2;
    double area_A = simpson_rule(function_A, 3, 6, N);
    double area_B = simpson_rule(function_B, 3, 6, N);
    std::cout << "Result Area: " << abs(area_A - area_B) << std::endl;
    return 0;
}