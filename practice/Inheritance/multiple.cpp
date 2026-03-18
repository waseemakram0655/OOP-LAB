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
class student:public virtual person,public boy{
	//we can also use class student:public virtual person,public boy{ as the boy is also inheriting from person virtually
  private:
  int grade;
  string subject;

  public:
student(string name,float height,string gender,int age,int g,string s):person(gender,age),subject(s),grade(g),boy(name,height){
  cout<<"The constructor of student is called"<<endl;
}
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
int main(){
boy b("waseem",5.11,"male",18);
b.show();
b.person::show();
//Constructor first patent then child.
cout<<"\n\n\n";
student s("Waseem",6,"male",18,13,"OOP");
s.show2();
  return 0;}
//In virtual inheritance, the most derived class (the "youngest" child) is the only one allowed to initialize the virtual base.
//
//Even though boy has a constructor that calls person, C++ ignores it when you are building a student.
//
//It uses the person(gender, age) call directly from the student constructor. This is why we don't see the "Person constructor called" message twice!s