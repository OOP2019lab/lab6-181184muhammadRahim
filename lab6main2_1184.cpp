#include"lab6header_1184.h"
void printstudentarray(student* ar1)
{
	cout << "************************************************" << endl;
	for (int i = 0; i < 3; i++)
	{
		ar1[i].print();

	}
}
void printstudentarray2(student* ar1,int size)
{
	cout << "************************************************" << endl;
	for (int i = 0; i < size; i++)
	{
		ar1[i].print();

	}
}
void swapobject(student &a, student &b)
{
	student temp(a);
    a=b;
	b = temp;
}

void descendingfunctions(student *arra, int size)
{
	
	float max = arra[0].getgpa();int index = 0;
	float a = 0;
	int size1 = size;
	for (int j = 0; j <size1; j++)
	{
		max = 0, index = 0, a = 0;
		for (int i = 0; i < size; i++)
		{
			a = arra[i].getgpa();
			if (max < a)
			{
				max = a;
				index = i;
			}

		}
		swapobject(arra[index], arra[size-1]);
		size--;
	}

}
student* excludingfunction(student*ar1, int size,int &size2)
{
	cout << "gpa sort:-" << endl;
	int* index = new int[size];
	int counter = 0;
	float b = 0;
	for (int i = 0; i < size; i++)
	{
		b = ar1[i].getgpa();
		if (b > 2.00)
		{
			index[counter] = i;
			counter++;
		}
	}
	student* temp = new student[counter];
	size2 = counter;
	for (int i = 0; i < counter; i++)
	{
		temp[i] = ar1[index[i]];
	}
	delete[] index;
	index = nullptr;
	return temp;
}

int main()
{
	student a(3, 2);
	student b(3, 3.2);
	student c(4, 2.33);
	student studentarray[3] = { a,b,c };
	int ar1[3] = { 1,4,10 };
	int ar2[3] = { 10,4,9 };
	int ar3[3] = { 9,8,7 };
	int ar4[2] = { 2,3 };
	for (int i = 0; i < 3; i++)
	{
		studentarray[0].addquizscore(ar1[i]);
		studentarray[1].addquizscore(ar2[i]);
		studentarray[2].addquizscore(ar3[i]);
	}
	printstudentarray(studentarray);
	int size = 4;
	student* studentarray2 = new student[size];
    student a1(3, 2);
	student b1(3, 3.2);
	student c1(4, 2.33);
	student d1(4, 1.00);
	student s[4] = { a1,b1,c1,d1 };
	for (int i = 0; i < size; i++)
	{
		studentarray2[i]=s[i];
	}
	for (int i = 0; i < size; i++)
	{
		studentarray2[0].addquizscore(ar1[i]);
		studentarray2[1].addquizscore(ar2[i]);
		studentarray2[2].addquizscore(ar3[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		studentarray2[4].addquizscore(ar4[i]);
	}
	printstudentarray2(studentarray2, size);
	student* intelligentstudents; 
	int size2;
	intelligentstudents = excludingfunction(studentarray2, size,size2);
	printstudentarray2(intelligentstudents, size2);
	cout << "original array" << endl;
	printstudentarray2(studentarray2, size);
	cout << "sorted array" << endl;
	descendingfunctions(studentarray2, size);
	printstudentarray2(studentarray2, size);
	system("pause");
}