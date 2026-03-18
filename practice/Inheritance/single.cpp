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
int main(){
boy b("waseem",5.11,"male",18);
b.show();
b.person::show();
boy v;//Constructor first patent then child.

  return 0;
}