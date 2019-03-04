#include<iostream>
using namespace std;
class student
{
private:
	static int counter;
	int id;
	float *quizscore;
	int quizcapacity;
	int quiztaken;
	float gpa;

public:
	student::student();//default constructor
	student(int a, float b);//parametrized constructor
	student::~student();//destructor
	student(const student&a);//copy function
	void addquizscore(float r);//add score of quiz if space available in array
	void setgpa(float p);//set value of gpa taken from user to private variable of class student
	float getgpa();//get value from private variable gpa
	void print() const;//print information of specified object
	bool comparestudent(student a);//compare two student on basis of gpa
	void updatescore(float qscore, int qno);//update score of a quiz on specified index


};




