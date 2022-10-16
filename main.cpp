//
// Created by lhc456 on 2022/10/16.
//
#include "Rvector.h"
#include "RMatrix.h"


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

}