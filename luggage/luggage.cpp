#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int main() {
    int m = 0;
    scanf("%d\n", &m);
    while (m > 0) {
        vector<int> data;
        string input;
        getline(cin, input);
        string tmp = "";
        // cout<<"m="<<m<<endl;
        // cout<<"i="<<input<<endl;
        for (size_t i = 0;i <= input.size();i++) {
            if (input[i] == ' ' || input[i] == '\0') {
                stringstream degree(tmp);
                int z = 0;
                degree >> z;
                data.push_back(z);
                tmp = "";
                continue;
            }
            tmp += input[i];
        }
        std::sort(data.begin(), data.end());
        int sum = 0;
        for (vector<int>::iterator i = data.begin();i != data.end();i++) {
            sum += *i;
        }
        // cout<<"sum="<<sum<<endl;
        if (sum % 2 == 1) {
            cout << "NO\n";
            m--;
            continue;
        }
        sum /= 2;
        vector<bool> ava(sum+1, false);
        ava[0] = true;
        for (size_t i = 0;i <= data.size();i++) {
            // cout <<"i="<<data[i]<<endl;
            for (int j = sum;j >= data[i];j--) {
                if (ava[j - data[i]]) {
                    ava[j] = true;
                }
            }
        }
        printf("%s\n", ava[sum] ? "YES" : "NO");
        m--;
    }
    return 0;
}