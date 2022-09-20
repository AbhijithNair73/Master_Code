#include <iostream>
#include <fstream>
#include <map>
using namespace std;

// static const char * FILENAME = "mapp.cfg";

int main(int argc, char ** argv)
{
    // map<string,string> configMap;

    cout<<"argc: "<<argc<<endl;
    for (int i = 0; i < argc; i++)
    {
        cout<<argv[i]<<endl;
    }
    string str;
    ifstream fin(argv[0]);
    while (getline(fin,str,'='))
    {
        cout<<str<<endl;
    }
   return 0; 
}