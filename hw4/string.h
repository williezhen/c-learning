#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define MAXLEN 128

class String {
	char buf[MAXLEN];

	static int strlen1(const char* s);
	static char* strcpy(char* dest, const char* src);
	static char* strncpy(char* dest, const char* src, int n);
	static char* strncat(char* dest, const char* src, int n);
	static int strcmp(const char* left, const char* right);
	static int strncmp(const char* left, const char* right, int n);
	static void reverse_cpy(char* dest, const char* src);
	static char* strchr(char* str, char c);
	//static char* strstr(char* haystatck, const char* needle) {

	//};
	static char* strstr1(char* s1, const char* s2);
	static const char* strstr2(const char* s1, const char* s2);

public:
	explicit String(const char* s = "");
	String(const String& s);
	void print(ostream& out) const;

	void read(istream& in);
	//1234567890
	String& operator = (const String& s);

	String& operator + (const String& s);
	char& operator [] (int index);
	size_t size();
	String reverse();
	int indexOf(const char c);
	int indexOf(const String s);
	bool operator == (const String s);
	bool operator != (const String s);
	bool operator > (const String s);
	bool operator < (const String s);
	bool operator <= (const String s);
	bool operator >= (const String s);
};

ostream& operator << (ostream& out, const String c);

istream& operator >> (istream& in, String& s);

//#include <iostream>
//#include <iomanip>
//
//#define MAXLEN 128
//
//class String {
//public:
//	explicit String(const char* s = "");
//
//	String(const String& s);
//
//	/*String(String&& s);*/
//
// 	//String& operator = (String&& s);
//	String& operator = (String& s);
//
//	char& operator [](int index);
//	 
//	size_t size();
//
//	String reverse();
//
//	int indexOf(const char c);
//
//	int indexOf(const String s);
//
//	bool operator == (const String s);
//	bool operator != (const String s);
//	bool operator > (const String s);
//	bool operator < (const String s);
//	bool operator <= (const String s);
//	bool operator >= (const String s);
//
//	String operator + (const String s);
//	String& operator += (const String s);
//	void print( std::ostream& out);
//	void read( std::istream& in);
//	~String();
//};