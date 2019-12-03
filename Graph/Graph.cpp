// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "GraphType.h"
#include <vector> 
#include "queue.h"
#include "stack.h"
#include <string>

void hardcodeGraph(vector<string> &cities, GraphType<string> &graph);
//void listFlights(vector<string> cities, GraphType<string> graph);
void DepthFirstSearch(GraphType<string> graph, string startVertex, string endVertex);
void BreadthFirstSearch(GraphType<string> graph, string startVertex, string endVertex);



using namespace std;
int main()
{
	vector<string> cities;
	
	GraphType<string> graph;
	hardcodeGraph(cities,graph);
	graph.DisplayFlights();
	//graph.Test();
	/*cout << "-----Depth First Search-----\n";
	DepthFirstSearch(graph, "Austin", "Washington");
	cout << "\n\n-----Breadth First Search-----\n";
	BreadthFirstSearch(graph, "Austin", "Washington");
	cout << "\n\n-----Flights-----\n";*/
	
}



void hardcodeGraph(vector<string> &cities, GraphType<string> &graph) {

	graph.AddVertex("Atlanta");
	graph.AddVertex("Austin");
	graph.AddVertex("Chicago");
	graph.AddVertex("Dallas");
	graph.AddVertex("Denver");
	graph.AddVertex("Houston");
	graph.AddVertex("Washington");

	cities.push_back("Dallas");
	cities.push_back("Austin");
	cities.push_back("Chicago");
	cities.push_back("Denver");
	cities.push_back("Atlanta");
	cities.push_back("Houston");
	cities.push_back("Washington");

	graph.AddEdge("Austin", "Dallas", 200);
	graph.AddEdge("Austin", "Houston", 160);
	graph.AddEdge("Dallas","Austin", 200);
	graph.AddEdge("Dallas", "Chicago", 900);
	graph.AddEdge("Dallas", "Denver", 780);
	graph.AddEdge("Chicago", "Denver", 1000);
	graph.AddEdge("Denver", "Chicago", 1000);
	graph.AddEdge("Denver", "Atlanta", 1400);
	graph.AddEdge("Houston", "Atlanta", 800);
	graph.AddEdge("Atlanta", "Houston", 800);
	graph.AddEdge("Atlanta", "Washington", 600);
	graph.AddEdge("Washington", "Atlanta", 600);
	graph.AddEdge("Washington", "Dallas", 1300);
}


void DepthFirstSearch(GraphType<string> graph, string startVertex, string endVertex)
// Assumes VertexType is a type for which the “==“ and “<<“
// operators are defined.
{
	StackType<string> stack;
	QueType<string> vertexQ;
	bool found = false;
	string vertex;
	string item;
	graph.ClearMarks();
	stack.Push(startVertex);
	do
	{
		vertex = stack.Pop();
		if (vertex == endVertex)
		{
			cout << vertex;
			found = true;
		}
		else
		{
			if (!graph.IsMarked(vertex))
			{
				graph.MarkVertex(vertex);
				cout << vertex + " ";
				graph.GetToVertices(vertex, vertexQ);
				while (!vertexQ.IsEmpty())
				{
					item = vertexQ.Dequeue();
					if (!graph.IsMarked(item))
						stack.Push(item);
				}
			}
		}
	} while (!stack.IsEmpty() && !found);
	if (!found)
		cout << "Path not found." << endl;
}

void BreadthFirstSearch(GraphType<string> graph, string startVertex, string endVertex)
	// Assumes VertexType is a type for which the “==“ and “<<“
	// operators are defined.
{
	QueType<string> queue;
	QueType<string> vertexQ;
	bool found = false;
	string vertex;
	string item;
	graph.ClearMarks();
	queue.Enqueue(startVertex);
	do
	{
		vertex = queue.Dequeue();
		if (vertex == endVertex)
		{
			cout << vertex;
			found = true;
		}
		else
		{
			if (!graph.IsMarked(vertex))
			{
				graph.MarkVertex(vertex);
				cout << vertex;
				graph.GetToVertices(vertex, vertexQ);
				while (!vertexQ.IsEmpty())
				{
					item = vertexQ.Dequeue();
					if (!graph.IsMarked(item))
						queue.Enqueue(item);
				}
			}
		}
	} while (!queue.IsEmpty() && !found);
	if (!found)
		cout << "Path not found." << endl;
}


//template<class VertexType>
//struct ItemType
//{
//	bool operator<(ItemType otherItem);
//	// < means greater distance
//	bool operator==(ItemType otherItem);
//	bool operator<=(ItemType otherItem);
//	VertexType fromVertex;
//	VertexType toVertex;
//	int distance;
//};
//
//template<class VertexType>
//void ShortestPath(GraphType<VertexType> graph,VertexType startVertex)
//{
//	ItemType item;
//	int minDistance;
//	PQType<ItemType> pq(10); 							// Assume at most 10 vertices
//	QueType<VertexType> vertexQ;
//	VertexType vertex;
//	int count = 0;
//	graph.ClearMarks();
//	item.fromVertex = startVertex;
//	item.toVertex = startVertex;
//	item.distance = 0;
//	pq.Enqueue(item);
//	cout << “Last Vertex Destination Distance” << endl;
//	cout << “----------------------------------” << endl;
//	do
//	{
//		pq.Dequeue(item);
//		if (!graph.IsMarked(item.toVertex))
//		{
//			graph.MarkVertex(item.toVertex);
//			cout << item.fromVertex;
//			cout << " ";
//			cout << item.toVertex;
//			cout << " " << item.distance << endl;
//			item.fromVertex = item.toVertex;
//			minDistance = item.distance;
//			graph.GetToVertices(item.fromVertex,
//				while (!vertexQ.IsEmpty()) {
//					vertexQ.Dequeue(vertex);
//					if (!graph.IsMarked(vertex))
//					{
//						item.toVertex = vertex;
//						item.distance = minDistance + graph.WeightIs(item.fromVertex, vertex);
//						pq.Enqueue(item);
//					}
//				}
//		}
//	} while (!pq.IsEmpty());
//}

