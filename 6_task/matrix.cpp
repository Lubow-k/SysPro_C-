#include "matrix.hpp"

void Matrix::alloc_matrix() {
    data = new double*[len];
    for (int i = 0; i < len; ++i) {
        data[i] = new double[len];
    }
}

void Matrix::fill_zero() {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            data[i][j] = 0;
        }
    }
}

std::vector<double> Matrix::diagonal(int len, double num) {
    std::vector<double> d;
    for (int i = 0; i < len; ++i) d.push_back(num);
    return d;
}

Matrix::Matrix(int len) : len(len) {
    alloc_matrix();
    fill_zero();
}

Matrix::Matrix(std::vector<double> v) : len(v.size()) {
    alloc_matrix();
    fill_zero();
    for (int i = 0; i < len; ++i) {
        data[i][i] = v[i];
    }
}

Matrix::Matrix(const Matrix& other): len(other.len) {
    alloc_matrix();
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix::Matrix(Matrix&& other): len(other.len) {
    data = other.data;
    other.data = nullptr;
}

Matrix& Matrix::operator=(Matrix other) { 
    std::swap(len, other.len);
    std::swap(data, other.data);
    return *this;
}

Matrix::~Matrix() {
    for (int i = 0; i < len; ++i) {
        delete[] data[i];
    }
    delete[] data;
}


Matrix::operator double() const {
    double res = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            res += data[i][j];
        }
    }
    return res;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator+=(double num) {
    Matrix buf(diagonal(len, num));
    return (*this += buf);
}

Matrix& Matrix::operator*=(const Matrix& other) {
    Matrix buf(len);
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            for (int k = 0; k < len; ++k) {
                buf.data[i][j] += (data[i][k] * other.data[k][j]);
            }
        }
    }
    return (*this = buf);
}

Matrix& Matrix::operator*=(double num) {
    Matrix buf(diagonal(len, num));
    return (*this *= buf);
}


// FRIENDS 

Matrix operator+(const Matrix& m1, const Matrix& m2) {
    Matrix temp(m1);
    return (temp += m2);
}

Matrix operator+(const Matrix& m, double num) {
    Matrix temp(m);
    return (temp += num);
}

Matrix operator*(const Matrix& m1, const Matrix& m2) {
    Matrix temp(m1);
    return (temp *= m2);
}

Matrix operator*(const Matrix& m, double num) {
    Matrix temp(m);
    return (temp *= num);
}

Matrix operator*(double num, const Matrix& m) {
    return m * num; 
}

bool operator==(const Matrix& m1, const Matrix& m2) {
    if (m1.len != m2.len) return false;
    for (int i = 0; i < m1.len; ++i) {
        for (int j = 0; j < m1.len; ++j) {
            if (m1.data[i][j] != m2.data[i][j]) return false;
        }
    }
    return true;
}


bool operator!=(const Matrix& m1, const Matrix& m2) {
    return !(m1 == m2);
}


std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (int i = 0; i < m.len; ++i) {
        for (int j = 0; j < m.len; ++j) {
            os << m.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
