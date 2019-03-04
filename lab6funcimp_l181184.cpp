#include"lab6header_1184.h"
int student::counter = 0;
student::student()
{
	counter++;
	cout << "default constructor was invoked" << endl;
	id = counter;
	quizcapacity = 3;
	gpa = -1;
	quizscore = nullptr;
	quiztaken = 0;

}
student::~student()
{
	cout << "destructor was invoked for id=" <<id<< endl;
	delete[] quizscore;
}
student::student(int x, float y)
{
	cout << "parametrized construtor was invoked" << endl;	
	counter++;
	id = counter;
	quizcapacity = x;
	gpa = y;
	quizscore = new float[quizcapacity];
	quiztaken = 0;

}
student::student(const student&a)
{
	cout << "copy constructor was invoked for id=" <<id<< endl;
	cout << "copied from id=" << a.id << endl;
	id = a.id;
	quizcapacity = a.quizcapacity;
	gpa = a.gpa;
	quiztaken = a.quiztaken;
	quizscore = new float[a.quizcapacity];
	for (int i = 0; i < quiztaken; i++)
	{
		quizscore[i] = a.quizscore[i];
	}
}
void student::addquizscore(float r)
{
	if (quizscore == nullptr)
	{
		quizscore = new float[quizcapacity];
	}
	if (quiztaken < quizcapacity)
	{
		quizscore[quiztaken] = r;
		quiztaken++;
	}
	else if(quiztaken>=quizcapacity)
	{
		cout << "no space available" << endl;
	}

}
void student::setgpa(float p)
{
	gpa = p;
	cout << "gpa updated" << endl;
}
float student::getgpa() 
{
	float a = gpa;
	return a;
}
void student::print() const
{
	cout << "id=" << id << endl;
	cout << "quiz capacity=" << quizcapacity << endl;
	cout << "quizzes taken=" << quiztaken << endl;
	cout << "gpa=" << gpa << endl;
	for (int i = 0; i < quiztaken; i++)
	{
		cout << "quiz " << i + 1 << "score=" << quizscore[i] << endl;
	}
}
bool student::comparestudent(student a)
{
	if (a.gpa > gpa)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void student::updatescore(float qscore, int qno)
{
	if (qno > quiztaken)
	{
		cout << "not possible" << endl;
	}
	else
	{
		quizscore[qno - 1] = qscore;
		cout << "value updated" << endl;
	}
}
