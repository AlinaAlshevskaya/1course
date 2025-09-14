
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
#define V 9
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
            printf("%5d",Matrix[i][j]);
        }
        cout << endl;
    }
}

void Dejkstra(int Matrix[V + 1][V + 1], int point)
{
    bool visited[V + 1];
    int distences[V + 1];
    int minindex = 0, min, temp;
    for (int i = 1; i <= V; i++)
    {
        distences[i] = 10000;
        visited[i] = 0;
    }
    distences[point] = 0;

    while (minindex < 10000)
    {
        minindex = 10000;
        min = 10000;
        for (int i = 1; i <= V; i++)
        {
            if ((visited[i] == 0) && (distences[i] < min))
            {
                min = distences[i];
                minindex = i;
            }
        }
        if (minindex != 10000)
        {
            for (int i = 1; i <= V; i++)
            {
                if (Matrix[minindex][i] > 0)
                {
                    int temp = min + Matrix[minindex][i];
                    if (temp < distences[i])
                    {
                        distences[i] = temp;
                    }
                }
            }
            visited[minindex] = 1;
        }
    }


        
        char alfabet[V + 1] = { ' ','A','B','C','D','E','F','G','H','I' };
        cout << endl << "Кратчайшие расстояния до вершин : " << endl;;
        for (int i = 1; i <= V; i++) 
        {
            cout << alfabet[point] << " -> " << alfabet[i] << " = " << distences[i] << endl;;
        }
}
    
        





int main() {
    setlocale(LC_ALL, "russian");

    int matrix[V + 1][V + 1];
    initMatrix(matrix);

    addEdge(matrix, 1, 2, 7);
    addEdge(matrix, 1, 3, 10);
    addEdge(matrix, 2, 6, 9);
    addEdge(matrix, 3, 6, 8);
    addEdge(matrix, 3, 5, 31);
    addEdge(matrix, 2, 7, 27);
    addEdge(matrix, 7, 9, 15);
    addEdge(matrix, 6, 8, 11);
    addEdge(matrix, 5, 4, 32);
    addEdge(matrix, 4, 8, 17);
    addEdge(matrix, 8, 9, 15);
    addEdge(matrix, 4, 9, 21);

    printMatrix(matrix);
    int userpoint;
    cout << "Введите номер интрересующей вершины(A-1,B-2,C-3,D-4,E-5,F-6,G-7,H-8,I-9) : ";
   cin >> userpoint;
   if (userpoint > 9 || userpoint < 1) {
       cout << "Такой вершины не найдено";
   }
   else{ Dejkstra(matrix, userpoint); }


}