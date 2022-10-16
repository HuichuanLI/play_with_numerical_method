//
// Created by lhc456 on 2022/10/16.
//
#include "Rvector.h"
#include <cmath>
#include <iostream>
#include <iomanip>

RVector::RVector() {
    ndim = NULL;
}

RVector::RVector(int ndim) {
    this->ndim = ndim;
    std::vector<double> vector(ndim);
    for (int i = 0; i < ndim; i++) {
        vector[i] = 0;
    }
    this->vector = vector;
}

RVector::RVector(const RVector &v) {
    ndim = v.ndim;
    vector = v.vector;
}


RVector::RVector(std::vector<double> vector) {
    ndim = vector.size();
    this->vector = vector;
}

int RVector::GetLength() {
    return ndim;
}

vector<double> RVector::GetVector() {
    return vector;
}

double &RVector::operator[](int i) {
    if (i < 0 || i > ndim) {
        throw "Erroro!";
    }
    return vector[i];
}


RVector operator+(RVector v1, RVector v2) {
    if (v1.ndim == v2.ndim) {
        RVector v3(v1.ndim);
        for (int i = 0; i < v1.ndim; i++) {
            v3[i] = v1[i] + v2[i];
        }
        return v3;
    } else {
        throw "Error!";
    }
}

RVector RVector::Exp(RVector v) {
    RVector r(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        r[i] = exp(v[i]);
    }
    return r;
}

RVector RVector::Log(RVector v) {
    RVector r(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        r[i] = log(v[i]);
    }
    return r;
}


RVector RVector::Pow(RVector v, double x) {
    RVector r(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        r[i] = pow(v[i], x);
    }
    return r;
}

RVector RVector::LineSpace(double start, double end, int n) {
    RVector r(n + 1);
    for (int i = 0; i < r.ndim; i++) {
        r.vector[i] = start + (end - start) / n * i;
    }
    return r;
}

RVector RVector::LineSpace(double start, double inter, double end) {
    int ndim = (int) (floor((end - start) / inter) + 1);
    RVector r(ndim);
    for (int i = 0; i < r.ndim; i++) {
        r.vector[i] = start + inter * i;
    }
    return r;
}


void RVector::ShowVector(RVector v) {
    for (int i = 0; i < v.ndim; i++) {
        cout << fixed << setprecision(4) << v[i] << " ";
    }
    cout << endl << endl;
}

void RVector::ShowVector(std::vector<double> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << fixed << setprecision(4) << v[i] << " ";
    }
    cout << endl << endl;
}

