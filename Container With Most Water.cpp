#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cctype>

using namespace std;
/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

*/
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int left = 0; int right = height.size()-1;
        int best = min(height[0], height[height.size() - 1])*(height.size()-1);

        bool side_stop; //0 - left; 1 - right
        if (height[0] >= height[height.size() - 1])
        {
            side_stop = 0;
        }
        else 
        {
            side_stop = 1;
        }
        for (int i = 0; i < height.size(); i++)
        {
            if (!side_stop) //left
            {
                --right;
                if (right == left) // if ==, then zero length
                {
                    break;
                }
                int current = min(height[left], height[right])*(right-left);
                if (current > best)
                {
                    best = current;
                }
                if (height[left] < height[right])
                {
                    side_stop = 1;
                }
            }
            else
            {
                ++left;
                if (right == left)
                {
                    break;
                }
                int current = min(height[left], height[right]) * (right - left);
                if (current > best)
                {
                    best = current;
                }
                if (height[left] < height[right])
                {
                    side_stop = 1;
                }
                else
                {
                    side_stop = 0;
                }
            }
        }
        return best;
    }
};
int main()
{
    vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    Solution S;
    cout<<S.maxArea(height)<<endl;
}
