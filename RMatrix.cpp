#include "RMatrix.h"

using namespace std;

RMatrix::RMatrix() {
    nRows = NULL;
    nCols = NULL;
}

RMatrix::RMatrix(int ndim) {
    nRows = ndim;
    nCols = ndim;
    vector<vector<double>> matrix(nRows, vector<double>(nCols));
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            matrix[i][j] = 0;
        }
    }
    this->matrix = matrix;
}

RMatrix::RMatrix(int nRows, int nCols) {
    this->nRows = nRows;
    this->nCols = nCols;
    vector<vector<double>> matrix(nRows, vector<double>(nCols));
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            matrix[i][j] = 0;
        }
    }
    this->matrix = matrix;
}

RMatrix::RMatrix(vector<vector<double>> matrix) {
    int nRows = matrix.size();
    int nCols = matrix[0].size();
    this->nRows = nRows;
    this->nCols = nCols;
    this->matrix = matrix;
}

RMatrix::RMatrix(const RMatrix &m) {
    nRows = m.nRows;
    nCols = m.nCols;
    matrix = m.matrix;
}

int RMatrix::GetnRows() {
    return nRows;
}

int RMatrix::GetnCols() {
    return nCols;
}

vector<vector<double>> RMatrix::GetMatrix() {
    return matrix;
}

RMatrix operator+(RMatrix m1, RMatrix m2) {
    if (m1.nRows != m2.nRows && m1.nCols != m2.nCols) {
        throw "Error!";
    }
    RMatrix result(m1.nRows, m1.nCols);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result;
}

RMatrix operator-(RMatrix m1, RMatrix m2) {
    if (m1.nRows != m2.nRows && m1.nCols != m2.nCols) {
        throw "Error!";
    }
    RMatrix result(m1.nRows, m1.nCols);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m1.nCols; j++) {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return result;
}

RMatrix operator*(RMatrix m1, RMatrix m2) {
    if (m1.nCols != m2.nRows) {
        throw "Error";
    }
    double tmp;
    RMatrix result(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            tmp = 0;
            for (int k = 0; k < m1.nCols; k++) {
                tmp += m1[i][k] * m2[k][j];
            }
            result[i][j] = tmp;
        }
    }
    return result;
}

RMatrix RMatrix::ZerosMatrix(int ndim) {
    int nRows = ndim;
    int nCols = ndim;
    RMatrix m(nRows, nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            m[i][j] = 0;
        }
    }
    return m;
}

RMatrix RMatrix::ZerosMatrix(int nRows, int nCols) {
    RMatrix m(nRows, nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            m[i][j] = 0;
        }
    }
    return m;
}

RMatrix RMatrix::OnesMatrix(int nRows, int nCols) {
    RMatrix m(nRows, nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            m[i][j] = 1;
        }
    }
    return m;
}

RMatrix RMatrix::OnesMatrix(int ndim) {
    int nRows = ndim;
    int nCols = ndim;
    RMatrix m(nRows, nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            m[i][j] = 1;
        }
    }
    return m;
}

RMatrix RMatrix::IdentityMatrix(int nRows, int nCols) {
    RMatrix m(nRows, nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (i == j) {
                m[i][j] = 1;
            }
        }
    }
    return m;
}

RMatrix RMatrix::IdentityMatrix(int ndim) {
    int nRows = ndim;
    int nCols = ndim;
    RMatrix m(nRows, nCols);
    for (int i = 0; i < m.nRows; i++) {
        m[i][i] = 1;
    }
    return m;
}

vector<double> &RMatrix::operator[](int i) {
    if (i < 0 || i > nRows) {
        throw "Error!";
    }
    return matrix[i];
}

RMatrix RMatrix::Transpose(RMatrix m) {
    RMatrix r(m.nCols, m.nRows);
    for (int i = 0; i < r.nRows; i++) {
        for (int j = 0; j < r.nCols; j++) {
            r[i][j] = m[j][i];
        }
    }
    return r;
}

RMatrix RMatrix::TriU(RMatrix m) {
    RMatrix r(m.nRows, m.nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (i <= j) {
                r[i][j] = m[i][j];
            } else {
                r[i][j] = 0;
            }
        }
    }
    return r;
}

RMatrix RMatrix::CatCols(RMatrix m, RVector v) {

    if (m.nRows != v.GetLength()) {
        throw "Error";
    }
    RMatrix r(m.nRows, m.nCols + 1);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            r[i][j] = m[i][j];
        }
        r[i][m.nCols] = v[i];
    }
    return r;
}

RMatrix RMatrix::SwapRow(RMatrix mat, int m, int n) {
    double temp = 0;
    for (int i = 0; i < mat.nCols; i++) {
        temp = mat[m][i];
        mat[m][i] = mat[n][i];
        mat[n][i] = temp;
    }
    return mat;
}

RVector RMatrix::GetRowVector(RMatrix mat, int m) {
    if (m < 0 || m > mat.nRows) {
        throw "Error";
    }
    RVector v(mat.nCols);
    for (int i = 0; i < mat.nCols; i++) {
        v[i] = mat[m][i];
    }
    return v;
}

RVector RMatrix::GetColVector(RMatrix mat, int n) {
    if (n < 0 || n > mat.nCols) {
        throw "Error";
    }
    RVector v(mat.nRows);
    for (int i = 0; i < mat.nRows; i++) {
        v[i] = mat[i][n];
    }
    return v;
}

RMatrix RMatrix::ReplaceRow(RMatrix mat, int m, RVector vec) {
    if (m < 0 || m > mat.nRows) {
        throw "Error!";
    }
    if (vec.GetLength() != mat.nCols) {
        throw "Error!";
    }
    for (int i = 0; i < mat.nCols; i++) {
        mat[m][i] = vec[i];
    }
    return mat;
}

RMatrix RMatrix::ReplaceCol(RMatrix mat, int n, RVector vec) {
    if (n < 0 || n > mat.nCols) {
        throw "Error!";
    }
    if (vec.GetLength() != mat.nRows) {
        throw "Error!";
    }
    for (int i = 0; i < mat.nRows; i++) {
        mat[i][n] = vec[i];
    }
    return mat;
}

void RMatrix::ShowMatrix(RMatrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            cout << fixed << setprecision(4) << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void RMatrix::ShowMatrix(vector<vector<double>> m) {
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size(); j++) {
            cout << fixed << setprecision(4) << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

RVector operator*(RMatrix m, RVector v) {
    if (v.GetLength() != m.nCols) {
        throw "Error";
    }
    RVector r(m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        double sum = 0;
        for (int j = 0; j < m.nCols; j++) {
            sum += v[j] * m[i][j];
        }
        r[i] = sum;
    }
    return r;
}

RMatrix operator*(RMatrix m, double r) {
    RMatrix result(m.nRows, m.nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            result[i][j] = m[i][j] * r;
        }
    }
    return result;

}

RMatrix operator*(double r, RMatrix m) {
    RMatrix result(m.nRows, m.nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            result[i][j] = m[i][j] * r;
        }
    }
    return result;
}

RMatrix operator/(RMatrix m, double r) {
    RMatrix result(m.nRows, m.nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            result[i][j] = m[i][j] / r;
        }
    }
    return result;
}

RMatrix operator/(double r, RMatrix m) {
    RMatrix result(m.nRows, m.nCols);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            result[i][j] = r / m[i][j];
        }
    }
    return result;
}

RVector RMatrix::Max(RMatrix m) {
    RVector r(m.nCols);
    for (int i = 0; i < m.nCols; i++) {
        r[i] = RVector::Max(RMatrix::GetColVector(m, i));
    }
    return r;
}

RVector RMatrix::Min(RMatrix m) {
    RVector r(m.nCols);
    for (int i = 0; i < m.nCols; i++) {
        r[i] = RVector::Min(RMatrix::GetColVector(m, i));
    }
    return r;
}

RVector RMatrix::Sum(RMatrix m) {
    RVector r(m.nCols);
    RVector v(m.nRows);
    for (int i = 0; i < m.nCols; i++) {
        v = RMatrix::GetColVector(m, i);
        r[i] = RVector::Sum(v);
    }
    return r;
}

RVector RMatrix::Average(RMatrix m) {
    RVector r(m.nCols);
    for (int i = 0; i < m.nCols; i++) {
        r[i] = RVector::Average(RMatrix::GetColVector(m, i));
    }
    return r;
}

RVector RMatrix::StandardDeviation(RMatrix m) {
    RVector r = Variance(m);
    r = RVector::Sqrt(r);
    return r;
}

RVector RMatrix::Variance(RMatrix m) {
    int ndim = m.nCols;
    RVector r(ndim);
    RVector v(m.nRows);
    for (int i = 0; i < ndim; i++) {
        v = RMatrix::GetColVector(m, i);
        r[i] = RVector::Variance(v);
    }
    return r;
}

RMatrix RMatrix::CovarianceMatrix(RMatrix m) {
    int ndim = m.nCols;
    RMatrix r(ndim);
    RVector x(m.nRows);
    RVector y(m.nRows);
    for (int i = 0; i < ndim; i++) {
        for (int j = 0; j < ndim; j++) {
            x = RMatrix::GetColVector(m, i);
            y = RMatrix::GetColVector(m, j);
            r[i][j] = RVector::Covariance(x, y);
        }
    }
    return r;
}

RMatrix RMatrix::CorrelationMatrix(RMatrix m) {
    int ndim = m.nCols;
    RMatrix r(ndim);
    RVector x(m.nRows);
    RVector y(m.nRows);
    for (int i = 0; i < ndim; i++) {
        for (int j = 0; j < ndim; j++) {
            x = RMatrix::GetColVector(m, i);
            y = RMatrix::GetColVector(m, j);
            r[i][j] = RVector::Correlation(x, y);
        }
    }
    return r;
}

RMatrix RMatrix::MinMaxNormalization(RMatrix m) {
    RMatrix r(m.nRows, m.nCols);
    RVector min = Min(m);
    RVector max = Max(m);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            r[i][j] = (m[i][j] - min[j]) / (max[j] - min[j]);
        }
    }
    return r;
}

RMatrix RMatrix::ZeroScoreNormalization(RMatrix m) {
    RMatrix r(m.nRows, m.nCols);
    RVector average = Average(m);
    RVector std = StandardDeviation(m);
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            r[i][j] = (m[i][j] - average[j]) / std[j];
        }
    }
    return r;
}

//RMatrix RMatrix::MinMaxNormalization(RMatrix m)
//{
//	RMatrix r(m);
//	RVector v(m.nRows);
//	RVector temp(m.nRows);
//	for (int i = 0; i < m.nCols; i++)
//	{		
//		v = RMatrix::GetColVector(r, i);
//		temp = RVector::MinMaxNormalization(v);
//		r = RMatrix::ReplaceCol(r, i, temp);
//	}
//	return r;
//}
//RMatrix RMatrix::ZeroScoreNormalization(RMatrix m)
//{
//	RMatrix r(m);
//	RVector v(m.nRows);
//	RVector temp(m.nRows);
//	for (int i = 0; i < m.nCols; i++)
//	{
//		v = RMatrix::GetColVector(r, i);
//		temp = RVector::ZeroScoreNormalization(v);
//		r = RMatrix::ReplaceCol(r, i, temp);
//	}
//	return r;
//}
RMatrix RMatrix::UniformRandomMatrix(int m, int n) {
    RMatrix r(m, n);
    srand((unsigned) time(NULL));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            r[i][j] = double(rand()) / double(RAND_MAX);
        }
    }
    return r;
}

RMatrix RMatrix::ConvertToRow(RVector v) {
    int ndim = v.GetLength();
    RMatrix m(1, ndim);
    for (int i = 0; i < ndim; i++) {
        m[0][i] = v[i];
    }
    return m;
}

RMatrix RMatrix::ConvertToCol(RVector v) {
    int ndim = v.GetLength();
    RMatrix m(ndim, 1);
    for (int i = 0; i < ndim; i++) {
        m[i][0] = v[i];
    }
    return m;
}

double RMatrix::Norm(RMatrix m) {
    double r = 0;
    int nRows = m.nRows;
    int nCols = m.nCols;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            r += m[i][j] * m[i][j];
        }
    }
    r = sqrt(r);
    return r;
}