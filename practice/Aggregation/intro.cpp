// Aggregation is a unidirectional in which one class owns other like a department owns a teacher or teachers
//The lifetime of owned class doesnot depends upon the owner but the owner depends upon the owned
//Waseeem has address that means address is owned by waseem, department has a teacher
//"Has-A" or "Part-of"
//The "Whole" (the container) and the "Part" (the contained) can exist without each other.
//
//both objects are independent
//
#include<iostream>
using namespace std;
class professor{
  public:
  void show(){cout<<"The professor is still alive"<<endl;}
};
class department{
  professor *p;
public:
void set(professor *o){p=o;}
};

int main(){
professor *p=new professor;
department *d=new department;
d->set(p);
delete d;
p->show();
delete p;
p=nullptr;
  return 0;
}