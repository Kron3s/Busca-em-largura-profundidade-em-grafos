#include "graph.h"
#include <iostream>


Graph::Graph(int v)
{
 this->vertice =  v;
    this->adj =  new list<int>[v];
}



void Graph::addAresta(int v , int w){
    this->adj[v].push_back(w);
    this->adj[w].push_back(v);

}


// função que rastreia o caminho  do no inicial até o final
void Graph::findpath(int s, int w, int *parent,list<int> *path){
      int currentV = w;
      while(parent[currentV]!= -1){
          path->push_back(currentV);
          currentV = parent[currentV];
      }
       path->push_back(s);
}

void Graph::BFS(int v, int w,list<int>*path)
{
    //  vetor para marca os nos visitados
    bool *visited = new bool[vertice];
    int *parent = new int[vertice];
    for(int i = 0; i < vertice; i++){
        visited[i] = false;
        parent[i] = -1;
}
    // cria uma lista que simula uma fila
    list<int> queue;


    visited[v] = true;
    queue.push_back(v);

    // i é um iterator que sera usado para percorre toda a lista de adj;
    // de um vertice
    list<int>::iterator i;
       int s;
    while(!queue.empty())
    {

        s = queue.front();
       // cout << s << " " << endl;
        queue.pop_front();
             if(s == w)
               break;
         // percorre os vertice adjacentes do vertice atual e insere na fila 
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                parent[*i] = s;
                queue.push_back(*i);
            }
        }
    }

   if(visited[w] != false ){
       findpath(v,w,parent,path);
   }




}

void Graph::DFS(int v , int w, list<int> *path)
{
    // Marca o vertices não visitados
    bool *visited = new bool[vertice];
    int *parent = new int[vertice];
    for (int i = 0; i < vertice; i++){
        visited[i] = false;
        parent[i] = -1;

}
    // chama a função recursiva;

    DFSUtil(v, visited, parent,w);
   /* for(int i = 0;i < vertice ;i++){
         cout << i << "é filho de "<< parent[i] << endl;
    }*/if(visited[w] != false ){
        findpath(v,w,parent,path);
    }
}

void Graph::DFSUtil(int v, bool visited[], int *parent, int w)
{
    // marca o no atual como visitado

    visited[v] = true;
   // cout << v << " " << endl;
       if(v == w)
           return;
    // recuperar  todos os vertices adjacentes
    // do vertice atual
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i]){
             parent[*i] = v;
            DFSUtil(*i, visited, parent,w);
        }
    }
}

// main
int main(){
    int v = 10;
    
    Graph graph(v);
    
        graph.addAresta(0, 1);
        graph.addAresta(0,2);
        graph.addAresta(0, 3);
        graph.addAresta(3, 2);
        graph.addAresta(3,4);
        graph.addAresta(4, 2);
        graph.addAresta(2, 1);
        graph.addAresta(2, 8);
        graph.addAresta(2,7);
        graph.addAresta(1, 5);
        graph.addAresta(1, 6);
        graph.addAresta(1, 7);
        graph.addAresta(7, 8);
         graph.addAresta(8,9);
        graph.addAresta(7, 9);
    // escolhe o estado incial eo final combase na posição do vetor
            // posiçoes     0    1    2     3   4    5    6   7      8   9
    vector<string>estados {"TO","PA","MT","GO","MS","AP","RR","AM","RO","AC"};
    list<int> resultado;
        graph.DFS(0,9,&resultado);
       // graph.BFS(0,9,&resultado);
     // quando recupera o caminho ele vem invertido de traz para frente
         resultado.reverse();  // reverte a ordem 
    
    
      
     for (auto it = resultado.begin();it != resultado.end();it++)
         cout << estados[*it] << endl;
     int i;
   /* for(i = 0;i < estados.size();i++){
         if(teste == t.at(i))
             break;
    }*/
}