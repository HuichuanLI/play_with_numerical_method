//
// Created by lhc456 on 2022/10/22.
//

#include "NumericalOptimization.h"

double GoldenMin(Function f, double a, double b) {
    double delta = 1E-6;
    double tol = 1E-6;
    double g = (sqrt(5) - 1) / 2;
    double h = b - a;
    double x1 = a + (1 - g) * (b - a);
    double x2 = a + g * (b - a);
    double f1 = f(x1);
    double f2 = f(x2);
    int k = 1;
    while (abs(f2 - f1) > tol || h > delta) {
        k = k + 1;
        if (f1 < f2) {
            b = x2;
            x2 = x1;
            x1 = a + (1 - g) * (b - a);
            f2 = f1;
            f1 = f(x1);
            h = b - a;
        } else {
            a = x1;
            x1 = x2;
            x2 = a + g * (b - a);
            f1 = f2;
            f2 = f(x2);
            h = b - a;
        }
    }
    return (a + b) / 2;
}


double QuadMin(Function f, double a, double b, double x0) {
    double tol = 1E-6;
    double x1 = a;
    double x2 = x0;
    double x3 = b;
    double fx1 = f(x1);
    double fx2 = f(x2);
    double fx3 = f(x3);
    double fx4;
    double x4 = 0;
    double x5 = x2;
    double er;
    do {
        x4 = (x1 + x2) / 2 -
             (fx2 - fx1) * (x3 - x1) * (x3 - x2) / (2 * (x2 - x1) * (fx3 - fx2) - 2 * (fx2 - fx1) * (x3 - x2));
        fx4 = f(x4);
        if (fx4 < fx2 && x4 < x2) {
            x3 = x2;
            x2 = x4;
            fx3 = fx2;
            fx2 = fx4;
        } else if (fx4 < fx2 && x4 > x2) {
            x1 = x2;
            x2 = x4;
            fx1 = fx2;
            fx2 = fx4;
        } else if (fx4 > fx2 && x4 < x2) {
            x1 = x4;
            fx1 = fx4;
        } else if (fx4 > fx2 && x4 > x2) {
            x3 = x4;
            fx3 = fx4;
        }
        er = abs(x4 - x5);
        x5 = x4;
    } while (er > tol);
    return x5;
}