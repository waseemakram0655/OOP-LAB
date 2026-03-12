#include<iostream>
using namespace std;
class Car{

  public:
void move(){cout<<"The car is moving"<<endl;}
};
class Driver{
  Car *currentvehicle;

  public:
  void drive(){currentvehicle->move();}
  void setter(Car *c){currentvehicle=c;}
};


int main(){
Driver d1;
Car c1;
d1.setter(&c1);
d1.drive();

  return 0;
}