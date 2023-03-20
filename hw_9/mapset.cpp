#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include "MapArray.h"
#include "SetList.h"

using namespace std;

bool is_stopwords(SetList<string>& stopwords, string& word) {
    return (stopwords.find(word) != stopwords.end());
}

class WordCounter {
private:
    MapArray<string, int>& m_word_count;

public:
    WordCounter(MapArray<string, int>& word_count)
        : m_word_count(word_count) {}

    void operator()(const string& word) {
        ifstream stopwords_file("./txt/stopwords.txt");
        SetList<string> stopwords;
        copy(istream_iterator<string>(stopwords_file), istream_iterator<string>(), inserter(stopwords, stopwords.begin()));
        //cout << *stopwords.find("because") << endl;

        string lowercase_word(word);
        transform(lowercase_word.begin(), lowercase_word.end(), lowercase_word.begin(), ::tolower);

        if (!is_stopwords(stopwords, lowercase_word)) {
            m_word_count[lowercase_word]++;
        }
    }
};

int main() {
    MapArray<string, int> word_count;
    ifstream input_file("./txt/sample_doc.txt");
    string word;
    while (input_file >> word) {
        WordCounter counter(word_count);
        counter(word);
    }

    for (const auto& pair : word_count) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
//#include<stdio.h>
//#include<stddef.h>
//#include<string.h>
//int main(int argc, char* argv[])
//{
//    char str[] = "Hello world!";
//    char* pstart = str;
//    char* pend = str + strlen(str);
//    ptrdiff_t difp = pend - pstart;
//    printf("%d\n", difp);
//    return 0;
//}
