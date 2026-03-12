#include<iostream>
using namespace std;
class Lens{
	public:
		void showlens(){cout<<"The lens exists"<<endl;
		}
	
};
class MemoryCard{
	public:
		void showMemoryCard(){cout<<"The memory Card exists"<<endl;
		}
	
};
class camera{
	Lens *l;
	MemoryCard *m;
	
	public://here &p is the address and we are storing in pointer variable.
		camera(Lens &p):l(&p),m(nullptr){
		}
		void setm(MemoryCard *k){m=k;
		}
	
};

int main(){
	Lens l;
	MemoryCard *m=new MemoryCard;
	camera *c=new camera(l);
	delete c;
	l.showlens();
	m->showMemoryCard();
	delete m;
	
	return 0;
}