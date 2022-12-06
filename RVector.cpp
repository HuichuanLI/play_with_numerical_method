#include "RVector.h"

RVector::RVector() {
    ndim = NULL;
}

RVector::RVector(int ndim) {
    this->ndim = ndim;
    std::vector<double> vector(ndim);
    for (int i = 0; i < ndim; i++) {
        vector[i] = 0;
    }
    this->vector = vector;
}

RVector::RVector(const RVector &v) {
    ndim = v.ndim;
    vector = v.vector;
}

RVector::RVector(std::vector<double> vector) {
    ndim = vector.size();
    this->vector = vector;
}

int RVector::GetLength() {
    return ndim;
}

vector<double> RVector::GetVector() {
    return vector;
}

RVector RVector::ZerosVector(int ndim) {
    RVector v(ndim);
    for (int i = 0; i < ndim; i++) {
        v.vector[i] = 0;
    }
    return v;
}

RVector RVector::OnesVector(int ndim) {
    RVector v(ndim);
    for (int i = 0; i < ndim; i++) {
        v.vector[i] = 1;
    }
    return v;
}

RVector operator+(RVector v1, RVector v2) {
    if (v1.ndim == v2.ndim) {
        RVector v3(v1.ndim);
        for (int i = 0; i < v1.ndim; i++) {
            v3[i] = v1[i] + v2[i];
        }
        return v3;
    } else {
        throw "Error!";
    }
}

RVector operator-(RVector v1, RVector v2) {
    if (v1.ndim == v2.ndim) {
        RVector v3(v1.ndim);
        for (int i = 0; i < v1.ndim; i++) {
            v3[i] = v1[i] - v2[i];
        }
        return v3;
    } else {
        throw "Error!";
    }
}

RVector operator*(RVector v1, RVector v2) {
    if (v1.ndim == v2.ndim) {
        RVector v3(v1.ndim);
        for (int i = 0; i < v1.ndim; i++) {
            v3[i] = v1[i] * v2[i];
        }
        return v3;
    } else {
        throw "Error!";
    }
}

RVector operator/(RVector v1, RVector v2) {
    if (v1.ndim == v2.ndim) {
        RVector v3(v1.ndim);
        for (int i = 0; i < v1.ndim; i++) {
            v3[i] = v1[i] * v2[i];
        }
        return v3;
    } else {
        throw "Error!";
    }
}

RVector RVector::LineSpace(double start, double end, int n) {
    RVector r(n + 1);
    for (int i = 0; i < r.ndim; i++) {
        r.vector[i] = start + (end - start) / n * i;
    }
    return r;
}

RVector RVector::LineRange(double start, double inter, double end) {
    int ndim = (int) (floor((end - start) / inter) + 1);
    RVector r(ndim);
    for (int i = 0; i < r.ndim; i++) {
        r.vector[i] = start + inter * i;
    }
    return r;
}

double &RVector::operator[](int i) {
    if (i < 0 || i > ndim) {
        throw "Error!";
    }
    return vector[i];
}

RVector RVector::Exp(RVector v) {
    RVector r(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        r[i] = exp(v[i]);
    }
    return r;
}

RVector RVector::Log(RVector v) {
    RVector r(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        r[i] = log(v[i]);
    }
    return r;
}

RVector RVector::Pow(RVector v, double x) {
    RVector r(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        r[i] = pow(v[i], x);
    }
    return r;
}

RVector RVector::Sqrt(RVector v) {
    RVector r(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        r[i] = sqrt(v[i]);
    }
    return r;
}

RVector RVector::Abs(RVector v) {
    RVector r(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        r[i] = abs(v[i]);
    }
    return r;
}

void RVector::ShowVector(RVector v) {
    for (int i = 0; i < v.ndim; i++) {
        cout << fixed << setprecision(4) << v[i] << " ";
    }
    cout << endl << endl;
}

RVector operator+(RVector v, double r) {
    RVector v2(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        v2[i] = v[i] + r;
    }
    return v2;
}

RVector operator+(double r, RVector v) {
    RVector v2(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        v2[i] = r + v[i];
    }
    return v2;
}

RVector RVector::operator-() {
    int ndim = this->ndim;
    RVector r(ndim);
    for (int i = 0; i < ndim; i++) {
        r[i] = -this->vector[i];
    }
    return r;
}

RVector RVector::operator+() {
    int ndim = this->ndim;
    RVector r(ndim);
    r.vector = this->vector;
    return r;
}

RVector operator-(RVector v, double r) {
    RVector v2(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        v2[i] = v[i] - r;
    }
    return v2;
}

RVector operator-(double r, RVector v) {
    RVector v2(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        v2[i] = r - v[i];
    }
    return v2;
}

RVector operator*(RVector v, double r) {
    RVector v2(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        v2[i] = v[i] * r;
    }
    return v2;
}

RVector operator*(double r, RVector v) {
    RVector v2(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        v2[i] = r * v[i];
    }
    return v2;
}

RVector operator/(RVector v, double r) {
    RVector v2(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        v2[i] = v[i] / r;
    }
    return v2;
}

RVector operator/(double r, RVector v) {
    RVector v2(v.ndim);
    for (int i = 0; i < v.ndim; i++) {
        v2[i] = r / v[i];
    }
    return v2;
}

double RVector::Norm(RVector v) {
    double result = 0;
    for (int i = 0; i < v.ndim; i++) {
        result += v[i] * v[i];
    }
    result = sqrt(result);
    return result;
}

double RVector::NormInf(RVector v) {
    double result = v[0];
    for (int i = 0; i < v.ndim; i++) {
        if (abs(v[i]) > result) {
            result = abs(v[i]);
        }
    }
    return result;
}

double RVector::Average(RVector v) {
    double result = 0;
    for (int i = 0; i < v.ndim; i++) {
        result += v[i];
    }
    result = result / v.ndim;
    return result;
}

double RVector::DotProduct(RVector v1, RVector v2) {
    double result = 0;
    if (v1.ndim == v2.ndim) {
        for (int i = 0; i < v1.ndim; i++) {
            result += v1[i] * v2[i];
        }
        return result;
    } else {
        throw "Error!";
    }
}

RVector RVector::RandomShuffle(RVector v) {
    srand((unsigned) time(NULL));
    random_shuffle(v.vector.begin(), v.vector.end());
    return v;
}

//RVector RVector::RandomShuffle(RVector v)
//{
//	srand((unsigned)time(NULL));
//	RVector result(v);
//	for (int i = v.GetLength() - 1; i >= 0; i--)
//	{
//		int index = (rand() % (i + 1));
//		double temp = result[index];
//		result[index] = result[i];
//		result[i] = temp;
//	}
//	return result;
//}
RVector RVector::UniformRandomVector(int ndim) {
    if (ndim <= 0) {
        throw "Error";
    }
    RVector result(ndim);
    srand((unsigned) time(NULL));
    for (int i = 0; i < ndim; i++) {
        result[i] = rand() / double(RAND_MAX);
    }
    return result;
}

RVector RVector::NormalRandomVector(int ndim) {
    if (ndim <= 0) {
        throw "Error";
    }
    RVector v(ndim);
    srand((unsigned) time(NULL));
    double fac, rsq, v1, v2, gset1;
    double gset2 = 0;
    double it = 0;
    for (int i = 0; i < ndim; i++) {
        if (it == 0) {
            do {
                v1 = 2 * rand() / double(RAND_MAX) - 1.0;
                v2 = 2 * rand() / double(RAND_MAX) - 1.0;
                rsq = v1 * v1 + v2 * v2;
            } while (rsq >= 1.0 || rsq == 0.0);
            fac = sqrt(-2.0 * log(rsq) / rsq);
            gset1 = v1 * fac;
            gset2 = v2 * fac;
            v[i] = gset1;
            it = 1;
        } else {
            v[i] = gset2;
            it = 0;
        }
    }
    return v;
}

void RVector::ShowVector(std::vector<double> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << fixed << setprecision(4) << v[i] << " ";
    }
    cout << endl << endl;
}

double RVector::Max(RVector v) {
    double r = *max_element(v.vector.begin(), v.vector.end());
    return r;
}

double RVector::Min(RVector v) {
    double r = *min_element(v.vector.begin(), v.vector.end());
    return r;
}

double RVector::Sum(RVector v) {
    double r = 0;
    int n = v.ndim;
    for (int i = 0; i < n; i++) {
        r += v[i];
    }
    return r;
}

double RVector::StandardDeviation(RVector v) {
    double result = Variance(v);
    result = sqrt(result);
    return result;
}

double RVector::Variance(RVector v) {
    double average = Average(v);
    double result = 0;
    for (int i = 0; i < v.ndim; i++) {
        result += (v[i] - average) * (v[i] - average);
    }
    result = result / v.ndim;
    return result;
}

double RVector::Covariance(RVector x, RVector y) {
    if (x.GetLength() != y.GetLength()) {
        throw "Error!";
    }
    int ndim = x.GetLength();
    double r = 0;
    for (int i = 0; i < ndim; i++) {
        r += (x[i] - Average(x)) * (y[i] - Average(y)) / ndim;

    }
    return r;
}

double RVector::Correlation(RVector x, RVector y) {
    if (x.GetLength() != y.GetLength()) {
        throw "Error!";
    }
    int ndim = x.GetLength();
    double r;
    double sigma1 = Variance(x);
    double sigma2 = Variance(y);
    double covxy = Covariance(x, y);
    r = covxy / sqrt(sigma1 * sigma2);
    return r;
}

RVector RVector::MinMaxNormalization(RVector v) {
    int n = v.ndim;
    RVector r(n);
    for (int i = 0; i < n; i++) {
        r[i] = (v[i] - Min(v)) / (Max(v) - Min(v));
    }
    return r;
}

RVector RVector::ZeroScoreNormalization(RVector v) {
    int ndim = v.ndim;
    RVector r(ndim);
    for (int i = 0; i < ndim; i++) {
        r[i] = (v[i] - Average(v)) / StandardDeviation(v);
    }
    return r;
}

double RVector::Distance(RVector x, RVector y) {
    if (x.GetLength() != y.GetLength()) {
        throw "Error";
    }
    double r = 0;
    for (int i = 0; i < x.GetLength(); i++) {
        r += (x[i] - y[i]) * (x[i] - y[i]);
    }
    r = sqrt(r);
    return r;
}



