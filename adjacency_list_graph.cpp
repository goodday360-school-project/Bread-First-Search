#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Node {
public:
    int vertex;
    Node* next;

    Node(int v) {
        vertex = v;
        next = nullptr;
    }
};

class Graph {
private:
    int numVertices;

    // Array of linked lists
    vector<Node*> adjList;

public:
    Graph(int n) {
        numVertices = n;
        adjList.resize(n, nullptr);
    }

    void addEdge(int src, int dest) {

        // Add dest to src list
        Node* newNode = new Node(dest);
        newNode->next = adjList[src];
        adjList[src] = newNode;

        // Undirected graph:
        // Add src to dest list
        newNode = new Node(src);
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }

    void printAdjList() {

        cout << "Adjacency List:" << endl;

        for (int i = 0; i < numVertices; i++) {

            cout << (char)('A' + i) << " -> ";

            Node* temp = adjList[i];

            while (temp != nullptr) {
                cout << (char)('A' + temp->vertex);

                if (temp->next != nullptr)
                    cout << " -> ";

                temp = temp->next;
            }

            cout << endl;
        }

        cout << endl;
    }

    void BFS(int startVertex) {

        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS Traversal: ";

        while (!q.empty()) {

            int current = q.front();
            q.pop();

            cout << (char)('A' + current) << " ";

            // Traverse linked list of neighbors
            Node* temp = adjList[current];

            while (temp != nullptr) {

                int neighbor = temp->vertex;

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }

                temp = temp->next;
            }
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

    g.printAdjList();

    g.BFS(0);

    return 0;
}