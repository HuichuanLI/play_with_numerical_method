#include "EigenvectorandEigenvalue.h"

tuple<RMatrix, RMatrix> EigenvectorandEigenvalue::QRGivensRotations(RMatrix m) {
    int nRows = m.GetnRows();
    int nCols = m.GetnCols();
    if (nRows != nCols) {
        throw "Error!";
    }
    RMatrix R = m;
    RMatrix Q = RMatrix::IdentityMatrix(nRows, nCols);
    RMatrix G;
    double t;
    double c;
    double s;
    for (int j = 0; j < nCols; j++) {
        for (int i = nRows - 1; i > j; i--) {
            G = RMatrix::IdentityMatrix(nRows);
            if (R[i][j] != 0) {
                if (abs(R[i - 1][j]) >= abs(R[i][j])) {
                    t = R[i][j] / R[i - 1][j];
                    c = 1 / sqrt(1 + t * t);
                    s = c * t;
                    G[i - 1][i - 1] = c;
                    G[i][i] = c;
                    G[i - 1][i] = s;
                    G[i][i - 1] = -s;
                } else {
                    t = R[i - 1][j] / R[i][j];
                    s = 1 / sqrt(1 + t * t);
                    c = s * t;
                    G[i - 1][i - 1] = c;
                    G[i][i] = c;
                    G[i - 1][i] = s;
                    G[i][i - 1] = -s;
                }
                R = G * R;
                Q = Q * RMatrix::Transpose(G);
            }
        }
    }
    return make_tuple(Q, R);
}

tuple<RMatrix, RMatrix> EigenvectorandEigenvalue::QRGramSchmidt(RMatrix m) {
    int nRows = m.GetnRows();
    int nCols = m.GetnCols();
    if (nRows != nCols) {
        throw "Error!";
    }
    RMatrix Q = RMatrix(nRows, nCols);
    RMatrix R = RMatrix(nCols, nCols);
    RVector v;
    RVector q;
    for (int j = 0; j < nCols; j++) {
        v = RMatrix::GetColVector(m, j);
        for (int i = 0; i < j; i++) {
            q = RMatrix::GetColVector(Q, i);
            R[i][j] = RVector::DotProduct(q, v);
            v = v - R[i][j] * q;
        }
        R[j][j] = RVector::Norm(v);
        q = v / R[j][j];
        Q = RMatrix::ReplaceCol(Q, j, q);
    }
    return make_tuple(Q, R);
}

tuple<RMatrix, RMatrix> EigenvectorandEigenvalue::QRHouseholder(RMatrix m) {
    int nRows = m.GetnRows();
    int nCols = m.GetnCols();
    if (nRows != nCols) {
        throw "Error!";
    }
    RMatrix Q = RMatrix::IdentityMatrix(nRows, nRows);
    RMatrix R = RMatrix(m);
    RMatrix H;
    RVector v;
    RVector omega;
    for (int j = 0; j < nCols; j++) {
        v = RMatrix::GetColVector(R, j);
        for (int i = 0; i < j; i++) {
            v[i] = 0;
        }
        v[j] = v[j] - RVector::Norm(v);
        omega = v / RVector::Norm(v);
        H = RMatrix::IdentityMatrix(nRows);
        H = H - 2 * RMatrix::ConvertToCol(omega) * RMatrix::ConvertToRow(omega);
        R = H * R;
        Q = Q * H;
    }
    return make_tuple(Q, R);
}

RMatrix EigenvectorandEigenvalue::HessenbergHouseholder(RMatrix m) {
    int nRows = m.GetnRows();
    int nCols = m.GetnCols();
    if (nRows != nCols) {
        throw "Error!";
    }
    RMatrix Q = RMatrix::IdentityMatrix(nRows, nRows);
    RMatrix R = RMatrix(m);
    RMatrix H;
    RVector v;
    RVector omega;
    int sign = 0;
    for (int j = 0; j < nCols - 2; j++) {
        v = RMatrix::GetColVector(R, j);
        for (int i = 0; i < j + 1; i++) {
            v[i] = 0;
        }
        if (v[j + 1] >= 0) {
            sign = 1;
        } else {
            sign = -1;
        }
        v[j + 1] = v[j + 1] + sign * RVector::Norm(v);
        omega = v / RVector::Norm(v);
        H = RMatrix::IdentityMatrix(nRows);
        H = H - 2 * RMatrix::ConvertToCol(omega) * RMatrix::ConvertToRow(omega);
        R = H * R * H;
    }
    return R;
}

RMatrix EigenvectorandEigenvalue::Eigenvalue(RMatrix m) {
    RMatrix H = HessenbergHouseholder(m);
    int nRows = m.GetnRows();
    int nCols = m.GetnCols();
    //RMatrix H = HessenbergHouseholder(m);
    tuple<RMatrix, RMatrix> qr;
    RMatrix Q;
    RMatrix R;
    RMatrix Ht;
    double er;
    double tol = 1E-6;
    RVector trace(nRows);
    do {
        qr = QRGivensRotations(H);
        Q = get<0>(qr);
        R = get<1>(qr);
        Ht = R * Q;
        for (int i = 0; i < nRows; i++) {
            trace[i] = abs(Ht[i][i] - H[i][i]);
        }
        er = RVector::Norm(trace);
        H = Ht;
    } while (er > tol);
    RMatrix E(nRows);
    for (int i = 0; i < nRows; i++) {
        E[i][i] = H[i][i];
    }
    return E;
}

RVector EigenvectorandEigenvalue::Eigenvector(RMatrix m, double p) {
    int nRows = m.GetnRows();
    int nCols = m.GetnCols();
    if (nRows != nCols) {
        throw "Error!";
    }
    RMatrix I;
    RMatrix A;
    RVector u = RVector::OnesVector(nRows);
    RVector v;
    RVector x;
    double xmax;
    int it = 0;
    int itmax = 20;
    double er;
    double tol = 1E-6;
    double temp;
    int j;
    do {
        it = it + 1;
        I = RMatrix::IdentityMatrix(nRows, nCols);
        A = m - p * I;
        v = u;
        x = SolutionofLinearEquations::Gauss(A, v);
        temp = abs(x[0]);
        j = 0;
        for (int i = 0; i < nRows; i++) {
            if (abs(x[i]) > temp) {
                temp = abs(x[i]);
                j = i;
            }
        }
        v = x / x[j];
        er = RVector::NormInf(u - v);
        if (it > itmax) {
            break;
        }
        u = v;
    } while (er > tol);
    return v;
}