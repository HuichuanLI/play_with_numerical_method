#pragma once

#include "RVector.h"
#include<vector>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

class RMatrix {
private:
    int nRows;
    int nCols;
    vector<vector<double>> matrix;
public:
    RMatrix();

    RMatrix(int ndim);

    RMatrix(int nRows, int nCols);

    RMatrix(const RMatrix &ma);

    RMatrix(vector<vector<double>> matrix);

    int GetnRows();

    int GetnCols();

    vector<vector<double>> GetMatrix();

    vector<double> &operator[](int i);

    static RMatrix ZerosMatrix(int ndim);

    static RMatrix ZerosMatrix(int nRows, int nCols);

    static RMatrix OnesMatrix(int nRows, int nCols);

    static RMatrix OnesMatrix(int ndim);

    static RMatrix IdentityMatrix(int nRows, int nCols);

    static RMatrix IdentityMatrix(int ndim);

    friend RMatrix operator+(RMatrix m1, RMatrix m2);

    friend RMatrix operator-(RMatrix m1, RMatrix m2);

    friend RMatrix operator*(RMatrix m1, RMatrix m2);

    friend RVector operator*(RMatrix m, RVector v);

    friend RMatrix operator*(RMatrix m, double r);

    friend RMatrix operator*(double r, RMatrix m);

    friend RMatrix operator/(RMatrix m, double r);

    friend RMatrix operator/(double r, RMatrix m);

    static RMatrix Transpose(RMatrix m);

    static RMatrix TriU(RMatrix m);

    static RMatrix CatCols(RMatrix m, RVector v);

    static RMatrix SwapRow(RMatrix mat, int m, int n);

    static RVector GetRowVector(RMatrix mat, int m);

    static RVector GetColVector(RMatrix mat, int n);

    static RMatrix ReplaceRow(RMatrix mat, int m, RVector vec);

    static RMatrix ReplaceCol(RMatrix mat, int n, RVector vec);

    static RMatrix ConvertToRow(RVector v);

    static RMatrix ConvertToCol(RVector v);

    static void ShowMatrix(RMatrix m);

    static void ShowMatrix(vector<vector<double>> m);

    static RVector Max(RMatrix m);

    static RVector Min(RMatrix m);

    static RVector Sum(RMatrix m);

    static RVector Average(RMatrix m);

    static RVector StandardDeviation(RMatrix m);

    static RVector Variance(RMatrix m);

    static RMatrix CovarianceMatrix(RMatrix m);

    static RMatrix CorrelationMatrix(RMatrix m);

    static RMatrix MinMaxNormalization(RMatrix m);

    static RMatrix ZeroScoreNormalization(RMatrix m);

    static RMatrix UniformRandomMatrix(int m, int n);

    static double Norm(RMatrix m);

//    static RMatrix Replace(RMatrix A, RVector b, int i);

};
