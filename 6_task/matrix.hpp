#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
    int len;
    double** data;

    void alloc_matrix();
    void fill_zero();
    static std::vector<double> diagonal(int, double);

    class Row {
        const Matrix& matrix;
        size_t row;
        public:
            Row(Matrix& matrix, size_t row): matrix(matrix), row(row) {}
            double& operator[](size_t col) { 
                if ((0 <= row) && (row < matrix.len) && (0 <= col) && (col < matrix.len))
                    return matrix.data[row][col]; 
                else {
                    std::string message = "Row: " + std::to_string(row) + ", col: " + std::to_string(row) +
                                          ", matrix len: " + std::to_string(matrix.len);
                    throw std::out_of_range(message);
                }
            }
    };

    public:
        Matrix(int);
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
        friend Matrix operator*(double, const Matrix&);
        friend bool operator==(const Matrix&, const Matrix&);
        friend bool operator!=(const Matrix&, const Matrix&);
        friend std::ostream& operator<<(std::ostream&, const Matrix&);
};