#include <iostream>
#include <new>
#include <cstring>
using namespace std;
class balance {
double cur_bal;
char name[80];
public:
balance() {cout<<"constructing"<<name<<endl;} // parameterless constructor
~balance() {
cout << "Destructing ";
cout << name << "\n";
}
void set(double n, char *s) {
cur_bal = n;
strcpy(name, s);
}
void get_bal(double &n, char *s) {
n = cur_bal;
strcpy(s, name);
}
};
int main()
{
balance *p;
char s[80];
double n;
int i;
p = new balance [3]; // allocate entire array

// note use of dot, not arrow operators
p[0].set(12387.87, "Ralph Wilson");
p[1].set(144.00, "A. C. Conners");
p[2].set(-11.23, "I. M. Overdrawn");
for(i=0; i<3; i++) {
p[i].get_bal(n, s);
cout << s << "'s balance is: " << n;
cout << "\n";
}
delete [] p;
return 0;
}
