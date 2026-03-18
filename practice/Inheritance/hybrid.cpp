#include<iostream> 
using namespace std;

class person{
  protected:
  string gender;
  int age;
  public:
  person(){}
  void show(){cout<<"Alhamdulillah"<<endl;}
  person(string gender,int age){
    this->gender=gender;
    this->age=age;
    cout<<"Person constructor called "<<endl;
  }
  ~person(){cout<<"Person destructor called"<<endl;}
};
class boy:public virtual person{
  private:
  string name;
  float height;

  public:
   boy(string name,float height){
     cout<<"Boy constructor called "<<endl;
    
    this->height=height;
    this->name=name;
    //this->gender=gende
   }// as i have used initialization list
  boy(string name,float height,string gender,int age):person(gender,age){
    this->height=height;
    this->name=name;
    //this->gender=gender;
    //this->age=age;
  }
  void show(){
    cout<<"name: "<<name<<endl;
    cout<<"gender: "<<gender<<endl;
    cout<<"age: "<<age<<endl;
    cout<<"height: "<<height<<endl;
  }
  ~boy(){cout<<"Boy destructor called"<<endl;}
};
class student:public boy{
	//we can also use class student:public virtual person,public boy{ as the boy is also inheriting from person virtually
  private:
  int grade;
  string subject;

  public:
  	
student(string name,float height,string gender,int age,int g,string s):person(gender,age),subject(s),grade(g),boy(name,height){
  cout<<"The constructor of student is called"<<endl;}
//
//student(string s,int g):grade(g),subject(s){
//cout<<"The constructor of student is called"<<endl;
//}
~student(){
  cout<<"The destructor of student is called"<<endl;
}
void show2(){
//person::show();
boy::show();
cout<<"Gender: "<<gender<<endl;
  cout<<"subject: "<<subject<<endl;
  cout<<"Grade: "<<grade<<endl;
  cout<<"Age: "<<age<<endl;
}

};
class cr:public student{
	int points;
	int rollno;
	public:
		void display(){
			show2();
			cout<<"Points: "<<points<<endl;
			cout<<"Roll Number: "<<rollno<<endl;
		}
		cr(string name,float height,string gender,int age,int g,string s,int p,int r):points(p),rollno(r),student(name,height,gender,age,g,s){
  cout<<"The constructor of CR is called"<<endl;
}
~cr(){
  cout<<"The destructor of CR is called"<<endl;
}

};
int main(){
	cr s("Waseem",6,"male",18,13,"OOP",200,45);
s.display();
s.person::show();
  return 0;}
  //The default constructor is called for person so garbage value is stored in it 
  //call to person(gender,age) is ignored, because person is virtually the cr constructor can initialize person.
  //The virtual base class is constructed only once by the most derived class.