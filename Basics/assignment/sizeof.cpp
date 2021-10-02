// use format specifier %zu for sizeof while printing in c style.
/*By sizeof(func), you probably mean sizeof(&func), which is the size of a function pointer in bytes.

As far as what the size of an A object is, the standard only says:

Complete objects and member subobjects of class type shall have nonzero size.

All functions are stored as function pointers so it may take the size of a
pointer on that particular platform
*/
#include<iostream>
class A{
public:
	A(){}
	void fun(void)
	{}
	void Hello()
	{
		int var=10;
	}
};

void func(){}
int main()
{
 std::cout<<sizeof(A)<<std::endl<<sizeof(&func);
 return 0;

}