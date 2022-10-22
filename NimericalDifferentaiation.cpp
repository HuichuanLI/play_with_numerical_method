//
// Created by lhc456 on 2022/10/22.
//

#include "NimericalDifferentaiation.h"
#include <cmath>

double NumericalDifferentaitioan::CentralDifferecne(Function f, double x0, double dx) {
    double df;
    df = (f(x0 + dx) - f(x0 - dx)) / 2 / dx;
    return df;
}

RVector NumericalDifferentaitioan::CentralDifference(RVector x, double dx) {
    int n = x.GetLength();
    RVector df(n);
    df[0] = (-3 * x[0] + 4 * x[1] - x[2]) / 2 / dx;
    for (int i = 1; i < x.GetLength() - 1; i++) {
        df[i] = (x[i + 1] - x[i - 1]) / 2 / dx;
    }
    df[x.GetLength() - 1] = (x[x.GetLength() - 3] - 4 * x[x.GetLength() - 2] + 3 * x[x.GetLength() - 1]) / 2 / dx;
    return df;
}

double NumericalDifferentaitioan::CentralDifferenceLimits(Function f, double x0, double tol) {
    double df0 = (f(x0 + 1) - f(x0 - 1)) / 2;
    double df1;
    double er;
    int maxit = 10;
    int i = 1;
    while (er < tol) {
        df1 = (f(x0 + pow(10, -i) - f(x0 - pow(10, -i)))) / 2 / pow(10, -i);
        er = abs(df1 - df0);
        i = i + 1;
        if (i > maxit) {
            break;
        }
        df0 = df1;
    }
    return df0;
}
