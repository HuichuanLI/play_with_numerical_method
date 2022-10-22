//
// Created by lhc456 on 2022/10/16.
//
#include <vector>
#include "Rvector.h"

using namespace std;

#ifndef PLAY_WITH_ALGO_RMATRIX_H
#define PLAY_WITH_ALGO_RMATRIX_H


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

    friend RMatrix operator+(RMatrix m1, RMatrix m2);

    friend RMatrix operator*(RMatrix m1, RMatrix m2);

    static RMatrix Transpose(RMatrix m);

    static RMatrix TriU(RMatrix m);

    static RMatrix SwapRow(RMatrix mat, int m, int n);

    static RMatrix ZerosMatrix(int nRows, int nCols);

    static RMatrix OnesMatrix(int nRows, int nCols);

    static void ShowMatrix(RMatrix m);


    static void ShowMatrix(vector<vector<double>> m);


    static RVector GetColVector(RMatrix m, int i);

    static RVector Max(RMatrix v);

    static RVector Min(RMatrix v);

    static RVector Sum(RMatrix v);

    static RVector Average(RMatrix v);

    static RVector StadnardDeviation(RMatrix v);

    static RVector Variance(RMatrix v);

    static RMatrix MinMaxNormalization(RMatrix x);

    static RMatrix ZeroScoreNormalization(RMatrix x);

    static RVector GetRowVector(RMatrix x, int i);

    static RMatrix UniformRandomMatrix(int rows, int cols);

    void SetRowVector(int i, RVector v);

    friend RVector operator*(RMatrix m1, RVector m2);

    friend RMatrix operator*(RMatrix m1, double m2);

    friend RMatrix operator+(RMatrix m1, RVector m2);

    friend RMatrix operator*(RVector m1, RVector m2);

    static RMatrix Outerproduct(RVector m1, RVector m2);

    static RMatrix CatCols(RMatrix A, RVector B);

};


#endif //PLAY_WITH_ALGO_RMATRIX_H
