#include <bits/stdc++.h>

void solve2(vector<vector<int>> &matrix, int r1, int c1)
{
    int r = matrix.size();
    int c = matrix[0].size();

    if (c1 == -1)
    {
        for (int i = 0; i < c; i++)
        {
            matrix[r1][i] = 0;
        }
    }

    if (r1 == -1)
    {
        for (int i = 0; i < r; i++)
        {
            matrix[i][c1] = 0;
        }
    }
}

void solve(vector<vector<int>> &matrix, unordered_map<int, int> m1, unordered_map<int, int> m2)
{
    int r, c;

    for (auto i : m1)
    {
        r = i.first;
        solve2(matrix, r, -1);
    }

    for (auto i : m2)
    {
        c = i.first;
        solve2(matrix, -1, c);
    }
}

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    int r = matrix.size();
    int c = matrix[0].size();

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
            {
                m1[i]++;
                m2[j]++;
            }
        }
    }

    solve(matrix, m1, m2);
}
