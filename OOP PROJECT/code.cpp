#include<iostream>
#include<fstream>
using namespace std;
class Liabilities;

class Assets;
double nisab=503529.0;
double goldprice=495000;
double silverprice=9757;
bool valuechecker(int n){
  if(n>=0){return true;}
  else return false;
}
  bool valuechecker(float n){
  if(n>=0){return true;}
  else return false;
}

void show(){cout<<"JazakAllah Khair for using Zaya Zakat."<<endl;
                cout<<"May Allah accept your Zakat and bless you abundantly."<<endl;}
class chatbot{
public:
void menu(){
  
  cout<<"1. Calculate Zakat"<<endl;
    cout<<"2. View History"<<endl;
    cout<<"3. Record Zakat Payment"<<endl;
    cout<<"4. Zakat FAQ"<<endl;
    cout<<"5. Charity Recommendations"<<endl;
    cout<<"6. Exit"<<endl;
    cout<<"\n\nEnter SNo"<<endl;
  
}

};
class Information{
string name;
string email;
string phoneNumber;
int age;
double zakatpayable;
Assets a;
Liabilities l;
zakat z;

public:
friend void setzakat(Information i);
string getname(){return name;}
string getemail(){return email;}
double getzakat(){return zakatpayable;}
void setInformation(){
cout<<"Enter name"<<endl; cin>>name;
cout<<"Enter email"<<endl; cin>>email;
cout<<"Enter phone number"<<endl; cin>>phoneNumber;
cout<<"Enter age"<<endl; cin>>age;
}
void calculatezakat(){
  l.setliabilities();
  a.setassets();
  get_total(a,l,z);
if(z.gettotal()>=nisab){
zakatpayable=z.gettotal()*0.025;
cout<<"The total zakat payable is ="<<zakatpayable<<endl;
}else cout<<"You are not eligible for zakat"<<endl;
}

Information(string n,string e,string p,int a):name(n),email(e),phoneNumber(p),age(a){}
Information(){}



};
class zakat{
  double total;
  public:
  zakat(){
    total=0;
  }
  friend void get_total(Assets a,Liabilities l,zakat z);
  double gettotal(){return total;}
};
class checkEligibility:public Information{

};
//
class Assets{
double gold;
double silver;
double cash;
double stocksValue;
double businessInventory;
double other;
double lent;

public:
friend void get_total(Assets a,Liabilities l,zakat z);
void setassets(){
  char x;
  cout<<"You will be inquired about your assets:\n\n";
  cout<<"Do you have Gold [y/n]"<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<"Enter the amount of gold you have in tola"<<endl;cin>>gold;
  }else gold=0;
  cout<<"Do you have silver [y/n]"<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<"Enter the amount of silver you have in tola"<<endl;cin>>silver;
  }else silver=0;
  cout<<"Do you have cash [y/n]"<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<"Enter the amount of cash you have in pkr"<<endl;cin>>cash;
  }else cash=0;
  cout<<"Do you have business inventory [y/n]"<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<"Enter the value of business inventory you have in pkr"<<endl;cin>>businessInventory;
  }else businessInventory=0;
  cout<<"Do you have shares of stocks  [y/n]"<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<"Enter the value of stocks you have in pkr"<<endl;cin>>stocksValue;
  }else stocksValue=0;
  cout<<"Do you have any other business good zakatable [y/n]"<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<"Enter the value of that good you have in pkr"<<endl;cin>>other;
  }else other=0;
  cout<<"Do you have any other money lent to others which they will pay back [y/n]"<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<"Enter the value of that money you have in pkr"<<endl;cin>>lent;
  }else other=0;
cout<<"\n\n";
}


};
//
class Liabilities{
double loans;
double bills;
double others;

public:
friend void get_total(Assets a,Liabilities l,zakat z);

void setliabilities(){
  
  cout<<"Now You will be inquired about your liabilities\n\n";
  char x;
cout<<"Do you have any loan to pay [y/n]"<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<"Enter the value of loans on you in pkr"<<endl;cin>>loans;
  }else loans=0;
  cout<<"Do you have any bills pending on you [y/n]"<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<"Enter the value of bills on you in pkr"<<endl;cin>>bills;
  }else bills=0;
  cout<<"Do you have any other liability [y/n]"<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<"Enter the value of liabilities on you in pkr"<<endl;cin>>others;
  }else others=0;
cout<<"\n\n";}
double get_liabilities_amount(){
  return (loans+others+bills);
}
};
class FAQ{};
class Identation{};
class Display{};
class Teachings{};
class History{};
class Suggestions{};
class Evidence{};
class History{

  public:
  void save(string name,string email,double zakat){
    ofstream out("history.txt",ios::app);
    if(out.is_open()){
    out<<"Username: "<<name<<" | Email: "<<email<<" |Zakat: "<<zakat<<endl;
    out.close();
    }
  }
    void viewhistory(){
      ifstream in("history.txt");
      cout<<"=======Previous Zakat Records========"<<endl;
      string l;
      if(in.is_open()){
        while(getline(in,l)){
          cout<<l<<endl;
        }in.close();
      }else cout<<"No history found"<<endl;
      cout<<"---------------------------------------"<<endl;
    }
  
};

void get_total(Assets a,Liabilities l,zakat z){
  z.total=((a.gold*goldprice)+(a.silver*silverprice)+a.cash+a.stocksValue+a.businessInventory+a.other+a.lent-l.bills-l.loans-l.others);
}
void setzakat(Information i){
  double p;
  cout<<"Enter the amount you want to pay from your zakat"<<endl;
  cin>>p;
  i.zakatpayable-=p;
}
int main(){
Information client;
client.setInformation();
chatbot clientschatbot;
  History h;
int n=1;
while (n!=6){
clientschatbot.menu();
cin>>n;
switch(n) {
            case 1:
          //Calculate zakat
          client.calculatezakat();
          h.save(client.getname(),client.getemail(),client.getzakat());
           break;
            case 2:
                //view_history
         h.viewhistory();
                break;
            case 3:
            setzakat(client);
            h.save(client.getname(),client.getemail(),client.getzakat());
            
            
                break;
            case 4:
             //   show_faq
                break;
            case 5:
                //show_charity_options
                break;
            case 6:
               break;
               show();
}

}
return 0;}