#include <iomanip>
using namespace std;
#include <string>
template
<typename T>
class Array
{
    int len;
    T* buf;

    bool in_bounds(int i) const {
        return (i >= 0 && i < len);
    }

public:
    Array() : len(0), buf(nullptr) {};

    Array(int new_len)
        : len(new_len), buf(new T[len])
    {
        fill(T());

    }

    int length()
    {
        return len;
    }

    T& operator [](int index)
    {
        if (in_bounds(index))
            return buf[index];

        else {
            string msg = "Exception operator[]" + to_string(len) + "Out Of Range";
            throw msg;
        }
    }

    Array(const Array& a) : len(a.len), buf(new T[a.len]) {
        for (int i = 0; i < len; i++)
            buf[i] = a.buf[i];
    }

    Array& operator = (Array& a) = delete;

    void fill(T val)
    {
        for (int i = 0; i < len; ++i)
            buf[i] = val;
    }

    void print(ostream& out) const
    {
        for (int i = 0; i < len; ++i) {
            out << setw(8)
                << setprecision(2)
                << fixed
                << right
                << buf[i];
        }
    }

    friend ostream& operator << (ostream& out, const Array& a)
    {
        a.print(out);
        return out;
    }

    ~Array() {
        delete[] buf;
    }
};

