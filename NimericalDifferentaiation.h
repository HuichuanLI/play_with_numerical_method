//
// Created by lhc456 on 2022/10/22.
//
#pragma once

#include "Rvector.h"
#include "RMatrix.h"

class NumericalDifferentaitioan {
public :
    typedef double (*Function)(double);

    static double CentralDifferecne(Function f, double x0, double dx);

    static RVector CentralDifference(RVector x, double dx);

    static double CentralDifferenceLimits(Function f, double x0, double tol);

    typedef double (*MultiVarFunction)(RVector);

    static RVector Gradient(MultiVarFunction f, RVector x0, double dx);

    static RMatrix Hessian(MultiVarFunction f, RVector x0, double dx);
};