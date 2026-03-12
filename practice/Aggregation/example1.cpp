#include<iostream>
using namespace std;


class Captain{
	public:
		void showc(){
			cout<<"Oh captain my captain"<<endl;
		}
};
class sponsor{
	string name;
	public:
		string getname(){return name;
		}
		void setname(const string n){name=n;
		}
		void shows(){
			cout<<"Oh sponsor my sponsor"<<endl;
		}
};
class Team{
Captain *c=nullptr;
sponsor *s=nullptr;

public:
Team(Captain &cg):c(&cg){
}
void setter(sponsor *cd){
	s=cd;
}
void cond(){
if(s){
	cout<<s->getname()<<endl;
}else cout<<"none"<<endl;}
};
int main(){
	Captain c;
	sponsor s;
	Team t(c);
	s.setname("cola");
	t.cond();
	t.setter(&s);t.cond();
	
	
	return 0;
}