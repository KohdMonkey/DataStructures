#include <vector>
#include <string>

enum NodeState {unvisited, visiting, visited};

struct Node {
    NodeState visited;
    int vertex;
    std::vector<Node*> neighbors;
};

struct Graph {
    std::vector<Node*> nodes;
};

Node* newNode(int vertex);
Graph* newGraph();


// adds a node to the graph
void addNode(Graph* graph, Node* node);

//add an edge from a node to another
void addAdjacent(Node* from, Node* to);
