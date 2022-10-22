//
// Created by lhc456 on 2022/10/22.
//

#ifndef PLAY_WITH_ALGO_NUMERICALOPTIMIZATION_H
#define PLAY_WITH_ALGO_NUMERICALOPTIMIZATION_H
#pragma once

#include <cmath>

typedef double (*Function)(double);

double GoldenMin(Function f, double a, double b);

double QuadMin(Function f, double a, double b, double x0);

#endif //PLAY_WITH_ALGO_NUMERICALOPTIMIZATION_H

