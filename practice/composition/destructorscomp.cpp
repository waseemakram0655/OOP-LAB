//. When we call delete, it isn't a single "zap" of memory; it is a two-step process.
//
//Professional Demolition Crew:
//
//The Cleaning (Destructor): First, they go inside and remove the furniture, disconnect the gas, and clear the rooms (this is the destructor).
//
//The Wrecking Ball (Deallocation): Only once the inside is safe and empty do they knock down the walls and return the land to the city (this is freeing the memory).
#include<iostream>
using namespace std;
class Robot{
	string name;
	public:
	Robot(string n):name(n){
	}
	void show(){cout<<"The robot "<<name<<" started working"<<endl;
	}
	~Robot(){cout<<name<<" Scrapped!"<<endl;
	}
};
class InternalGenerator{
	string name;
	
	public:
		InternalGenerator(string n):name(n){
		}
		void show(){cout<<"The generator "<<name<<" started huming"<<endl;
	}
	~InternalGenerator(){cout<<name<<" Powering Down"<<endl;
	}	
};
class MegaFactory{
	InternalGenerator gen;
	Robot *bots[2];
	public:
	MegaFactory(string a,string b,string c):gen(a){
			bots[0]=new Robot(b);
			bots[1]=new Robot(c); 
		
	}
	void work(){
		gen.show();
		bots[0]->show();
		bots[1]->show();
	}
	~MegaFactory(){delete bots[0];
	delete bots[1];
	cout<<"Robots deleted"<<endl;
	}
	
};
int main(){
MegaFactory *m=new MegaFactory("Sogo","robo","john");
m->work();
delete m;

return 0;}