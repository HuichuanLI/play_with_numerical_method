//
// Created by lhc456 on 2022/10/20.
//
#include "RMatrix.h"
#include <tuple>
#include <cmath>

class NeuralNetWork {
public:
    static double Sigmoid(double x);

    static RVector Sigmoid(RVector x);

    static double Line(double x);

    static RVector Line(RVector x);

    static double ReLu(double x);

    static RVector ReLu(RVector x);

    static tuple<RVector, double> StochasticGradientDescent(RMatrix X, RVector D, int epoch);

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


static tuple<RVector, double> StochasticGradientDescent(RMatrix X, RVector D, int epoch) {
    if (X.GetnRows() != D.GetLength()) {
        throw "Error!";
    }
    double alpha = 0.9;
    int ndim = X.GetnRows();
    int notes = X.GetnCols();
    RVector x;
    double d;
    RVector W = RVector::UniformRandomVector(X.GetnRows());
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








