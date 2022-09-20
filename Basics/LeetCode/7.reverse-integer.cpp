// #include<algorithm>
// #include<sstream>
class Solution {
public:
    void reverseStr(string& str)
    {
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }
    
    int reverse(int x) {
        std::string str;
        str = std::to_string(x);
        // std::reverse(str.begin(),str.end());
        reverseStr(str);
        int rever =0 ;
        try{
        rever = stoi(str);
        }
        catch(...)
        {
            return 0;
        }
        if(x<0)
        {
            rever = -rever;
        }
        return rever;
    }
};