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

#pragma once
#include <cstddef>

using namespace std;

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
        using pointer = T*;
        using reference = T&;
        using difference_type = std::ptrdiff_t;

        explicit iterator(ListNode* const ptr = nullptr)
            : current(ptr)
        {}
        iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }
        iterator operator++(int) {
            iterator temp(*this);
            ++(*this);
            return temp;
        }
        reference operator*() const {
            return current->data;
        }
        pointer operator->() const {
            return &(current->data);
        }
        bool operator==(iterator const& other) const {
            return current == other.current;
        }
        bool operator!=(iterator const& other) const {
            return current != other.current;
        }

        void print(ostream& out) {
            out << current->data;
        }

        friend ostream& operator<<(ostream& out, iterator& m) {
            m.print(out);
            return out;
        }
    };
    //static_assert(std::forward_iterator<iterator>);

public:
    using value_type = T;
    SetList()
        : head(nullptr)
    {}
    iterator begin() {
        return iterator(head);
    }
    iterator end() {
        return iterator(nullptr);
    }
    iterator find(T value) {
        for (auto iter = begin(); iter != end(); ++iter) {
            if (*iter == value) {
                return iter;
            }
        }
        return end();
    }
    iterator insert(iterator const pos, T value) {
        if (pos == end() || (pos != end() && *pos != value)) {
            head = new ListNode(value, head);
            return iterator(head);
        }
        return pos;
    }

    void print(ostream& out) {
        out << head->data;
    }

    friend ostream& operator<<(ostream& out, SetList& m) {
        m.print(out);
        return out;
    }

    ~SetList() {
        while (head) {
            ListNode* const next = head->next;
            delete head;
            head = next;
        }
    }
};
