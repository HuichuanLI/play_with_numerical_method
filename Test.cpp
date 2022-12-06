//
// Created by lhc456 on 2022/10/16.
//
#include <iostream>
#include "SoulutionofNonLinearEquation.h"
#include <iomanip>
#include "Test.h"
#include "NimericalDifferentaiation.h"
#include "NumericalOptimization.h"
#include "CurvingFitting.h"
#include "EigenvectorandEigenvalue.h"

using namespace std;

int main() {
//    double x0 = 1;
//    double tol = 1E-6;
//    int maxit = 200;
//    double r;
//    r = SolutionofNonlinearEquation::FixedPointIteration(Fun, x0, tol, maxit);
//    cout << setprecision(16) << r << endl;
//
//    double a = -1;
//    double b = 2;
//    tol = 1E-6;
//    vector<double> r1;
//    r1 = SolutionofNonlinearEquation::BisectionIteration(Fun, a, b, tol);
//
//    cout << "x is" << setprecision(15) << r1[0] << endl;
//
//    cout << "f(x) is" << setprecision(15) << r1[1] << endl;
//
//    cout << "iteration is" << setprecision(15) << r1[2] << endl;

//    x0 = 2.1;
//    tol = 1E-6;
//    vector<double> r2;
//
//    r2 = SolutionofNonlinearEquation::NewtonRaphsonIteration(Fun2, x0, tol);
//
//    cout << " x is" << r2[0] << endl;
//    cout << " f(x) is" << r2[1] << endl;
//
//    cout << " iteration is" << r2[2] << endl;

//    double dx = 1E-6;
//    vector<double> x2 = {-3, -2};
//    RVector X0(x2);
//    RVector G = NumericalDifferentaitioan::Gradient(Fun3, X0, dx);
//    RVector::ShowVector(G);
//    double a = 0;
//    double b = 4;
//    double x;
//    double g;
//    double f;
//    x = GoldenMin(Fun4, a, b);
//    g = Fun4(x);
//    f = -g;
//    cout << "x=" << endl;
//
//    cout << "fixed" << setprecision(4) << x << endl;
//    cout << "f=" << endl;
//    cout << fixed << setprecision(4) << f << endl;



    vector<vector<double>> m = {{3,  0, -10},
                                {-1, 3, 4},
                                {0,  1, -2}};
    RMatrix M(m);
    double p = 4.3;
    RMatrix::ShowMatrix(M);
    RVector u = EigenvectorandEigenvalue::Eigenvector(M, p);
    RVector::ShowVector(u);
    RVector v = M * u;
    RVector::ShowVector(v);
    double x1 = v[0] / u[0];
    cout << x1 << endl;
    double x2 = v[1] / u[1];
    cout << x2 << endl;
    double x3 = v[2] / u[2];
    cout << x3 << endl;

}

