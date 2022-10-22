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


RVector SolutionofLinearEquations::Thomas(RVector Up, RVector Dia, RVector Down, RVector B) {

    if (Dia.GetLength() != Up.GetLength() || Dia.GetLength() != Down.GetLength() + 1 ||
        Dia.GetLength() != B.GetLength()) {
        throw "Error!";
    }
    int n = B.GetLength();
    RVector Lvector = RVector(n - 1);
    RVector Uvector = RVector(n);
    Uvector[0] = Dia[0];
    for (int i = 0; i < n - 1; i++) {
        Lvector[i] = Down[i] / Uvector[i];
        Uvector[i + 1] = Dia[i + 1] - Lvector[i] * Up[i];
    }
    RVector Y = RVector(n);
    Y[0] = B[0];
    for (int i = 0; i < n - 1; i++) {
        Y[i + 1] = B[i + 1] - Lvector[i] * Y[i];
    }
    RVector X = RVector(n);
    X[n - 1] = Y[n - 1] / Uvector[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        X[i] = (Y[i] - Up[i] * X[i + 1]) / Uvector[i];
    }
    return X;
}

RVector SolutionofLinearEquations::Gauss(RMatrix A, RVector B) {
    int n = B.GetLength();
    double temp;
    int pmax = 0;
    RMatrix Augmat = RMatrix::CatCols(A, B);
    for (int i = 0; i < n; i++) {

        temp = 0;
        for (int j = i; j < n; j++) {
            if (abs(A[j][i]) > temp) {
                temp = abs(A[j][i]);
                pmax = j;
            }
        }
        Augmat = RMatrix::SwapRow(Augmat, i, pmax);
        RVector tvector(n);
        for (int j = i + 1; j < n; j++) {
            tvector = RMatrix::GetRowVector(Augmat, j) - RMatrix::GetRowVector(Augmat, i) / Augmat[i][i];
            Augmat = RMatrix::
        }
    }

    RMatrix aout(n);
    RVector bout(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            aout[i][j] = Augmat[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        bout[i] = Augmat[i][n];
    }
    RVector X = BackSubstitution(aout, bout);

    return X;
}