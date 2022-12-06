//
// Created by lhc456 on 2022/10/18.
//

#ifndef PLAY_WITH_ALGO_SOLUTIONOFLINEAREQUATION_H
#define PLAY_WITH_ALGO_SOLUTIONOFLINEAREQUATION_H

#include "RMatrix.h"
#include "Rvector.h"

#pragma once

#include "RVector.h"
#include "RMatrix.h"

class SolutionofLinearEquations {
public:
    static RVector BackSubstitution(RMatrix A, RVector B);

    static RVector Thomas(RVector Up, RVector Dia, RVector Down, RVector D);

    static RVector Gauss(RMatrix A, RVector B);

    static RMatrix LUFactorization(RMatrix m);

    static RVector GaussSeidel(RMatrix A, RVector B, RVector X0);

    static RVector SOR(RMatrix A, RVector B, double omega, RVector X0);
};


#endif //PLAY_WITH_ALGO_SOLUTIONOFLINEAREQUATION_H
