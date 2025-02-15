#pragma once
#include "queue.h"
const int NULL_EDGE = 0;

template<class VertexType>
class GraphType
{
public:
	GraphType();            // constructor, default of 50 vertices.
	GraphType(int maxV);    // parameterized constructor, maxV <= 50.
	~GraphType();           // destructor    

	void MakeEmpty();
	// Function: Initialize graph to the empty state.
	// Post: Graph is empty.
	bool IsEmpty() const;
	bool IsFull() const;
	// Function: Determines if the graph is full.
	// Post: Function value = (graph is full). 
	void AddVertex(VertexType);
	// Function: Adds vertex to the graph.
	// Pre:  Graph is not full.
	// Post: vertex is in V(graph)
	void AddEdge(VertexType, VertexType, int);
	// Function: Adds an edge with the specified
	// weight from fromVertex to toVertex.
	// Pre:  fromVertex and toVertex are in V(graph)
	// Post: (fromVertex, toVertex) is in E(graph)
	// with the specified weight.
	void RemoveEdge(VertexType, VertexType);
	int WeightIs(VertexType, VertexType);
	// Function: Determines the weight of the edge
	// from fromVertex to toVertex.
	// Pre:  fromVertex and toVertex are in V(graph)
	// Post: Function value = weight of 			//				(fromVertex, toVertex).
	void GetToVertices(VertexType, QueType<VertexType>&);
	// Function: Returns a queue of the vertices
	// that are adjacent from vertex.
	// Pre:  vertex is in V(graph).
	// Post: vertexQ contains the names of all
	// the vertices that are heads of edges for 	// which vertex is the tail.    
	void ClearMarks();
	// Function: Sets marks for all vertices to 	// false.
	// Post:  All makrs have been set to false.
	void MarkVertex(VertexType);
	// Function: Sets mark for vertex to true.
	// Pre:  vertex is in V(graph).
	// Post: IsMarked(vertex) is true.
	bool IsMarked(VertexType) const;
	// Function: Determines if vertex has been 	// marked.
	// Pre:  vertex is in V(graph).
	// Post: Function value = (vertex is marked 	// true)
	void DisplayFlights();
	bool FindAirport(VertexType vertex);


private:
	int numVertices;
	int maxVertices;
	VertexType* vertices;
	int edges[50][50];
	bool* marks; // marks[i] is mark for vertices[i].
};


template<class VertexType>
GraphType<VertexType>::GraphType()
// Post: Arrays of size 50 are dynamically allocated for
//       marks and vertices. numVertices is set to 0;
//       maxVertices is set to 50.
{
	numVertices = 0;
	maxVertices = 50;
	vertices = new VertexType[50];
	marks = new bool[50];
}

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
// Post: Arrays of size maxV are dynamically
// allocated for marks and vertices.
// numVertices is set to 0; maxVertices is set to maxV.
{
	numVertices = 0;
	maxVertices = maxV;
	vertices = new VertexType[maxV];
	marks = new bool[maxV];
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
// Post: arrays for vertices and marks have been   // deallocated.
{
	delete[] vertices;
	delete[] marks;
}

template<class VertexType>
void GraphType<VertexType>::MakeEmpty()
{

}


template<class VertexType>
bool GraphType<VertexType>::IsEmpty() const
{
	return (numVertices == 0);
}

template<class VertexType>
bool GraphType<VertexType>::IsFull() const
{
	return (numVertices == maxVertices);
}

template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
// Post: vertex has been stored in vertices.
//       Corresponding row and column of edges have been
// 	  set to NULL_EDGE.
//       numVertices has been incremented.
{
	//Not allowed to add duplicate vertex
	bool duplicate = false;
	for (int i = 0; i < numVertices; i++) {
		if (vertices[i] == vertex)
			duplicate = true;
	}

	if (!duplicate) {
		vertices[numVertices] = vertex;
		for (int index = 0; index < numVertices; index++)
		{
			edges[numVertices][index] = NULL_EDGE;
			edges[index][numVertices] = NULL_EDGE;
		}
		numVertices++;
	}
	else {
		cerr << "Cannot add duplicate vertex\n";
	}
	
}

template<class VertexType>
int IndexIs(VertexType * vertices,VertexType vertex)
	// Post: Function value = index of vertex in vertices.
{
	int index = 0;
	while (!(vertex == vertices[index]))
		index++;
	return index;
}

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex,VertexType toVertex, int weight)
	// Post: Edge (fromVertex, toVertex) is stored in edges.
{
	/*int row;
	int column;*/
	int row = IndexIs(vertices, fromVertex);
	int col = IndexIs(vertices, toVertex);
	edges[row][col] = weight;
}

template<class VertexType>
void GraphType<VertexType>::RemoveEdge(VertexType fromVertex, VertexType toVertex)
{
	int row = IndexIs(vertices, fromVertex);
	int col = IndexIs(vertices, toVertex);
	edges[row][col] = NULL_EDGE;
}

template<class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex,VertexType toVertex)
	// Post: Function value = weight associated with the
	// 		edge (fromVertex, toVertex).
{
	/*int row;
	int column;*/
	int row = IndexIs(vertices, fromVertex);
	int col = IndexIs(vertices, toVertex);
	return edges[row][col];
}

template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, QueType<VertexType>& adjvertexQ)
{
	int fromIndex;
	int toIndex;

	fromIndex = IndexIs(vertices, vertex);
	for (toIndex = 0; toIndex < numVertices; toIndex++)
		if (edges[fromIndex][toIndex] != NULL_EDGE)
			adjvertexQ.Enqueue(vertices[toIndex]);
}

template<class VertexType>
void GraphType<VertexType>::ClearMarks()
{
	for (int i = 0; i < maxVertices; i++) {
		marks[i] = false;
	}
}

template<class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType vertex)
{
	for (int i = 0; i < numVertices; i++) {
		if (vertex == vertices[i]) {
			marks[i] = true;
			break;
		}
	}

}

template<class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType vertex) const
{
	for (int i = 0; i < numVertices; i++) {
		if (vertices[i] == vertex) {
			return marks[i];
		}
	}
}

template<class VertexType>
void GraphType<VertexType>::DisplayFlights()
{
	//foreach vertex
	QueType<VertexType> q;
	VertexType adjVertex;
	int weight;
	for (int i = 0; i < numVertices; i++) {
		GetToVertices(vertices[i], q);
		//get adjacent vertices
		while (!q.IsEmpty()) {
			q.Dequeue(adjVertex);
			weight = WeightIs(vertices[i], adjVertex);
			cout << vertices[i] << " to " << adjVertex << " " << weight << endl;
		}
	}
	
}

template<class VertexType>
bool GraphType<VertexType>::FindAirport(VertexType vertex)
{
	for (int i = 0; i < numVertices; i++) {
		if (vertices[i] == vertex)
			return true;
	}
	return false;
}



