#include<iostream>
using namespace std;
class Member{
	public:
	void cheer(){
		cout<<"gogo";
	}
};
class Club{
	Member*present;
	public:
	Member*getpresent(){return present;

	}
	void set(Member *p){present =p;
	}
};

int main(){
	Club c;
	Member m;
	c.set(&m);
c.getpresent()->cheer();
	
	
	Member *getpresent();
	return 0;
}