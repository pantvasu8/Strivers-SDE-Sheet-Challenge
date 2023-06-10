#include <bits/stdc++.h>

void solve(vector<vector<long long int>> &ans, int val)
{
    ans[val - 1].push_back(1);
    for (int i = 1; i <= val - 2; i++)
    {
        long long int valToPush = ans[val - 2][i - 1] + ans[val - 2][i];
        ans[val - 1].push_back(valToPush);
    }

    ans[val - 1].push_back(1);
}

vector<vector<long long int>> printPascal(int n)
{
    // Write your code here.
    vector<vector<long long int>> ans(n, vector<long long int>());
    ans[0].push_back(1);
    if (n == 1)
    {
        return ans;
    }

    ans[1].push_back(1);
    ans[1].push_back(1);

    if (n == 2)
    {
        return ans;
    }

    for (int i = 2; i < n; i++)
    {
        int val = i + 1;
        solve(ans, val);
    }
    return ans;
}
