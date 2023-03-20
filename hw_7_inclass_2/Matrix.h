using namespace std;
#include "Array.h"

template
<typename T>
class Matrix
{
    int rows, cols;
    Array<Array<T>*> matrix;

    bool in_bounds(int i) const {
        return (i >= 0 && i < rows);
    }

public:

    Matrix(int new_rows, int new_cols) : rows(new_rows), cols(new_cols), matrix(rows) {
        for (int i = 0; i < rows; i++)
            matrix[i] = new Array<T>(cols);
    }

    Matrix(const Matrix& a) : rows(a.rows), cols(a.cols), matrix(rows) {
        for (int i = 0; i < rows; i++) {
            matrix[i] = new Array<T>(cols);
            for (int j = 0; j < cols; j++) {
                *(matrix[i])[j] = *(a.matrix[i])[j];
            }
        }
    }

    //Matrix & operator = (Matrix & a) = delete;

    int num_rows()
    {
        return rows;
    }

    int num_cols()
    {
        return cols;
    }

    void fill(T val)
    {
        for (int i = 0; i < rows; i++) {
            matrix[i]->fill(val);
            /*     for (int j = 0; j < cols; j++) {
                     matrix[i][j] = val;
                 }*/
        }
    }

    Array<T>*& operator [](int row)
    {
        if (in_bounds(row))
            return matrix[row];

        else {
            string msg = "Exception operator[]" + to_string(num_rows()) + "Out Of Range";
            throw msg;
        }
    }

    void print(ostream& out)
    {
        for (int i = 0; i < rows; i++)
            out << matrix[i] << endl;
    }

    friend ostream& operator << (ostream& out, Matrix& m)
    {
        out << m.num_rows();
        return out;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete matrix[i];
    }

};

