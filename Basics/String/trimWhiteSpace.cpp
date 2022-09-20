#include <iostream>
using namespace std;


void trimString(string & str)
{
    size_t found = str.find_first_not_of(" ");
    if(found != string::npos)
    {
        str.erase(str.begin(), str.begin()+found);
        cout<<str<<endl;
        found = str.find_last_not_of(" ");
        str.erase(str.begin()+found+1, str.end());
        cout<<str<<endl;
    }
    else{
        str.clear();
        cout<<"only white space in str";
    }
}
int main()
{
	string str = "    Hello    World   ";
    cout<<str<<endl;
	trimString(str);
   return 0; 
}