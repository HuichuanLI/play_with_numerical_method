//
// Created by lhc456 on 2022/10/20.
//
#include "RMatrix.h"
#include <tuple>
#include <cmath>
#include <iostream>

class NeuralNetWork {
public:
    static double Sigmoid(double x);

    static RVector Sigmoid(RVector x);

    static double Line(double x);

    static RVector Line(RVector x);

    static double ReLu(double x);

    static RVector ReLu(RVector x);

};

double NeuralNetWork::Sigmoid(double x) {
    return 1 / (1 + exp(-x));
}


RVector NeuralNetWork::Sigmoid(RVector x) {
    int ndim = x.GetLength();
    RVector r(ndim);
    for (int i = 0; i < ndim; i++) {
        r[i] = Sigmoid(x[i]);
    }
    return r;
}

double NeuralNetWork::Line(double x) {
    return x;
}

RVector NeuralNetWork::Line(RVector x) {
    return x;
}

double NeuralNetWork::ReLu(double x) {
    if (x < 0) {
        return 0;
    } else {
        return x;
    }
}


RVector NeuralNetWork::ReLu(RVector x) {
    int ndim = x.GetLength();
    RVector r(ndim);
    for (int i = 0; i < ndim; i++) {
        r[i] = ReLu(x[i]);
    }
    return r;
}


tuple<RVector, double> StochasticGradientDescent(RMatrix X, RVector D, int epoch) {
    if (X.GetnRows() != D.GetLength()) {
        throw "Error!";
    }
    double alpha = 0.9;
    int ndim = X.GetnRows();
    int notes = X.GetnCols();
    RVector x;
    double d;

    RVector W = RVector::UniformRandomVector(X.GetnCols()) * 2.0 - 1;
    RVector::ShowVector(W);

    double B = RVector::UniformRandom() - 1;

    double v;
    double y;
    double e;
    double delta;
    RVector dW(notes);
    double dB;
    for (int j = 0; j < epoch; j++) {
        for (int i = 0; i < ndim; i++) {
            x = RMatrix::GetRowVector(X, i);
            d = D[i];
            v = RVector::DotProduct(W, x) + B;
            y = NeuralNetWork::Sigmoid(v);
            e = d - y;
            delta = y * (1 - y) * e;
            dW = x * (alpha * delta);
            dB = alpha * delta;
            W = W + dW;
            B = B + dB;
        }
    }

    return make_tuple(W, B);
}


tuple<RVector, double> StochasticBatch(RMatrix X, RVector D, int epoch) {
    if (X.GetnRows() != D.GetLength()) {
        throw "Error!";
    }
    double alpha = 0.9;
    int ndim = X.GetnRows();
    int notes = X.GetnCols();
    RVector x;
    double d;

    RVector W = RVector::UniformRandomVector(X.GetnCols()) * 2.0 - 1;
    RVector::ShowVector(W);

    double B = RVector::UniformRandom() - 1;

    double v;
    double y;
    double e;
    double delta;
    RVector dW(notes);
    double dB;
    RVector dWsum(notes);
    double dBsum;

    for (int j = 0; j < epoch; j++) {
        dWsum = RVector::ZerosVector(notes);
        dBsum = 0;
        for (int i = 0; i < ndim; i++) {
            x = RMatrix::GetRowVector(X, i);
            d = D[i];
            v = RVector::DotProduct(W, x) + B;
            y = NeuralNetWork::Sigmoid(v);
            e = d - y;
            delta = y * (1 - y) * e;
            dW = x * (alpha * delta);
            dB = alpha * delta;
            W = W + dW;
            B = B + dB;
        }
        W = W + dWsum / ndim;
        B = B + dBsum / ndim;

    }

    return make_tuple(W, B);
}

static RVector ComputeOneLaterNetWork(RMatrix X, tuple<RVector, double> WB) {
    RVector w = get<0>(WB);
    double B = get<1>(WB);
    int ndim = X.GetnRows();
    RVector x;
    double v;
    RVector Y(ndim);
    for (int i = 0; i < ndim; i++) {
        x = RMatrix::GetRowVector(X, i);
        v = RVector::DotProduct(w, x) + B;
        Y[i] = NeuralNetWork::Sigmoid(v);
    }
    return Y;
}


int main() {
    vector<vector<double>> x = {{0, 0, 1},
                                {0, 1, 1,},
                                {1, 0, 1},
                                {1, 1, 1}};
    RMatrix X(x);
    cout << "X= " << endl;
    RMatrix::ShowMatrix(X);
    vector<double> d = {0, 0, 1, 1};
    RVector D(d);
    RVector::ShowVector(d);

    int epoch = 10000;
    tuple<RVector, double> WB = StochasticGradientDescent(X, D, epoch);
    RVector Y = ComputeOneLaterNetWork(X, WB);
    cout << "Y=" << endl;
    RVector::ShowVector(Y);



    tuple<RVector, double> WB1 = StochasticBatch(X, D, epoch);
    RVector Y1 = ComputeOneLaterNetWork(X, WB);
    cout << "Y=" << endl;
    RVector::ShowVector(Y1);
}