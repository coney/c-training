#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <time.h>

std::string generateRandomString(int n);
std::string toString(int n);

class Student
{
public:
	Student(std::string name, int age, std::string address, int id)
		: name_(name), age_(age), address_(address), id_(id){}

	Student(const Student& stu) { 
		name_ = stu.name_;  age_ = stu.age_;
		address_ = stu.address_; id_ = stu.id_;
	}

	static Student generateStucent()
	{
		return Student(std::string("name_") + generateRandomString(3),
			rand() % 5 + 10,
			std::string("address_") + generateRandomString(8),
			100000 + rand() % 1000);
	}

private:
	std::string name_;
	int	age_;
	std::string address_;
	int id_;
};


int main()
{
	std::vector<Student> students;
	for (int i = 0; i < 100; ++ i )
	{
		students.push_back(Student::generateStucent());
	}

	return 0;
}

std::string generateRandomString(int n)
{
	srand((unsigned int)time(NULL));

	std::string alphas = "abcdefghijklmnopqrstuvwxyz";
	std::random_shuffle(alphas.begin(), alphas.end());
	return alphas.substr(0, n);
}

std::string toString(int n)
{
	std::stringstream ss;
	ss << n;
	return ss.str();
}
