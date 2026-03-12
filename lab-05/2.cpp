#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer;
class Restaurant;

class Order {
private:
    int id;
    string customerName;
    string restaurantName;
    string foodItem;

public:
    Order(int orderId, string cName, string rName, string food) 
        : id(orderId), customerName(cName), restaurantName(rName), foodItem(food) {}

    void show() {
        cout << "--- Order Details ---" << endl;
        cout << "Order ID: " << id << endl;
        cout << "Customer: " << customerName << endl;
        cout << "Restaurant: " << restaurantName << endl;
        cout << "Food Item: " << foodItem << endl;
        cout << "---------------------" << endl;
    }
};

class Restaurant {
private:
    string name;

public:
    Restaurant(string n) : name(n) {}

    string getName() { return name; }

    void takeOrder(Order* o) {
        cout << "[System] " << name << " has received the order." << endl;
        o->show();
    }
};

class Customer {
private:
    string name;

public:
    Customer(string n) : name(n) {}

    void placeOrder(Restaurant* r, string food) {
        static int nextId = 101; 
        
        Order* newOrder = new Order(nextId++, this->name, r->getName(), food);
        
        cout << "[System] " << name << " is placing an order at " << r->getName() << "..." << endl;
        
        r->takeOrder(newOrder);
        
        delete newOrder;
    }
};

int main() {
    Customer user1("Waseem");
    Restaurant rest1("The Burger Joint");

    user1.placeOrder(&rest1, "Zinger Burger");

    return 0;
}