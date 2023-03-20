#pragma once
#include "Shape.h"

using namespace std;

class Picture {
	//SHAPE -> SHAPE -> SHAPE -> NULL
	//new Circle
	struct ListNode {
		Shape* data;
		ListNode* next;

		ListNode(Shape* new_data, ListNode* new_next) :data(new_data), next(new_next) {};

	};

	ListNode* head; //NODE null
	//new -> not null
	//head->next -> ListNode->next -> List-> NEW LIstNode->data -> nullptr
	//head.data = circle -> next nullptr

	//for(List tmp = head; tmp!=nullptr; tmp=tmp->next){



public:
	Picture() {};

	void add(Shape* sp) {
		//head.data = sp
		//*
		//1. delca -> ptr
		//2. È¡Öµ
		ListNode* tail = new ListNode(sp, nullptr);

		if (head) {
			//for(begin; end; loop_end)
			ListNode* tmp;
			for (tmp = head; tmp->next != nullptr; tmp = tmp->next) {}
			tmp->next = tail;
		}
		else {
			head = tail;
		}


		//old tail = newLISTNode
		// new tail =  nullptr
		//data = sp
		//this -> picture -> head
		//ListNode->data/next
	};

	double total_area() {
		//1.new
		//2.±éÀú
		//3.add new node
		double res = 0;
		for (ListNode* tmp = head; tmp; tmp = tmp->next) {
			//area()
			res += tmp->data->area();
		}
		return res;

		//func(this)
		// if this == null
		//	return 0
		//return this->area+func(this->next)
	};

	void draw_all() {
		for (ListNode* tmp = head; tmp; tmp = tmp->next) {
			tmp->data->draw();
		}
	};

	void print_all() {};

	~Picture() {
		delete head;
	};
};