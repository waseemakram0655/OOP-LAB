//There are two methods one is by passing whole array once and other is by passing one by one which is suitable in DMA


#include<iostream>
using namespace std;
//Forward declaration is necessary as one class must know that other exists
class teacher;
class student{
  int roll;
  teacher *t;
  string name;
  public:
  void setteacher(teacher *y){t=y;}
  void info(){
    cout<<"The teacher of the student "<<name<<" is "<<t->gettname()<<endl;

  }
  student(int n=0,string l=" "):roll(n),name(l){}
void setstname(string n){name=n;}
void setstroll(int n){roll=n;}
int getstroll(){return roll;}
string getstname(){return name;}
};

class teacher{
  int sno;
  string name;
  student *s[10];
  public:
  teacher(int n=0,string l=" "):sno(n),name(l){}
void settname(string n){name=n;}
void settsno(int n){sno=n;}
int gettsno(){return sno;}
string gettname(){return name;}
//we can define and declare outside the body of class to not to get error that is school and info
void school(){
  for(int i=0;i<10;i++){
    cout<<"The teacher "<<name<<" teaches "<<s[i]->getstname()<<endl;

  }}
  void setstudent(student *so[]){for(int i=0;i<10;i++){s[i]=so[i];}}
};

int main(){
teacher *t=new teacher(25,"Zameer Ahmed");
student *s[10];
for(int i=0;i<10;i++){
  s[i]=new student(i," ");
  s[i]->setteacher(t);
}
t->setstudent(s);

  return 0;
}