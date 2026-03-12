#include<iostream>
using namespace std;
class Doctor;
class Patient{
  Doctor *d;

  public:
  void seter(Doctor *d){this->d=d;}
};
class Doctor{
  Patient *p;
  public:
  void set(Patient *o){p=o;}

};

int main(){
Doctor *d=new Doctor;
Patient *p=new Patient;
d->set(p);
p->seter(d);
delete p;
delete d;
  return 0;
}