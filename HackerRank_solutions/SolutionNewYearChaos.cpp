#include <bits/stdc++.h>

using namespace std;
int max_swaps=0;
vector<string> split_string(string);
void swap(vector<int>&pt,int pos1,int pos2)
{
    max_swaps++;
    int temp=pt[pos1];
    pt[pos1]=pt[pos2];
    pt[pos2]=temp;
}
// Complete the minimumBribes function below.
void minimumBribes(vector<int> a) {
max_swaps=0;
int size=a.size();
vector<int> orig(size);
long i;
int pos=0;
std::vector<int>::iterator it; 
for (i = 0; i < size; i++)
{
    orig[i]=i+1;
}
for (i = 0; i < size; i++)
{
    if(a[i]!=orig[i])
    {
        it = find (orig.begin(), orig.end(), a[i]);
        pos=it-orig.begin();
        swap(orig,pos,pos-1);
        if(a[i]!=orig[i])
        {
            swap(orig,pos-1,pos-2);
            if(a[i]!=orig[i])
            {
                printf("Too chaotic\n");
                return;
            }
            else
            {
                continue;
            }
        }
    }
    else
    {
        continue;
    }
}
//for(i=0;i<size;i++)
//printf("%d  ",orig[i]);
//printf("\n");
printf("%d\n",max_swaps);
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
