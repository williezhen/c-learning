#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Shape.h"
#ifndef PICTURE_H
#define PICTURE_H

class Picture
{
    struct ListNode
    {
        Shape* data;
        ListNode* next;

        ListNode(Shape* new_data, ListNode* new_next) : data(new_data), next(new_next) {};

        ~ListNode() {
            if (data) {
                delete data;
            }
            
        }


    };

    ListNode* head;
    ListNode* tail;

public:

    Picture() {
        head = nullptr;
    };
    //(){} ListNode* ptr; !=nullptr => random address
    //nullptr -> 00000000
    //if(ptr) -> false
    //if(nullptr) -> false
    //nullptr


    void add(Shape* sp) {
        if (head) {
            ListNode * newNode = new ListNode(sp, nullptr);
            cout << "NewNode: " << newNode << endl;
            cout << "sp: " << sp << endl;
            tail->next = newNode;
            tail = tail->next;
        }else {
            head = new ListNode(sp, nullptr);
            tail = head;
            cout << "sp: " << sp << endl;
        }
    }

    double total_area() {
        double total_area = 0;
        for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
            total_area += temp->data->area();
        }
        return total_area;

    }

    void draw_all() {
        for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
            temp->data->draw();
        }

    }

    void print_all() {
        for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
            temp->data->print();
        }

    }

    void delete_pic() {
        for (ListNode* tmp = head; ; tmp = tmp->next) {
            if (tmp->next == tail){
                delete tail;
                tail = tmp;
                tail->next = nullptr;
                break;
            }
        }
    }



    ~Picture() {
        //for (ListNode* temp = head; temp and temp->data; temp = temp->next) {
        //    cout << "data: " << temp->data << endl;
        //    delete temp->data;
        //}
        while (head->next) {
            delete_pic();
        }
        delete head;
    }

};
#endif

