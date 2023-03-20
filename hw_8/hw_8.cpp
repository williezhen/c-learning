#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <numeric>

using namespace std;


bool is_stopword(const std::set<std::string>& stopwords, const std::string& word) {
   return stopwords.count(word) != 0;
}

class WordCounter {
private:
   std::map<std::string, int>& m_word_count;

public:
   WordCounter(std::map<std::string, int>& word_count)
       : m_word_count(word_count) {}

   void operator()(const std::string& word) {
       ifstream stopwords_file("./txt/stopwords.txt");
       set<string> stopwords;
       copy(istream_iterator<string>(stopwords_file), istream_iterator<string>(), inserter(stopwords, stopwords.end()));

       std::string lowercase_word(word);
       std::transform(lowercase_word.begin(), lowercase_word.end(), lowercase_word.begin(), ::tolower);

       if (!is_stopword(stopwords, lowercase_word)) {
           m_word_count[lowercase_word]++;
       }
   }
};

int main() {
	ifstream stopwords_file("./txt/stopwords.txt");
	set<string> stopwords;
	copy(istream_iterator<string>(stopwords_file), istream_iterator<string>(), inserter(stopwords, stopwords.end()));

	ifstream doc_context("./txt/sample_doc.txt");
	map<string, int> word_count;
   for_each(istream_iterator<string>(doc_context),
       istream_iterator<string>(),
			 //[stopwords, word_count](string word){
			 //std::string lowercase_word(word);
       //std::transform(lowercase_word.begin(), lowercase_word.end(), lowercase_word.begin(), ::tolower);
		 	//if (!is_stopword(stopwords, lowercase_word)) {
			// 		word_count[lowercase_word]++;
			// }
		//});
       WordCounter(word_count));


   ofstream output("frequency.txt");
   for_each(word_count.begin(), word_count.end(),
       [&output](const pair<string, int>& p) {
           output << p.first << " " << p.second << endl;
       });
   return 0;
}



void error(string msg) {
	cout << "Error: " << msg << endl;
}

class Student {
	string first_name;
	string last_name;
	vector<int> quiz;
	vector<int> hw;
	double quiz_ave;
	double hw_ave;
	double final_score;
	int course_score;
	string course_grade;

public:
	void compute_grade() {
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

		if (hw.size() == 0) {
			hw_ave = 0;
		}
		else {
			hw_ave = accumulate(hw.begin(), hw.end(), 0) / hw.size();
		}

		course_score = round(quiz_ave * 0.4 + hw_ave * 0.3 + final_score * 0.3);

		//course_grade
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

	void read(istream& in) {
		string label;
		string line;

		while (getline(in, line)) {

			istringstream iss(line);
			iss >> label;

			//cout << label << endl;

			if (label == "Name") {
				iss >> first_name >> last_name;
				if (first_name.size() == 0) {
					cout << "hello" << endl;
					first_name = "Missing";
					last_name = "Name";
				}
				//cout << "test : " << first_name << endl;
			}
			else if(label == "Quiz") {
				int grade;
				while (iss >> grade) {
					quiz.push_back(grade);
				}
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
	}
	void print(ostream& out) const {
		out << "Name: " << first_name << " " << last_name << endl;
		out << "HW Ave: " << hw_ave << endl;
		out << "QZ Ave: " << quiz_ave << endl;
		out << "Final: " << final_score << endl;
		out << "Grade: " << course_grade << endl;

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
	vector<Student> students;

public:
	void compute_grades() {
		for (auto& student : students)
			student.compute_grade();
	}

	void sort() {
		std::sort(students.begin(), students.end(), [](Student& a, Student& b) {
			return a.get_last_name() < b.get_last_name() || (a.get_last_name() == b.get_last_name() && a.get_first_name() < b.get_first_name());
			});
	}
	void print(ostream& out) const {
		for (const auto& student : students) {
			out << student << endl;
		}
	}
	void read(istream& in) {
		string line;
		while (in) {
			int flag = 0;
			Student student;
			while (getline(in, line)) {
				if (line.empty()) {
					break;
				}
				flag = 1;
				istringstream iss(line);
				iss >> student;
			}
			if(flag == 1)
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
