//
// Created by lhc456 on 2022/10/16.
//

#ifndef PLAY_WITH_ALGO_RMATRIX_H
#define PLAY_WITH_ALGO_RMATRIX_H

#include <vector>

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


    friend RMatrix operator+(RMatrix m1, RMatrix m2);

    friend RMatrix operator*(RMatrix m1, RMatrix m2);

    static RMatrix Transpose(RMatrix m);

    static RMatrix TriU(RMatrix m);

    static RMatrix SwapRow(RMatrix mat, int m, int n);

    static RMatrix ZerosMatrix(int nRows, int nCols);

    static RMatrix OnesMatrix(int nRows, int nCols);

    static void ShowMatrix(RMatrix m);


    static void ShowMatrix(vector<vector<double>> m);


};


#endif //PLAY_WITH_ALGO_RMATRIX_H
