//#include <iostream>
//#include <fstream>
//#include <string>
//#include <algorithm>
//#include <iterator>
//#include <map>
//#include <set>
//
//using namespace std;
//
//bool is_stopword(const std::set<std::string>& stopwords, const std::string& word) {
//    return stopwords.count(word) != 0;
//}
//
//class WordCounter {
//private:
//    std::map<std::string, int>& m_word_count;
//
//public:
//    WordCounter(std::map<std::string, int>& word_count)
//        : m_word_count(word_count) {}
//
//    void operator()(const std::string& word) {
//        ifstream stopwords_file("./txt/stopwords.txt");
//        set<string> stopwords;
//        copy(istream_iterator<string>(stopwords_file), istream_iterator<string>(), inserter(stopwords, stopwords.end()));
//
//        std::string lowercase_word(word);
//        std::transform(lowercase_word.begin(), lowercase_word.end(), lowercase_word.begin(), ::tolower);
//
//        if (!is_stopword(stopwords, lowercase_word)) {
//            m_word_count[lowercase_word]++;
//        }
//    }
//};
//
//int main() {
//    ifstream stopwords_file("./txt/stopwords.txt");
//    set<string> stopwords;
//    copy(istream_iterator<string>(stopwords_file), istream_iterator<string>(), inserter(stopwords, stopwords.end()));
//
//    ifstream doc_context("./txt/sample_doc.txt");
//    map<string, int> word_count;
//    for_each(istream_iterator<string>(doc_context),
//        istream_iterator<string>(),
//        //[stopwords, word_count](string word){
//        //std::string lowercase_word(word);
//  //std::transform(lowercase_word.begin(), lowercase_word.end(), lowercase_word.begin(), ::tolower);
//       //if (!is_stopword(stopwords, lowercase_word)) {
//       // 		word_count[lowercase_word]++;
//       // }
//   //});
//        WordCounter(word_count));
//
//
//    ofstream output("frequency.txt");
//    for_each(word_count.begin(), word_count.end(),
//        [&output](const pair<string, int>& p) {
//            output << p.first << " " << p.second << endl;
//        });
//    return 0;
//}

#include <iostream>
#include "SetList.h"
#include "MapArray.h"
//#include <map>
#include <fstream>
#include <cctype>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;

/*
bool is_stopwords(const SetList<string> & stopwords, string & word) {
    return (stopwords.count(word) != 0);
}*/

int main() {
    ifstream stopwords_file("./txt/stopwords.txt");
    SetList<string> stopwords;
    copy(istream_iterator<string>(stopwords_file),
        istream_iterator<string>(),
        inserter(stopwords, stopwords.end()));
    //transform all the stopwords to lowercase.
    transform(stopwords.begin(), stopwords.end(),
        inserter(stopwords, stopwords.end()),
        [](string lowercase_stopwords) {
            transform(lowercase_stopwords.begin(),
                lowercase_stopwords.end(),
                lowercase_stopwords.begin(),
                [](char c) {
                    return tolower(c);
                });
            return lowercase_stopwords;
        });
    ifstream doc_file("./txt/sample_doc.txt");
    MapArray<string, int> word_count;
    for_each(istream_iterator<string>(doc_file),
        istream_iterator<string>(),
        [&](string word) {
            string lowercase_word = word;
            transform(lowercase_word.begin(), lowercase_word.end(),
                lowercase_word.begin(),
                ::tolower);

            if (stopwords.find(lowercase_word) == stopwords.end()) {
                word_count[lowercase_word]++;
            }
        });

    ofstream out("frequency.txt");
    for_each(word_count.begin(), word_count.end(),
        [&out](const pair<string, int>& p) {out << p.first << " " << p.second << endl; });

    return 0;
}

