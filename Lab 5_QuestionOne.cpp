#include <iostream>
using namespace std;

class Order;
class Restaurant;
class Customer;

class Order
{
	public:
		static int currentID;
		int id;
		string foodItem;
		Customer* customer;
		Restaurant* restaurant;		
		
		Order(string foodItem, Customer* customer, Restaurant* restaurant)
		{
			id = ++currentID;			
			this->foodItem   = foodItem;
			this->customer   = customer;
			this->restaurant = restaurant;
		}
		void show();
		
};
class Restaurant
{
	public:
		string name;
		Order *o;
		Restaurant(string name)
		{
			this->name = name;
		}
		void takeOrder(Order* o)
		{
			this->o = o;
			o->show();
		}
};
class Customer
{
	public:
		string name;	
		
		
		void placeOrder(Restaurant* r, string food)
		{
			Order o(food, this, r);
			r->takeOrder(&o);
		}
};
int Order::currentID = 0;
void Order::show()
{
	cout << "Order ID: "   << id 				 << endl;
	cout << "Food Item: "  << foodItem         << endl;
	cout << "Customer: "   << customer->name   << endl;
	cout << "Restaurant: " << restaurant->name << endl;
}

int main()
{
	Customer c1 = {"Alice"};
	Customer c2 = {"Bob"};
	
	Restaurant r1("Pizza Heaven");
	Restaurant r2("Taco Fiesta");
	
	c1.placeOrder(&r1, "Pepperoni Pizza");
	c2.placeOrder(&r2, "Burrito");	
}