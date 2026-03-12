//Association is a"Has A" or "work with" relationship
//Independant lifecycles
#include<iostream>
using namespace std;
class student{
  int roll;
  string name;
  public:
  
  student(int n=0,string l=" "):roll(n),name(l){}
void setstname(string n){name=n;}
void setstroll(int n){roll=n;}
int getstroll(){return roll;}
string getstname(){return name;}
void info(teacher*p){ cout<<getstroll()<<" studies from "<<p->gettname()<<endl;}
};

class teacher{
  int sno;
  string name;
  public:
  teacher(int n=0,string l=" "):sno(n),name(l){}
void settname(string n){name=n;}
void settsno(int n){sno=n;}
int gettsno(){return sno;}
string gettname(){return name;}
void school(student *s){
    cout<<"The teacher "<<name<<" teaches "<<s->getstname()<<endl;

  }
};


int main(){
teacher *t=new teacher(25,"Zameer Ahmed");
student *s[10];
for(int i=0;i<10;i++){
   s[i]=new student;
   string name;int n;
  cout<<"Enter name of student "<<i+1<<endl;
  cin>>name;s[i]->setstname(name);
  cout<<"Enter roll no of student "<<i+1<<endl;
  cin>>n;
  s[i]->setstroll(n);
}
for(int i=0;i<10;i++){
s[i]->info(t);

}

  return 0;
}