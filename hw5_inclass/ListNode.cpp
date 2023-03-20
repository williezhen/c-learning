#include "ListNode.h"

using namespace std;

int ListNode::total_allocations = 0;
int ListNode::net_allocations = 0;
int ListNode::total_bytes = 0;

List ListNode::list_from_string(const char* s) {//s = ""
	ListNode* tail = new ListNode(*s++, nullptr);//& -- address // * -- value
	//new head data next
	ListNode* head = tail;

	while (*s) {
		ListNode * tmp = new ListNode(*s++, nullptr);
		tail->next = tmp;
		tail = tail->next;
	}

	return head;
}

void ListNode::list_delete(List L) {
	ListNode* ret;
	//while(bool){}
	//L.ret
	do {
		ret = L;
		L = L->next;
		delete ret;

	} while (L != NULL);

}

List ListNode::list_copy(List L) {
	if (L) {
		List res = new ListNode(L->data, nullptr);//L->next;
		List tmp = res;
		L = L->next;
		for (; L != nullptr; L = L->next) {
			tmp->next = new ListNode(L->data, L->next);
			tmp = tmp->next;
		}
		return res;
	}
	return nullptr;//L
}

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
		List res = new ListNode(L1->data, nullptr);//L->next;
		List tmp = res;
		L1 = L1->next;
		for (; L1 != nullptr; L1 = L1->next) {
			tmp->next = new ListNode(L1->data, L1->next);
			tmp = tmp->next;
		}
		for (; L2 != nullptr; L2 = L2->next) {
			tmp->next = new ListNode(L2->data, L2->next);
			tmp = tmp->next;
		}
		//for(first:once//pass;seconde:every beginning;third:every ending)
		return res;
	}
	return nullptr;//L
}

List ListNode::list_str(List haystack, List needle) {
	//List tmp = haystack;
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
}

int ListNode::list_difference(List L1, List L2) {
	int c = 0;
	for (List tmp = L1; tmp != L2; tmp = tmp->next) {
		c++;
		continue;
	}
	return c;
}