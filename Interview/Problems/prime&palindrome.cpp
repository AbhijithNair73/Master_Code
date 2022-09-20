#include<iostream>
using namespace std;

void printPrime(int num)
{
	int count = 1;
	bool flag = true;
	for(int idx = 2; count<=num ; ++idx)
	{
	    flag = true;
        // cout<<"idx = "<<idx<<endl;
		for(int idx2 = 1; idx2<=idx ; ++idx2)
		{
            // cout<<"idx2 = "<<idx2<<endl;
			if(idx % idx2 == 0)
			{
				if(idx2 ==1 || idx2 == idx)
				{
                    // cout<<"continue"<<endl;
					continue;
				}
				else{
                    // cout<<"flag false not a prime"<<endl;
					flag =false;
					break;
				}
			}
		}
		if(flag)
		{
			cout<<idx<<" ";
			count++;
		}
	}

}

// bool checkPalindrome(int palin)
// {
// 	string str;
// 	str = to_string(palin);
// 	size_t idx, idx2;
// 	for(idx = 0, idx2 = str.size()-1; idx<=idx2; idx++)
// 	{
// 		if(str[idx] == str[idx2])
// 		{
// 			idx2--;
// 			continue;
// 		}
// 		else{
// 			return false;
// 			break;
// 		}
// 	}
// 	if(idx>idx2)
// 	{
// 		return true;
// 	}
// }

int main()
{
    printPrime(20);
    return 0;

}