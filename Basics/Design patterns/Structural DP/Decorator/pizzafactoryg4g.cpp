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
		return name +" "+ PizzaDecorator::get_string();
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
		return name +" "+PizzaDecorator::get_string();
	}
};

size_t replacer(std::string & input, const std::string str,int count)
{
	string newstr;
	if(count == 2)
	{
		newstr = "Double"+str;
		input.replace(input.find(str),str.size()+1,newstr);
	}
	else if(count == 3)
	{
		newstr = "Triple"+str;
		input.replace(input.find(str),str.size()+1,newstr);
	}
	else
	{
		newstr = "Poly"+str;
		input.replace(input.find(str),str.size(),newstr);
	}
	return newstr.size();
}

int repeatcount(std::string & input , const std::string str, size_t found1)
{
	int count = 0;
	size_t found =0 ;
	while(found != string::npos)
	{
		count++;
		found = input.find(str,found1);
		if(found != string::npos)
		{
			input.erase(found,str.size());
		}
	}
	return count;
}

void wrapperStringSorter(std::string & input)
{
	//To Do 
	// cheese cheese ==> Double cheese
	// append with pizza
	// only allow one base
	string str;
	size_t found,next=0;
	cout<<"Original Input ="<<input.c_str()<<endl;
	found = input.find(' ',next); 
	while(found != string::npos)
	{
		cout<<"Found = "<<found<<endl;
		str = input.substr(next,found-next);
		cout<<"str "<<str.c_str()<<endl;;
		int count = repeatcount(input,str,found);
		if(count>1)
			next += replacer(input, str, count);
		else
			next += (found-next);
		cout<<"Next ="<<next<<endl<<"Count ="<<count<<endl<<"Input ="<<input.c_str()<<endl;
		str.empty();
		found = input.find(' ',next+1);
	}
}



int main()
{
	Pizza * local = new Cheese(new Cheese(new Jalapeno(new Jalapeno(new Jalapeno(new Farmhouse())))));
	int result = local -> get_cost();
	string unstruct = local->get_string();
	wrapperStringSorter(unstruct);
	cout<<"Total value of "<<unstruct<<" is "<<result<<endl;
	return 0;
}