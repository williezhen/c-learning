#include <iostream>
#include <algorithm>

using namespace std;

#define MAXLEN 128

// string s;
// s.length();

class String {
	char buf[MAXLEN];

	static int strlen(const char* s) {
		int c = 0;

		while (s[c] != '\0') {
			c++;
		}

		return c;
	};
	static char* strcpy(char* dest, const char* src) {
		int i;
		for (i = 0; src[i] != '\0'; i++) {
			dest[i] = src[i];
		}
		dest[i] = '\0';
		return dest;
	};
	static char* strncpy(char* dest, const char* src, int n) {
		int i;
		for (i = 0; src[i] != '\0' and i < n; i++) {
			dest[i] = src[i];
		}
		dest[i] = '\0';
		return dest;
	};
	static char* strncat(char* dest, const char* src, int n) {
		int i;
		int len = strlen(dest);
		for (i = 0; (i < n and src[i] != '\0'); i++) {
			dest[len + i] = src[i];
		}
		dest[len + i] = '\0';
		return dest;
	};
	static int strcmp(const char* left, const char* right) {
		int i = 0;
		while (left[i] != '\0' and right[i] != '\0') {
			if (left[i] == right[i]) {
				i++;
				continue;
			}
			break;
		}
		return left[i] - right[i];
	};
	static int strncmp(const char* left, const char* right, int n) {
		int i = 0;
		while (left[i] != '\0' and right[i] != '\0' and i < n) {
			if (left[i] == right[i]) {
				i++;
				continue;
			}
			break;
		}
		if (i == n) {
			return 0;
		}
		return left[i] - right[i];
	};

	static void reverse_cpy(char* dest, const char* src) {
		int i;
		int len = strlen(src)-1;
		for (i = len; i>=0; i--) {
			dest[len - i] = src[i];
		}
		dest[len - i] = '\0';
	};
	//str = hello'\0' // strlen = 5;
	//str[4] = 'o' //str[5] = '\0'
	//str[0] = 'h'

	static char* strchr(char* str, char c) {
		//int i;
		//for (i = 0; str[i] != '\0'; i++) {
		//	if (str[i] == c) {
		//		return &str[i];
		//	}
		//}
		//return nullptr;

		while (str) {
			if (*str != c) {
				str++;
			}
			else {
				return str;
			}
		}
	};
	// & -> 取地址符
	// ptr1 -> 指向地址 0xffff6a8f
	// ptr2 -> *ptr / ptr[i]
	// * 1. 取值   2. 声明 - 》标识指针函数/指针变量

	//static char* strstr(char* haystatck, const char* needle) {

	//};
	static char* strstr1(char* s1, const char* s2) {
		int n;
		if (*s2) { // s2[]
			while (*s1) {
				for (n = 0; *(s1 + n) == *(s2 + n); n++) {
					if (!*(s2 + n + 1)) {
						return s1;
					}
				}
				s1++;//int index ++
			}
			return NULL;
		}
		else {
			return s1;
		}
	};
	static const char* strstr2(const char* s1, const char* s2) {

	};

public:
	explicit String(const char* s = "") {
		if(strlen(s)<MAXLEN){
			strncpy(buf, s, strlen(s));
		}
		else {
			cout << "ERROR" << endl;
			//127
		};
	};
	String(const String& s) {
		strcpy(buf, s.buf);
	};
	void print(ostream& out) const {
		out << buf;
	};

	// a = b; this = a ; b = s
	String& operator = (const String& s) {
		strcpy(this->buf, s.buf);
		return *this;
	};

	// a = b + c // b = b c = c
	// b = a = b+c
	String& operator + (const String& s) {
		String tmp;//
		char tmp2[MAXLEN];
		//char* tmp3 = this->buf;
		this->strcpy(tmp2, this->buf);
		int len1 = strlen(this->buf);
		int len2 = strlen(s.buf);
		// if maxlen
		this->strncat(tmp2, s.buf, len2);
		//MAXLEN
		/*for (int i = 0; i < len1 + len2; i++) {
			tmp.buf[i] = tmp2[i];
			if (tmp2[i] == '\0') {
				break;
			}
		}*/
		this->strcpy(tmp.buf, tmp2);
		return tmp;
	};
	// a(this += b(s
	String& operator += (const String& s) {
		int len1 = strlen(this->buf);
		int len2 = strlen(s.buf);
		// if maxlen
		this->strncat(this->buf, s.buf, len2);
		//MAXLEN
		/*for (int i = 0; i < len1 + len2; i++) {
			tmp.buf[i] = tmp2[i];
			if (tmp2[i] == '\0') {
				break;
			}
		}*/
		return *this;
	};
	char& operator [] (int index) {
		return buf[index];
	};
	size_t size() {
		strlen(buf);
	};
	String reverse() {
		char tmp[MAXLEN];
		strcpy(tmp, buf);
		reverse_cpy(buf, tmp);
		return *this;//dest, src
	};
	//String s;
	// s.buf
	// s.reverse(s.buf, s.buf);
	// 0 - n
	// n - 0
	int indexOf(const char c) {
		char* a = strchr(buf, c);
		char* tmp = this->buf;
		return a - tmp;
	};
	int indexOf(const String s) {
		char* tmp = this->buf;
		char* a = strstr1(buf, s.buf);
		return a - tmp; //NULL
	};
	bool operator == (const String s) {
		return strcmp(buf, s.buf)==0;
	};
	bool operator != (const String s);
	bool operator > (const String s);
	bool operator < (const String s);
	bool operator <= (const String s);
	bool operator >= (const String s);
};

ostream& operator << (ostream& out, const String c) {
	c.print(out);
	return out;
};

//istream{
// 
//return in

