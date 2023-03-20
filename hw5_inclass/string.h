#include "ListNode.h"

class String {
public:
	explicit String(const char* s = "");
	String(const String& s);
	String(String&& s);


	String& operator = (String&& s);
	String& operator = (const String& s);
	char& operator [] (int index);//index for(<index) return data//*(ptr+index)
	int size() const;
	String reverse() const;
	int indexOf(const char c) const;
	int indexOf(const String& s) const;
	String operator + (const String& s);

	bool operator == (const String& s);
	bool operator != (const String& s);
	bool operator > (const String& s);
	bool operator < (const String& s);
	bool operator <= (const String& s);
	bool operator >= (const String& s);

	void print(std::ostream& out) const;

	void read(std::istream& in);

	~String() {
		ListNode::list_delete(head);
		ListNode::report_allocations();
	};

private:
	String(List L);
	//ListNode * 

	//bool in_bounds(int i) const;
	void error(const char* msg) const;

	List head;
};

inline std::ostream& operator << (std::ostream& out, const String& c) {
	c.print(out);
	return out;
};

inline istream& operator >> (istream& in, String& s) {
	s.read(in);
	return in;
}