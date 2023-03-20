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
char* String::strdup(const char* s) {
	int len = strlen1(s);
	char* output = Alloc1::new_char_array(len + 1);
	void* tmp = output;
	for (int i = 0; i < len+1; i++) {
		*output = *s;
		output++;
		s++;
	}
	/*
	if ((output <= s) || output >= s + len) {
		while (len--) {
			*output = *s;
			output++;
			s++;
		}
	}
	else {
		while (len > 0) {
			*(output + len - 1) = *(s + len - 1);
			len--;
		}
	}*/
	return (char*)tmp;
	
	//int len = strlen1(s);
	//
	//char* tmp = Alloc1::new_char_array(len + 1);
	////char * tmp = new char[len + 1];
	//strncpy(tmp, s, len);
	//char* ptr = move(tmp);
	//cout << ptr << endl;
	////Alloc1::delete_char_array(tmp);
	////delete[] tmp;
	//cout << "ptr---------------------" << endl;
	//cout << ptr << endl;
	////cout << tmp << endl;
	//return ptr;
	//Alloc1::delete_char_array(tmp);
	////return;
	////delete;
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
	//cout << '1' << endl;
	int len = strlen1(s);
	buf = alloc.new_char_array(len + 1);//ADD

	int index = 0;
	while (s[index] != '\0') {
		buf[index] = s[index];
		index++;
	}
	buf[index] = '\0';
}

String::String(const String& s) noexcept {
	//cout << '2' << endl;
	int len = strlen1(s.buf);
	buf = alloc.new_char_array(len + 1);//ADD

	int index = 0;
	while (s.buf[index] != '\0') {
		buf[index] = s.buf[index];
		index++;
	}
	buf[index] = '\0';
}

String::String(String&& s) noexcept {
	int len = strlen(s.buf);
	//buf = strdup(s.buf);
	buf = Alloc1::new_char_array(len + 1);
	strncpy(buf, s.buf, len);
	cout << "fuck null" << endl;
	/*Alloc1::delete_char_array(s.buf);
	s.buf = nullptr;*/
	//cout << "&&" << endl;
	//int len = strlen1(s.buf);
	//buf = alloc.new_char_array(len + 1);//ADD

	//int index = 0;
	//while (s.buf[index] != '\0') {
	//	buf[index] = s.buf[index];
	//	index++;
	//}
	//buf[index] = '\0';
}// 

void String::print(ostream& out) const {
	int index = 0;
	while (buf[index] != '\0') {
		out << buf[index++];
	}
}

void String::read(istream& in) {
	char temp[1024];
	in >> temp;
	size_t len = strlen1(temp);
	Alloc1::delete_char_array(buf);
	buf = strdup(temp);
	/*char tmp;
	int len = 0;
	while (in.get(tmp) and tmp!='\n') {
		len++;
		char* tmp_arr = Alloc1::new_char_array(len + 1);
		strncpy(tmp_arr, buf, len - 1);
		tmp_arr[len - 1] = tmp;

		Alloc1::delete_char_array(buf);
		buf = Alloc1::new_char_array(len + 1);
		strncpy(buf, tmp_arr, len);
		Alloc1::delete_char_array(tmp_arr);
	}
	buf[len] = '\0';*/
}
//void String::read(istream& in) {
//	char tmp[1024];
//	in >> tmp;
//	int len = strlen1(tmp);//hello\0
//	alloc.delete_char_array(buf);
//	//buf = alloc.new_char_array(len + 1);
//	buf = 
// (tmp);
//}

//if len_new ? len_ori
// delete

String& String::operator = (const String& s) {
	
	int len = strlen1(s.buf);
	//if len_new == len_ori 
	//this -> buf == ptr
	alloc.delete_char_array(buf);
	buf = alloc.new_char_array(len + 1);

	strncpy(buf, s.buf, len);
	return *this;
}

String& String::operator = (String&& s) noexcept {
	//cout << "=&&" << endl;
	int len = strlen1(s.buf);
	//if len_new == len_ori 
	//this -> buf == ptr
	alloc.delete_char_array(buf);
	buf = alloc.new_char_array(len + 1);

	strncpy(buf, s.buf, len);
	return *this;
}

String String::operator + (const String& s) {
	// return buf + s.buf
	// return tmp.buf = this->buf + s.buf
	// String("") tmp.buf = ""

	//this->tmp;
	// 
	//buf == tmp;

	//if (temp_string != nullptr) {
	//	delete temp_string;
	//	cout << "#" << endl;
	//}
	String temp_string;

	int len1 = strlen1(buf);
	int len2 = strlen1(s.buf);
	char* tmp_arr;
	
	tmp_arr = Alloc1::new_char_array(len1 + len2 + 1);
	
	strncpy(tmp_arr, buf, len1);
	strncpy(tmp_arr + len1, s.buf, len2);

	Alloc1::delete_char_array(temp_string.buf);
	temp_string.buf = Alloc1::new_char_array(len1 + len2 + 1);
	temp_string.buf = strcpy(temp_string.buf, tmp_arr);
	Alloc1::delete_char_array(tmp_arr);
	return temp_string;
}

char& String::operator [] (int index) {
	if (index >= 0 and index < strlen1(buf))
		return this->buf[index];
}

size_t String::size() {
	return strlen1(buf);
}

String String::reverse() {
	size_t buf_len = strlen(buf);
	//char* temp = Alloc1::new_char_array(buf_len + 1);
	//strncpy(temp, buf, buf_len);
	String temp_cpy(*this);
	reverse_cpy(temp_cpy.buf, buf);
	return temp_cpy;
}

String& String::operator += (const String& s) {
	int buf_len = strlen(buf);
	int s_buf_len = strlen(s.buf);
	char* tmp_arr = Alloc1::new_char_array(buf_len + s_buf_len + 1);
	strncpy(tmp_arr, buf, buf_len);
	strncpy(tmp_arr + buf_len, s.buf, s_buf_len);

	Alloc1::delete_char_array(buf);
	buf = Alloc1::new_char_array(buf_len + s_buf_len + 1); 
	strcpy(buf, tmp_arr);
	Alloc1::delete_char_array(tmp_arr);
	return *this;
}

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
	//int index;
	if (*s.buf)
	{
		while (*tmp)//[]
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
	return strcmp(buf, s.buf);
}


