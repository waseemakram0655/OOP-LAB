#include<iostream>
using namespace std;
class Driver{
string name;
int LicenseId;
public:
	Driver(string n,int b):name(n),LicenseId(b){
	}
	void show(){
		cout<<"Name : "<<name<<" License ID : "<<LicenseId<<endl;
	}
};
class Bus{
	int BusNo;
	Driver *d=nullptr;
	
	public:
		Bus(int no,Driver *g):BusNo(no),d(g){
		}
};
class Depot{
	Bus *b[1];
	
	public:
  //arrays can not be initialized using initialization list//but the modern way states that other then using () use { }to initialize
		Depot(Bus *l[]):b{l[0]}{}

};
int main(){
	Driver d("Aman",925);
	Bus *b[1];
  b[0]=new Bus(225,&d);
	Depot *t=new Depot(b);
delete b[0];
delete t;
d.show();
  return 0;
}