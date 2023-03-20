#include "string.h"

using namespace std;

int String::strlen1(const char* s) {
	int i = 0;
	while (s[i])
	{
		if (s[i] != '\0') {
			i++;
		}
		else {
			break;
		}
	}
	return i;
};
char* String::strcpy(char* dest, const char* src) {
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
};
char* String::strncpy(char* dest, const char* src, int n) {
	int i;
	for (i = 0; i < n; i++) {
		dest[i] = src[i];
		if (src[i] == '\0') {
			break;
		}
	}
	dest[i] = '\0';
	return dest;
};
char* String::strncat(char* dest, const char* src, int n) {
	int index = 0;
	while (dest[index] != '\0') {
		index++;
	}
	int i;
	for (i = 0; i < n; i++) {
		dest[i + index] = src[i];
		if (src[i] == '\0') {
			break;
		}
	}
	dest[i] = '\0';
	return dest;
};
int String::strcmp(const char* left, const char* right) {
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
int String::strncmp(const char* left, const char* right, int n) {
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
void String::reverse_cpy(char* dest, const char* src) {
	int index = 0;
	for (int i = strlen(src) - 1; i >= 0; i--) {
		dest[index] = src[i];
		index++;
	}
	dest[index] = '\0';
};
char* String::strchr(char* str, char c) {
	while (str) {
		if (str[0] != c) {
			str++;
		}
		else {
			return str;
		}
	}
};
char* String::strstr1(char* s1, const char* s2) {
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
const char* String::strstr2(const char* s1, const char* s2) {
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

String::String(const char* s) {
	int len = strlen1(s);
	buf = this->alloc.new_char_array(len + 1);

	int index = 0;
	while (s[index] != '\0')
	{
		buf[index] = s[index];
		index++;
	}
	buf[index] = '\0';
};
String::String(const String& s) {
	int len = strlen1(s.buf);
	buf = this->alloc.new_char_array(len + 1);

	int index = 0;
	while (s.buf[index] != '\0')
	{
		buf[index] = s.buf[index];
		index++;
	}
	buf[index] = '\0';
};
//String::String(String&& s) {
//	cout << "&&" << endl;
//	int len = strlen1(s.buf);
//	buf = this->alloc.new_char_array(len + 1);
//
//	int index = 0;
//	while (s.buf[index] != '\0')
//	{
//		buf[index] = s.buf[index];
//		index++;
//	}
//	buf[index] = '\0';
//};

void String::print(ostream& out) const {
	int index = 0;
	while (buf[index] != '\0') {
		out << buf[index++];
	}
};

//void String::read(istream& in) {
//	char tmp[MAXLEN + 1];
//	in >> setw(MAXLEN) >> tmp;
//	//in.get(tmp, 128);
//	if (strlen(tmp) >= MAXLEN) {
//		cout << "ERROR: String Capacity Exceeded." << endl;
//		tmp[MAXLEN - 1] = '\0';
//	}
//	strcpy(buf, tmp);
//}

String& String::operator = (const String& s) {
	int len_2 = strlen1(s.buf);
	this->alloc.delete_char_array(buf);
	buf = this->alloc.new_char_array(len_2 + 1);

	strncpy(buf, s.buf, len_2);
	return *this;
};

String& String::operator = (String&& s) {
	int len_2 = strlen1(s.buf);
	this->alloc.delete_char_array(buf);
	buf = this->alloc.new_char_array(len_2 + 1);

	strncpy(buf, s.buf, len_2);
	return *this;
};

String& String::operator + (const String& s) {
	String tmp;
	int len1 = strlen1(buf);
	int len2 = strlen1(s.buf);
	tmp.alloc.delete_char_array(tmp.buf);
	tmp.buf = tmp.alloc.new_char_array(len1 + len2 + 1);
	strncpy(tmp.buf, buf, len1);
	strncat(tmp.buf + len1, s.buf, len2);
	return tmp;

};
char& String::operator [] (int index) {
	if (index >= 0 and index < strlen1(buf))
		return this->buf[index];
};
size_t String::size() {
	return strlen1(buf);
};
String String::reverse() {
	int len = strlen1(buf);
	char* tmp1 = this->alloc.new_char_array(len + 1);
	this->strncpy(tmp1, buf, len);
	this->reverse_cpy(buf, tmp1);
	this->alloc.delete_char_array(tmp1);
	cout << buf << endl;
	return *this;
};
int String::indexOf(const char c) {
	int n = 0;
	while (this->buf[n])
	{
		if (this->buf[n] == c)
			return n;
		n++;
	}
	return NULL;
};
int String::indexOf(const String s) {
	char* tmp = this->buf;
	int n;
	if (*s.buf)
	{
		while (*tmp)
		{
			for (n = 0; *(tmp + n) == *(s.buf + n); n++)
			{
				if (!*(s.buf + n + 1) or *(s.buf + n + 1) == '\0')
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
bool String::operator == (const String s) {
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

String& String::strdup(const String& s) {
	String* tmp = new String;
	int len = strlen1(s.buf);
	tmp->alloc.delete_char_array(tmp->buf);
	tmp->buf = tmp->alloc.new_char_array(len + 1);
	strncpy(tmp->buf, s.buf, len);
	cout << tmp->buf << endl;
	return *tmp;
};

//String::~String() {
//	alloc.delete_char_array(buf);
//	cout << "memo free" << endl;
//}

//String::ostream& operator << (ostream& out) {
//	this->print(out);
//	return out;
//};
//
//istream& operator >> (istream& in, String& s) {
//	s.read(in);
//	return in;
//}

