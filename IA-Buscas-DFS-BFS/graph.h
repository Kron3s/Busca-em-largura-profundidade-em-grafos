#ifndef GRAPH_H
#define GRAPH_H


#include <list>
#include <string>
#include <stack>
#include<queue>
using namespace std;
class Graph
{
private:
int vertice;
list<int> *adj;



public:
    Graph(int v);
    void addAresta(int v, int  w);
    bool existeVisinho( int v1 , int v2);


     void BFS(int s, int w, list<int> *path);
    void DFS(int v, int w, list<int> *path);
    void DFSUtil(int v, bool visited[], int *parent,int w);
void findpath(int s, int w, int *parent,list<int> *path );
};






#endif // GRAPH_H
