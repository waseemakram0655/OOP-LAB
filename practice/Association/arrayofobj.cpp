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

int main(){
//Student s[5]("waseem","talha".......);
//In cpp special syntax;
Student s[10]={Student("waseem"),Student("Talha"),Student("Ali"),Student("Ahmed"),Student("Hamid")};


for(int i=5;i<10;i++){
string nme;
  cout<<"Enter namefor student "<<i+1<<endl;
  cin>>nme;
s[i].setter(nme);

}
display(s,10);


  return 0;
}