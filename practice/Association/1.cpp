#include<iostream>
using namespace std;
class LibraryBook{
  string title;
  public:
  void settitle(string n){
    title=n;
  }
  string gettitle(){return title;}
};
class Reader{
  public:
  void readBook(LibraryBook *r){
   cout<<"I am reading book "<<r->gettitle()<<endl; 
  }
};
int main(){
Reader r;
LibraryBook l;
r.readBook(&l);
  return 0;
}