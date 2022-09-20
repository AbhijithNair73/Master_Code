/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vect(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            vector<int> temp(i + 1);
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    temp.at(j) = 1;
                }
                else
                {
                    temp.at(j) = vect[i - 1][j - 1] + vect[i - 1][j];
                }
            }
            vect[i] = temp;
        }
        return vect;
    }
};
// @lc code=end
