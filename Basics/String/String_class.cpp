#include <iostream>
#include <cstring>
using namespace std;

class String
{
	char* mData;
	int msize;
public:
	String(): mData(nullptr), msize(0)
	{
		cout<<"Default ctctor"<<endl;
	}

	String(const char* inputStr)
	{
		cout << "Const char * ctctor"<<endl;
		msize = strlen(inputStr);
		cout << "size = "<<msize<<endl;
		mData = new char[msize + 1];
		memcpy(mData,inputStr,msize);
		mData[msize] = 0;
	}

	String(const std::string& inputStr)
	{
		cout<<"String ctctor"<<endl;
		msize = inputStr.size();
		cout <<"size = "<<msize<<endl;
		mData = new char[msize + 1];
		memcpy(mData,inputStr.c_str(),msize);
		mData[msize] = 0;
	}

	String(const String& original)
	{
		cout<<"copy constructor"<<endl;
		msize = original.msize;
		mData = new char[msize + 1];
		strcpy(mData,original.mData);
	}

	String& operator = (const String& original)
	{
		cout<<"assignment operator"<<endl;
		msize = original.msize;
		mData = new char[msize + 1];
		strcpy(mData,original.mData);
		return *this;
	}

	char& operator [](int i)
	{
		return mData[i];
	}

	bool operator >(const String & other)
	{
		if(strcmp(this->mData,other.mData) > 0)
			return true;
		else
			return false;
	}

	bool operator <(const String & other)
	{
		if(strcmp(this->mData,other.mData) < 0)
			return true;
		else
			return false;
	}

	bool operator ==(const String & other)
	{
		if(!strcmp(this->mData,other.mData))
			return true;
		else
			return false;
	}

	String operator +(const String & other)
	{
		String temp;
		temp.msize = this->msize + other.msize;
		cout << "size = "<<this->msize<<" + "<<other.msize<<" = "<< temp.msize<<endl;
		temp.mData = new char[temp.msize+1];
		strcpy(temp.mData,this->mData);
		strcat(temp.mData,other.mData);
		return temp;
	}

	int size() const
	{
		return msize;
	}

	bool empty() const
	{
		return msize ? false : true;
	}

	friend ostream& operator << (ostream& out, String & obj)
	{
		if(!obj.empty())
		{
			for(int i=0;obj.mData[i];++i)
			{
				out<<obj.mData[i];
			}
		}
		return out;
	}

};

int main(int argc, char const *argv[])
{
	String s1("Abhijith");
	String s2("Abhi");
	String s3(s1);
	String s4;
	cout<<"empty: "<<s4.empty()<<"Size = "<<s4.size()<<endl;
	s4=s1+s1;
	cout<<"empty: "<<s4.empty()<<"Size = "<<s4.size()<<endl;	
	cout<<s4<<endl;
	cout<<s3<<endl<<s2<<endl<<s1<<endl;
	return 0;
}