#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
class spacing;
class Liabilities;
class zakat;
class Assets;
class spacing{
  string text;
  int size=80;

  public:
  spacing(string t):text(t){}

  friend ostream& operator <<(ostream& out,const spacing &a);
};
ostream& operator <<(ostream& out,const spacing &a){
int pad=(a.size-a.text.length())/2;
for(int i=0;i<pad;i++){out<<" ";}
out<<a.text;
return out;
}
void print_separator();
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

void show(){cout<<spacing("JazakAllah Khair for using Zaya Zakat.")<<endl;
                cout<<spacing("May Allah accept your Zakat and bless you abundantly.")<<endl;}




                class chatbot{
public:
void intro(){
  print_separator();
  
  cout<<"===========================================Welcome to Zaya Zakat======================"<<endl;
  print_separator();
  
  cout<<spacing("You will be inquired by a series of questions inorder to maintain authenticity")<<endl;
print_separator();
  cout<<"========================In the name of Allah who is the most gracious and merciful======================="<<endl;
  print_separator();
}
void menu(){
  
  cout<<spacing("1. Calculate Zakat")<<endl;
    cout<<spacing("2. View History")<<endl;
    cout<<spacing("3. Pay Zakat")<<endl;
    cout<<spacing("4. Zakat FAQ")<<endl;
    cout<<spacing("5. Charity Recommendations")<<endl;
    cout<<spacing("6. Exit")<<endl;
    cout<<spacing("\n\nEnter SNo")<<endl;
  
}

};
class Assets{
double gold=0;
double silver=0;
double cash=0;
double stocksValue=0;
double businessInventory=0;
double other=0;
double lent=0;

public:
friend void get_total(Assets a,Liabilities l,zakat &z);
void setassets(){
  char x;
  cout<<spacing("You will be inquired about your assets:\n\n");
  cout<<spacing("Kindly Enter the assets on which one year has been passee\n\n");
  cout<<spacing("Do you have Gold [y/n]")<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<spacing("Enter the amount of gold you have in tola")<<endl;cin>>gold;
  }else gold=0;
  cout<<spacing("Do you have silver [y/n]")<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<spacing("Enter the amount of silver you have in tola")<<endl;cin>>silver;
  }else silver=0;
  cout<<spacing("Do you have cash [y/n]")<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<spacing("Enter the amount of cash you have in pkr")<<endl;cin>>cash;
  }else cash=0;
  cout<<spacing("Do you have business inventory [y/n]")<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<spacing("Enter the value of business inventory you have in pkr")<<endl;cin>>businessInventory;
  }else businessInventory=0;
  cout<<spacing("Do you have shares of stocks  [y/n]")<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<spacing("Enter the value of stocks you have in pkr")<<endl;cin>>stocksValue;
  }else stocksValue=0;
  cout<<spacing("Do you have any other business good zakatable [y/n]")<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<spacing("Enter the value of that good you have in pkr")<<endl;cin>>other;
  }else other=0;
  cout<<spacing("Do you have any other money lent to others which they will pay back [y/n]")<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<spacing("Enter the value of that money you have in pkr")<<endl;cin>>lent;
  }else lent=0;
cout<<"\n\n";
}


};
//
class zakat{
  double total;
  public:
  zakat(){
    total=0;
  }
  friend void get_total(Assets a,Liabilities l,zakat &z);
  double gettotal(){return total;}
};

//
class Liabilities{
double loans=0;
double bills=0;
double others=0;

public:
Liabilities(){}
friend void get_total(Assets a,Liabilities l,zakat &z);

void setliabilities(){
  
  cout<<spacing("Now You will be inquired about your liabilities\n\n");
  char x;
cout<<spacing("Do you have any loan to pay [y/n]")<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<spacing("Enter the value of loans on you in pkr")<<endl;cin>>loans;
  }else loans=0;
  cout<<spacing("Do you have any bills pending on you [y/n]")<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<spacing("Enter the value of bills on you in pkr")<<endl;cin>>bills;
  }else bills=0;
  cout<<spacing("Do you have any other liability [y/n]")<<endl;cin>>x;
  if(x=='y'||x=='Y'){
    cout<<spacing("Enter the value of liabilities on you in pkr")<<endl;cin>>others;
  }else others=0;
cout<<"\n\n";}
double get_liabilities_amount(){
  return (loans+others+bills);
}
};
//
class Information{
string name;
string email;
string phoneNumber;
int age;
double zakatpayable=0;
Assets a;
Liabilities l;
zakat z;

public:
Information(){}
friend void setzakat(Information &i,double p);
string getname(){return name;}
string getemail(){return email;}
double getzakat(){return zakatpayable;}
void setInformation(){
cout<<spacing("Enter name")<<endl; getline(cin,name);
cout<<spacing("Enter email")<<endl; cin>>email;
cout<<spacing("Enter phone number")<<endl; cin>>phoneNumber;
cout<<spacing("Enter age")<<endl; cin>>age;
}
void calculatezakat(){
  l.setliabilities();
  a.setassets();
  get_total(a,l,z);
if(z.gettotal()>=nisab){
zakatpayable=z.gettotal()*0.025;
cout<<spacing("The total zakat payable is =")<<zakatpayable<<endl;
}else {cout<<spacing("You are not eligible for zakat")<<endl;
  zakatpayable=0;
}}

Information(string n,string e,string p ,int a,double x):zakatpayable(x),name(n),email(e),phoneNumber(p),age(a){}
void displayRandomHadith() {
    string ahadith[] = {
        "\"The best of you are those who learn the Quran and teach it.\" (Bukhari)",
        "\"Charity does not decrease wealth.\" (Muslim)",
        "\"Save yourself from hellfire even by giving half a date-fruit in charity.\" (Bukhari)",
        "\"Every act of goodness is charity.\" (Muslim)",
        "\"The upper hand is better than the lower hand (the one that gives is better than the one that takes).\" (Bukhari)"
    };

   
   int t= sizeof(ahadith) / sizeof(ahadith[0]);
    
    
    int index = rand() % t;
print_separator();
    cout <<spacing( "\n[Hadith of the Moment]" )<< endl;
    cout << ahadith[index] <<"\n"<< endl;
  print_separator();}



};

//

//


class History{

  public:
  void savepayment(string name,string email,double p,double zakat){
    ofstream out("history.txt",ios::app);
    if(out.is_open()){
      out<<"Username: "<<name<<" | Email: "<<email<<" |Zakat Paid: "<<p<<" | Pending Zakat: "<<zakat<<endl;
    }
  }
  void save(string name,string email,double zakat){
    ofstream out("history.txt",ios::app);
    if(out.is_open()){
    out<<"Username: "<<name<<" | Email: "<<email<<" |Zakat: "<<zakat<<endl;
    out.close();
    }
  }
    void viewhistory(){
      ifstream in("history.txt");
      cout<<spacing("=======Previous Zakat Records========")<<endl;
      string l;
      if(in.is_open()){
        while(getline(in,l)){
          cout<<l<<endl;
        }in.close();
      }else cout<<spacing("No history found")<<endl;
      cout<<spacing("---------------------------------------")<<endl;
    }
  
};
class support{
public:
virtual void show()=0;
};
class Suggestions:public support{
  
  public:
  void show()override{
    print_separator();
cout << spacing("===== CHARITY RECOMMENDATIONS =====") << endl;
        cout << spacing("1. Edhi Foundation (Welfare)") << endl;
        cout << spacing("2. Indus Hospital (Healthcare)") << endl;
        cout << spacing("3. Saylani Welfare Trust (Food/Education)" )<< endl;
        cout << spacing("4. IMCHF" )<< endl;
        cout <<spacing( "===================================\n") << endl;

    print_separator();
  }
  
    
};

class FAQ:public support{


  public:
  void show()override{
  cout<<spacing("=============ZAKAT FAQ=============")<<endl;
    print_separator();
    printf("\n\n");
    
    cout<<spacing("Q: What is Zakat?")<<endl;
   cout<<spacing("A: Zakat is obligatory charity - 2.5%% of wealth held for one year.");
    cout<<"\n\n";
    
    cout<<spacing("Q: Who must pay Zakat?\n");
    cout<<spacing("A: Muslims whose wealth exceeds Nisab for one lunar year.")<<endl;
    cout<<"\n\n";
    
    cout<<spacing("Q: What is Nisab?");
    cout<<"\n";
    cout<<spacing("A: The minimum threshold - equivalent to 87.48g gold or 612.36g silver.");
    cout<<"\n\n";
    
    cout<<spacing("Q: What wealth is Zakatable?");
    cout<<"\n";
    cout<<spacing("A: Cash, gold, silver, savings, business assets, money owed to you.");
    cout<<"\n\n";
    
    cout<<spacing("Q: What about real estate/property?\n");
    cout<<spacing("A: Personal residence is exempt. Rental/investment property is Zakatable.\n\n");
    
    cout<<spacing("Q: What about vehicles?\n");
    cout<<spacing("A: Personal use vehicles are exempt. Commercial vehicles are Zakatable.\n\n");
    
    cout<<spacing("Q: Can I deduct debts?\n");
    cout<<spacing("A: Yes, immediate debts/bills reduce your Zakatable wealth.\n\n");
    
    cout<<spacing("Q: Who receives Zakat?\n");
    cout<<spacing("A: 8 categories in Quran 9:60 - poor, needy, collectors, new Muslims,");
    cout<<spacing("freeing captives, debtors, in Allah's cause, travelers in need.\n\n");
    
    cout<<spacing("Q: Special cases not covered here?\n");
    cout<<spacing("A: Please consult a qualified Islamic scholar for guidance.\n\n");
print_separator();
  }
};
void get_total(Assets a,Liabilities l,zakat &z){
  z.total=((a.gold*goldprice)+(a.silver*silverprice)+a.cash+a.stocksValue+a.businessInventory+a.other+a.lent-l.bills-l.loans-l.others);
}
void setzakat(Information &i,double p){
  i.zakatpayable-=p;
}
void print_separator(){
  cout<<"_________________________________________________________________________________________________________________________________________________________________"<<endl;
}
int main(){
  chatbot clientschatbot;
  clientschatbot.intro();
  srand(time(0));
Information client;
client.setInformation();

  History h;
  support *f,*s;//must delete memory
  f=new FAQ;
  s=new Suggestions;
int n=1;
while (n!=6){
clientschatbot.menu();
cin>>n;
switch(n) {
            case 1:
          //Calculate zakat
          client.calculatezakat();
          h.save(client.getname(),client.getemail(),client.getzakat());
          cout<<spacing("Your Zakat is = ")<<client.getzakat()<<endl;
          client.displayRandomHadith();
          
          
           break;
            case 2:
                //view_history
         h.viewhistory();
         client.displayRandomHadith();
                break;
            case 3:
            double p;if(client.getzakat()>0){
          cout<<spacing("Enter the amount you want to pay from your zakat")<<endl;
            cin>>p;
            if(p<=client.getzakat()){
            setzakat(client,p);
            
            h.savepayment(client.getname(),client.getemail(),p,client.getzakat());}
          else {cout<<spacing("Your amount is greater then the zakat due i.e. ")<<client.getzakat
            ()<<endl;
          cout<<spacing("Try Again")<<endl;}}
            else {cout<<spacing("You are ineligible for zakat")<<endl;}
            client.displayRandomHadith();
            
                break;
            case 4:
            f->show();
            client.displayRandomHadith();
             //   show_faq
                break;
            case 5:
                //show_charity_options
                s->show();
                client.displayRandomHadith();
                break;
            case 6:
            show();
            client.displayRandomHadith();
               break;
               
}

}


delete s;
delete f;
return 0;}