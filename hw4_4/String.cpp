#include <iostream>
using namespace std;
#include "String.h"
#include "Alloc.h"


size_t String::strlen (const char * s) {
    int count = 0;
    while (s[count] != '\0') {
        count++;
    }
    return count;
}

char * String::strdup (const char * s) {
    size_t len = strlen(s);
    String * temp = new String;
    Alloc::delete_char_array(temp->buf);
    temp->buf = Alloc::new_char_array(len + 1);
    strncpy(temp->buf, s, len);

    return temp->buf;
}

char * String::strcpy (char * dest, const char * src) {
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char * String::strncpy (char * dest, const char * src, int n) {
    int i;
    for (i = 0; (i < n && src[i] != '\0'); i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char * String::strcat (char * dest, const char * src) {
    int i;
    size_t len = strlen(dest);
    for (i = 0; src[i] != '\0'; i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return dest;
}

char * String::strncat (char * dest, const char * src, int n) {
    int i;
    size_t len = strlen(dest);
    for (i = 0; (i < n && src[i] != '\0'); i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return dest;
}

int String::strcmp (const char * left, const char * right) {
    int i = 0;
    while (left[i] != '\0' && right[i] != '\0') {
        if (left[i] == right[i]) {
            i++;
            continue;
        }
        break;
    }
    if ((left[i] - right[i]) > 0)
        return 1;
    else if((left[i] - right[i]) < 0) 
        return -1;
    
    return 0;
}

int String::strncmp (const char * left, const char * right, int n) {
    int i = 0;
    while (left[i] != '\0' && right[i] != '\0' && i < n) {
        if (left[i] == right[i]) {
            i++;
            continue;
        }
        break;
    }
    if (i == n) 
        return 0;

    if ((left[i] - right[i]) > 0)
        return 1;
    else if ((left[i] - right[i]) < 0)
        return -1;
    return 0;
}

void String::reverse_cpy (char * dest, const char * src) {
    int i;
    size_t len = strlen(src) - 1;
    for (i = len; i >= 0; i--) {
        dest[len - i] = src[i];
    }
    dest[len - i] = '\0';
}

char * String::strchr (char * str, char c) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return &str[i];
    }
    return nullptr;

}

char * String::strstr (char * haystack, const char * needle) {
    int i;
    if (*needle) {
        while(*haystack) {
            for (i = 0; *(haystack + i) == *(needle + i); i++) {
                if (!*(needle + i + 1))
                            return haystack;
            }
            haystack++;
        }
        return nullptr;

    }

    else
        return haystack;
}

const char * String::strstr (const char * haystack, const char * needle) {
    return const_cast<const char *>(String::strstr(const_cast<char *>(haystack), needle));
}

 
String::String (const char * s) {
    size_t len = strlen(s);
    buf = Alloc::new_char_array(len + 1);
    strncpy(buf, s, len);
}

String::String (const String & s) {
    size_t len = strlen(s.buf);
    buf = Alloc::new_char_array(len + 1);
    strncpy(buf, s.buf, len);
}

String::String (String && s) {
    size_t len = strlen(s.buf);
    buf = Alloc::new_char_array(len + 1);
    strncpy(buf, s.buf, len);
}

String & String::operator = (const String & s) {
    size_t len = strlen(s.buf);
    strncpy(buf, s.buf, len);
    return *this;
}

String & String::operator = (String && s) {
    Alloc::delete_char_array(buf);
    buf = strdup(s.buf);
    return *this;
}

char & String::operator [] (int index) {
    if (in_bounds(index))
        return buf[index];
    return buf[0];
}

size_t String::size() {
    return strlen(buf);
}

String String::reverse() {
    size_t buf_len = strlen(buf);
    char * temp = Alloc::new_char_array(buf_len + 1);
    strncpy(temp, buf, buf_len);
    String temp_cpy(temp);
    Alloc::delete_char_array(temp);
    reverse_cpy(temp_cpy.buf, buf);
    return temp_cpy;

}

int String::indexOf (const char c) {
    char * ch = strchr(buf, c);
    char * temp = buf;
    if (c == '\0')
        return -1;
    return ch - temp;
}

int String::indexOf (const String & s) {
    char * line = strstr(buf, s.buf);
    char * temp = buf;
    if (*s.buf == '\0')
        return strlen(buf);
    return line - temp;
}

bool String::operator == (const String & s) {
    return strcmp(buf, s.buf) == 0;
}

bool String::operator != (const String & s) {
    return strcmp(buf, s.buf) != 0;
}

bool String::operator > (const String & s) {
    return strcmp(buf, s.buf) > 0;
}

bool String::operator < (const String & s) {
    return strcmp(buf, s.buf) < 0;
}

bool String::operator <= (const String & s) {
    return strcmp(buf, s.buf) <= 0;
}

bool String::operator >= (const String & s) {
    return strcmp(buf, s.buf) >= 0;
}

String String::operator + (const String & s) {
    String * temp = new String(this->buf);
    int buf_len = strlen(buf);
    int s_buf_len = strlen(s.buf);

    Alloc::delete_char_array(temp->buf);//temp->Alloc
    temp->buf = Alloc::new_char_array(buf_len + s_buf_len + 1);//temp->Alloc
    strncpy(temp->buf, buf, buf_len);
    strncat(temp->buf + buf_len, s.buf, s_buf_len);
    return *temp;

}

String & String::operator += (const String & s) {
    int buf_len = strlen(buf);
    int s_buf_len = strlen(s.buf);
    strncat(buf, s.buf, s_buf_len);
    return *this;
}

void String::print(ostream & out) {
    out << buf;
}

void String::read(istream & in) {
    char temp[1024];
    in >> temp;
    size_t len = strlen(temp);
    Alloc::delete_char_array(buf);
    buf = strdup(temp);
}

String::~String() {
    Alloc::delete_char_array(buf);
}


bool String::in_bounds (int i) {
    return i >= 0 && i < strlen(buf);
}

ostream & operator << (ostream & out, String s) {
    s.print(out);
    return out;
}

istream & operator >> (istream & in, String & s) {
    s.read(in);
    return in;
}

