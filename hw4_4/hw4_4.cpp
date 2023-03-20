#include <iostream>
#include "String.h"
#include "Alloc.h"

using namespace std;


void test_constructors_and_print() {
    cout << "Constructor and operator << TESTS" << endl;
    String s("Hello World");
    String emp_s("");
    String s1(s);
    String emp_s1(emp_s);
    cout << "s: " << "|" << s << "|" << endl;
    //test empty string
    cout << "emp_s: " << "|" << emp_s << "|" << endl;
    //test copy
    cout << "The copy of s is s1: " << "|" << s1 << "|" << endl;
    cout << "The copy of emp_s is emp_s1: " << "|" << emp_s1 << "|" << endl;
    //test move constructor &&
    cout << "Test (String && s)" << endl;
    String foo("");
    String bar(move(foo));
    cout << "foo: " << "|" << foo << "|" << endl;
    cout << "bar: " << "|" << bar << "|" << endl;
    cout << "bar(move(foo)): " << "|" << bar << "|" << endl;
}

void test_assignment() {
    cout << "Assignment TESTS" << endl;
    //test normal equal cases.
    cout << "Test normal assignment cases" << endl;
    String s1("Olivia");
    String s2(s1);
    cout << "Is s1 = s2?" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s1 = s2: " << "|" << (s1 = s2) << "|" << endl;
    String emp_s("");
    String emp_s1(emp_s);
    cout << "Is emp_s = emp_s1?" << endl;
    cout << "emp_s: " << "|" << emp_s << "|" << endl;
    cout << "emp_s1: " << "|" << emp_s1 << "|" << endl;
    cout << "emp_s = emp_s1: " << "|" << (emp_s = emp_s1) << "|" << endl;

    cout << "Test empty assignment cases." << endl;
    String foo("");
    String bar("");
    cout << "foo: " << "|" << foo << "|" << endl;
    cout << "bar: " << "|" << bar << "|" << endl;
    cout << "bar = foo: " << "|" << (bar = foo) << "|" << endl;
}

void test_relationals() {
    cout << "Relational TESTS" << endl;
    String s1("Bob");
    String s2("Leo");
    String s3("Steven");
    String s4("Kate");
    String s5(s1);
    String s6("");
    //test <
    cout << "Test <" << endl;
    cout << "Bob should be less than Steven and return 1." << endl;
    cout << "<: " << (s1 < s3) << endl;
    //test >
    cout << "Test >" << endl;
    cout << "Bob should not be greater than Steven and return 0." << endl;
    cout << ">: " << (s1 > s3) << endl;
    // test ==
    cout << "Test ==" << endl;
    cout << "Bob should be equal to Bob and return 1." << endl;
    cout << "==: " << (s1 == s5) << endl;
    //test <=
    cout << "Test <=" << endl;
    cout << "Bob should be less than or equal to Bob and return 1." << endl;
    cout << "<=: " << (s1 <= s5) << endl;
    //test >=
    cout << "Test >=" << endl;
    cout << "Kate should not be greater than or equal to Leo and return 0." << endl;
    cout << ">=: " << (s4 >= s2) << endl;
    //test !=
    cout << "Test !=" << endl;
    cout << "Bob should not be equal to Bob and return 0." << endl;
    cout << "!=: " << (s5 != s1) << endl;
    //test empty cases
    cout << "Test empty cases" << endl;
    cout << "|s6| should be less than Leo and return 1." << endl;
    cout << "Empty cases <: " << (s6 < s2) << endl;
    cout << "s5 should not be equal to s6 and return 1." << endl;
    cout << "Empty cases !=: " << (s5 != s6) << endl;
}

void test_reverse() {
    cout << "Reverse TESTS" << endl;
    String s1("kayak");
    String s2("eva can i see bees in a cave");
    cout << "Test |kayak| reverse" << endl;
    cout << "The reverse of |kayak| is " << "|" << s1.reverse() << "|" << endl;
    cout << "Test |Eva can I see bees in a cave| reverse" << endl;
    cout << "The reverse of |eva can i see bees in a cave| is " << "|" << s2.reverse() << "|" << endl;
    cout << "Test reverse empty cases" << endl;
    String s3("");
    String s4(s3);
    cout << "s3: |" << s3 << "|; " << "s4: |" << s4 << "|" << endl;
    cout << "The reverse of s3 is " << "|" << s3.reverse() << "|" << endl;
    cout << "The reverse of s4 is " << "|" << s4.reverse() << "|" << endl;
    String s5("AAAAAAAAAAAA AAAAAAAAAAAAA");
    String s6("AAAABBBBCCCDD BAAAAAADDDDEEE");
    String s7("AAAACCCCCCCCCCCCCCCCC CAAAAAAAAAAAAAAAAAAAAAAAAAAA");
    cout << "s5: " << s5 << " ->12 A's first half, 13 A's second half." << endl;
    cout << "s6: " << s6 << " ->13 letters first half, 14 letters second half." << endl;
    cout << "s7: " << s7 << endl;
    cout << "s5 reverse: " << s5.reverse() << endl;
    cout << "s6 reverse: " << s6.reverse() << endl;
    cout << "s7 reverse: " << s7.reverse() << endl;
}

void test_concatenate() {
    cout << "Concatenate TESTS" << endl;
    String s1("AAAAAAAAABAAAA");
    String s2("CAAAAAAAAABAAAAC");
    //test +

    cout << "Test +" << endl;
    cout << "s1: " << s1 << ";" << "s2: " << s2 << endl;
    cout << "s1 + s2 should be AAAAAAAAABAAAACAAAAAAAAABAAAAC" << endl;
    cout << "s1 + s2: " << (s1 + s2) << endl;
    cout << "Now s1 is " << s1 << endl;
    cout << "Now s2 is " << s2 << endl;
    String emp_s("");
    String emp_s1("");
    cout << "emp_s: " << "|" << emp_s << "|" << endl;
    cout << "emp_s1: " << "|" << emp_s1 << "|" << endl;
    cout << "emp_s + emp_s1: " << (emp_s + emp_s1) << endl;
    cout << "Now emp_s is " << "|" << emp_s << "|" << endl;
    cout << "Now emp_s1 is " << "|" << emp_s1 << "|" << endl;
    //test +=
    cout << "Test +=" << endl;
    cout << "s1: " << s1 << "; " << "s2: " << s2 << endl;
    cout << "s1 += s2: " << (s1 += s2) << endl;
    cout << "Now s1 is " << s1 << endl;
    cout << "emp_s += emp_s1: " << "|" << (emp_s += emp_s1) << "|" << endl;
    cout << "Now emp_s is " << "|" << emp_s << "|" << endl;
    cout << "Now emp_s1 is " << "|" << emp_s1 << "|" << endl;
}

void test_indexOf() {
    cout << "indexOf TESTS" << endl;
    String s1("mymacbookpro");
    String s2("mac");
    String s3("");
    String s4("abc");
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: ||" << s3 << endl;
    cout << "s4: " << s4 << endl;
    //test indexOf(String)
    cout << "Test indexOf(String)" << endl;
    cout << "s1.indexOf(s2): " << s1.indexOf(s2) << endl;
    cout << "s3.indexOf(s4): " << s3.indexOf(s4) << endl;
    cout << "s4.indexOf(s3): " << s4.indexOf(s3) << endl;
    //test indexOf(char)
    cout << "Test indexOf(char)" << endl;
    cout << "s1.indexOf('b') should be 5." << endl;
    cout << "s1.indexOf('b'): " << s1.indexOf('b') << endl;
    cout << "s1.indexOf('d'): " << s1.indexOf('d') << endl;
    //test "[] & size()"
    cout << "Test [] & size()" << endl;
    cout << "s2[0]: " << s2[0] << endl;
    cout << "s1[s1.size() - 1]: " << s1[s1.size() - 1] << endl;
    cout << "s4[4]: " << "|" << s4[4] << "|" << endl;
    cout << "s3[2]: " << "|" << s3[2] << "|" << endl;
}

void test_input() {
    String s1;
    cout << "Enter a String for testing input (should be less than char[1024]: ";
    cin >> s1;
    cout << "You've entered: " << s1 << endl;
    cout << "The size of s1 is " << s1.size() << endl;
    cout << "The first index of s1 is " << "|" << s1[0] << "|" << endl;
    cout << "The last index of s1 is " << "|" << s1[s1.size() - 1] << "|" << endl;
}

int main() {
    test_constructors_and_print();
    test_assignment();
    test_relationals();
    test_reverse();
    test_concatenate();
    test_indexOf();
    test_input();
    Alloc::report_allocations();
    return 0;
}

