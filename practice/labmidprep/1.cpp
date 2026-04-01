#include<iostream>
using namespace std;

class laptop{
  string brand;
  string model;
  int price;
  int ramsize;
  static int totallaptops;
  static int totalprice;
  int n;
  public:
  laptop(const laptop &s){
    brand=s.brand;
    model=s.model;
    ramsize=s.ramsize;
    price=s.price;
    totallaptops++;
    totalprice+=price;
    n=totallaptops;
  }
  laptop(string b,string m,int p,int r):brand(b),model(m),price(p),ramsize(r){
    totallaptops++;
    totalprice+=p;
    n=totallaptops;
  }
  void display(){cout<<"Laptop "<<n<<" "<<brand<<" Price: "<<price<<" RAM: "<<ramsize<<endl;}
  void setnooflaptops(int n){totallaptops=n;}
  void setprice(int h){totalprice=h;}

  static void d(){
  cout<<"Total number of laptops: "<<totallaptops<<endl;
  cout<<"Total price of laptops: "<<totalprice<<endl;
}

};

// void d(){
//   cout<<"Total number of laptops: "<<totallaptops<<endl;
//   cout<<"Total price of laptops: "<<totalprice<<endl;
// }



int laptop::totallaptops=0;
int laptop::totalprice=0;
int main(){
  laptop l1("Dell","Pro",28000,4);
  laptop l2("HP","Elitebook",65000,8);
l1.display();
l2.display();

laptop l3(l1);
l3.display();
laptop::d();







}