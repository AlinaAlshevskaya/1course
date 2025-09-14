#include <iostream>


using namespace std;
#define V 6
#define INF 99999
int adjMatrix[V +1][V +1];

void initMatrix(int Matrix[V + 1][V + 1])
{

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if(i==j)
            Matrix[i][j] = 0;
            else 
                Matrix[i][j] = INF;
        }
    }
}
void addEdge(int Matrix[V + 1][V + 1], int u, int v, int value)
{

    Matrix[u][v] = value;
}

void printMatrix(int Matrix[V + 1][V + 1])
{
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (Matrix[i][j] == INF)
                printf("%5s", "INF");
            else
            printf("%5d", Matrix[i][j]);
        }
        cout << endl;
    }
}

void initEdgeMatrix(int Matrix[V + 1][V + 1])
{

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (i == j)Matrix[i][j] = 0;
            else
            Matrix[i][j] = j;
        }
    }
}
void printEdgeMatrix(int Matrix[V + 1][V + 1])
{
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            printf("%4d", Matrix[i][j]);
        }
        cout << endl;
    }
}


void FloydWarshall(int Matrix[V+1][V+1]) {
    int EdgeMatrix[V + 1][V + 1];
    initEdgeMatrix(EdgeMatrix);
    printEdgeMatrix(EdgeMatrix);
    cout << endl << endl;
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (Matrix[i][j] > (Matrix[i][k] + Matrix[k][j]) && (Matrix[k][j] != INF && Matrix[i][k] != INF)) {
                    Matrix[i][j] = Matrix[i][k] + Matrix[k][j];
                    EdgeMatrix[i][j] = k ;
                }
            }
        }
    }
    printMatrix(Matrix);
    cout << endl << endl;
    printEdgeMatrix(EdgeMatrix);

    return;
}







int main() {
    setlocale(LC_ALL, "russian");
    int edgeMatrix[V + 1][V + 1];
    int matrix[V + 1][V + 1];
    initMatrix(matrix);

    addEdge(matrix, 1, 2, 28);
    addEdge(matrix, 2, 1, 7);
    addEdge(matrix, 1, 3, 21);
    addEdge(matrix, 3, 1, 9);
    addEdge(matrix, 2, 6, 9);
    addEdge(matrix, 6, 2, 18);
    addEdge(matrix, 3, 2,32);
    addEdge(matrix, 2, 3, 24);
    addEdge(matrix, 3, 5, 11);
    addEdge(matrix, 5, 3, 15);
    addEdge(matrix, 2, 5, 21);
    addEdge(matrix, 5, 2, 13);
    addEdge(matrix, 1, 5, 12);
    addEdge(matrix, 5, 1, 14);
    addEdge(matrix, 6, 5, 6);
    addEdge(matrix, 5, 6,22);
    addEdge(matrix, 6, 1, 15);
    addEdge(matrix, 1, 6, 27);
    addEdge(matrix, 5, 4, 10);
    addEdge(matrix, 4, 5, 16);
    addEdge(matrix, 1, 4, 59);
    addEdge(matrix, 4, 1, 8);
    addEdge(matrix, 4, 3, 5);
    addEdge(matrix, 3, 4, 13);
    

    printMatrix(matrix);
    cout << endl<<endl;

    FloydWarshall(matrix);
    
 


}