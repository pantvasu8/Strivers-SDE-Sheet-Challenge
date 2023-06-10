#include <bits/stdc++.h>

void solve(vector<int> &v, int index)
{
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] > v[index])
        {
            swap(v[i], v[index]);
            break;
        }
    }

    sort(v.begin() + index + 1, v.end());
}

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int index;
    for (int i = n - 1; i >= 0; i--)
    {
        if (permutation[i] > permutation[i - 1])
        {
            index = i - 1;
            break;
        }
        if (i == 0)
        {
            index = -1;
        }
    }

    if (index == -1)
    {
        sort(permutation.begin(), permutation.end());
        return permutation;
    }
    solve(permutation, index);
    return permutation;
}