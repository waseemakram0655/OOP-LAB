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
void display(Student **s,int n){
  for(int i=0;i<n;i++){
s[i]->getter();}
}

int main(){
Student *s[10];
for(int i=0;i<10;i++){
  s[i]=new Student(" ");
}


for(int i=5;i<10;i++){
string nme;
  cout<<"Enter namefor student "<<i+1<<endl;
  cin>>nme;
s[i]->setter(nme);

}
display(s,10);
for(int i=0;i<10;i++){delete s[i];}
//As it is an array of pointers not DMA so we must have to delete each new assign to each pointer
//If you used new, you must use delete.

//If you used new[] (to create a primitive array), you must use delete[]

  return 0;
}