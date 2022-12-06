#pragma once

#include "RMatrix.h"
#include <tuple>
#include <cmath>
#include "SolutionofLinearEquation.h"

using namespace std;

class EigenvectorandEigenvalue {
public:
    static tuple<RMatrix, RMatrix> QRGivensRotations(RMatrix m);

    static tuple<RMatrix, RMatrix> QRGramSchmidt(RMatrix m);

    static tuple<RMatrix, RMatrix> QRHouseholder(RMatrix m);

    static RMatrix HessenbergHouseholder(RMatrix m);

    static RMatrix Eigenvalue(RMatrix m);

    static RVector Eigenvector(RMatrix m, double p);
};

