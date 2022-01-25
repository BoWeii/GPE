#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
using namespace std;

int get_min_m(int num)
{
    int min_num=1;
    while(true){
        bool *z = (bool *)malloc(sizeof(bool *) * num);
        // int times=7;
        vector<int> order;
        int index = 0;
        for (int i = 0; i < num; i++){
            z[i] = true;
        }
        z[0] = false;
        order.push_back(0);
        while (true)
        {
            int count = 0;
            bool is_over = true;
            for(int i=0;i<num;i++){
                if (z[i])
                {
                    is_over = false;
                    break;
                }
            }
            if(is_over)
                {
                    break;
                }
            while(true){
                index=(index+1)%num;
                if(z[index]){
                    count++;
                }
                if(count==min_num){
                    z[index]=false;
                    order.push_back(index);
                    break;
                }
            }
        }
        // cout<<"---begin---\n";
        // for(vector<int>::iterator i=order.begin();i!=order.end();i++){
        //     cout<<*i<<"\n";
        // }
        // cout<<"---end---\n";
        if(order.back()==12) return min_num;
        min_num++;
        }

}

int main()
{
    vector<int> res;
    while (true)
    {
        int num = 0;
        int a = 0;
        cin >> num;
        if (num == 0)
            break;
        else
        {
            a = get_min_m(num);
            res.push_back(a);
        }
    }
    for (vector<int>::iterator i = res.begin(); i != res.end(); i++)
    {
        cout << *i << "\n";
    }
    return 0;
}