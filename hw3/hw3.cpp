// hw3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//#include <string.h>
#include "string.h"

using namespace std;

//static void reverse_cpy(char* dest, const char* src) {
//	int index = 0;
//	for (int i = strlen(src) - 1; i >= 0; i--) {
//		dest[index] = src[i];
//		index++;
//	}
//	dest[index] = '\n';
//};
//
//static char* strcpy1(char* dest, const char* src) {
//    int i = 0;
//    while (src[i] != '\n')
//    {
//        dest[i] = src[i];
//        i++;
//    }
//    i++;
//    dest[i] = src[i];
//    return dest;
//};

int main()
{  
    //char s1[] = "GeeksforGeeks";
    //char s2[] = "for";
    //char* a = strstr(s1, s2);
    //cout << a - s1 + 1 << endl;
    String firstString("First");
    String secondString("Second");
    cout << secondString << endl;
    String thirdString(firstString);
    cout << firstString << endl;
    cout << thirdString << endl;
    String fourthString("Fourth");
    String fifthString = String();
    cout << "+:" << firstString<< endl;
    fifthString = firstString + secondString;
    cout << firstString << endl;
    cout << secondString << endl;
    cout << thirdString << endl;
    cout << "=:" << fifthString << endl;
    cout << "[]:" << fifthString[1] << endl;
    cout << "size:" << fifthString.size() << endl;
    cout << "reverse:" << fourthString.reverse() << endl;
    cout << "indexofchar:" << fifthString.indexOf('n') << endl;
    //cout << fifthString << endl;
    //cout << secondString << endl;
    cout << "indexofstring:" << fifthString.indexOf(secondString) << endl;
    cout << "==:" << (firstString == thirdString) << endl;
    cout << "==:" << (firstString == secondString) << endl;
    String sixthString;
    cin >> sixthString;
    cout << sixthString << endl;

    //char b[18];
    //cin >> b;
    //char* a = new char[18];
    //strcpy1(a, b);
    //reverse_cpy(b, a);
    //int i = 0;
    //while (b[i]!='\n')
    //{
    //    cout << b[i];
    //    i++;
    //}
    //cout << a;


    return 0;
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
