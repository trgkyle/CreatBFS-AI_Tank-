#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <set>
using namespace std;
//Define Varrible
struct toado
{
    int x;
    int y;
};
vector<pair<int, int> > DirecTion;
int matric[22][22];
vector<toado> V[22][22]; //Add Node near it
// Function
void BFS(toado Begin, toado End) //inlcude <queue>,<set>
{
    vector<pair<int, int> > Direction[22][22];
    queue<toado> Q;
    set<int> S; //check The postiton will add it with Length x *2 The Height + y Width
    toado Cache;
    Cache = Begin;
    Q.push(Cache);
    Direction[Cache.x][Cache.y].push_back(make_pair(Cache.x, Cache.y));
    S.insert(Cache.x * 23 + Cache.y);
    //cout<<"Them "<<Cache.x * 23 + Cache.y<<endl;
    while (!Q.empty())
    {
        Cache.x = Q.front().x;
        Cache.y = Q.front().y;
        // cout << "duyet Canh " << Cache.x << " " << Cache.y << endl;
        // cout << "Size cua no la : " << V[(Cache).x][(Cache).y].size() << endl;
        if ((Cache).x == (End).x and (Cache).y == (End).y)
        {
            //cout << "Tim kiem xong ";
            break;
        }
        Q.pop();
        for (int i = 0; i < V[(Cache).x][(Cache).y].size(); i++)
        {
            if (S.find(V[(Cache).x][(Cache).y][i].x * 23 + V[(Cache).x][(Cache).y][i].y) == S.end())
            {
                //cout<<"Them "<<V[(Cache).x][(Cache).y][i].x * 23 + V[(Cache).x][(Cache).y][i].y<<endl;
                S.insert(V[(Cache).x][(Cache).y][i].x * 23 + V[(Cache).x][(Cache).y][i].y);
                Q.push(V[(Cache).x][(Cache).y][i]);
                //cout<<endl<<"Q.back() x and y "<<Q.back().x<<" "<<Q.back().y<<endl;
                Direction[(V[Cache.x][Cache.y][i].x)][(V[Cache.x][Cache.y][i].y)] = Direction[Cache.x][Cache.y];
                Direction[(V[Cache.x][Cache.y][i].x)][(V[Cache.x][Cache.y][i].y)].push_back(make_pair((V[Cache.x][Cache.y][i].x), (V[Cache.x][Cache.y][i].y)));
            }
            else
            {
                //cout<<"bi loai "<<V[(Cache).x][(Cache).y][i].x * 23 + V[(Cache).x][(Cache).y][i].y<<endl;
            }
        }
        if (Q.empty())
        {
            //cout << "Rong " << endl;
        }
    }
    DirecTion = Direction[End.x][End.y];
}
void Start()
{
    ifstream OpenFile;
    string s;
    int l = 0, g = 0;
    OpenFile.open("./TheMatricOfMap.txt");
    if (OpenFile.is_open())
    {
        while (getline(OpenFile, s))
        {
            for (int i = 0; i < s.size(); i++)
            {
                matric[l][i] = s[i] - 48;
            }
            l++;
        }

        OpenFile.close();
    }
    else
    {
        cout << "can't open file";
    }
    cout << endl;
    // for (int i = 0; i < 22; i++)
    // {

    //     for (int e = 0; e < 22; e++)
    //     {

    //         cout << matric[i][e] << " ";
    //     }
    //     cout << endl;
    // }
    //creat Node and Direction
    for (int i = 0; i < 22; i++)
    {
        for (int e = 0; e < 22; e++)
        {
            if (matric[i][e] == 0)
            {
                if (matric[i - 1][e] == 0)
                {
                    toado cache;
                    cache.x = i - 1;
                    cache.y = e;
                    V[i][e].push_back(cache);
                }
                if (matric[i + 1][e] == 0)
                {
                    toado cache;
                    cache.x = i + 1;
                    cache.y = e;
                    V[i][e].push_back(cache);
                }
                if (matric[i][e - 1] == 0)
                {
                    toado cache;
                    cache.x = i;
                    cache.y = e - 1;
                    V[i][e].push_back(cache);
                }
                if (matric[i][e + 1] == 0)
                {
                    toado cache;
                    cache.x = i;
                    cache.y = e + 1;
                    V[i][e].push_back(cache);
                }
            }
        }
    }
}

int main()
{
    Start();
    //BFS use to return COPY Vector
    //BFS
    toado Begin;
    toado End;
    cin >> Begin.x >> Begin.y;
    cout << "Begin " << matric[Begin.x][Begin.y] << endl;
    cin >> End.x >> End.y;
    cout << "End " << matric[End.x][End.y] << endl;
    BFS(Begin, End);
    for (int i = 0; i < DirecTion.size(); i++)
    {
        cout << DirecTion[i].first << " " << DirecTion[i].second << endl;
    }
    cout << endl
         << "This part print The martric has 0 and size on it " << endl;
    for (int i = 0; i < 22; i++)
    {
        for (int e = 0; e < 22; e++)
        {
            //cout<<V[i][e].size()<<" ";
        }
        //cout<<endl;
    }
    return 0;
}
