/****
 * Given an array of integers, return the sum of two elements closest to zero.
****/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int closestToZero(int arr[], int n)
    {
        sort(arr, arr + n);
        int n1 = INT_MAX, n2;
        int l = 0, r = n - 1;
        while (l < r)
        {
            if (n1 > abs(arr[r] + arr[l] - 0))
            {
                n1 = abs(arr[r] + arr[l]);

                n2 = arr[r] + arr[l];
            }
            else if (n1 == abs(arr[r] + arr[l] - 0))
            {
                if (arr[r] + arr[l] > n2)
                    n2 = arr[r] + arr[l];
            }
            if (arr[r] + arr[l] < 0)
            {
                l++;
            }
            else
                r--;
        }
        return n2;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}