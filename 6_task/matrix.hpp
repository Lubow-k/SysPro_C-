#include <iostream>
#include <vector>

class Matrix {
    int len;
    double** data;

    void alloc_matrix();
    void fill_zero();
    std::vector<double> diagonal(int, double);

    public:
        Matrix(int);
        Matrix();
        Matrix(std::vector<double>);
        Matrix(const Matrix&);
        Matrix(Matrix&&);
        Matrix& operator=(Matrix other);
        ~Matrix();

        explicit operator double() const;
        Matrix& operator+=(const Matrix&);
        Matrix& operator+=(double);
        Matrix& operator*=(const Matrix&);
        Matrix& operator*=(double);

        friend Matrix operator+(const Matrix&, const Matrix&);
        friend Matrix operator+(const Matrix&, double);
        friend Matrix operator*(const Matrix&, const Matrix&);
        friend Matrix operator*(const Matrix&, double);
        friend bool operator==(const Matrix&, const Matrix&);
        friend bool operator!=(const Matrix&, const Matrix&);
        friend std::ostream& operator<<(std::ostream&, const Matrix&);
};