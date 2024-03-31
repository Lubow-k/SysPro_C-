#include <iostream>
#include <vector>

class Matrix {
    int len;
    double** data;

    void alloc_matrix();
    void fill_zero();
    std::vector<double> diagonal(int, double);

    class Row {
        const Matrix& matrix;
        size_t row;
        public:
            Row(Matrix& matrix, size_t row): matrix(matrix), row(row) {}
            double& operator[](size_t col) { return matrix.data[row][col]; }
    };

    public:
        Matrix(int);
        Matrix();
        Matrix(std::vector<double>);
        Matrix(const Matrix&);
        Matrix(Matrix&&);
        Matrix& operator=(Matrix other);
        ~Matrix();

        explicit operator double() const;
        Row operator[](size_t row) { return Row(*this, row); }
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