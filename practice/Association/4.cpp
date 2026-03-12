#include<iostream>
using namespace std;
class Passengers{
  string name;
  public:
  void setname(string n){name=n;}
  string getname(){return name;}
};
class Bus{
Passengers *seat[5]={};
public:
//void set(Passengers p[]){}//
  bool addpassenger(Passengers *p){
  	 for(int i=0;i<5;i++){
  	 	
    
  	if(!seat[i]){seat[i]=p;
  	return true;
	  }
	  
  }return false;
}};


int main(){
  Bus b;
  	string n;
  Passengers *p[6];
  for(int i=0;i<6;i++){
  p[i]=new Passengers;
  	cout<<"Enter passenger "<<i+1<<" name "<<endl;
  	cin>>n;
  	p[i]->setname(n);
  }
   for(int i=0;i<6;i++){
  if(b.addpassenger(p[i])){cout<<"Assigned"<<endl;
  }else {
  cout<<"Bus is full"<<endl;
}
  
}
  

  return 0;
}