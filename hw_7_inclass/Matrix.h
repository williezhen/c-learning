#pragma once
#include "Array.h"

using namespace std;

template<typename T>
class Matrix {
    int rows, cols;
    Array<Array<T>*> matrix;

public:
    Matrix(int new_rows, int new_cols) : rows(new_rows), cols(new_cols), matrix(rows) {
        for (int i = 0; i < rows; i++) {
            matrix[i] = new Array<T>(cols);
            matrix[i]->fill(T());
        }
    }

    Matrix(Matrix& a) : rows(a.rows), cols(a.cols), matrix(rows) {
        for (int i = 0; i < rows; i++) {
            matrix[i] = new Array<T>(*(a.matrix[i]));
            /*matrix[i] = new Array<T>(cols);
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = a.matrix[i][j];
            }*/
        }
    }

    //Matrix& operator=(Matrix& a) {
    //    if (this == &a) {
    //        return *this;
    //    }

    //    if (rows != a.rows || cols != a.cols) {
    //        for (int i = 0; i < rows; i++) {
    //            delete matrix[i];
    //        }
    //        matrix = Array<Array<T>*>(a.rows);
    //        for (int i = 0; i < a.rows; i++) {
    //            matrix[i] = new Array<T>(a.cols);
    //        }
    //        rows = a.rows;
    //        cols = a.cols;
    //    }

    //    for (int i = 0; i < rows; i++) {
    //        for (int j = 0; j < cols; j++) {
    //            (*matrix[i])[j] = (*a.matrix[i])[j];
    //        }
    //    }

    //    return *this;
    //}

    int num_rows() const {
        return rows;
    }

    int num_cols() const {
        return cols;
    }

    Array<T> & operator[](int row) {
        return *matrix[row];
    }

    const Array<T>*& operator[](int row) const {
        return matrix[row];
    }

    void fill(T val) {
        for (int i = 0; i < rows; i++) {
            matrix[i]->fill(val);
        }
    }

    void print(ostream& out) {
        for (int i = 0; i < rows; i++) {
            out << *matrix[i] << endl;
        }
    }

    friend ostream& operator<<(ostream& out, Matrix& m) {
        out << m.num_rows() << " x " << m.num_cols() << endl;
        m.print(out);
        return out;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete matrix[i];
        }
    }
};
