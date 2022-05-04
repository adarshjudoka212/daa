#include <iostream>
#include <climits>
using namespace std;
#define v 5
int parent[v];
bool visited[v] = {0};

int find(int i)
{
while (parent[i] != i)
i = parent[i];
return i;
}
void union1(int i, int j)
{
int a = find(i), b = find(j);
parent[a] = b;
}
int kruskal_mst(int cost[][v])
{
int mincost = 0;
int edge_count = 0;
for (int i = 0; i < v; i++)
parent[i] = i;
while (edge_count < v - 1)
{
int min = INT_MAX, a = -1, b = -1;
for (int i = 0; i < v; i++)
for (int j = 0; j < v; j++)
if (find(i) != find( j) &&
cost[i][ j] < min)
{
min = cost[i][ j];
a = i;
b = j;
}
union1(a, b);
mincost += min;
cout << "\n\t Edge " << edge_count++ << " ("
<< a << " , " << b << ") : " << min;
}
return mincost;
}

bool validEdge(int a, int b)
{
if (a == b || visited[a] == visited[b])
return false;
return true;
}
int prim_mst(int cost[][v])
{
int mincost = 0, edge_count = 0;
fill(visited, visited + v, false);
visited[0] = true;
while (edge_count < v - 1)
{
int min = INT_MAX, a = -1, b = -1;
for (int i = 0; i < v; i++)
for (int j = 0; j < v; j++)
if (cost[i][ j] < min &&
validEdge(i, j))
{
min = cost[i][ j];
a = i;
b = j;
}
visited[a] = visited[b] = true;
mincost += min;
cout << "\n\t Edge " << edge_count++ << " ("
<< a << " , " << b << ") : " << min;
}
return mincost;
}

int main()
{
int Graph[][v] = {
{INT_MAX, 5, INT_MAX, 4, INT_MAX},
{5, INT_MAX, 3, 4, 8},
{INT_MAX, 4, INT_MAX, INT_MAX,6},
{4,6, INT_MAX, INT_MAX, 8},
{INT_MAX, 3, 2, 7, INT_MAX},
};
cout << "\n\tMinimum Spanning Tree Algorithms";
cout << "\n\n Given Graph is :\n\n\t Edges : Weights\n";
for (int i = 0; i < v; i++)
for (int j = 0; j < v; j++)
if (Graph[i][j] != INT_MAX && !(visited[j]))
{
visited[i] = true;
cout << "\t " << i << " - " << j << " :\t" << Graph[i][j] << endl;
}
cout << "\n 1. Minimum Spanning Tree using Kruskal's Algorithm : \n";
int k = kruskal_mst(Graph);
cout << "\n\n\t Minimum Cost\t: " << k << endl;
cout << "\n 2. Minimum Spanning Tree using Prim's Algorithm : \n";
k = prim_mst(Graph);
cout << "\n\n\t Minimum Cost\t: " << k << endl;
}
