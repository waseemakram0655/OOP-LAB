#include<iostream> 
using namespace std;
class person{
string name;
int age;

public:
	person(string nam=" ",int ag=18):name(nam),age(ag){
	}
	void show(){
		cout<<"Name: "<<name<<endl;
		cout<<"Age: "<<age<<endl;
	}
};
class student:public virtual person{
	int grade;
	string department;
	
	public:
		student(string nam=" ",int ag=18,string dpt=" ",int gd=8):person(nam,ag),department(dpt),grade(gd){
		}
void show1(){
	cout<<"Department: "<<department<<endl;
		cout<<"Grade: "<<grade<<endl;
}
};
class teacher:public virtual person{
	int salary;
	string department;
	
	public:
		teacher(string nam=" ",int ag=18,string dpt=" ",int sc=0):person(nam,ag),department(dpt),salary(sc){
		}
void show2(){
	cout<<"Department: "<<department<<endl;
		cout<<"Salary: "<<salary<<endl;
}
};
class school:public student,public teacher{
	string schoolname;
	public:
		school(string nam=" ",int ag=18,string dpt=" ",int sc=0,string j=" ",int gd=8)
: person(nam,ag), teacher(nam,ag,dpt,sc), student(nam,ag,dpt,gd), schoolname(j)
{
}
//When a base class is virtual, the most derived class must construct it.
//But your school constructor does not call the person constructor.

//So what happens is:

//person is constructed using its default values

//" " for name

//18 for age

//So when show() prints, the name is just a blank string, which looks like it is not printing.
		void showall(){
		person::show();
		cout<<"School Name: "<<schoolname<<endl;
		cout<<"Student"<<endl;
		show1();
		cout<<"Teacher"<<endl;
		show2();
		}};
    int main(){
school s("Waseem",18,"CS",18000,"Gallant",95);

s.showall();

  return 0;
}