// hw_8_inclass.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


#define QUIZ_PROPOTION 0.4
#define HW_PROPOTION 0.3
#define FINAL_PROPOTION 0.3


//int main() {
//    // Open input file
//    std::ifstream input_file("./txt/rand_numbers.txt");
//    if (!input_file.is_open()) {
//        std::cerr << "Error: could not open input file\n";
//        return 1;
//    }
//
//    // Read numbers into a vector using an iterator and back inserter
//    std::vector<int> numbers;
//    std::copy(std::istream_iterator<int>(input_file), std::istream_iterator<int>(), std::back_inserter(numbers));
//
//    // Sort the vector
//    std::sort(numbers.begin(), numbers.end());
//
//    // Open output files
//    std::ofstream odds_file("odds.txt");
//    if (!odds_file.is_open()) {
//        std::cerr << "Error: could not open odds file\n";
//        return 1;
//    }
//    std::ofstream evens_file("evens.txt");
//    if (!evens_file.is_open()) {
//        std::cerr << "Error: could not open evens file\n";
//        return 1;
//    }
//
//    // Write odd and even numbers to their respective files using copy_if and a lambda
//    std::copy_if(numbers.begin(), numbers.end(), std::ostream_iterator<int>(odds_file, " "), [](int n) { return n % 2 != 0; });
//    odds_file << std::endl;
//    std::copy_if(numbers.begin(), numbers.end(), std::ostream_iterator<int>(evens_file, "\n"), [](int n) { return n % 2 == 0; });
//
//    // Close files
//    input_file.close();
//    odds_file.close();
//    evens_file.close();
//
//    return 0;
//}

//bool is_stopwords(const set<string>& stopwords, string& word) {
//    return (stopwords.count(word) != 0);
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
//        if (!is_stopwords(stopwords, lowercase_word)) {
//            m_word_count[lowercase_word]++;
//        }
//    }
//};
//
//int main()
//{
//    ifstream stopwords_file("./txt/stopwords.txt");
//    set<string> up_stopwords;
//    copy(istream_iterator<string>(stopwords_file), istream_iterator<string>(), inserter(up_stopwords, up_stopwords.end()));
//    set<string> lower_stopwords;
//    transform(up_stopwords.begin(), up_stopwords.end(), inserter(lower_stopwords, lower_stopwords.end()),
//        [](string s) {
//            transform(s.begin(), s.end(), s.begin(), tolower);
//                //[](unsigned char c) { return tolower(c); });
//            return s;
//        });
//    //tolower
//
//    ifstream doc_context("./txt/sample_doc.txt");
//    map<string, int> word_count;
//    for_each(istream_iterator<string>(doc_context),//*iter
//        istream_iterator<string>(),
//        WordCounter(word_count));
//        //[&word_count, stopwords](string word) {
//        //    string lowercase_word(word);
//        //    transform(lowercase_word.begin(), lowercase_word.end(), lowercase_word.begin(), tolower);//tolower
//
//        //    if (!is_stopwords(stopwords, lowercase_word)) {
//        //        word_count[lowercase_word]++;
//        //    }
//        //    //word = coMpuTer
//        //});
//
//    ofstream output("frequency.txt");
//    for_each(word_count.begin(), word_count.end(),
//        [&output](const pair<string, int>& p) {
//            output << p.first << " " << p.second << endl;
//        });
//
//    return 0;
//
//    //for(int i = doc_context_begin; i!=doc_context.end; i++){
//    // *i
//    //
//    //for_each -> tolower
//    //for_each -> count
//}


void error(string msg) {
	cout << "Error: " << msg << endl;
}

class Student {
private:
	string first_name; // = ?
	string last_name;
	vector<int> quiz;//size = 0
	vector<int> hw;
	double quiz_ave;
	double hw_ave;
	double final_score; // = 0
	int course_score;
	string course_grade;

//protect

public:
	
	Student() {
		first_name = "Missing";
		last_name = "Name";
	}

	void compute_grade() {
		if (hw.size() == 0) {
			hw_ave = 0;
		}
		else {
			hw_ave = accumulate(hw.begin(), hw.end(), 0) / double(hw.size());
		}

		if (quiz.size() == 0) {
			quiz_ave = 0;
		}
		else if (quiz.size() == 1) {
			quiz_ave = quiz[0];
		}
		else {
			int min_quiz_grade = *min_element(quiz.begin(), quiz.end());
			quiz_ave = (accumulate(quiz.begin(), quiz.end(), 0) - min_quiz_grade) / (quiz.size() - 1.0);
		}

		course_score = round(quiz_ave * QUIZ_PROPOTION + hw_ave * HW_PROPOTION + final_score * FINAL_PROPOTION);

		//switch_case
		if (course_score >= 97) {
			course_grade = "A+";
		}
		else if (course_score >= 93) {
			course_grade = "A";
		}
		else if (course_score >= 90) {
			course_grade = "A-";
		}
		else if (course_score >= 87) {
			course_grade = "B+";
		}
		else if (course_score >= 83) {
			course_grade = "B";
		}
		else if (course_score >= 80) {
			course_grade = "B-";
		}
		else if (course_score >= 77) {
			course_grade = "C+";
		}
		else if (course_score >= 73) {
			course_grade = "C";
		}
		else if (course_score >= 70) {
			course_grade = "C-";
		}
		else if (course_score >= 67) {
			course_grade = "D+";
		}
		else if (course_score >= 63) {
			course_grade = "D";
		}
		else if (course_score >= 60) {
			course_grade = "D-";
		}
		else {
			course_grade = "F";
		}

	}


	void read(istream& iss) {
		string label;
		string line;


		iss >> label;

		if (label == "Name") {
			iss >> first_name >> last_name;
			if (first_name.empty()) {
				first_name = "Missing";
				last_name = "Name";
			}
		}
		else if (label == "Quiz") {
			std::for_each(std::istream_iterator<int>(iss), std::istream_iterator<int>(), [this](int grade) {
					quiz.push_back(grade);
				});
			//while (iss >> grade) {
			//	quiz.push_back(grade);
			//}
		}
		else if (label == "HW") {
			int grade;
			while (iss >> grade) {
				hw.push_back(grade);
			}
		}
		else if (label == "Final") {
			iss >> final_score;
		}
		
	}

	void print(ostream& out) const {
		out << "Name\t" << first_name << " " << last_name << endl;
		out << "HW Ave:\t" << hw_ave << endl;
		out << "QZ Ave:\t" << quiz_ave << endl;
		out << "Final:\t" << final_score << endl;
		out << "Total:\t" << course_score << endl;
		out << "Grade:\t" << course_grade << endl;
		//out << endl;
	}

	string get_first_name() {
		return first_name;
	}

	string get_last_name() {
		return last_name;
	}

	friend ostream& operator << (ostream& out, const Student& student) {
		student.print(out);
		return out;
	}

	friend istream& operator >>(istream& in, Student& student) {
		student.read(in);
		return in;
	}
};

class GradeBook {
	vector<Student> students;//[0]

public:
	void compute_grades() {
		for (auto& student : students)
			student.compute_grade();
		//for (auto i = students.begin(); i != students.end(); i++) {
		//	i->compute_grade();
		//}
	}

	void sort() {
		//sort(begin, end, (a, b))
		//.sort(func)
		std::sort(students.begin(), students.end(),
			[](Student& a, Student& b) {
				return a.get_last_name() < b.get_last_name()
					|| (a.get_last_name() == b.get_last_name() and a.get_first_name() < b.get_first_name());
			});
	}

	void print(ostream& out) const {
		for (auto student : students) {
			out << student << endl;
		}
	}

	void read(istream& in) {
		string line;
		while (in) {//end of file EOF
			Student student;
			int flag = 0;
			while (getline(in, line)) {
				if (line.empty()) {
					break;
				}
				flag = 1;
				istringstream iss(line);
				iss >> student;
			}
			if(flag==1)
				students.push_back(student);
		}
	}

	friend ostream& operator << (ostream& out, const GradeBook& gb) {
		gb.print(out);
		return out;
	}

	friend istream& operator >>(istream& in, GradeBook& gb) {
		gb.read(in);
		return in;
	}
};

int main() {
	ifstream in("./txt/gradebook.txt");
	GradeBook gb;
	in >> gb;
	gb.sort();
	gb.compute_grades();
	ofstream out("course_grades.txt");
	out << gb;
}

