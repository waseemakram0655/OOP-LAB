
#include<iostream>
using namespace std;

class message{
private:
	string type;
	
	public:
		message(string v):type(v){
		}
		 string toString()const{
			return type;
		}
		

void gettype(){
	cout<<type<<endl;
}
};

class sms:public message{
	string recipientContactNo;
	
	public:
		sms(const string &i,const string &o):recipientContactNo(i),message(o){
		}
		string display(){
			return recipientContactNo;
		}
		void setcontact(){
			string s;
			cout<<"Enter the new contact number:\n"<<endl;
			cin>>s;
			recipientContactNo=s;
		}
		string toString(){
			string v=message::toString()+""+recipientContactNo;
		return v;
		}
	
};


class email:public message{
string sender;
string reciever;
string subject;
public:
	
	email(const string &s,const string &r,const string &su,const string &t):sender(s),reciever(r),subject(su),message(t){
	}
	void setsender(string c){
		sender=c;
	}
	void setreciever(string c){
		reciever=c;
	}
	void setsubject(string c){
		subject=c;
	}
	string setsender(){
		return sender;
	}
	string setreciever(){
		return reciever;
	}
	string setsubject(){
		return subject;
	}
	
	string toString(){
		string g=sender+" "+reciever+" "+subject+" "+message::toString();
	return g;}
bool ContainsKeyword(const message &am, const string &mp){
	//int y=am.length();
	int count=0;
	string t=am.toString();
	int x=t.length();
	int z;
	int f=0;
    string*ptr=new string;
	for(int i=0;i<x;i++)
	{
	if(t[i]==' '){
	f++;}
	
	int j=0;
	for(int i=0;i<x;i++)
	{
	if(t[i]==' '){j++;z=j;
	}
	ptr[j][i]=t[i];
	
    }
for(i=0;i<z;i++){
	if(ptr[i]==mp){return true;
	}else return false;
}
}
void encode(){
	int y=t.length();
	for(int i=0;i<y;i++){
		type[i]++;
	}
}
};

int main(){
	sms s1("03122419436","hello");
	email e1("waseem","Rafay","Education","Hello");
	if(e1.ContainsKeyword(e1,"hello")){cout<<"Present"<<endl;
	}
	e1.encode();
	s1.gettype();
	return 0;
}