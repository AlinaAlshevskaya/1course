
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
//матрица смежности
#define V 10


void initAdjMatrix(int adjMatrix[V+1][V+1])
{
    
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int adjMatrix[V+1][V+1], int u, int v)
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void printAdjMatrix(int adjMatrix[V+1][V+1])
{
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
void bfs( int adjMatrix[V+1][V+1], int start)
{
    queue<int> q;

    bool visited[V+1];
    for (int i = 1; i <=V; i++) {
        visited[i] = false;
    }

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {

        int ind = q.front();
        q.pop();
        cout << ind << " ";
        for (int i = 1; i <=V; i++)
        {
            if (adjMatrix[ind][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void dfs(int adjMatrix[V + 1][V + 1], int start)
{
    stack <int> Stack;
    int visited[V+1]; 
    for (int i = 0; i <= V; i++) {
        visited[i] = 0;
    }
        Stack.push(start);
        while (!Stack.empty())
        { 
            int node = Stack.top(); 
            Stack.pop();
            if (visited[node] == 2) continue;
            visited[node] = 2;
            for (int j = V; j >= 0; j--)
            { 
                if (adjMatrix[node][j] == 1 && visited[j] != 2)
                { 
                    Stack.push(j); 
                    visited[j] = 1; 
                }
            }
            cout << node <<" "; 
        }
        
}



//список смежности
void addEdgeL(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printList(vector<int> adj[]) {
    for (int i = 1; i <= V; i++) {
        cout << "Вершина " << i << " связана с вершиной(ами): ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void bfsforList(vector<int> adj[], int start)
{
    deque<int> q;

    bool visited[V + 1];
    for (int i = 1; i <= V; i++)
    {
        visited[i] = false;
    }

    q.push_back(start);

    while (!q.empty())
    {
        int ind = q.front();
        q.pop_front();
        cout << ind << " ";
        for (int j = 0; j < adj[ind].size(); j++)
        {
            if (!(std::find(q.begin(), q.end(), adj[ind][j]) != q.end()) && !visited[adj[ind][j]] == 1)
            {
                q.push_back(adj[ind][j]);
            }
        }
        visited[ind] = true;
    }
}

void dfsforList(vector<int> adj[], int start)
{
    deque<int> stack;
    int visited[V + 1];
    for (int i = 0; i <= V; i++) {
        visited[i] = 0;
    }
    stack.push_front(start);
    while (!stack.empty())
    {
        int node = stack.front();
        stack.pop_front();
        if (visited[node] == 1) continue;
        visited[node] = 1;
        for (int j = 0; j<adj[node].size(); j++)
        {
            if (!(std::find(stack.begin(), stack.end(), adj[node][j]) != stack.end()) && visited[adj[node][j]] != 1)
            {
                stack.push_front(adj[node][j]);
            } 
        }
        visited[node] = 1;
        cout << node << " ";
    }

}



//Список ребер


struct Edge {
    int vertex1;
    int vertex2;
};

void addEdgeRebro(vector<Edge> &edges,int vertex1, int vertex2) {
    edges.push_back({vertex1,vertex2});
}

void printGraph(vector<Edge> edges) {
    for (int i = 0; i < edges.size();i++) {
        std::cout << "Ребро " << i + 1 << ": (" << edges[i].vertex1 << ", " << edges[i].vertex2 << ")\n";
    }
}

void bfsRebro(vector<Edge> edges, int start)
{
    deque<int> q;

    bool visited[V + 1];
    for (int i = 1; i <= V; i++)
    {
        visited[i] = false;
    }

    q.push_back(start);

    while (!q.empty())
    {
        int ind = q.front();
        q.pop_front();
        cout << ind << " ";
        for (int j = 0; j < edges.size(); j++)
        {
            if (edges[j].vertex1 == ind) {
                if (!(std::find(q.begin(), q.end(), edges[j].vertex2) != q.end()) && !visited[edges[j].vertex2] == 1)
                {
                    q.push_back(edges[j].vertex2);
                }
            }
            if (edges[j].vertex2 == ind) {
                if (!(std::find(q.begin(), q.end(), edges[j].vertex1) != q.end()) && !visited[edges[j].vertex1] == 1)
                {
                    q.push_back(edges[j].vertex1);
                }
            }
        }
        visited[ind] = true;
    }
}

void dfsRebro(vector<Edge> edges, int start)
{
    deque<int> stack;
    int visited[V + 1];
    for (int i = 0; i <= V; i++) {
        visited[i] = 0;
    }
    stack.push_front(start);
    while (!stack.empty())
    {
        int node = stack.front();
        stack.pop_front();
        if (visited[node] == 1) continue;
        visited[node] = 1;
        for (int j = 0; j < edges.size(); j++)
        {
            for (int j = 0; j < edges.size(); j++)
            {
                if (edges[j].vertex1 == node) {
                    if (!(std::find(stack.begin(), stack.end(), edges[j].vertex2) != stack.end()) && visited[edges[j].vertex2] != 1)
                    {
                        stack.push_front(edges[j].vertex2);
                    }
                }
                if (edges[j].vertex2 == node) {
                    if (!(std::find(stack.begin(), stack.end(), edges[j].vertex1) != stack.end()) && visited[edges[j].vertex1] != 1)
                    {
                        stack.push_front(edges[j].vertex1);
                    }
                }
            }
        }
        visited[node] = 1;
        cout << node << " ";
    }

}



int main()
{
    setlocale(LC_ALL, "russian");
    
    int adjMatrix[V + 1][V + 1];
    initAdjMatrix(adjMatrix);

    
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 5);
    addEdge(adjMatrix, 2, 8);
    addEdge(adjMatrix, 2, 7);
    addEdge(adjMatrix, 7, 8);
    addEdge(adjMatrix, 8, 3);
    addEdge(adjMatrix, 5, 6);
    addEdge(adjMatrix, 6, 4);
    addEdge(adjMatrix, 4, 9);
    addEdge(adjMatrix, 9, 10);

    cout << "Матрица смежности:" << endl;
   
    printAdjMatrix(adjMatrix);
    int start = 1;
    cout << "Список вершин при обходе в ширину начиная с вершины " << start << " :" << endl;
    bfs(adjMatrix, start);
    cout << endl<<"Список вершин при обходе в глубину начиная с вершины " << start << " :" << endl;
    dfs(adjMatrix, start);
    cout << endl<<endl;
    //
    //
    //
    vector<int> *adj = new vector<int>[V+1]; 
    
    addEdgeL(adj, 1, 2);
    addEdgeL(adj, 1, 5);
    addEdgeL(adj, 2, 7);
    addEdgeL(adj, 2, 8);
    addEdgeL(adj, 7, 8);
    addEdgeL(adj, 8, 3);
    addEdgeL(adj, 5, 6);
    addEdgeL(adj, 6, 4);
    addEdgeL(adj, 4, 9);
    addEdgeL(adj, 6, 9);
    addEdgeL(adj, 9, 10);

    cout << "Список смежности:" << endl;
    printList(adj);
    cout << "Список вершин при обходе в ширину начиная с вершины " << start << " :" << endl;
    bfsforList(adj, start);
    cout << endl << "Список вершин при обходе в глубину начиная с вершины " << start << " :" << endl;
    dfsforList(adj, start);
    cout << endl<<endl;
    //
    //
    //
    vector<Edge> edges;
    addEdgeRebro(edges, 1, 2);
    addEdgeRebro(edges, 1, 5);
    addEdgeRebro(edges, 2, 7);
    addEdgeRebro(edges, 2, 8);
    addEdgeRebro(edges, 7, 8);
    addEdgeRebro(edges, 8, 3);
    addEdgeRebro(edges, 5, 6);
    addEdgeRebro(edges, 6, 4);
    addEdgeRebro(edges, 4, 9);
    addEdgeRebro(edges, 9, 10);
    addEdgeRebro(edges, 9, 6);
    cout << "Список ребер:" << endl;
    printGraph(edges);
    cout << "Список вершин при обходе в ширину начиная с вершины " << start << " :" << endl;
    bfsRebro(edges, start);
    cout << endl << "Список вершин при обходе в глубину начиная с вершины " << start << " :" << endl;
    dfsRebro(edges, start);
    cout << endl << endl;



    return 0;
}
