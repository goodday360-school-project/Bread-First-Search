#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Edge {
public:
    int src;
    int dest;

    Edge(int s, int d) : src(s), dest(d) {}
};

class Graph {
private:
    int numVertices;
    vector<Edge> edgeList;

public:
    Graph(int n) : numVertices(n) {}

    void addEdge(int i, int j) {
        edgeList.push_back(Edge(i, j));
        edgeList.push_back(Edge(j, i)); // undirected, so store both directions
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

            // No matrix row or adjacency list to index into here:
            // we have to scan every triplet to find edges leaving "current".
            for (int e = 0; e < (int)edgeList.size(); e++) {
                if (edgeList[e].src == current) {
                    int neighbor = edgeList[e].dest;
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }

    void printEdgeList() {
        cout << "Edge List (src, dest):" << endl;
        for (int e = 0; e < (int)edgeList.size(); e++) {
            cout << "(" << (char)('A' + edgeList[e].src) << ", "
                 << (char)('A' + edgeList[e].dest) << ")" << endl;
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

    g.printEdgeList();
    g.BFS(0);

    return 0;
}