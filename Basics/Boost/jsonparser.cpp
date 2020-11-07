#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"
#include <bits/stdc++.h> 

int main() {
    using boost::property_tree::ptree;

    std::ifstream jsonFile("sample.json");

    ptree pt;
    read_json(jsonFile, pt);

    for (auto & array_element: pt) {
        for (auto & property: array_element.second) {
            std::cout << property.first << " = " << property.second.get_value < std::string > () << "\n";
        }
    }
}