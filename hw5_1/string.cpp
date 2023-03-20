#include "String.h"

using namespace std;

void String::error(const char* msg) const {
	cout << "ERROR: " << msg << endl;
}

//bool String::in_bounds(int i) const {
//	return i >= 0 && i < ListNode::list_length(head);
//}
void String::print(std::ostream& out) const{
	List tmp = head;
	while (tmp != nullptr) {
		out << tmp->data;
		tmp = tmp->next;
	}
}

String::String(const char* s) {
	head = ListNode::list_from_string(s);
};

String::String(const String& s) {
	head = ListNode::list_copy(s.head);
};

String::String(String&& s) {
	head = ListNode::list_copy(s.head);
};

String::String(List L) {
	head = L;
};

String String::reverse() const {
	List rev = ListNode::list_reverse(head);
	String tmp_cpy(rev);
	return tmp_cpy;
};

String String::operator + (const String& s) {
	List plus = ListNode::list_append(this->head, s.head);
	String tmp_plus(plus);
	return tmp_plus;
};

String& String::operator = (String&& s) {
	ListNode::list_delete(head);
	head = ListNode::list_copy(s.head);
	return *this;
};
String& String::operator = (const String& s) {
	ListNode::list_delete(head);
	head = ListNode::list_copy(s.head);
	return *this;
};

int String::indexOf(const String& s) const {
	List haystack = this->head;
	List needle = s.head;
	int res = 0;
	if (needle) {
		while (haystack) {
			for (List tmp1 = haystack, tmp2 = needle;
				tmp1->data == tmp2->data;
				tmp1 = tmp1->next, tmp2 = tmp2->next) {
				if (!tmp2->next) {
					return res;
				}
			}
			res += 1;
			haystack = haystack->next;
		}
	}
	else {
		return -1;
	}
};