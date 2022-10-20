//
// Created by lhc456 on 2022/10/16.
//
#include <iostream>
#include "SoulutionofNonLinearEquation.h"
#include <iomanip>
#include "Test.h"

using namespace std;

int main() {
    double x0 = 1;
    double tol = 1E-6;
    int maxit = 200;
    double r;
    r = SolutionofNonlinearEquation::FixedPointIteration(Fun, x0, tol, maxit);
    cout << setprecision(16) << r << endl;

    double a = -1;
    double b = 2;
    tol = 1E-6;
    vector<double> r1;
    r1 = SolutionofNonlinearEquation::BisectionIteration(Fun, a, b, tol);

    cout << "x is" << setprecision(15) << r1[0] << endl;

    cout << "f(x) is" << setprecision(15) << r1[1] << endl;

    cout << "iteration is" << setprecision(15) << r1[2] << endl;

    x0 = 2.1;
    tol = 1E-6;
    vector<double> r2;

    r2 = SolutionofNonlinearEquation::NewtonRaphsonIteration(Fun2, x0, tol);

    cout << " x is" << r2[0] << endl;
    cout << " f(x) is" << r2[1] << endl;

    cout << " iteration is" << r2[2] << endl;




}