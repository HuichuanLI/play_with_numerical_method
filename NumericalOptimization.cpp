//
// Created by lhc456 on 2022/10/22.
//

#include "NumericalOptimization.h"
#include "NimericalDifferentaiation.h"

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


RVector MultivVarGradientMin(MultiVarFunction f, RVector x0) {
    RVector x1;
    RVector x2 = x0;
    double dx = 1E-4;
    double delta = 1E-4;
    double tol = 1E-4;

    RVector G;
    RVector p;
    double h;
    RVector xr, xs, xt, t1, t2;
    double fr, fs, ft, ft1, ft2, fx1, fx2;
    double g = (sqrt(5) - 1) / 2;

    int k;
    do {
        x1 = x2;
        fx1 = f(x1);
        G = NumericalDifferentaitioan::Gradient(f, x1, dx);
        p = G / G.Norm() * -1;
        h = 1;
        xr = x1;
        xs = x1 + p * h / 2;
        fr = f(xr);
        fs = f(xs);
        ft = f(xt);
        do {
            if (fr < fs) {
                xt = xs;
                ft = fs;
                h = h / 2;
                xs = xr + p * h / 2;
                fs = f(xs);
            } else if (ft < fs) {
                xs = xt;
                fs = ft;
                h = 2 * h;
                xt = xt + p * h;
                ft = f(xt);
            } else
                break;
        } while (true);

        t1 = xr + p * (1 - g) * h;
        t2 = xt + p * g * h;
        ft1 = f(t1);
        ft2 = f(t2);
        k = 1;
        while (h > delta || abs(ft2 - ft1) > tol) {
            k = k + 1;
            if (ft1 < ft2) {
                xt = t2;
                t2 = t1;
                h = g * h;
                t1 = xt + p * (1 - g) * h;
                ft2 = ft1;
                ft1 = f(t1);
            } else {
                xr = t1;
                t1 = t2;
                h = g * h;
                t2 = xr + p * g * h;
                ft1 = ft2;
                ft2 = f(t2);
            }
        }
        x2 = (xt + xr) / 2;
        fx2 = f(x2);
    } while ((x2 - x1).Norm() > delta || abs(fx2 - fx1) > tol);
    return x2;
}

