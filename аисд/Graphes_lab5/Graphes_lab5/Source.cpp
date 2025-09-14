#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define V 8
int adjMatrix[V + 1][V + 1];

void initMatrix(int Matrix[V + 1][V + 1])
{

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
                Matrix[i][j] = 0;
        }
    }
}
void addEdge(int Matrix[V + 1][V + 1], int u, int v, int value)
{

    Matrix[u][v] = value;
    Matrix[v][u] = value;
}

void printMatrix(int Matrix[V + 1][V + 1])
{
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
                printf("%5d", Matrix[i][j]);
        }
        cout << endl;
    }
}


void PrimAlg(int Matrix[V + 1][V + 1], int start)
{
    int strokai, strokaj, min = 99, s = 0;
    vector<int> visited;
    vector<int> rebra;
    
    visited.push_back(start);
    for (int i = 1; i <= V; i++) {
        if (Matrix[start][i] < min && Matrix[start][i]!=0) {
            min = Matrix[start][i];
            strokai = i;
       }
    }
    visited.push_back(strokai);
    s = s + min;
    rebra.push_back(min);



    while (visited.size() != V) {
        for (int k = 0; k < visited.size(); k++) {
            for (int j = 1; j <= V; j++)
            {
                Matrix[visited[k]][j] = 0;
            }

        }
        int mininside = 99;
        for (int k = 0; k < visited.size(); k++)
        {
            for (int i = 1; i <= V; i++) {

                if (Matrix[i][visited[k]] < mininside && Matrix[i][visited[k]] != 0) {
                    mininside = Matrix[i][visited[k]];
                    strokai = i;
                }

            }
        }
        s = s + mininside;
        min = mininside;
        visited.push_back(strokai);
        rebra.push_back(min);



    }

    int Ostrov[V + 1][V + 1];
    initMatrix(Ostrov);
    for (int i = 0; i < rebra.size(); i++) {
        Ostrov[visited[i]][visited[i + 1]] = rebra[i];
        Ostrov[visited[i + 1]][visited[i]] = rebra[i];
    }
    cout << "Матрица остовного дерева с помощью алгоритма Прима " << endl << endl;
    printMatrix(Ostrov);
    cout << endl << "Длина остового дерева = " << s << endl;
    cout << "Список вершин: " << endl;
    for (int f = 0; f < visited.size(); f++) {
        cout << visited[f] << " ";
    }
    cout << endl;
}


struct Edge {
    int src, dest, weight;
};

void matrixIntoVector(int Matrix[V + 1][V + 1], vector<Edge>& EdgeL) {
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (Matrix[i][j] != 0) {

                EdgeL.push_back({ i,j,Matrix[i][j] });
            }
        }
    }

}

void PrintVector(vector<Edge>& EdgeL) {
    for (int i = 0; i < EdgeL.size(); i++) {
        cout << EdgeL[i].src << " -- " << EdgeL[i].dest << " == " << EdgeL[i].weight << endl;
    }
}


bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Найти корень узла
int findRoot(vector<int>& parent, int i) {
    if (parent[i] == i)
        return i;
    return findRoot(parent, parent[i]);
}

// Объединить два поддерева
void unionTrees(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = findRoot(parent, x);
    int rootY = findRoot(parent, y);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void KruskallAlg(vector<Edge> edges) {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(V+1);
    vector<int> rank(V+1, 1);

    for (int i = 1; i <=V; i++)
        parent[i] = i;

    vector<Edge> mst;

    for (Edge& edge : edges) {
        int rootSrc = findRoot(parent, edge.src);
        int rootDest = findRoot(parent, edge.dest);

        if (rootSrc != rootDest) {
            mst.push_back(edge);
            unionTrees(parent, rank, rootSrc, rootDest);
        }
    }
    int s = 0;
    cout << "Список ребер остового дерева алгоритмом Крускала:\n";
    for (Edge& edge : mst) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
        s += edge.weight;

    }
    cout << endl << "Длина остового дерева = " << s << endl;

    
    
}











int main() {
    setlocale(LC_ALL, "russian");
    int matrix[V + 1][V + 1];
    initMatrix(matrix);

    addEdge(matrix, 1, 2, 2);
    addEdge(matrix, 1, 4, 8);
    addEdge(matrix, 1, 5, 2);
    addEdge(matrix, 2, 4, 10);
    addEdge(matrix, 2, 5, 5);
    addEdge(matrix, 2, 3, 3);
    addEdge(matrix, 3, 8, 7);
    addEdge(matrix, 3, 5, 12);
    addEdge(matrix, 4, 5, 14);
    addEdge(matrix, 4, 7, 1);
    addEdge(matrix, 4, 6, 3);
    addEdge(matrix, 6, 5, 11);
    addEdge(matrix, 6, 7, 6);
    addEdge(matrix, 5, 7, 4);
    addEdge(matrix, 7, 8, 9);
    addEdge(matrix, 5, 8, 8);

    vector<Edge> Edges;
    matrixIntoVector(matrix, Edges);

    printMatrix(matrix);
    cout << endl << endl;
    int start;
    cout << "Введите вершину : ";
    cin >> start;
    cout << endl << endl;
    PrimAlg(matrix,start);
    cout << endl << endl;
    cout << "Список ребер :" << endl;
    PrintVector(Edges);
    KruskallAlg(Edges);
    
    
}
