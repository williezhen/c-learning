#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define MAXLEN 128

class String {
	char buf[MAXLEN];

	static int strlen(const char* s) {
		int i = 0;
		//cs161写覆盖
		while (s[i])
		{
			if (s[i] != '\0') {
				i++;
			}
			else {
				break;
			}
		}
		return i + 1;
	};
	static char* strcpy(char* dest, const char* src) {
		int i = 0;
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return dest;
	};
	static char* strncpy(char* dest, const char* src, int n) {
		for (int i = 0; i < n; i++) {
			dest[i] = src[i];
			if (src[i] == '\0') {
				break;
			}
		}
		return dest;
	};
	static char* strncat(char* dest, const char* src, int n) {
		int index = 0;
		while (dest[index] != '\0') {
			index++;
		}
		for (int i = 0; i < n; i++) {
			dest[i + index] = src[i];
			if (src[i] == '\0') {
				break;
			}
		}
		return dest;
	};
	static int strcmp(const char* left, const char* right) {
		int tmp1;
		int tmp2;

		for (int i = 0; i < min(strlen(left), strlen(right)); i++) {
			tmp1 = left[i];
			tmp2 = right[i];
			if (tmp1 < tmp2) {
				return -1;
			}
			else if (tmp1 > tmp2) {
				return 1;
			}
		}
		return 0;
	};
	static int strncmp(const char* left, const char* right, int n) {
		int tmp1;
		int tmp2;

		for (int i = 0; i < n; i++) {
			tmp1 = left[i];
			tmp2 = right[i];
			if (tmp1 < tmp2) {
				return -1;
			}
			else if (tmp1 > tmp2) {
				return 1;
			}
		}
		return 0;
	};
	static void reverse_cpy(char* dest, const char* src) {
		int index = 0;
		for (int i = strlen(src) - 2; i >= 0; i--) {
			dest[index] = src[i];
			index++;
		}
		dest[index] = '\0';
	};
	static char* strchr(char* str, char c) {
		while (str) {
			if (str[0] != c) {
				str++;
			}
			else {
				return str;
			}
		}
	};
	//static char* strstr(char* haystatck, const char* needle) {

	//};
	static char* strstr1(char* s1, const char* s2) {
		int n;
		if (*s2)
		{
			while (*s1)
			{
				for (n = 0; *(s1 + n) == *(s2 + n); n++)
				{
					if (!*(s2 + n + 1))
						return s1;
				}
				s1++;
			}
			return NULL;
		}
		else
			return s1;
	};
	static const char* strstr2(const char* s1, const char* s2) {
		int n;
		if (*s2)
		{
			while (*s1)
			{
				for (n = 0; *(s1 + n) == *(s2 + n); n++)
				{
					if (!*(s2 + n + 1))
						return s1;
				}
				s1++;
			}
			return NULL;
		}
		else
			return s1;
	};

public:
	explicit String(const char* s = "") {
		int index = 0;
		while (s[index])
		{
			buf[index] = s[index];
			index++;
			if (index >= MAXLEN-1) {
				break;
			}
		}
		buf[index] = '\0';
	};
	String(const String& s) {
		int index = 0;
		while (s.buf[index])
		{
			buf[index] = s.buf[index];
			index++;
			if (index == MAXLEN - 1) {
				break;
			}
		}
		buf[index] = '\0';
	};
	void print(ostream& out) const {
		int index = 0;
		while (this->buf[index] != '\0') {
			out << this->buf[index++];
		}
	};

	void read(istream& in) {
		char tmp[MAXLEN + 1];
		in >> setw(MAXLEN) >> tmp;
		//in.get(tmp, 128);
		if (strlen(tmp) >= MAXLEN) {
			cout << "ERROR: String Capacity Exceeded." << endl;
			tmp[MAXLEN - 1] = '\0';
		}
		strcpy(buf, tmp);
	}
	//1234567890
	String& operator = (const String& s) {
		//this->buf = strcpy(*this->buf, *s.buf);
		for (int i = 0; i < sizeof(s.buf) / sizeof(s.buf[0]); i++) {
			this->buf[i] = s.buf[i];
			if (s.buf[i] == '\0') {
				break;
			}
		}
		return *this;
	};

	String& operator + (const String& s) {
		String* tmp = new String;
		char tmp2[MAXLEN];
		this->strcpy(tmp2, this->buf);
		int index1 = 0;
		int index2 = 0;
		while (this->buf[index1] != '\0') {
			index1++;
		}
		while (s.buf[index2] != '\0') {
			index2++;
		}
		index2++;
		if (index1 + index2 > MAXLEN) {
			cout << "ERROR" << endl;
			return *tmp;
		}
		this->strncat(tmp2, s.buf, index2);
		for (int i = 0; i < index1+index2; i++) {
			tmp->buf[i] = tmp2[i];
			if (tmp2[i] == '\0') {
				break;
			}
		}
		//for (int i = 0; i < sizeof(tmp.buf) / sizeof(tmp1); i++) {
		//	this->buf[i] = tmp1[i];
		//	if (tmp1[i] == '\n') {
		//		break;
		//	}
		//}
		return *tmp;

	};
	char& operator [] (int index) {
		if(index>=0 and index<MAXLEN)
			return this->buf[index];
	};
	size_t size() {
		return this->strlen(this->buf);
	};
	String reverse() {
		char tmp1[MAXLEN];
		char tmp2[MAXLEN];
		this->strcpy(tmp1, this->buf);
		//for (int i = 0; i < MAXLEN; i++) {
		//	//this->buf[i] = tmp[i];
		//	cout << tmp1[i];
		//	if (tmp1[i] == '\n') {
		//		break;
		//	}
		//}
		this->reverse_cpy(tmp2, tmp1);
		//for (int i = 0; i < MAXLEN; i++) {
		//	//this->buf[i] = tmp[i];
		//	cout << tmp2[i];
		//	if (tmp2[i] == '\n') {
		//		break;
		//	}
		//}
		this->strcpy(this->buf, tmp2);
		/*for (int i = 0; i < MAXLEN; i++) {
			if (this->buf[i] != '\n') {
				cout << this->buf[i];
			}
			else {
				break;
			}
		}*/
		//for (int i = 0; i < MAXLEN; i++) {
		//	//this->buf[i] = tmp[i];
		//	cout << tmp[i];
		//	if (tmp[i] == '\n')
		//		break;
		//}
		return *this;
	};
	int indexOf(const char c) {
		int n = 0;
		while (this->buf[n])
		{
			if(this->buf[n] == c)
				return n;
			n++;
		}
		return NULL;
	};
	int indexOf(const String s) {
		char* tmp = this->buf;
		int n;
		if (*s.buf)
		{
			while (*tmp)
			{
				for (n = 0; *(tmp + n) == *(s.buf + n); n++)
				{
					if (!*(s.buf + n + 1) or *(s.buf + n + 1)=='\0')
						return tmp - this->buf;
				}
				tmp++;
			}
			cout << 1 << endl;
			return NULL;
		}
		else
			return tmp - this->buf;
	};
	bool operator == (const String s) {
		for (int i = 0; i < MAXLEN; i++) {
			if (this->buf[i] != s.buf[i]) {
				return false;
			}
			if (this->buf[i] == '\0') {
				break;
			}
		}
		return true;
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

istream& operator >> (istream& in, String& s) {
	s.read(in);
	return in;
}