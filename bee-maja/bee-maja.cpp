#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

#define _SIZE 100000
struct mappingSystem
{
    int x, y;
};

mappingSystem res[_SIZE + 1];

void create()
{
    int round = 1;
    int x = 0, y = 0;
    res[1].x = 0;
    res[1].y = 0;
    for (int i = 2; i <= _SIZE;)
    {
        for (int d = 0; d < round && i <= _SIZE; d++, i++)
        {
            res[i].x = x;
            res[i].y = ++y;
        }
        for (int d_l = 0; d_l < round - 1 && i <= _SIZE; d_l++, i++)
        {
            res[i].x = --x;
            res[i].y = ++y;
        }
        for (int u_l = 0; (u_l < round) && (i <= _SIZE); u_l++, i++)
        {
            res[i].x = --x;
            res[i].y = y;
        }
        for (int u = 0; u < round && i <= _SIZE; u++, i++)
        {
            res[i].x = x;
            res[i].y = --y;
        }
        for (int u_r = 0; u_r < round && i <= _SIZE; u_r++, i++)
        {
            res[i].x = ++x;
            res[i].y = --y;
        }
        for (int d_r = 0; d_r < round && i <= _SIZE; d_r++, i++)
        {
            res[i].x = ++x;
            res[i].y = y;
        }
        round++;
    }
}

int main()
{
    create();
    int num=-1;
    while((cin>>num)){
        printf("%d %d\n",res[num].x,res[num].y);
    }
    return 0;
}