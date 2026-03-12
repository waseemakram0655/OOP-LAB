#include<iostream>
using namespace std;
class Cpu{
	//need a clockspeed
	int clockspeed;
	public:
		Cpu(int n):clockspeed(n){
		cout<<"Cpu built"<<endl;
		}
		~Cpu(){cout<<"Cpu destroyed"<<endl;
		}
};
class MotherBoard{
	Cpu c;
	public:
		MotherBoard(int n):c(n){
		cout<<"Motherboard built"<<endl;
		}
		~MotherBoard(){cout<<"MotherBoard destroyed"<<endl;
		}
};
class Computer{
	MotherBoard m;
public:
	Computer(int n):m(n){
		cout<<"Computer Built"<<endl;
	}
	~Computer(){cout<<"Computer Destroyed"<<endl;
	}
};
int main(){
Computer c(102);

return 0;}