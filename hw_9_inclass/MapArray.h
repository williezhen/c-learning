//#pragma once
//#include <vector>
//
//template <typename Key, typename Value>
//class MapArray {
//	std::vector<std::pair<Key, Value>> vec;
//public:
//	class iterator {
//		std::pair<Key, Value>* current;
//	public:
//		using iterator_category = ? ? ? ;
//		using value_type = ? ? ? ;
//		using pointer = ? ? ? ;
//		using reference = ? ? ? ;
//		using difference_type = ? ? ? ;
//
//		explicit iterator(pointer const ptr = nullptr);
//		iterator& operator++();
//		iterator& operator--();
//		iterator operator++(int);
//		iterator operator--(int);
//		iterator& operator+= (difference_type const d);
//		iterator& operator-=(difference_type const d);
//		friend iterator operator+(iterator i, difference_type const d);
//		friend iterator operator+(difference_type const d, iterator i);
//		friend iterator operator-(iterator i, difference_type const d);
//		friend iterator operator-(difference_type const d, iterator i);
//		friend difference_type operator-(iterator const i, iterator const j);
//		auto operator <=> (iterator const& other) const = default;//c++20
//		//spaceman operaotr
//		//> = < >=
//		reference operator*() const;
//		pointer operator->() const;
//		reference operator[](difference_type const d) const;
//	};
//	static_assert(std::random_access_iterator<iterator>);
//	using value_type = ? ? ? ;
//	iterator begin();
//	iterator end();
//	Value& operator[](Key const& key);
//};
//
////int * a = new int[10]
////a + 5 = a[5]

#include <iostream>
#include <vector>

template <typename Key, typename Value>
class MapArray {
    std::vector<std::pair<Key, Value>> vec;

public:
    class iterator {
        std::pair<Key, Value>* current;

    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = std::pair<Key, Value>;
        using pointer = value_type*;
        using reference = value_type&;
        using difference_type = std::ptrdiff_t;

        explicit iterator(pointer const ptr = nullptr) : current(ptr) {};
        iterator& operator++() {
            ++current;
            return *this;
        }

        iterator& operator--() {
            --current;
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++current;
            return temp;
        }

        iterator operator--(int) {
            iterator temp = *this;
            --current;
            return temp;
        }

        iterator& operator+=(difference_type const d) {
            current += d;
            return *this;
        }

        iterator& operator-=(difference_type const d) {
            current -= d;
            return *this;
        }

        friend iterator operator+(iterator i, difference_type const d) {
            return i += d;
        }

        friend iterator operator+(difference_type const d, iterator i) {
            return i += d;
        }

        friend iterator operator-(iterator i, difference_type const d) {
            return i -= d;
        }

        friend difference_type operator-(iterator const i, iterator const j) {
            return (i.current - j.current);
        }

        //auto operator <=>(iterator const& other) const {
        //    return current <=> other.current;
        //}

        bool operator !=(iterator const& other) const {
            return current != other.current;
        }

        reference operator*() const {
            return *current;
        }

        pointer operator->() const {
            return current;
        }

        reference operator[](difference_type const d) const {
            return current[d];
        }

    };

    //static_assert(std::random_access_iterator<iterator>);
    using value_type = std::pair<Key, Value>;
    iterator begin() {
        return iterator(vec.data());
    }

    iterator end() {
        return iterator(vec.data() + vec.size());
    }

    Value& operator[](Key const& key) {

        auto new_pair = std::lower_bound(vec.begin(), vec.end(), key,
            [](auto const& pair, Key const& k) {
                return pair.first < k;
            });
        if (new_pair == vec.end() || new_pair->first != key) {
            vec.emplace(new_pair, key, Value{});
        }
        return new_pair->second;

    }

};

