#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include "boost/lexical_cast.hpp"
using boost::property_tree::ptree;
#define custLat 12.9611159 
#define RADIUS 0.5
// Longitude of customer who needs a cab. 
#define custLong 77.6362214 
  
#define pi 3.14159265358979323846 
#define earth_radius 6371.0 
//https://stackoverflow.com/questions/38941602/how-to-parse-this-specific-json-format-using-c-boost

long double degtorad(long double deg) 
{ 
    return ( deg * pi / 180); 
} 
  
// Function to calculate distance 
// between 2 given locations  
// using Great Circle Distance Formula. 
long double CustomerdistanceEarth(long double lat2d,long double lon2d) 
{                  
    long double lat1, lon1, lat2, lon2,  
           delta_lon, central_ang; 
  
    lat1 = degtorad(custLat); 
    lon1 = degtorad(custLong); 
    lat2 = degtorad(lat2d); 
    lon2 = degtorad(lon2d); 
  
    delta_lon = lon2 - lon1; 
      
    // great circle distance formula. 
    central_ang = acos ( sin(lat1) * 
                  sin(lat2) + cos(lat1) * 
                  cos(lat2) * cos(delta_lon) );  
                    
    return (earth_radius * central_ang); 
} 

bool CustomerdistanceRange(long double lat2d,long double lon2d)
{
	long double customerLong = custLong;
	long double customerLat = custLat;
	customerLong += RADIUS;
	customerLat += RADIUS;
	if((lat2d<customerLat && lat2d >(customerLat-(2*RADIUS))) && (lon2d<customerLong && lon2d >(customerLong-(2*RADIUS))))
	{
		std::cout<<"latitude = "<<lat2d<<"Longitude ="<<lon2d<<std::endl;
		return true;
	}
return false;

}
struct User 
{
    long double latitude;
    int user_id;
    std::string name;
    long double longitude;

    void read(ptree const& node) 
    {
    	std::string::size_type sz;
       latitude = stold(node.get_child("latitude").get_value<std::string>(),&sz);
       user_id = stoi(node.get_child("user_id").get_value<std::string>(),&sz);
       name = node.get_child("name").get_value<std::string>();
       longitude = stold(node.get_child("longitude").get_value<std::string>(),&sz);
       return;
    };

    void printdata()
    {
    	std::cout<<latitude<<std::endl;
    	std::cout<<user_id<<std::endl;
    	std::cout<<name<<std::endl;
    	std::cout<<longitude<<std::endl; 
    	return;   	
    }
};
int main()
{
	std::vector<User> vt;
	std::map<std::string,User>longMatch;
	std::map<std::string,User>latMatch;
	int count=0;
	using boost::property_tree::ptree;
    std::ifstream jsonFile("CabDriver.json");
    std::ofstream outjson("DriverDetails.json");
    outjson<<"[ \n";
    ptree pt;
    read_json(jsonFile, pt);

    for (auto & array_element: pt.get_child("")) {
        
        	User temp; 
        	temp.read(array_element.second);
        	vt.push_back(temp);
        	latMatch[array_element.second.get_child("latitude").get_value<std::string>()]=temp;
        	longMatch[array_element.second.get_child("longitude").get_value<std::string>()]=temp;
        	if(CustomerdistanceRange(temp.latitude, temp.longitude))
        	{
        		//std::string integ = boost::lexical_cast<std::string>(temp.user_id);
        		std::string integ = std::to_string(temp.user_id);
        		outjson<<"{\n  \"User Id\": "<<integ<<",\n  \"Name\": "<<"\""<<temp.name<<"\""<<"\n},";
        	}
          //  std::cout << property.first << " = " << property.second.get_value < std::string > () << "\n";
       // }
    }
    outjson.seekp(-1, std::ios_base::end);
    outjson<< " ";
    outjson<<"\n]\n";
    outjson.close();
   /* for (auto u =vt.begin(); u != vt.end(); ++u) {
    	std::cout << "--------------------"<<std::endl;
        u->printdata();
    }*/

}