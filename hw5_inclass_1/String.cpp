#include <iostream>
using namespace std;
#include "String.h"


//private
void String::error(const char* msg) const
{
    cout << "Error: " << msg << endl;
}

bool String::in_bounds(int i) const
{
    return i >= 0 && i < ListNode::list_length(head);
}

String::String(List L) {
    ListNode::list_delete(head);
    head = L;
}

//public

String::String(const char* s) {
    head = ListNode::list_from_string(s);
}

String::String(const String& s) {
    head = ListNode::list_copy(s.head);
}

String::String(String&& s) {
    head = ListNode::list_copy(s.head);
}

String& String::operator = (String&& s) {
    ListNode::list_delete(head);
    head = ListNode::list_copy(s.head);
    return *this;
}

String& String::operator = (const String& s) {
    ListNode::list_delete(head);
    head = ListNode::list_copy(s.head);
    return *this;
}

char& String::operator [] (int index) {
    //if (!head) {
    //    error("Error: you cant index an empty string");
    //    List a = new ListNode('E', nullptr);
    //    return a->data;
    //}
    if (in_bounds(index))
        return ListNode::list_nth(head, index)->data;
    error("Error: index out of bound");
    return head->data;

}

int String::size() const {
    return ListNode::list_length(head);
}

String String::reverse() const {
    List rev = ListNode::list_reverse(head);
    String temp_rev(rev);
    return temp_rev;
}

int String::indexOf(const char c) const {
    List temp = head;
    List c_found = ListNode::list_chr(temp, c);
    if (c_found)
        return 0;
    int found = ListNode::list_difference(temp, c_found);
    return found;
}

int String::indexOf(const String& s) const {
    List haystack = head;
    List needle = s.head;
    List s_found = ListNode::list_str(haystack, needle);
    if (!s_found)
        return 0;
    int found = ListNode::list_difference(haystack, s_found);
    return found;
}

bool String::operator == (const String& s) const {
    if (ListNode::list_cmp(head, s.head) == 0)
        return true;
    else
        return false;
    //return (ListNode::list_cmp(head, s.head) == 0);
}

bool String::operator != (const String& s) const {
    return ListNode::list_cmp(head, s.head) != 0;
}

bool String::operator > (const String& s) const {
    return ListNode::list_cmp(head, s.head) > 0;
}

bool String::operator < (const String& s) const {
    return ListNode::list_cmp(head, s.head) < 0;
}

bool String::operator <= (const String& s) const {
    return ListNode::list_cmp(head, s.head) <= 0;
}

bool String::operator >= (const String& s) const {
    return ListNode::list_cmp(head, s.head) >= 0;
}

String String::operator + (const String& s) const {
    List plus = ListNode::list_append(head, s.head);
    String temp_plus(plus);
    return temp_plus;
}

String & String::operator += (const String & s) {
    // dest::
    //     a += b ; a = a + b
    //     this->head = ori_head + s.head
    //ListNode::list_delete(head);
   
    List tmp = ListNode::list_append(head, s.head);//new space
    ListNode::list_delete(head);
    head = tmp;

    return *this;
}

void String::print(ostream& out) const {
    for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
        out << temp->data;
    }
}

void String::read(istream& in) {
    char temp;
    ListNode::list_delete(head);
    while (in.get(temp) and temp == '\n') {};
    head = new ListNode(temp, nullptr);
    List res = head;

    while (in.get(temp) and temp != '\n') {
        res->next = new ListNode(temp, nullptr);
        res = res->next;
    }
}

String::~String() {
    ListNode::list_delete(head);
}

ostream& operator << (ostream& out, const String& s) {
    s.print(out);
    return out;
}

istream& operator >> (istream& in, String& s) {
    s.read(in);
    return in;
}

