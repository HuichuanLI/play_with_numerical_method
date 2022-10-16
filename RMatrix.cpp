//
// Created by lhc456 on 2022/10/16.
//

#include "RMatrix.h"
#include <cmath>
#include <iostream>
#include <iomanip>


RMatrix::RMatrix() {
    nRows = NULL;
    nCols = NULL;
}

RMatrix::RMatrix(int ndim) {
    nRows = ndim;
    nCols = ndim;
    vector<vector<double>> matrix(nRows, vector<double>(nCols));

    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            matrix[i][j] = 0;
        }
    }
    this->matrix = matrix;
}

RMatrix::RMatrix(int nRows, int nCols) {
    this->nRows = nRows;
    this->nCols = nCols;

    vector<vector<double>> matrix(nRows, vector<double>(nCols));
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            matrix[i][j] = 0;
        }
    }
    this->matrix = matrix;
}

RMatrix::RMatrix(vector<vector<double>> matrix) {
    int nRows = matrix.size();
    int nCols = matrix[0].size();
    this->nRows = nRows;
    this->nCols = nCols;
    this->matrix = matrix;
}

RMatrix::RMatrix(const RMatrix &m) {
    nRows = m.nRows;
    nCols = m.nCols;
    matrix = m.matrix;
}

int RMatrix::GetnCols() {
    return nRows;
}

int RMatrix::GetnRows() {
    return nCols;
}

vector<vector<double>> RMatrix::GetMatrix() {
    return matrix;
}

vector<double> &RMatrix::operator[](int i) {
    if (i < 0 || i > nRows) {
        throw "Error!";
    }
    return matrix[i];
}

RMatrix operator+(RMatrix m1, RMatrix m2) {
    if (m1.nRows != m2.nRows && m1.nCols != m2.nCols) {
        throw "Error!";
    }
    RMatrix result(m1.nRows, m1.nCols);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            result[i][j] = m1[i][j] + m2[i][j];

        }
    }
    return result;
}

RMatrix operator*(RMatrix m1, RMatrix m2) {
    if (m1.nCols != m2.nRows) {
        throw "Error";
    }

    double temp;
    RMatrix reuslt(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            temp = 0;
            for (int k = 0; k < m1.nCols; k++) {
                temp += m1[i][j] * m2[k][j];
            }
            reuslt[i][j] = temp;
        }
    }
    return reuslt;
}


RMatrix RMatrix::Transpose(RMatrix m) {
    RMatrix r(m.nCols, m.nRows);
    for (int i = 0; i < r.nRows; i++) {
        for (int j = 0; j < r.nCols; j++) {
            r[j][i] = m[i][j];
        }
    }
    return r;
}

RMatrix RMatrix::TriU(RMatrix m) {
    RMatrix r(m.nCols, m.nCols);

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (i <= j) {
                r[i][j] = m[i][j];
            } else {
                r[i][j] = 0;
            }
        }
    }
    return r;
}

RMatrix RMatrix::SwapRow(RMatrix mat, int m, int n) {
    double temp = 0;
    for (int i = 0; i < mat.nCols; i++) {
        temp = mat[m][i];
        mat[m][i] = mat[n][i];
        mat[n][i] = temp;
    }
    return mat;
}


RMatrix RMatrix::ZerosMatrix(int nRows, int nCols) {

    RMatrix m(nRows, nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            m[i][j] = 0;
        }
    }
    return m;
}

RMatrix RMatrix::OnesMatrix(int nRows, int nCols) {

    RMatrix m(nRows, nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            m[i][j] = 1;
        }
    }
    return m;
}

void RMatrix::ShowMatrix(RMatrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            cout << fixed << setprecision(4) << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void RMatrix::ShowMatrix(vector<vector<double>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout << fixed << setprecision(4) << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
