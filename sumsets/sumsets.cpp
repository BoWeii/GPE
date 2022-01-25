#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <climits>
#include<algorithm>
using namespace std;

int get_largest_d(vector<int> data)
{
    vector<int> res;

    for (int i = data.size() - 1; i >= 0; i--)
    {
        for (int a = 0; a < data.size(); a++)
        {
            for (int b = a + 1; b < data.size(); b++)
            {
                for (int c = b + 1; c < data.size(); c++)
                {
                    if ((data[i] == data[a] + data[b] + data[c]) && a != i && b != i && c != i)
                        return data[i];
                }
            }
        }
    }
    return INT_MAX;
}

int main()
{
    while (true)
    {
        int times = 0, temp, res;
        cin >> times;
        if (times == 0)
        {
            break;
        }
        vector<int> data;
        for (int i = 0; i < times; i++)
        {
            cin >> temp;
            data.push_back(temp);
        }
        sort(data.begin(), data.end());
        res = get_largest_d(data);
        if (res == INT_MAX)
        {
            cout << "no solution\n";
        }
        else
        {
            cout << res << "\n";
        }
    }
    return 0;
}