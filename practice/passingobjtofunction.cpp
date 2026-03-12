#include<iostream>
using namespace std;
class Student{
  string name;
  public:
  Student(string n=" "):name(n){}
  void setter(string n){name=n;}
  void getter(){cout<<name<<endl;}
};
//void display(Student S[],int n){
void display(Student *s,int n){
  for(int i=0;i<n;i++){
s[i].getter();}
}
//We can use void display1(Student s)  This is pass by value.
void display1(Student &s){
  s.getter();
}

int main(){
Student *s=new Student[5]{Student("Waseem"),Student("Talha"),Student("Taha"),Student("Hussain"),Student("Ali")};
display(s,5);

for(int i=0;i<5;i++){
string nme;
  cout<<"Enter namefor student "<<i+1<<endl;
  cin>>nme;
s[i].setter(nme);

}
display(s,5);//passing of object pointer to function
delete[] s;
Student n("Waseem");
display1(n);

  return 0;
}