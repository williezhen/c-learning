#include <iostream>
#include "ListNode.h"
using namespace std;

//private
int ListNode::total_allocations = 0;
int ListNode::net_allocations = 0;
int ListNode::total_bytes = 0;

//public
List ListNode::list_from_string(const char* s) {
    if (!*s) {
        return nullptr;
    }
    List tail = new ListNode(*s++, nullptr);
    List head = tail;
    while (*s != '\0') {
        List temp = new ListNode(*s++, nullptr);
        tail->next = temp;
        tail = tail->next;
    }
    return head;
}

List ListNode::list_copy(List L) {
    if (L) {
        List res = new ListNode(L->data, nullptr);
        List temp = res;
        L = L->next;
        for (; L != nullptr; L = L->next) {
            temp->next = new ListNode(L->data, L->next);
            temp = temp->next;
        }
        return res;
    }
    return nullptr;
}

List ListNode::list_reverse(List L) {
    if (!L) {
        return nullptr;
    }
    /*List rev = new ListNode(L->data, nullptr);*/
    List rev = nullptr;
    List temp = L;//->next;
    while (temp != nullptr) {
        rev = new ListNode(temp->data, rev);
        temp = temp->next;
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
        return res;
    }
    if (L2) {
        return list_copy(L2);
    }
    return nullptr;//L
}

List ListNode::list_str(List haystack, List needle) {
    int needle_len = list_length(needle);
    if(needle_len == 0){
        return haystack;
    }
    for(List p = haystack; (p = list_chr(p, needle->data)); p = p->next){
        if(list_ncmp(p, needle, needle_len) == 0){
            return p;
        }
    }
    return nullptr;
    /*List temp_hay = haystack;
    int len_n = list_length(needle);
    if (needle) {
        while (temp_hay) {
            if (list_ncmp(temp_hay, needle, len_n))
                return temp_hay;
            temp_hay = temp_hay->next;
        }
        return nullptr;
    }
    return haystack;*/
}

List ListNode::list_chr(List str, int c) {
    if (!str)
        return nullptr;
    List temp = str;
    while (temp != nullptr) {
        if (temp->data == c) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

List ListNode::list_nth(List str, int n) {
    if (!str)
        return nullptr;
    if (n <= list_length(str)) {
        List temp = str;
        int i = 0;
        for (; i < n; i++) {
            temp = temp->next;
        }
        return temp;
    }
    return nullptr;
}

void ListNode::list_delete(List L) {
    if (L) {
        ListNode* res;
        do {
            res = L;
            L = L->next;
            delete res;
        } while (L != NULL);
    }
}

void ListNode::print(ostream& out, List L) {
    for (; L != nullptr; L = L->next) {
        out << L->data;
    }
}

int ListNode::list_difference(List L1, List L2) {
    int i = 0;
    for (List temp = L1; temp != L2; temp = temp->next) {
        i++;
    }
    return i;
}

List ListNode::list_last(List L) {
    if (!L)
        return nullptr;
    List temp = L;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    return temp;
}

int ListNode::list_cmp(List L1, List L2) {
    if (!L1 && L2)
        return -(int)L2->data;
    else if (!L2 && L1)
        return (int)L1->data;
    else if (!L1 && !L2)
        return 0;
    List temp1 = L1; 
    List temp2 = L2; 
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
            continue;
        }
        else{
            return (int)temp1->data - (int)temp2->data;
        }
    }
    if (temp1 != nullptr) {
        return temp1->data;
    }
    if (temp2 != nullptr) {
        return -(int)temp2->data;
    }
    return 0;

}

int ListNode::list_ncmp(List L1, List L2, int n) {
    if (!L1 && L2)
        return -(int)L2->data;
    else if (!L2 && L1)
        return (int)L1->data;
    else if (!L1 && !L2)
        return 0;
    List temp1 = L1;
    List temp2 = L2;
    int i = 0;
    while (temp1 != nullptr && temp2 != nullptr && i < n) {
        if (temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
            i++;
            continue;
        }
        else{
            return (int)temp1->data - (int)temp2->data;
        }
    }
    if (i == n) {
        return 0;
    }
    else if (temp1 != nullptr) {
        return temp1->data;
    }
    else if (temp2 != nullptr) {
        return -(int)temp2->data;
    }
    return 0;
}

int ListNode::list_length(List L) {
    int count = 0;
    for (List temp = L; L != nullptr; L = L->next) {
        count++;
    }
    return count;
}

