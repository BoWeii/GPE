#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

struct coord
{
    int x;
    int y;
};

struct line
{
    int dx, dy;
    int x1, y1, x2, y2;
};

int get_num(vector<coord> data)
{
    // cout<<"data size="<<data.size()<<'\n';
    vector<line> all;
    for (size_t i = 0; i < data.size(); i++)
    {
        for (size_t j = i + 1; j < data.size(); j++)
        {
            line tmp;
            tmp.dx = data[j].x - data[i].x;
            tmp.dy = data[j].y - data[i].y;
            tmp.x1 = data[i].x;
            tmp.x2 = data[j].x;
            tmp.y1 = data[i].y;
            tmp.y2 = data[j].y;
            all.push_back(tmp);
        }
    }
    // cout<<"size= "<<all.size()<<endl;
    vector<line> res;
    // cout << "all line=";
    // for (vector<line>::iterator i = all.begin(); i != all.end(); i++)
    // {
    //     printf("contain (%d,%d) and (%d,%d)\n", i->x1, i->y1, i->x2, i->y2);
    // }
    // cout<<"=========\n";
    for (vector<line>::iterator i = all.begin(); i != all.end(); i++)
    {
        bool uniq = true;
        for (vector<line>::iterator j = res.begin(); j != res.end(); j++)
        {
            if (i->dy * j->dx == i->dx * j->dy)
            {
                int ax = j->x2 - i->x1;
                int ay = j->y2 - i->y1;
                int bx = j->x2 - i->x2;
                int by = j->y2 - i->y2;
                if (ay * bx == ax * by)
                {
                    uniq = false;
                    break;
                }
            }
        }
        if (uniq)
        {
            // printf("push (%d,%d) and (%d,%d)\n", i->x1, i->y1, i->x2, i->y2);

            res.push_back(*i);
        }
    }
    return res.size();
}

int main()
{
    int times = 0;
    cin >> times;
    vector<int> res;
    while (times != 0)
    {
        int num;
        cin >> num;
        vector<coord> data;
        for (int i = 0; i < num; i++)
        {
            int x = 0, y = 0;
            cin >> x;
            cin >> y;
            coord tmp;
            tmp.x = x;
            tmp.y = y;
            data.push_back(tmp);
        }
        // for(vector<coord>::iterator it=data.begin();it!=data.end();it++){
        //     cout<<"x="<<it->x<<" y="<<it->y<<endl;
        // }
        res.push_back(get_num(data));
        times--;
    }
    for(vector<int>::iterator it=res.begin();it!=res.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}