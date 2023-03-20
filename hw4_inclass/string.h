//#include <algorithm>
//#include <iomanip>
#include "alloc.h"

using namespace std;

class String {
	char* buf;
	Alloc1 alloc;

	//String * temp_string = new String();
	char* temp_1; //result
	int plus_count = 0; //flag -> tmp / buf
	// 
	//   c = ( a + b ) срж╣
	//  cout << ( a + b ) << endl;
	//   count  = 1
	//   cout << this.tmp << endl;
	//   cout << this.buf << endl; 


	static int strlen1(const char* s);
	static char* strcpy(char* dest, const char* src);
	static char* strncpy(char* dest, const char* src, int n);
	static char* strncat(char* dest, const char* src, int n);
	static int strcmp(const char* left, const char* right);
	static int strncmp(const char* left, const char* right, int n);
	static void reverse_cpy(char* dest, const char* src);
	static char* strchr(char* str, char c);
	static char* strdup(const char * s);
	//static char* strstr(char* haystatck, const char* needle) {

	//};
	static char* strstr1(char* s1, const char* s2);
	static const char* strstr2(const char* s1, const char* s2);

public:
	explicit String(const char* s = "");
	String(const String& s) noexcept;
	String(String&& s) noexcept;

	void print(ostream& out) const ;

	void read(istream& in);
	//1234567890
	String& operator = (const String& s);
	String& operator = (String&& s) noexcept;
	String& operator += (const String& s);
	String operator + (const String& s);
	char& operator [] (int index);
	size_t size();
	String reverse();
	int indexOf(const char c);
	int indexOf(const String s);
	bool operator == (const String s);


	void report() {
		strdup(buf);
		//alloc.report_allocations();
	}

	~String() {
		Alloc1::delete_char_array(buf);//private
		//if(temp_string!=nullptr)
		//	Alloc1::delete_char_array(temp_string->buf);
		alloc.report_allocations();
	};
};

inline ostream& operator << (ostream& out, const String c) {
	c.print(out);
	return out;
};

inline istream& operator >> (istream& in, String& s) {
	s.read(in);
	return in;
}
