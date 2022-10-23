//
// Created by lhc456 on 2022/10/22.
//

#ifndef PLAY_WITH_ALGO_NUMERICALOPTIMIZATION_H
#define PLAY_WITH_ALGO_NUMERICALOPTIMIZATION_H
#pragma once

#include <cmath>
#include "Rvector.h"

typedef double (*Function)(double);

typedef double (*MultiVarFunction)(RVector);

double GoldenMin(Function f, double a, double b);

double QuadMin(Function f, double a, double b, double x0);

RVector MultivVarGradientMin(MultiVarFunction f, RVector x0);

#endif //PLAY_WITH_ALGO_NUMERICALOPTIMIZATION_H


