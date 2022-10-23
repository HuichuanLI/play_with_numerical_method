//
// Created by lhc456 on 2022/10/16.
//



#include <vector>
#include <algorithm>


#ifndef PLAY_WITH_NUMERICAL_METHOD_RVECTOR_H
#define PLAY_WITH_NUMERICAL_METHOD_RVECTOR_H


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

    double &operator[](int i);

    friend RVector operator+(RVector v1, RVector v2);

    static RVector Exp(RVector v);

    static RVector Log(RVector v);

    static RVector Pow(RVector v, double x);

    static RVector LineSpace(double start, double end, int n);

    static RVector LineSpace(double start, double inter, double n);


    static void ShowVector(RVector v);

    static void ShowVector(std::vector<double> v);

    static RVector ZerosVector(int n);


    static double UniformRandom();

    static RVector UniformRandomVector(int ndim);

    static RVector UniformRandomVector(int ndim, int epoch);

    static RVector NormalRandomVector(int ndim);

    static RVector UniformRandomVector(int ndim, double min, double max);

    static RVector RandomShuffle(RVector v);

    static double Average(RVector v);


    static double Max(RVector v);

    static double Min(RVector v);

    static double Sum(RVector v);

    static double StadnardDeviation(RVector v);

    static double Variance(RVector v);

    static double Covariance(RVector x, RVector y);

    static double Correlation(RVector x, RVector y);

    static RVector MinMaxNormalization(RVector x);

    static RVector ZeroScoreNormalization(RVector x);

    static double Distance(RVector x, RVector y);

    static RVector Sqrt(RVector x);

    static double DotProduct(RVector x, RVector w);


    RVector operator*(double x);

    RVector operator*(RVector x);

    RVector operator-(double x);


    RVector operator-(RVector x);

    RVector operator/(double x);

    RVector clone();

    double Norm();
};

#endif //PLAY_WITH_NUMERICAL_METHOD_RVECTOR_H
