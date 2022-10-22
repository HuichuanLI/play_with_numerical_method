//
// Created by lhc456 on 2022/10/16.
//

#ifndef PLAY_WITH_ALGO_TEST_H
#define PLAY_WITH_ALGO_TEST_H

#include <cmath>
#include "Rvector.h"

double Fun(double x) {
    return (x + 2.0 / x) / 2;
}

double Fun1(double x) {
    return x - cos(x);
}


double Fun2(double x) {
    return pow(x, 3) - 3 * x - 2;
}

double Fun3(RVector x) {
    return (x[0] - x[1]) / (x[0] * x[0] + x[1] * x[1] + 2);
}


double Fun4(double x) {
    return -x * x / 10 - sin(x);
}


#endif //PLAY_WITH_ALGO_TEST_H
