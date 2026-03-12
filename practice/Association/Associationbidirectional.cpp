//Association is a"Has A" or "work with" relationship
//Independant lifecycles
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
  student *s;
  public:
  teacher(int n=0,string l=" "):sno(n),name(l){}
void settname(string n){name=n;}
void settsno(int n){sno=n;}
int gettsno(){return sno;}
string gettname(){return name;}
void school(){
    cout<<"The teacher "<<name<<" teaches "<<s->getstname()<<endl;

  }
  void setstudent(student *so){s=so;}
};

int main(){
teacher *t=new teacher(25,"Zameer Ahmed");
student *s[10];
for(int i=0;i<10;i++){
   s[i]=new student;
   s[i]->setteacher(t);
   string name;int n;
  cout<<"Enter name of student "<<i+1<<endl;
  cin>>name;s[i]->setstname(name);
  cout<<"Enter roll no of student "<<i+1<<endl;
  cin>>n;
  s[i]->setstroll(n);
}
for(int i=0;i<10;i++){
s[i]->info();

}
t->setstudent(s[8]);
t->school();
delete t;
for(int i=0;i<10;i++){
  delete s[i];
}

  return 0;
}