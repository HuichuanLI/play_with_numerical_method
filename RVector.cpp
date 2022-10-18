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

RVector RVector::ZerosVector(int n) {
    RVector r(n);
    for (int i = 0; i < r.ndim; i++) {
        r.vector[i] = 0;
    }
    return r;
}


double RVector::UniformRandom() {
    srand((unsigned) time(NULL));
    return rand() / double(RAND_MAX);
}


RVector RVector::UniformRandomVector(int ndim) {
    if (ndim <= 0) {
        throw "Error!";
    }
    RVector result(ndim);
    srand((unsigned) time(NULL));

    for (int i = 0; i < ndim; i++) {
        result[i] = rand() / double(RAND_MAX);
    }
    return result;
}

RVector RVector::NormalRandomVector(int ndim) {
    if (ndim <= 0) {
        throw "Error";
    }
    RVector v(ndim);
    srand((unsigned) time(NULL));

    double fac, rsq, v1, v2, gset1;
    double gset2 = 0;
    double it = 0;
    for (int i = 0; i < ndim; i++) {
        if (it == 0) {
            do {
                v1 = 2 * rand() / double(RAND_MAX) - 1.0;
                v2 = 2 * rand() / double(RAND_MAX) - 1.0;
                rsq = v1 * v1 + v2 * v2;
            } while ((rsq >= 1.0 || rsq == 0.0));
            fac = sqrt(-2.0 * log(rsq) / rsq);
            gset1 = v1 * fac;
            gset2 = v2 * fac;
            v[i] = gset1;
            it = 1;
        } else {
            v[i] = gset2;
            it = 0;
        }
    }
    return v;
}


RVector RVector::UniformRandomVector(int ndim, double min, double max) {
    if (ndim <= 0) {
        throw "Error!";
    }
    RVector result = RVector(ndim);
    for (int i = 0; i < ndim; i++) {
        result[i] = (max - min) * (rand() / double(RAND_MAX)) + min;
    }
    return result;
}

RVector RVector::RandomShuffle(RVector v) {
    srand((unsigned) time(NULL));
    RVector result(v);
    for (int i = v.GetLength() - 1; i >= 0; i--) {
        int index = (rand() % (i + 1));
        double temp = result[index];
        result[index] = result[i];
        result[i] = temp;
    }
    return result;
}


double RVector::Max(RVector v) {
    double r = *max_element(v.vector.begin(), v.vector.end());
    return r;
}

double RVector::Min(RVector v) {
    double r = *max_element(v.vector.begin(), v.vector.end());
    return r;
}

double RVector::Sum(RVector v) {
    double r = 0;
    int n = v.ndim;
    for (int i = 0; i < n; i++) {
        r += v[i];
    }
    return r;
}

double RVector::StadnardDeviation(RVector v) {
    double result = RVector::Variance(v);
    result = sqrt(result);
    return result;
}

double RVector::Variance(RVector v) {
    double average = Average(v);
    double result = 0;
    for (int i = 0; i < v.ndim; i++) {
        result += (v[i] - average) * (v[i] - average);
    }
    return result / v.ndim;
}

double RVector::Average(RVector v) {
    double result = Sum(v);
    return result / v.ndim;
}

double RVector::Covariance(RVector x, RVector y) {
    if (x.GetLength() != y.GetLength()) {
        throw "error!";
    }
    int ndim = x.GetLength();
    double r = 0;
    for (int i = 0; i < ndim; i++) {
        r += (x[i] - Average(x)) * (y[i] - Average(x));
    }
    return r;
}

double RVector::Correlation(RVector x, RVector y) {
    if (x.GetLength() != y.GetLength()) {
        throw "error!";
    }
    int ndim = x.GetLength();
    double r;
    double sigma1 = Variance(x);
    double sigma2 = Variance(y);
    double covxy = Covariance(x, y);
    r = covxy / sqrt(sigma1 * sigma2);
    return r;
}

RVector RVector::MinMaxNormalization(RVector x) {
    int n = x.ndim;
    RVector r(n);
    for (int i = 0; i < n; i++) {
        r[i] = (x[i] - Min(x)) / (Max(x) - Min(x));
    }
    return r;
}


RVector RVector::ZeroScoreNormalization(RVector x) {
    int ndim = x.ndim;
    RVector r(ndim);
    for (int i = 0; i < ndim; i++) {
        r[i] = (x[i] - Average(x)) / StadnardDeviation(x);
    }
    return r;
}

double RVector::Distance(RVector x, RVector y) {
    if (x.GetLength() != y.GetLength()) {
        throw "error!";
    }
    double r = 0;
    for (int i = 0; i < x.GetLength(); i++) {
        r += (x[i] - y[i]) * (x[i] - y[i]);
    }
    r = sqrt(r);
    return r;
}


