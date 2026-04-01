#include<iostream>
using namespace std;
class light{
  int brightness,power;
  public:
  light(int a,int g):brightness(g),power(a){}
  int getpower(){return power;}
  void display(){cout<<"Brightness "<<brightness<<"  power "<<power<<endl;}

};
class ac{
  float tonnage;
  int power;
  public:
  ac(int n,int u):power(n),tonnage(u){}
    int getpower(){return power;}
    void display(){cout<<"Tonnage "<<tonnage<<"  power "<<power<<endl;}
};
class camera{
  int power;
  string resolution;
  public:
  camera(int n,string c):power(n),resolution(c){}
    int getpower(){return power;}
    void display(){cout<<"Resolution "<<resolution<<"  power "<<power<<endl;}
};

class house{
  string name;
  string controllerId;
  int lightcount;int account;
  int cameracount;
   int g=0;
   light *l[6];
   camera *c[3];
   ac *a[4];
  
   public:
   house(string c,string h):name(c),controllerId(h){
    lightcount=0;account=0;
  cameracount=0;
   }
   void addlight(){
    if(lightcount<6){lightcount++;
      int b,p;
   cout<<"Enter power"<<endl;cin>>p;
   cout<<"Enter brightness"<<endl;cin>>b;
  l[lightcount-1]=new light(p,b);}
   else cout<<"No space Available\n";}
   void addac(){
if(account<4){account++;
int b,p;
   cout<<"Enter power"<<endl;cin>>p;
   cout<<"Enter tonnage"<<endl;cin>>b;
  a[account-1]=new ac(p,b);

}else cout<<"No space Available\n";
   }
   void addcamera(){
    if(cameracount<5){cameracount++;
    int p;
    string f;
   cout<<"Enter power"<<endl;cin>>p;
   cout<<"Enter resolution"<<endl;cin>>f;
  c[cameracount-1]=new camera(p,f);}
    else cout<<"No space Available\n";
   }
   void calculatepower(){
   
    for(int i=0;i<account;i++){g+=a[i]->getpower();}
    for(int i=0;i<cameracount;i++){g+=c[i]->getpower();}
    for(int i=0;i<lightcount;i++){g+=l[i]->getpower();}
cout<<"Memory Cleared"<<endl;
   }
   void display(){
    cout<<"name "<<name<<" \n"<<"controllerId "<<controllerId<<endl;
    cout<<"ACs"<<endl;
    for(int i=0;i<account;i++){cout<<"AC "<<i+1<<endl;
      a[i]->display();}
    cout<<"Security Cameras"<<endl;
    for(int i=0;i<cameracount;i++){cout<<"Security Cameras "<<i+1<<endl;
      c[i]->display();}
    cout<<"Lights"<<endl;
    for(int i=0;i<lightcount;i++){
      cout<<"Light "<<i+1<<endl;
      l[i]->display();;}
cout<<"Total Lights "<<lightcount<<endl;
cout<<"Total Security Cameras "<<cameracount<<endl;
cout<<"Total Acs "<<account<<endl;
cout<<"\n\n\nTotal power consumption "<<g<<endl;
}
~house(){
  for(int i=0;i<account;i++){delete a[i];}
    for(int i=0;i<cameracount;i++){delete c[i];}
    for(int i=0;i<lightcount;i++){delete l[i];}
}
};


int main(){
house h("SweetHome","1256");
h.addac();
h.addcamera();
h.addlight();
h.calculatepower();
h.display();



  return 0;
}