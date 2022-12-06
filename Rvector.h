#pragma once

#include<vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class RVector {
private:
    int ndim;
    vector<double> vector;
public:
    RVector();

    RVector(int ndim);

    RVector(const RVector &v);

    RVector(std::vector<double> vector);

    int GetLength();

    std::vector<double> GetVector();

    static RVector ZerosVector(int ndim);

    static RVector OnesVector(int ndim);

    static RVector LineSpace(double start, double end, int n);

    static RVector LineRange(double start, double inter, double end);

    friend RVector operator+(RVector v1, RVector v2);

    friend RVector operator-(RVector v1, RVector v2);

    friend RVector operator*(RVector v1, RVector v2);

    friend RVector operator/(RVector v1, RVector v2);

    friend RVector operator+(RVector v, double r);

    friend RVector operator+(double r, RVector v);

    friend RVector operator-(RVector v, double r);

    friend RVector operator-(double r, RVector v);

    friend RVector operator*(RVector v, double r);

    friend RVector operator*(double r, RVector v);

    friend RVector operator/(RVector v, double r);

    friend RVector operator/(double r, RVector v);

    double &operator[](int i);

    RVector operator-();

    RVector operator+();

    static RVector Exp(RVector v);

    static RVector Log(RVector v);

    static RVector Pow(RVector v, double x);

    static RVector Sqrt(RVector v);

    static RVector Abs(RVector v);

    static void ShowVector(RVector v);

    static double Norm(RVector v);

    static double NormInf(RVector v);

    static double Average(RVector v);

    static double DotProduct(RVector v1, RVector v2);

    static RVector RandomShuffle(RVector v);

    static RVector UniformRandomVector(int ndim);

    static RVector NormalRandomVector(int ndim);

    static void ShowVector(std::vector<double> v);

    static double Max(RVector v);

    static double Min(RVector v);

    static double Sum(RVector v);

    static double StandardDeviation(RVector v);

    static double Variance(RVector v);

    static double Covariance(RVector x, RVector y);

    static double Correlation(RVector x, RVector y);

    static RVector MinMaxNormalization(RVector v);

    static RVector ZeroScoreNormalization(RVector v);

    static double Distance(RVector x, RVector y);
};
