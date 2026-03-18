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
class boy:public person{
  private:
  string name;
  float height;

  public:
   boy(){
     cout<<"Boy constructor called "<<endl;
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
  private:
  int grade;
  string subject;

  public:
student(string name,float height,string gender,int age,int g,string s):subject(s),grade(g),boy(name,height,gender,age){
  cout<<"The constructor of student is called"<<endl;
}
~student(){
  cout<<"The destructor of student is called"<<endl;
}
void show2(){
show();
  cout<<"subject: "<<subject<<endl;
  cout<<"Grade: "<<grade<<endl;
}

};
int main(){
boy b("waseem",5.11,"male",18);
b.show();
b.person::show();
boy v;//Constructor first patent then child.
cout<<"\n\n\n";
student s("Waseem",6,"male",18,13,"OOP");
s.show2();
  return 0;
}