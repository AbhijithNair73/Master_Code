#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

void printElem(const string & s)
{
    cout<<s<<endl;
}

int main(){
  int count = 0;
  string inputStr("This     is     a   string");
  
// Approach-1  Doesn't works for multiple spaces.
//   stringstream iss();
//   string s;
//   while ( getline( iss, s, ' ' ) ) {
//     cout<<++count<<s<<endl;
//   }

//Approach-2  // worked
//   stringstream ss(inputStr);
//   vector<string> vec;
//   string s;
//   while (ss>>s){
// 	vec.push_back(s);
//   }
//   for_each(vec.begin(),vec.end(),printElem);
//   cout<< vec.size() << endl;


//Approach - 3 // works
// char * word = strtok(const_cast<char *>(inputStr.c_str())," ");
// while(word != NULL)
// {
//     cout<<++count<<word<<endl;
//     word = strtok(NULL," ");
// }


  
}