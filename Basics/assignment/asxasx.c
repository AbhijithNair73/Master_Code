// C Program to demonstrate working of anonymous union
#include<stdio.h>
struct Scope
{
	// Anonymous union
	union
	{
		char alpha;
		int num;
	}d;
};

int main()
{
	struct Scope x;
	x.d.num = 'a';
    x.d.alpha=65;

	// Note that members of union are accessed directly
	printf("x.alpha = %c, x.num = %d", x.d.alpha, x.d.num);

	return 0;
}
