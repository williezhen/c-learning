#include "ListNode.h"


using namespace std;

int ListNode::total_allocations = 0;
int ListNode::net_allocations = 0;
int ListNode::total_bytes = 0;


List ListNode::list_from_string(const char* s) {
	List head = new ListNode(*s++, nullptr);
	List res = head;
	while (*s) {
		List tmp = new ListNode(*s++, nullptr);
		head->next = tmp;
		head = head->next;
	}

	return res;
};

void ListNode::list_delete(List L) {
	List ret;
	do
	{
		ret = L;
		L = L->next;
		delete ret;
	} while (L != NULL);

};

List ListNode::list_copy(List L) {
	//List tmp = new ListNode(L->data, L->next);
	//return tmp;
	if (L) {
		List res = new ListNode(L->data, L->next);
		List tmp = res;
		L = L->next;
		for (; L != nullptr; L = L->next) {
			tmp->next = new ListNode(L->data, L->next);
			tmp = tmp->next;
		}
		return res;
	}
	return nullptr;
};

List ListNode::list_reverse(List L) {
	List rev = new ListNode(L->data, nullptr);
	List tmp = L->next;
	while (tmp != nullptr) {
		rev = new ListNode(tmp->data, rev);
		tmp = tmp->next;
	}
	return rev;
}

List ListNode::list_append(List L1, List L2) {
	if (L1) {
		List res = new ListNode(L1->data, nullptr);
		List tmp = res;
		L1 = L1->next;
		for (; L1 != nullptr; L1 = L1->next) {
			tmp->next = new ListNode(L1->data, nullptr);
			tmp = tmp->next;
			//cout << tmp->data;
		}
		for (; L2 != nullptr; L2 = L2->next) {
			tmp->next = new ListNode(L2->data, nullptr);
			//cout << tmp->data;
			tmp = tmp->next;
		}
		//for (List test = res; test != nullptr; test = test->next)
		//	cout << test->data << endl;
		return res;
	}
	return nullptr;
	
};

List ListNode::list_str(List haystack, List needle) {
	if (needle) {
		while (haystack) {
			for (List tmp1 = haystack, tmp2 = needle;
				tmp1->data == tmp2->data;
				tmp1 = tmp1->next, tmp2 = tmp2->next) {
				if (!tmp2->next) {
					return haystack;
				}
			}
			haystack = haystack->next;
		}
	}
	else {
		return haystack;
	}
};
