//
// Created by lhc456 on 2022/10/16.
//

#include <cmath>
#include "SoulutionofNonLinearEquation.h"
#include <iostream>

using namespace std;

double SolutionofNonlinearEquation::FixedPointIteration(Function f, double x0, double tol, int maxit) {
    double x1;
    double er;
    for (int i = 0; i < maxit; i++) {
        x1 = f(x0);
        std::cout << x1 << std::endl;
        er = abs(x1 - x0);
        x0 = x1;
        if (i > maxit || er < tol) {
            break;
        }
    }
    return x0;
}

vector<double> SolutionofNonlinearEquation::BisectionIteration(Function f, double a, double b, int tol) {
    vector<double> result(3);
    double ina = a;
    double inb = b;
    double inc = 0;
    double er = 1;
    int it = 0;
    while (er > tol) {
        it = it + 1;
        inc = (ina + inb) / 2;
        std::cout << inc << std::endl;
        if (f(ina) * f(inb) < 0) {
            if (f(inc) == 0) {
                ina = inc;
                inb = inc;
            } else if (f(inb) * f(inc) > 0) {
                inb = inc;
            } else {
                ina = inc;
            }
        }
        er = inb - ina;

    }
    result[0] = inc;
    result[1] = f(inc);
    result[2] = it;
    return result;
}

vector<double> SolutionofNonlinearEquation::NewtonRaphsonIteration(Function f, double x, double tol) {
    vector<double> result(3);
    double x0 = x;
    double dx = 1E-15;
    double dfx0;
    double d;
    double x1;
    int it = 0;
    dfx0 = (f(x0 + dx) - f(x0 - dx)) / dx / 2;
    d = f(x0) / dfx0;
    while (abs(d) > tol) {
        x1 = x0 - d;
        it = it + 1;
        x0 = x1;
        d = f(x0) / dfx0;
    }
    result[0] = x0;
    result[1] = f(x0);
    result[2] = it;
    return result;
}