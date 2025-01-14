#include <iostream>
using namespace std;

vector<vector<int>> *connected(int **edges, int n, bool *visited, int sv)
{
    visited[sv] = true;
    vector<vector<int>> *ans;
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 && !visited)
        {
            vector<int>
            connected(edges, n, visited, i);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
}