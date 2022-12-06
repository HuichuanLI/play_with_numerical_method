#include "SolutionofLinearEquation.h"
#include <cmath>

using namespace std;

RVector SolutionofLinearEquations::BackSubstitution(RMatrix A, RVector B) {
    int n = B.GetLength();
    RVector X = NULL;
    X = RVector::ZerosVector(n);
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
    if (Dia.GetLength() != Up.GetLength() + 1 || Dia.GetLength() != Down.GetLength() + 1 ||
        Dia.GetLength() != B.GetLength()) {
        throw "Error!";
    }
    int n = B.GetLength();
    RVector Lvector(n - 1);
    RVector Uvector(n);
    Uvector[0] = Dia[0];
    for (int i = 0; i < n - 1; i++) {
        Lvector[i] = Down[i] / Uvector[i];
        Uvector[i + 1] = Dia[i + 1] - Lvector[i] * Up[i];
    }
    RVector Y(n);
    Y[0] = B[0];
    for (int i = 0; i < n - 1; i++) {
        Y[i + 1] = B[i + 1] - Lvector[i] * Y[i];
    }
    RVector X(n);
    X[n - 1] = Y[n - 1] / Uvector[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        X[i] = (Y[i] - Up[i] * X[i + 1]) / Uvector[i];
    }
    return X;
}

RVector SolutionofLinearEquations::Gauss(RMatrix A, RVector B) {
    int n = B.GetLength();
    RVector X;
    X = RVector::ZerosVector(n);
    double temp;
    int pmax = 0;
    RMatrix Augmat;
    Augmat = RMatrix::CatCols(A, B);
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
            tvector = RMatrix::GetRowVector(Augmat, j) - RMatrix::GetRowVector(Augmat, i) * Augmat[j][i] / Augmat[i][i];
            Augmat = RMatrix::ReplaceRow(Augmat, j, tvector);
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
    X = BackSubstitution(aout, bout);
    return X;
}

RMatrix SolutionofLinearEquations::LUFactorization(RMatrix m) {
    int n = m.GetnRows();
    double temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp = 0;
            if (j >= i) {
                for (int k = 0; k < i; k++) {
                    temp += m[i][k] * m[k][j];
                }
                m[i][j] = m[i][j] - temp;
            } else {
                for (int k = 0; k < j; k++) {
                    temp += m[i][k] * m[k][j];
                }
                m[i][j] = (m[i][j] - temp) / m[j][j];
            }
        }
    }
    return m;
}

RVector SolutionofLinearEquations::GaussSeidel(RMatrix A, RVector B, RVector X0) {
    int n = B.GetLength();
    int it = 0;
    double maxit = 100;
    double er = 0;
    double tol = 1E-6;
    RVector Xn(n);
    RVector Xn1(n);
    double sum;
    do {
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                if (j < i) {
                    sum += A[i][j] * Xn1[j];
                } else if (j > i) {
                    sum += A[i][j] * Xn[j];
                }
            }
            Xn1[i] = (B[i] - sum) / A[i][i];
        }
        it += 1;
        er = RVector::Norm(Xn1 - Xn);
        Xn = Xn1;
        if (it > maxit) {
            break;
        }
    } while (er > tol);
    return Xn;
}

RVector SolutionofLinearEquations::SOR(RMatrix A, RVector B, double omega, RVector X0) {
    int n = B.GetLength();
    int it = 0;
    double maxit = 100;
    double er = 0;
    double tol = 1E-6;
    RVector Xn(n);
    RVector Xn1(n);
    double sum;
    do {
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                if (j < i) {
                    sum += A[i][j] * Xn1[j];
                } else if (j > i) {
                    sum += A[i][j] * Xn[j];
                }
            }
            Xn1[i] = (1 - omega) * Xn[i] + omega * (B[i] - sum) / A[i][i];
        }
        it += 1;
        er = RVector::Norm(Xn1 - Xn);
        Xn = Xn1;
        if (it > maxit) {
            break;
        }
    } while (er > tol);
    return Xn;
}