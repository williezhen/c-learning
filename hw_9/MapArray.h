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
//		auto operator <=> (iterator const& other) const = default;
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

#pragma once
#include <vector>
#include <compare>

template <typename Key, typename Value>
class MapArray {
    std::vector<std::pair<Key, Value>> vec;
public:
    class iterator {
        std::pair<Key, Value>* current;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = std::pair<Key, Value>;
        using pointer = std::pair<Key, Value>*;
        using reference = std::pair<Key, Value>&;
        using difference_type = std::ptrdiff_t;

        explicit iterator(pointer const ptr = nullptr) : current(ptr) {}
        iterator& operator++() {
            ++current;
            return *this;
        }
        iterator& operator--() {
            --current;
            return *this;
        }
        iterator operator++(int) {
            auto temp = *this;
            ++current;
            return temp;
        }
        iterator operator--(int) {
            auto temp = *this;
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
        friend iterator operator-(difference_type const d, iterator i) {
            return i -= d;
        }
        friend difference_type operator-(iterator const i, iterator const j) {
            return i.current - j.current;
        }
        //auto operator <=> (iterator const& other) const = default;
        reference operator*() const {
            return *current;
        }
        pointer operator->() const {
            return current;
        }
        reference operator[](difference_type const d) const {
            return *(*this + d);
        }
        bool operator!=(iterator const& other) const {
            return current != other.current;
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

    //Value& operator[](Key const& key) {
    //    auto it = std::find_if(vec.begin(), vec.end(), [&key](auto const& p) { return p.first == key; });
    //    if (it == vec.end()) {
    //        vec.emplace_back(key, Value{});
    //        return vec.back().second;
    //    }
    //    return it->second;
    //}



    // iter = vec.begin()
    // 
    // 
    //       iter iter  iter
    // vec = {1    2    3     4      5} end()
    // return 第一个不小于给定值的元素位置iter
    // lower_bound
    //key = 3


    //vec:
    // 1 2 3 5 6
    // a b d e ()
    //
    // map[3] = 3.value
    // map[3] = 3.value = char()
    // key = 3
    // first >= key
    // iter = return iter(4)
    // emplace(iter, value)
    // 
    // 
    //  
    //iter = return end()
    //key = 6
    //first < key
    //emplace(iter, value)

    Value& operator[](Key const& key) {
        auto it = std::lower_bound(vec.begin(), vec.end(), key, [](auto const& p, Key const& k) { return p.first < k; });
        if (it == vec.end() || it->first != key) {
            it = vec.emplace(it, key, Value{});
        }
        return it->second;
    }
};
