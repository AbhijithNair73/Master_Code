#include<iostream>
using namespace std;

class Pizza
{
public:
	virtual int get_cost() = 0;
	virtual std::string get_string() = 0;
};

class Farmhouse : public Pizza
{
	string name;
public:
	Farmhouse():name("Farmhouse")
	{	
	}
	virtual int get_cost() override
	{
		return 100;
	}
	virtual std::string get_string() override
	{
		return name;
	}

};

class Peppy:public Pizza
{
	string name;
public:
	Peppy():name("Peppy")
	{
		
	}
	virtual int get_cost() override
	{
		return 150;
	}
	virtual std::string get_string() override
	{
		return name;
	}
};

class ChickenFiesta:public Pizza
{
	string name;
public:
	ChickenFiesta():name("ChickenFiesta")
	{
		
	}
	virtual int get_cost() override
	{
		return 200;
	}
	virtual std::string get_string() override
	{
		return name;
	}
};

class PizzaDecorator: public Pizza
{
protected:
	Pizza * mpizza;
public:
	PizzaDecorator(Pizza * ptr): mpizza(ptr)
	{

	}

	virtual int get_cost()
	{
		return mpizza -> get_cost();
	}

	virtual std::string get_string() override
	{
		return mpizza->get_string();
	}
};

class Cheese :public PizzaDecorator
{
	string name;
public:
	Cheese(Pizza * ptr) : PizzaDecorator(ptr)
	{
		name = "Cheese";
	}
	virtual get_cost()
	{
		int value = PizzaDecorator::get_cost();
		return 50 + value;
	}
	virtual std::string get_string()
	{
		return name + PizzaDecorator::get_string();
	}
};

class Jalapeno:public PizzaDecorator
{
	string name;
public:
	Jalapeno(Pizza * ptr) : PizzaDecorator(ptr)
	{
		name="Jalapeno";
	}
	virtual get_cost()
	{
		int value = PizzaDecorator::get_cost();
		return 30 + value;
	}
	virtual std::string get_string()
	{
		return name + PizzaDecorator::get_string();
	}
};

void wrapperStringSorter(std::string & input)
{
	//To Do 
	// cheese cheese ==> Double cheese
	// append with pizza
	// only allow one base
}

int main()
{
	Pizza * local = new Cheese(new Jalapeno(new Farmhouse()));
	int result = local -> get_cost();
	string unstruct = local->get_string();
	wrapperStringSorter(unstruct);
	cout<<"Total value of "<<<<"is "<<result<<endl;
	return 0;
}