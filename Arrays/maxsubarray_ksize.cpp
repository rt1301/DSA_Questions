#include <bits/stdc++.h>
using namespace std;

/****
 * Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.
****/
class Solution
{
public:
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> n3;
        int j = 0;
        int n1 = INT_MIN;
        int n2 = -1;
        for (j = 0; j < k; j++)
        {
            if (n1 < arr[j])
            {
                n1 = arr[j];
                n2 = j;
            }
        }
        n3.push_back(n1);
        while (j < n)
        {
            if (n2 <= j - k)
            {
                j = j - k + 1;
                n1 = INT_MIN;
                int n3 = j + k;
                for (; j < n3; j++)
                {
                    if (n1 < arr[j])
                    {
                        n1 = arr[j];
                        n2 = j;
                    }
                }
                j--;
            }
            else
            {
                if (n1 < arr[j])
                {
                    n1 = arr[j];
                    n2 = j;
                }
            }
            n3.push_back(n1);
            j++;
        }
        return n3;
    }
};
int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}