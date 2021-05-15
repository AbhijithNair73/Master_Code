#include <string>
#include <iostream>
#include <memory>
#include <functional>

using namespace std;

struct Address
{
  string street;
  string city;
  int suite;
  Address() : street(nullptr), city(nullptr), suite(0)
  {

  }

  Address(const string& street, const string& city, const int suite)
    : street{street},
      city{city},
      suite{suite}
  {
  }

  Address(const Address& other)
    : street{other.street},
      city{other.city},
      suite{other.suite}
  {
  }

  friend ostream& operator<<(ostream& os, const Address& obj)
  {
    return os
      << "street: " << obj.street
      << " city: " << obj.city
      << " suite: " << obj.suite;
  }
};


struct Contact
{
  string name;
  Address* address;

/*  Contact& operator=(const Contact& other)
  {
    if (this == &other)
      return *this;
    name = other.name;
    address = other.address;
    return *this;
  }*/

  Contact() : name(nullptr), address(nullptr)
  {}

  Contact(string name, Address* address)
    : name{name}
  {
    this->address = new Address{ *address };
  }

  Contact(const Contact& other)
    : name{other.name}
    , address{ new Address{*other.address} }
  {
    /*address = new Address(
      other.address->street, 
      other.address->city, 
      other.address->suite
    );*/
  }
  ~Contact()
  {
    delete address;
  }


  friend ostream& operator<<(ostream& os, const Contact& obj)
  {
    return os
      << "name: " << obj.name
      << " works at " << *obj.address; // note the star here
  }
};

struct EmployeeFactory
{
  /*static Contact main;
  static Contact aux;*/

  static unique_ptr<Contact> NewMainOfficeEmployee(const string& name,const int suite)
  {
    Contact p{ "", new Address{ "123 East Dr", "London", 0 } };
    return NewEmployee(name, suite, p);
  }

  static unique_ptr<Contact> NewAuxOfficeEmployee(const string& name,const int suite)
  {
    Contact p{ "", new Address{ "123 Bakers St", "Uxbridge", 0 } };
    return NewEmployee(name, suite, p);
  }

private:
  static unique_ptr<Contact> NewEmployee(const string& name, const int suite, const Contact& proto)
  {
    auto result = make_unique<Contact>(proto);
    result->name = name;
    result->address->suite = suite;
    return result;
  }
};

//Contact EmployeeFactory::main{ "", new Address{ "123 East Dr", "London", 0 } };
//Contact EmployeeFactory::aux{ "", new Address{ "123B East Dr", "London", 0 } };

int main()
{
 
  auto john = EmployeeFactory::NewMainOfficeEmployee("John Doe", 123);
  auto jane = *john;
  cout<<"val = "<<john.get()<<"  val= "<<jane<<endl;
  jane.name="Jane Smith";
  jane.address->suite=100;

  cout << *john << "\n" << jane << "\n"; // note the stars here

  /*delete addr;

  getchar();*/
  return 0;
}