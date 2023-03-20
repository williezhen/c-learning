// hw3_inclass.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
// #include <string>
// string s = "hello" // const char *;
// string s2 = s;
#include "string.h"

using namespace std;

static int strlen1(const char* s) {
    int c = 0;
    while (s[c] != '\0') {
        c++;
    }
    return c;
};

static char* strncpy1(char* dest, const char* src, int n) {
    int i;
    for (i = 0; src[i] != '\0' and i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
};

static char* strncat1(char* dest, const char* src, int n) {
    int i;
    int len = strlen(dest);
    for (i = 0; (i < n and src[i] != '\0'); i++) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return dest;
};


static int strcmp1(const char* left, const char* right) {
    int i = 0;
    while (left[i] != '\0' and right[i] != '\0') {
        if (left[i] == right[i]) {
            i++;
            continue;
        }
        break;
    }
    return left[i] - right[i];//if 1 -1 0
};

static int strncmp1(const char* left, const char* right, int n) {
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

static char* strchr1(char* str, char c) {
    int i = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return &str[i];
        }
    }
};

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

static void reverse_cpy(char* dest, const char* src) {
    int i;
    int len = strlen(src) - 1;
    for (i = len; i >= 0; i--) {
        dest[len - i] = src[i];
    }
    dest[len - i] = '\0';
};

int main()
{
    String s("hello");
    String s2(s);
    String s3(" world");
    String s4(s3);

    cout << s << endl;
    cout << s2 << endl;
    s = s + s3;
    cout << s << endl;
    cout << s << endl;
    cout << s[2] << endl;
    //cout << s.reverse() << endl;
    cout << s.indexOf(s3) << endl;
    cout << (s3 == s) << endl;
    cout << s << endl;
    s += s2;
    cout << s << endl;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
