//
// Created by lhc456 on 2022/10/18.
//


#include "SolutionofLinearEquation.h"

RVector SolutionofLinearEquations::BackSubstitution(RMatrix A, RVector B) {
    int n = B.GetLength();
    RVector X = RVector::ZerosVector(n);

    double temp = 0;

    X[n - 1] = B[n - 1] / A[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        temp = 0;
        for (int j = i + 1; j <= n - 1; j++) {
            temp += A[i][j] * X[j];
        }
        X[i] = (B[i] - temp) / A[i][i];
    }
    return X;
}

