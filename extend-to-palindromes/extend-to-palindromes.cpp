#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <climits>
#include <algorithm>
using namespace std;

int get_duplicate_num(string a, string b)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i + j] != b[j])
            {
                break;
            }
            if (i + j == a.size() - 1)
            {
                return j + 1;
            }
        }
    }
    return 1;
}

int main()
{
    string data;
    while ((cin >> data))
    {
        string data_r = "";
        for (int i = data.size() - 1; i >= 0; i--)
        {
            data_r += data[i];
        }
        int count = get_duplicate_num(data, data_r);
        string temp = "";
        // cout<<"count=="<<count<<endl;
        if (count != data.size())
        {
            for (int i = count ; i < data_r.size(); i++)
                temp += data_r[i];
            cout << data << temp << endl;
        }
        else{
            cout << data <<endl;

        }
    }
    return 0;
}