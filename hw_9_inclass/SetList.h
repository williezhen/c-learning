//#pragma once
//template <typename T>
//class SetList {
//	struct ListNode {
//		T data;
//		ListNode* next;
//	};
//	ListNode* head;
//public:
//	class iterator {
//		ListNode* current;
//	public:
//		using iterator_category = ? ? ? ;
//		using value_type = ? ? ? ;
//		using pointer = ? ? ? ;
//		using reference = ? ? ? ;
//		using difference_type = ? ? ? ;
//
//		explicit iterator(ListNode* const ptr = nullptr);
//		iterator& operator++();
//		iterator operator++(int);
//		reference operator*() const;
//		pointer operator->() const;
//		bool operator==(iterator const& other) const = default;
//	};
//	static_assert(std::forward_iterator<iterator>);
//
//public:
//	using value_type = ? ? ? ;
//	SetList();
//	SetList(SetList const& other) = delete;
//	SetList& operator = (SetList const& other) = delete;
//	iterator begin();
//	iterator end();
//	iterator find(T value);
//	iterator insert(iterator const, T value);
//	~SetList();
//};
//
//
//// a = i++ -> a = i; i = i+1 
//// 
//// a = ++i -> i = i+1; a = i = (old(i)+1)
//
////this -> ptr
//// *this -> 对地址取值
//// &value -> 对值取地址
////&this -> address of ptr(this)
//// 对指针取地址 -》 对地址取地址
////*(&this) -> this
//
////ptr(address) -> another addr
//
////int* ptr
////int& a = b
//
//
////reference = T&
//// reference func()
//// int operator * (){
//// return int(var)
////*this -> iterator != current
//
////class A
//// var a
//
////A.a
//
////set<int> set = {1, 2, 3}
////iter = vec.begin()
////*iter = 1
//
////reference operator*() const;
////T& func(){
////  return current->data;
////}
//
//
////pointer operator->()const;
//// using pointer = T*
//// T* operator->() const;
//// 
//// 
////  return &current
////	ListNode* != T*
//// 
////	return current->next
////  ListNode* != T*
//// 
//// 
////  current&data
////  *current = data
////  ListNode = T
////  1. T* ptr -> data
////  T = T 
////  ptr -> addr
////  2. &value
////  对值取地址
//
//
////set<int> set = {1,    2,       3}
////				 head   node1    node2 ListNode*
////          iter  ^  ^  ^ -> 
////iter1 = vec.begin()
////iter2 = iter++
//// *iter1 = 1
//// for(auto i = set.begin(); i!=set.end(); i++)
//// 
//// ListNode -> SetList
////head -> node -> node -> nullptr
////   data    data    data
////   next	 next	 next
////     1       2	   3
//// 
////if (iter1 == iter2)
////this  --  other
////current == other.current
//
////ListNode a("hello")
////ListNode("HELLO")
//
////iterator begin()
//// return iterator(head);
//// constructor
//// 
//// return *head
//// ListNode != iterator
//
////iterator end()
//// nullptr
//// ptr ? &
//// return iterator(nullptr)
//
//
////this -> SetList*
////iterator find(T value)
//// for(auto iter = begin(); iter!=end(); ++iter){
////	if(*iter == value)
////		return iter;
//// return end()
//// 
//// *iter -> T& -> T
//// value -> T
//// 
//// ListNode
//// if(head->data == value){
////	return iterator(head)
//// ListNode->current
//// head->&data
//// ->data
//// ->next
//// iter.current -> head
//// }
//// (data == value)
//
////iterator(ListNode* ptr) : current(ptr)
////iterator()
////iterator(node)
////ptr = node
//
//
////iterator insert(iterator const, T value);
////	for(auto i = begin(); i!=end(); ++i){
////		if(*i == value){
////			return iterator(head);
////		}
//// }
//	//	head = new ListNode(value, head);
//	//	return iterator(head); 
//	// 
//	// 
////
//// `SetList(){
////		while(head){
////			ListNode* tmp = head;
////			head = head->next;
////			delete tmp;
////		}
//// }
////

#include <iostream>

template <typename T>
class SetList {
    struct ListNode {
        T data;
        ListNode* next;

                ListNode(T const& value, ListNode* const next_ptr = nullptr)
            : data(value), next(next_ptr)
        {}
    };
    ListNode* head;

public:
    class iterator {
        ListNode* current;
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using pointer = value_type*;
        using reference = value_type&;
        using difference_type = std::ptrdiff_t;

        explicit iterator(ListNode* const ptr = nullptr) : current(ptr) {};
        iterator& operator++() {
            current = current->next;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            current = current->next;
            return temp;
        }

        reference operator*() const {
            return current->data;
        }

        pointer operator->() const {
            return &(current->data);
        }

        bool operator!=(iterator const& other) const {
            return current != other.current;
        }

        bool operator==(iterator const& other) const {
            return current == other.current;
        }

    };

    //static_assert(std::forward_iterator<iterator>);

public:
    using value_type = T;

    SetList() : head(nullptr) {};

    SetList(SetList const& other) = delete;
    SetList& operator =(SetList const& other) = delete;
    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator();
    }

    iterator find(T value) {
        for (auto i = begin(); i != end(); ++i) {
            if (*i == value)
                return i;
        }
        return end();
    }

    iterator insert(iterator const, T value) {
        for (auto i = begin(); i != end(); ++i) {
            if (*i == value)
                return iterator(head);
        }
        head = new ListNode(value, head);
        return iterator(head);
    }

    ~SetList() {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

