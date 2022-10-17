//
// Created by lhc456 on 2022/10/18.
//

#ifndef PLAY_WITH_ALGO_SOLUTIONOFLINEAREQUATION_H
#define PLAY_WITH_ALGO_SOLUTIONOFLINEAREQUATION_H

#include "RMatrix.h"
#include "Rvector.h"

class SolutionofLinearEquations {
public:
    static RVector BackSubstitution(RMatrix A, RVector B);
};

#endif //PLAY_WITH_ALGO_SOLUTIONOFLINEAREQUATION_H
