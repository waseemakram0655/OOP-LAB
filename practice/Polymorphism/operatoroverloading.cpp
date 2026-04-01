#include<iostream>
using namespace std;


// cpp allows to specify more then one definitions for an operator in the same scope this is operator overloading 
// Almost all built in operators are available for it
// scope resoluition ::, sizeof,terniary?,,.,* they can not be used.

class comp{
  int real,imaginary;
  public:
  comp(int r=0,int i=0):real(r),imaginary(i){}
  void display(){
    cout<<"( "<<real<<" + i"<<imaginary<<")"<<endl;
  }
  comp operator +(comp &b){
  
  comp c;
  c.imaginary=imaginary+b.imaginary;
  c.real=b.real+real;
  return c;
} 
};

int main(){
  comp c1(6,2);
comp c2(2,5);
comp c3;
c3=c1+c2;


c3.display();


return 0;
}


