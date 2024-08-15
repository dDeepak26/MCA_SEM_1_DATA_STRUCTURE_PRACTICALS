#include <iostream.h>
#include <conio.h>

const int MAX_VERTICES = 10;

class Graph {
private:
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices;

public:
    Graph(int vertices);
    void addEdge(int start, int end);
    void dfs(int startVertex);
    void bfs(int startVertex);

private:
    void dfsRecursive(int currentVertex, int visited[]);
    void bfsTraversal(int startVertex, int visited[]);
};

Graph::Graph(int vertices) {
    numVertices = vertices;


    for (int i = 0; i < numVertices; ++i) {
	for (int j = 0; j < numVertices; ++j) {
	    adjacencyMatrix[i][j] = 0;
	}
    }
}

void Graph::addEdge(int start, int end) {

    adjacencyMatrix[start][end] = 1;
    adjacencyMatrix[end][start] = 1;
}

void Graph::dfs(int startVertex) {
    int visited[MAX_VERTICES] = {0};
    cout << "Depth-First Search starting from vertex " << startVertex << ": ";
    dfsRecursive(startVertex, visited);
    cout << endl;
}

void Graph::dfsRecursive(int currentVertex, int visited[]) {
    cout << currentVertex << " ";
    visited[currentVertex] = 1;

    for (int i = 0; i < numVertices; ++i) {
	if (adjacencyMatrix[currentVertex][i] && !visited[i]) {
	    dfsRecursive(i, visited);
	}
    }
}

void Graph::bfs(int startVertex) {
    int visited[MAX_VERTICES] = {0};
    cout << "Breadth-First Search starting from vertex " << startVertex << ": ";
    bfsTraversal(startVertex, visited);
    cout << endl;
}

void Graph::bfsTraversal(int startVertex, int visited[]) {
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    queue[++rear] = startVertex;
    visited[startVertex] = 1;

    while (front != rear) {
	int currentVertex = queue[++front];
	cout << currentVertex << " ";

	for (int i = 0; i < numVertices; ++i) {
	    if (adjacencyMatrix[currentVertex][i] && !visited[i]) {
		queue[++rear] = i;
		visited[i] = 1;
	    }
	}
    }
}

int main() {
    clrscr();

    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    if (numVertices > MAX_VERTICES) {
	cout << "Number of vertices exceeds the maximum limit." << endl;
	getch();
	return 0;
    }

    Graph graph(numVertices);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    int start, end;
    for (int i = 0; i < numEdges; ++i) {
	cout << "Enter edge " << i + 1 << " (start end): ";
	cin >> start >> end;

	if (start < 0 || start >= numVertices || end < 0 || end >= numVertices) {
	    cout << "Invalid vertex. Please enter valid vertices." << endl;
	    --i;
	} else {
	    graph.addEdge(start, end);
	}
    }

    int startVertex;
    cout << "Enter the starting vertex for traversal: ";
    cin >> startVertex;

    graph.dfs(startVertex);
    graph.bfs(startVertex);

    getch();
    return 0;
}
