#include "String.h"

using namespace std;

void String::error(const char* msg) const {
	cout << "ERROR: " << msg << endl;
}

void String::print(std::ostream& out) const {
	//int c = 0;
	for (ListNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
		out << tmp->data;
		//c++;
	}
}

void String::read(std::istream& in) {
	char tmp;
	ListNode::list_delete(head);
	while (in.get(tmp) and tmp == '\n') {};
	head = new ListNode(tmp, nullptr);
	List res_list = head;
	while (in.get(tmp) and tmp != '\n') {
		res_list->next = new ListNode(tmp, nullptr);
		res_list = res_list->next;
	}
}

String::String(const char* s) {
	head = ListNode::list_from_string(s);
}

String::String(const String& s) {
	head = ListNode::list_copy(s.head);
}

String::String(String&& s) {
	head = ListNode::list_copy(s.head);
}

String::String(List L) {
	head = L;
}

String String::reverse() const {
	List rev = ListNode::list_reverse(head);
	String tmp_rev(rev);
	return tmp_rev;
}

String String::operator + (const String& s) {
	List plus = ListNode::list_append(this->head, s.head);
	String tmp_plus(plus);
	return tmp_plus;
}

String& String::operator = (String&& s) {
	ListNode::list_delete(head);
	head = ListNode::list_copy(s.head);
	return *this;
}//s1 = s2;
String& String::operator = (const String& s) {
	ListNode::list_delete(head);
	head = ListNode::list_copy(s.head);
	return *this;
}

int String::indexOf(const String& s) const {
	List haystack = head;
	List needle = s.head;
	List List_found = ListNode::list_str(haystack, needle);
	int res = ListNode::list_difference(haystack, List_found);
	return res;
};

char& String::operator [] (int index) {
	//in_bound
	List tmp = head;
	while (index--) {//0 null nullptr //index fori<=index
		tmp = tmp->next;
	}
	return tmp->data;
	//return //ListNode::list_nth(head, index);
}