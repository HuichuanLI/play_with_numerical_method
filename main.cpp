//
// Created by lhc456 on 2022/10/16.
//
#include "Rvector.h"


int main() {
    RVector v1(10);
    vector<double> t = {1, 2, 3, 4, 5, 6, 7};
    RVector v2(t);
    RVector v3 = v2;
    RVector v4(v3);
    RVector v5;

    RVector::ShowVector(v2);
}