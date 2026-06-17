#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int n) : numVertices(n), adjMatrix(n, vector<int>(n, 0)) {}

    void addEdge(int i, int j) {
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1;
    }

    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS traversal starting from vertex " << (char)('A' + startVertex) << ": ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << (char)('A' + current) << " ";

            for (int neighbor = 0; neighbor < numVertices; neighbor++) {
                if (adjMatrix[current][neighbor] == 1 && !visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void printMatrix() {
        cout << "Adjacency Matrix:" << endl;
        cout << "   ";
        for (int i = 0; i < numVertices; i++)
            cout << (char)('A' + i) << " ";
        cout << endl;

        for (int i = 0; i < numVertices; i++) {
            cout << (char)('A' + i) << ": ";
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
};

int main() {

    Graph g(4);
    g.addEdge(0, 1); // A-B
    g.addEdge(0, 2); // A-C
    g.addEdge(0, 3); // A-D
    g.addEdge(1, 3); // B-D
    g.addEdge(2, 3); // C-D

    g.printMatrix();
    g.BFS(0);

    return 0;
}