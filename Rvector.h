//
// Created by lhc456 on 2022/10/16.
//
#include <vector>

using namespace std;
#ifndef PLAY_WITH_NUMERICAL_METHOD_RVECTOR_H
#define PLAY_WITH_NUMERICAL_METHOD_RVECTOR_H

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

    

};

#endif //PLAY_WITH_NUMERICAL_METHOD_RVECTOR_H
