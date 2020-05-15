#include <iostream>
#include "Graph.hpp"


Node* newNode(int vertex) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = vertex;
    return node;
}

Graph* newGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    return graph;
}

void addAdjacent(Node* from, Node* to) {
    from->neighbors.push_back(to);
}

void addNode(Graph* graph, Node* node) {
    graph->nodes.push_back(node);
}
