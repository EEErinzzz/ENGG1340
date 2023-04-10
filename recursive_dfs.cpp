#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// global variable of Ajacency Matrix 邻接矩阵

const int MAX = 100;
int n,m;
int map[MAX][MAX];

bool visited[MAX];

vector<int> path; 
vector<vector<int>> pathlist;
// for current path recording

void display(vector<vector<int>> &v) 
{
    for (int i = 0; i < v.size(); i++) 
    {
        for (int j = 0; j < v[i].size(); j++) 
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}

void dfs(int scr) 
// This is a recursive dfs
{   
    // put source into visited list
    visited[scr] = true;
    path.push_back(scr);

    if (scr == n) 
    {   
        for (int i = 0; i < path.size() - 1; i++) 
        {
            cout << path[i] << " -> ";
        }
        cout << path.back() << endl;
        vector<int> copypath;
        for (int i = 0; i < path.size(); i++) 
        {
            copypath.push_back(path[i]);
        }
        pathlist.push_back(copypath);
    }
    else 
    {
        for (int i = 1; i <= n; i++) 
        {
            if (map[scr][i]) 
            {
                if (!visited[i]) 
                {
                    dfs(i);
                }
                else if (find(path.begin(), path.end(), i) == path.end())
                {
                    continue;
                }
            }
        }
    }

    visited[scr] = false;
    path.pop_back();
}

int main() 
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) 
    {
        int x,y;
        cin >> x >> y;
        map[x][y] = map[y][x] = 1;
    }
    dfs(1);
    display(pathlist);

    return 0;
}