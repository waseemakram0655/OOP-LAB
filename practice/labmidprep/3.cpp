#include<iostream>
using namespace std;
class vehicle{
  int vehicleid;
  string brand;
  int capacity;

  public:
  vehicle(int i,string h,int j):vehicleid(i),brand(h),capacity(j){}
  void show(){cout<<vehicleid<<" "<<brand<<" "<<capacity<<endl;}
};
class truck:public vehicle{
  float loadcapacity;
  public:
  truck(float r,int i,string h,int c):loadcapacity(r),vehicle(i,h,c){}
  void show1(){show();
    cout<<loadcapacity<<endl;
  }
};
class van:public vehicle{
  int passengercapacity;
  public:
  van(int r,int i,string h,int c):passengercapacity(r),vehicle(i,h,c){}
  void show3(){show();
  cout<<passengercapacity<<endl;}
};
class bike:public vehicle{
  float fuelefficiency;
public:
bike(float r,int i,string h,int c):fuelefficiency(r),vehicle(i,h,c){}
void show4(){show();
  cout<<fuelefficiency<<endl;}
};
class refrigeratedtruck:public truck{
  string temp;
  public:
  refrigeratedtruck(int id,string b,int c,float f,string t):truck(f,id,b,c),temp(t){}
  void show2(){show1();
  cout<<temp<<endl;
  }
};
class driver{
  protected:
  string name;
  string licensetype;
  public:
  driver(string n,string h):name(n),licensetype(h){}
  void show6(){
    cout<<name<<"\n"<<licensetype<<endl;
  }
};
class deliveryagent :virtual public vehicle,public driver{
  public:
  deliveryagent(int i,string g,int h,string n,string j):vehicle(i,g,h),driver(n,j){}
  void final(){
    show6();
    show();
  }
};


int main(){
truck t(2500.0,125,"ISUZU",1000);
deliveryagent d(125,"ISUZU",236,"Ali","Heavy");
d.final();
t.show1();

  return 0;
}