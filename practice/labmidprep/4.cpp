#include<iostream>
using namespace std;
class media{
  string title;
  int duration;

  public:
  media(string t,int d):title(t),duration(d){}
  virtual void play(){
cout<<"Media is playing"<<endl;
  }
  string gettitle(){return title;}
  bool operator > (media &m){
  if(duration>m.duration){return true;}
  else return false;
}

};

class video:public media{

  public:
  void play()override{
    cout<<"Video is playing"<<endl;

  }
  video(string t,int d):media(t,d){}
};
class audio:public media{

  public:
  audio(string t,int d):media(t,d){}
  void play()override{cout<<"Audio is playing"<<endl;}

};
class podcast:public media{

  public:
  podcast(string t,int d):media(t,d){}
  void play()override{cout<<"Podcast is playing"<<endl;}
};
class mediaplayer{
string type;
int duration;
public:

  void playmedia(string typ,int dur){
  cout<<typ<<" is playing having duration "<<dur<<endl;}
  void playmedia(string typ){
  cout<<typ<<" is playing Unknowm"<<endl;}

void playmedia(string typ,float speed){
  cout<<typ<<" is playing with speed "<<speed<<"x"<<endl;}};



int main(){
  media *t[3];
  podcast p("FSW",120);
audio a("Atif",20);
video v("Raftar",60);


cout<<"\n\n\nPlay"<<endl;
p.play();
a.play();
v.play();
cout<<"\n\n\nFunction Overloading\n\n"<<endl;
mediaplayer mp;
mp.playmedia("Audio",200);
mp.playmedia("video");

t[0]=&p;
t[1]=&a;
t[2]=&v;
if(a>v){cout<<a.gettitle()<<" > "<<v.gettitle()<<endl;}else cout<<a.gettitle()<<" < "<<v.gettitle()<<endl;;


  return 0;
}