#include <iostream>
using namespace std;
#include "String.h"

//Test ListNode.cpp
void test_list_from_string_and_print()
{
    cout << "TESTS: list_from_string_and_print" << endl;
    cout << endl;
    List L1 = ListNode::list_from_string("HelloHelloHello");
    List L2 = ListNode::list_from_string("WorldWorldWorld");
    List L3 = ListNode::list_from_string("");
    List L4 = ListNode::list_from_string("");
    ListNode::print(cout, L1);
    cout << endl;
    ListNode::print(cout, L2);
    cout << endl;
    cout << "|" << L3 << "|" << endl;
    cout << "|" << L4 << "|" << endl;
    cout << ListNode::list_length(L1) << endl;
    cout << ListNode::list_length(L2) << endl;
    cout << endl;
    cout << ListNode::list_length(L3) << endl;
    cout << ListNode::list_length(L4) << endl;
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    ListNode::list_delete(L3);
    ListNode::list_delete(L4);
    cout << endl;
}

void test_list_append()
{
    cout << "TESTS: list_append" << endl;
    List L1 = ListNode::list_from_string("Hellooooo");
    List L2 = ListNode::list_from_string("Worlddddddddddddddddddd!");
    List C = ListNode::list_append(L1, L2);
    List L3 = ListNode::list_from_string("");
    List L4 = ListNode::list_from_string("");
    List E = ListNode::list_append(L3, L4);
    ListNode::print(cout, C);
    cout << endl;
    ListNode::print(cout, E);
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    ListNode::list_delete(C);
    ListNode::list_delete(L3);
    ListNode::list_delete(L4);
    ListNode::list_delete(E);
    cout << endl;

}

void test_list_reverse()
{
    cout << "TESTS: test_reverse" << endl;
    List L1 = ListNode::list_from_string("Hellooooooooooooooooooo");
    List L2 = ListNode::list_from_string("Worlddddddddddddddddddddddddddddddd!");
    List C = ListNode::list_append(L1, L2);
    List R = ListNode::list_reverse(C);
    List L3 = ListNode::list_from_string("");
    List L4 = ListNode::list_from_string("");
    List C1 = ListNode::list_append(L3, L4);
    List R1 = ListNode::list_reverse(C1);
    ListNode::print(cout, R);
    cout << endl;
    ListNode::print(cout, R1);
    cout << endl;
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    ListNode::list_delete(C);
    ListNode::list_delete(R);
    ListNode::list_delete(L3);
    ListNode::list_delete(L4);
    ListNode::list_delete(C1);
    ListNode::list_delete(R1);
}

void test_list_str() {
    cout << "TESTS: test_list_str" << endl;
    List L1 = ListNode::list_from_string("Hello");
    List L2 = ListNode::list_from_string("World");
    List A = ListNode::list_append(L1, L2);
    List E = ListNode::list_from_string("");
    List E1 = ListNode::list_from_string("");
    List L3 = ListNode::list_from_string("Wor");
    List S = ListNode::list_str(A, L3);
    List S1 = ListNode::list_str(A, E);
    List E2 = ListNode::list_str(E, E1);
    ListNode::print(cout, S);
    cout << endl;
    ListNode::print(cout, S1);
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    ListNode::list_delete(A);
    ListNode::list_delete(E);
    ListNode::list_delete(E1);
    ListNode::list_delete(L3);
    cout << endl;
}

void test_list_chr() {
    cout << "TESTS: test_list_chr" << endl;
    List L1 = ListNode::list_from_string("Hiwhatareyoudoing?");
    ListNode::print(cout, L1);
    cout << endl;
    List L3 = ListNode::list_chr(L1, 3);
    if (L3) {
        cout << L3->data << endl;
    }
    else {
        cout << "null not found" << endl;
    }
    //cout << ListNode::list_chr(L1, 3)->data << endl;//nullptr X data
    cout << ListNode::list_chr(L1, 'h')->data << endl;//List->data
    List L2 = ListNode::list_from_string("");
    cout << "|" << L2 << "|" << endl;
    //cout << ListNode::list_chr(L2, 'h')->data << endl;
    List L4 = ListNode::list_chr(L2, 'h');
    if (L4) {
        cout << L4->data << endl;
    }
    else {
        cout << "null not found" << endl;
    }
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    cout << endl;

}

void test_list_nth_and_list_last() {
    cout << "TESTS: test_list_nth_and_list_last" << endl;
    List L1 = ListNode::list_from_string("Iameatingdinnernow");
    ListNode::print(cout, L1);
    cout << endl;
    cout << ListNode::list_nth(L1, 2)->data << endl;//ListNode* List -> data/ ->next
    cout << ListNode::list_nth(L1, 15)->data << endl;
    cout << ListNode::list_last(L1)->data << endl;
    List L2 = ListNode::list_from_string("");
    cout << "|" << L2 << "|" << endl;
    //cout << ListNode::list_nth(L2, 3)->data << endl;
    //cout << ListNode::list_last(L2)->data << endl;
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    cout << endl;

}

void test_list_difference() {
    cout << "TESTS: test_list_difference" << endl;
    List L1 = ListNode::list_from_string("Helloleo");
    List L2 = ListNode::list_from_string("Hello");
    ListNode::print(cout, L1);
    cout << endl;
    ListNode::print(cout, L2);
    cout << endl;
    List str = ListNode::list_str(L1, L2);
    cout << ListNode::list_difference(L1, str) << endl;
    List L3 = ListNode::list_from_string("heyyyyyyyyyyyyyyyy");
    List L4 = ListNode::list_from_string("");
    List L5 = ListNode::list_from_string("");
    ListNode::print(cout, L3);
    cout << endl;
    cout << "|" << L4 << "|" << endl;
    List str1 = ListNode::list_str(L3, L4);
    cout << ListNode::list_difference(L3, str1) << endl;
    List str2 = ListNode::list_str(L4, L5);
    cout << ListNode::list_difference(L4, str2) << endl;
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    ListNode::list_delete(L3);
    ListNode::list_delete(L4);
    ListNode::list_delete(L5);
    cout << endl;
}


void test_list_copy() {
    cout << "TESTS: list_copy" << endl;
    List L1 = ListNode::list_from_string("Olivia");
    List L2 = ListNode::list_from_string("");
    List L3 = ListNode::list_copy(L1);
    List L4 = ListNode::list_copy(L2);
    ListNode::print(cout, L1);
    cout << endl;
    cout << "|" << L2 << "|" << endl;
    ListNode::print(cout, L3);
    cout << endl;
    cout << "|" << L4 << "|" << endl;
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    ListNode::list_delete(L3);
    ListNode::list_delete(L4);
    cout << endl;
}

void test_list_cmp_and_list_ncmp() {
    cout << "TESTS: list_cmp_and_list_ncmp" << endl;
    List L1 = ListNode::list_from_string("Hello");
    List L2 = ListNode::list_from_string("World");
    List L3 = ListNode::list_copy(L1);
    List L4 = ListNode::list_from_string("");
    List L5 = ListNode::list_from_string("");
    ListNode::print(cout, L1);
    cout << endl;
    ListNode::print(cout, L2);
    cout << endl;
    ListNode::print(cout, L3);
    cout << endl;
    cout << "|" << L4 << "|" << endl;
    cout << ListNode::list_cmp(L1, L3) << endl;
    cout << ListNode::list_cmp(L2, L4) << endl;
    cout << ListNode::list_cmp(L1, L2) << endl;
    cout << ListNode::list_cmp(L4, L5) << endl;
    cout << ListNode::list_ncmp(L1, L2, 2) << endl;
    cout << ListNode::list_ncmp(L4, L2, 0) << endl;
    cout << ListNode::list_ncmp(L4, L5, 4) << endl;
    ListNode::list_delete(L1);
    ListNode::list_delete(L2);
    ListNode::list_delete(L3);
    ListNode::list_delete(L4);
    ListNode::list_delete(L5);
    cout << endl;
}
//Test String.cpp

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
    cout << "Now s2 is " << s2 << endl;
    cout << "emp_s += emp_s1: " << "|" << (emp_s += emp_s1) << "|"<< endl;
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
    //cout << "s4[4]: " << "|" << s4[4] << "|" << endl;
    //cout << "s3[2]: " << "|" << s3[2] << "|" << endl;
}

void test_input() {
    String s1;
    cout << "Enter a String for testing input: ";
    cin >> s1;
    cout << "You've entered: " << s1 << endl;
    cout << "The size of s1 is " << s1.size() << endl;
    cout << "The first index of s1 is " << "|" << s1[0] << "|" << endl;
    cout << "The last index of s1 is " << "|" << s1[s1.size() - 1] << "|" << endl;
}

int main() {
    //Tests for ListNode helper functions
    //test_list_from_string_and_print();
    //test_list_append();
    //test_list_reverse();
    //test_list_str();
    //test_list_chr();
    //test_list_nth_and_list_last();
    //test_list_difference();
    //test_list_copy();
    //test_list_cmp_and_list_ncmp();

    ////Tests for String public functions
    //test_constructors_and_print();
    //test_assignment();
    //
    //test_relationals();
    //test_reverse();
    //test_concatenate();
    //test_indexOf();
    //test_input();
    List a = ListNode::list_from_string("hello");
    List b = ListNode::list_from_string("ll");
    cout << ListNode::list_cmp(a, b) << endl;
    cout << ListNode::list_ncmp(a, b, 10) << endl;
    cout << ListNode::list_ncmp(a, b, 3) << endl;
    List d = ListNode::list_reverse(a);
    ListNode::print(cout, d);
    cout << endl;
    List c = ListNode::list_append(a, b);
    ListNode::print(cout, c);
    cout << endl;
    ListNode::print(cout, ListNode::list_str(a, b));
    ListNode::list_delete(a);
    ListNode::list_delete(b);

    //String s1("hello");
    //String s2("hell");

    //cout << (s1 > s2) << endl;
    //
    ListNode::report_allocations();
    return 0;
}

