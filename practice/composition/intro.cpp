//Strong form of aggregation
//whole(owner)-part relationship
//Life time of part depends upon the lifetime of whole or death relationship
//Has a relationship
//In destructor order objects destroy opposite to how they were created that is first parent destroys then objects in reverse order
//hink of a Bus that contains an Engine, and the Engine contains a SparkPlug.

//Construction: SparkPlug → Engine → Bus.

//Destruction: Bus → Engine → SparkPlug.
//The last thing built is the first thing removed.
//The SparkPlug was the first thing put onto the stack memory.

//Therefore, it must be the last thing taken off the stack.
#include<iostream>
using namespace std;
class SecurityCamera{
	string area;
	public:
		SecurityCamera(string n):area(n){
		}
		void get(){cout<<"The sucurity camera is activated in the area "<<area<<endl;
		}
		~SecurityCamera(){cout<<"Security camera destroyed placed in "<<area<<endl;
		}
	
};
class SmartHome{
	SecurityCamera cams[2];

public:
	SmartHome(string a,string b):cams{
	SecurityCamera(a),SecurityCamera(b)
	}{}
	void activatesecurity(){
		for(int i=0;i<2;i++){
			cams[i].get();
		}
		
	}
	~SmartHome(){
		cout<<"Smart Home destroyed"<<endl;
	}
};
int main(){
SmartHome h("Entrance","Exit");
h.activatesecurity();
  return 0;
}