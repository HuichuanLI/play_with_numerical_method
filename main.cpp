//
// Created by lhc456 on 2022/10/16.
//
#include "Rvector.h"
#include "RMatrix.h"
#include "SolutionofLinearEquation.h"
#include <iostream>

int main() {
    RVector v1(10);
    vector<double> t = {1, 2, 3, 4, 5, 6, 7};
    RVector v2(t);
    RVector v3 = v2;
    RVector v4(v3);
    RVector v5;

    RVector::ShowVector(v2);


    RMatrix m1(3, 5);
    vector<vector<double>> t1 = {{1, 2, 3},
                                 {4, 5, 6}};
    RMatrix m2(t1);

    RMatrix m3 = m2;

    RMatrix m4(m3);

    RMatrix m5;

    vector<vector<double>> a = {{4, -1, 2, 3},
                                {0, -2, 7, -4},
                                {0, 0,  6, 5},
                                {0, 0,  0, 3}};

    vector<double> b = {20, -7, 4, 6};

    RMatrix A(a);
    RVector B(b);

    RVector X = SolutionofLinearEquations::BackSubstitution(A, B);
    RVector::ShowVector(X);

    vector<double> up = {2, 3, 0.5};
    vector<double> dia = {1, 1, 2, 1};

    vector<double> down = {2, 1, 3};
    RVector Up = RVector(up);
    RVector Dia = RVector(dia);
    RVector Down = RVector(down);

    std::cout << "the up vector is" << std::endl;
    RVector::ShowVector(Up);

    std::cout << "the dialog vector is" << std::endl;
    RVector::ShowVector(Dia);

    std::cout << "the down vector is" << std::endl;
    RVector::ShowVector(Down);

    std::cout << "the constant vector is" << std::endl;
    RVector::ShowVector(B);

    std::cout << "the solution vector is" << std::endl;
    RVector::ShowVector(X);

}