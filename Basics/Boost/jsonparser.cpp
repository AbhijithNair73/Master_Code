#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include <bits/stdc++.h> 

/*

Referece : http://www.cochoy.fr/boost-property-tree/
https://stackoverflow.com/questions/13972252/parsing-json-with-boost-property-tree
https://stackoverflow.com/questions/52502090/boost-property-tree-issues-getting-values
*/
/* void read(ptree const& node) 
    {
    	using namespace std;
    	
    	const char * defdouble = "0.0000";
       cout<< node.get_child("latitude").get_value()<<endl;;
       user_id = node.get_child("user_id").get_value<std::int>();
       name = node.get_child("name").get_value<std::string>();
       longitude = node.get_child("longitude").get_value<double>();
       return;
    };*/
int main() {
    using boost::property_tree::ptree;

    std::ifstream jsonFile("sample.json");

    ptree pt;
    read_json(jsonFile, pt);

    for (auto & array_element: pt) {
       
      //     std::cout<<array_element.second.get("user_id",-1)<<std::endl;
        

           //get_value ke liye default value dena zaroori nahi
           //but get ke liye default aur path dena zaroori he so jo path hum denge wo uska get child krke get_value karta he as shown below 
           // don't call get with and empty path to do this as it will try to extract contents of subkey with empty name. -> get_value() == get_child("").get_value()
        std::cout<<array_element.second.get_child("user_id").get_value(1)<<std::endl;


        //get_value ke liye get_value<data type> data_type dena zaroori he. Agar data_type nhi dena to default dena zaroori he

/*tree is node and has 2 children (pi, name). While calling

tree.get_value(defaultValue) // you are not passing PATH, but DEFAULT VALUE
above line is translated into

tree.get_child("").get_value(defaultValue)
    , "" path exists because it is path to tree node, and tree.data() returns "" - empty string for this path. So defaultValue cannot be printed and you see empty string as output. You should call get_value only for children (use get_child on tree before calling this methid, it is described in boost reference), and parameter of get_value is default value. So replace

  std::cout << "pi : " << tree.get_child("pi").get_value("PI is 4.0") << "\n";
  std::cout << "name : " << tree.get_child("name").get_value("noname") << "\n"; */
    }
}