/****
 * Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 * You can assume that you can always reach the last index.
****/
// Frequently asked question in OT
#include <bits/stdc++.h>
using namespace std;
int jump(vector<int> &nums)
{
    int current = 0, start = 0, end = nums.size() - 1, noj = 0, maxx = 0, k = 0;
    for (int i = start; i < end; i++)
    {
        maxx = max(maxx, i + nums[i]);
        if (i == current)
        {
            current = maxx;
            noj++;
        }
        if (current > end - 1)
        {
            return noj;
        }
    }
    return noj;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> maxJumpLength;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            maxJumpLength.push_back(temp);
        }
        cout << jump(maxJumpLength) << endl;
    }
    return 0;
}