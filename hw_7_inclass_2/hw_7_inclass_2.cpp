#include <iostream>
using namespace std;

#include "Matrix.h"

template
<typename FN, typename T>
void fill_with_fn(Array<T>& a, FN fn)
{
    for (int i = 0; i < a.length(); ++i)
        a[i] = fn(i);
}


void test_int_array()
{
    Array<int> a{ 10 };
    auto fn = [](int i) {return i + 1; };
    a.fill(int());
    cout << a << endl;
    fill_with_fn(a, fn);
    cout << a << endl;
    cout << endl;
}

template
<typename FN, typename T>
void fill_with_fn(Matrix<T>& m, FN fn)
{
    for (int i = 0; i < m.num_rows(); i++) {
        for (int j = 0; j < m.num_cols(); j++) {
            m[i][j] = fn(i, j);
        }
    }
}
void test_int_matrix()
{
    Matrix<int> m{ 10, 10 };
    auto fn = [](int r, int c) {return ((r + 1) + (c + 1)); };
    m.fill(int());
    cout << m << endl;
    fill_with_fn(m, fn);
    cout << m << endl;
    cout << endl;
}

void test_double_array()
{
    Array<double> a{ 10 };
    auto fn = [](int i) {return i + 1.1; };
    a.fill(double());
    cout << a << endl;
    fill_with_fn(a, fn);
    cout << a << endl;
    cout << endl;
}

void test_double_matrix()
{
    Matrix<double> m{ 10, 10 };
    auto fn = [](int r, int c) {return ((r + 1.0) + (c + 1.0) / 100.0); };
    m.fill(double());
    cout << m << endl;
    fill_with_fn(m, fn);
    cout << m << endl;
    cout << endl;
}

void test_char_array()
{
    Array<char> a{ 26 };
    auto fn = [](char i) {return i + 65; };
    a.fill(char());
    cout << a << endl;
    fill_with_fn(a, fn);
    cout << a << endl;
    cout << endl;
}

void test_char_matrix()
{
    Matrix<char> m{ 26, 26 };
    auto fn = [](char r, char c) {return ((r + 65) + (c + 65)); };
    m.fill(char());
    cout << m << endl;
    fill_with_fn(m, fn);
    cout << m << endl;
    cout << endl;
}


void test_exceptions()
{
    try {
        //generate the exception in array
        Array<int> a{ 10 };
        a.fill(int());
        a[11];
    }

    catch (std::string& e)
    {
        cout << e << endl;
    }

    try {
        //generate the exception in matrix with rows

    }

    catch (std::string& e)
    {
        cout << e << endl;
    }

    try {
        //generate the exception in matrix with cols

    }

    catch (std::string& e)
    {
        cout << e << endl;
    }
}


/*
void test_extras()
{
    Matrix<int> m{10, 10};
    Matrix<int> n{m};
    Array<int> a{10};
    cout << &a << endl; //operator <<() for pointer to Array.
}
*/

#define N 1
int main()
{
    for (int i = 1; i <= N; ++i)
    {
        test_int_array();

        test_int_matrix();
        test_double_array();
        //test_double_matrix();
        test_char_array();
        //test_char_matrix();
        //test_exceptions();
        //test_extras();

    }
}

