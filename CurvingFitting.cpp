//
// Created by lhc456 on 2022/10/24.
//
#include "Rvector.h"
#include "RMatrix.h"
#include "CurvingFitting.h"
#include "SolutionofLinearEquation.h"

RVector LineFitting(RVector x, RVector y) {
    RVector result(2);
    double averagex = RVector::Average(x);
    double averagey = RVector::Average(y);
    double sumxx = RVector::DotProduct((x - averagex), (x - averagex));
    double sumxy = RVector::DotProduct((x - averagex), (y - averagey));

    double a = sumxy / sumxx;
    double b = averagey - a * averagex;
    result[0] = b;
    result[1] = a;
    return result;

}


//RVector PolynomialFitting(RVector X, RVector Y, int deg) {
//    int num = X.GetLength();
//    RMatrix Phi(deg + 1, num);
//    RMatrix PhiT(num, deg + 1);
//
//    RVector vec(num);
//    RMatrix A;
//    RVector B;
//    for (int i = 0; i < Phi.GetnCols(); i++) {
//        vec = RVector::Pow(X, i);
//        Phi = RMatrix::Replace(Phi, vec,i);
//    }
//    PhiT = RMatrix::Transpose(Phi);
//    A = Phi * PhiT;
//    B = Phi * Y;
//    RVector result = SolutionofLinearEquations::Gauss(A, B);
//    return result;
//
//}