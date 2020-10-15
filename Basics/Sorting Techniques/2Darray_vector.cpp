#include <iostream>
#include <vector>
using namespace std;
int main() {
   vector<vector<int>>v{ { 4, 5, 3 }, { 2, 7, 6 }, { 3, 2, 1 ,10 } };
   cout<<"the 2D vector is:"<<endl;
   for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v[i].size(); j++)
         cout << v[i][j] << " ";
         cout << endl;
   }
   return 0;
}