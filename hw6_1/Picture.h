#pragma once
#include "Shape.h"

using namespace std;

class Picture {
	struct ListNode {
		Shape* data;
		ListNode* next;

		ListNode(Shape* new_data, ListNode* new_next) {
			data = new_data;
			next = new_next;
		};
	};

	ListNode* head;

public:

	Picture() {};

	void add(Shape* sp) {
		ListNode* newNode = new ListNode(sp, nullptr);
		if (head) {
			ListNode* tmp = head;
			while (tmp->next) {
				tmp = tmp->next;
			};
			tmp->next = newNode;
		}
		else {
			head = newNode;
		}
	};

	double total_area() {
		ListNode* tmp = head;
		double res = 0;
		while (tmp) {
			res += tmp->data->area();
			tmp = tmp->next;
		};
		return res;
	};

	void draw_all() {
		ListNode * tmp = head;
		while (tmp) {
			tmp->data->draw();
			tmp = tmp->next;
		}
	};

	void print_all() {
		ListNode* tmp = head;
		while (tmp) {
			tmp->data->print();
			tmp = tmp->next;
		}
	};

	~Picture() {
		if (head) {
			delete head;
		}
	};
};