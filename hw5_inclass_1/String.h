#include <iostream>
#include "ListNode.h"

class String
{
public:

    explicit String(const char* s = "");

    String(const String& s);

    String(String&& s);

    String& operator = (String&& s);

    String& operator = (const String& s);

    char& operator [] (int index);

    int size() const;

    String reverse() const;

    int indexOf(const char c) const;

    int indexOf(const String& s) const;

    bool operator == (const String& s) const;

    bool operator != (const String& s) const;

    bool operator > (const String& s) const;

    bool operator < (const String& s) const;

    bool operator <= (const String& s) const;

    bool operator >= (const String& s) const;

    String operator + (const String& s) const;

    String& operator += (const String& s);

    void print(ostream& out) const;

    void read(istream& in);

    ~String();

private:

    String(List L);

    bool in_bounds(int i) const;

    void error(const char* msg) const;

    List head;

};

ostream& operator << (ostream& out, const String& s);
istream& operator >> (istream& in, String& s);

