//
// Created by lhc456 on 2022/10/16.
//

#ifndef PLAY_WITH_ALGO_SOULUTIONOFNONLINEAREQUATION_H
#define PLAY_WITH_ALGO_SOULUTIONOFNONLINEAREQUATION_H

#include <vector>

using namespace std;

typedef double  (*Function)(double);


class SolutionofNonlinearEquation {
public:
    static double FixedPointIteration(Function f, double x0, double tol, int maxit);

    static vector<double> BisectionIteration(Function f, double x0, double tol, int maxit);

    static vector<double> NewtonRaphsonIteration(Function f, double x, double tol);
};

#endif //PLAY_WITH_ALGO_SOULUTIONOFNONLINEAREQUATION_H
