// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "GraphType.h"
#include "queue.h"
#include "stack.h"
#include <string>
#include <vector>

int DisplayMenu();
void CheckForFlight();
void Exit();
void HardcodeGraph(GraphType<string> &graph);
void DepthFirstSearch(GraphType<string> &graph, string startVertex, string endVertex);
void BreadthFirstSearch(GraphType<string> &graph, string startVertex, string endVertex);

GraphType<string> graph;

using namespace std;
int main()
{
	HardcodeGraph(graph);

	string fromVertex, toVertex;
	int option;
	do{
		option = DisplayMenu();
		switch (option) {
		case 0:
			Exit();
			break;
		case 1:
			CheckForFlight();
			break;
		case 2:
			system("cls");
			graph.DisplayFlights();
			break;
		default:
			cout << "\nInvalid option\n";
			break;
		}
	} while (option != 0);
	
}

int DisplayMenu() {
	int option;
	cout << "\n0. Quit";
	cout << "\n1. Check for flight";
	cout << "\n2. View all flights";
	cout << "\n3. Add flight";
	cout << endl;
	cin >> option;
	
	return option;
}

void CheckForFlight() {
	string departure, destination;
	cout << "\nEnter departure airport\n";
	cin >> departure;
	cout << "\nEnter destination airport\n";
	cin >> destination;

	DepthFirstSearch(graph, departure, destination);

}

void Exit() {
	system("cls");
	cout << "\nThank you for flying with Moylish Airlines!\n";
}

void HardcodeGraph(GraphType<string> &graph) {

	graph.AddVertex("Atlanta");
	graph.AddVertex("Austin");
	graph.AddVertex("Chicago");
	graph.AddVertex("Dallas");
	graph.AddVertex("Denver");
	graph.AddVertex("Houston");
	graph.AddVertex("Washington");

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

void DepthFirstSearch(GraphType<string> &graph, string startVertex, string endVertex)
// Assumes VertexType is a type for which the “==“ and “<<“
// operators are defined.
{
	StackType<string> stack;
	QueType<string> vertexQ;
	bool found = false;
	string vertex;
	string item;
	graph.ClearMarks();
	vector<string> airports;
	stack.Push(startVertex);
	do
	{
		vertex = stack.Pop();
		if (vertex == endVertex)
		{
			cout << vertex;
			found = true;
			airports.push_back(vertex);
			//cout << endl << startVertex << " to " << endVertex << " is available.\n";
		}
		else
		{
			if (!graph.IsMarked(vertex))
			{
				graph.MarkVertex(vertex);
				//cout << vertex + " ";
				airports.push_back(vertex);
				graph.GetToVertices(vertex, vertexQ);
				while (!vertexQ.IsEmpty())
				{
					vertexQ.Dequeue(item);
					if (!graph.IsMarked(item))
						stack.Push(item);
				}
			}
		}
	} while (!stack.IsEmpty() && !found);
	if (!found) {
		system("cls");
		cout << endl << startVertex << " to " << endVertex << " is not available.\n";
	}
	else {
		system("cls");
		cout << endl << startVertex << " to " << endVertex << " is available.\n";
		for (string s : airports) {
			cout << s << " ";
		}
	}
}

void BreadthFirstSearch(GraphType<string> &graph, string startVertex, string endVertex)
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
		queue.Dequeue(vertex);
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
				cout << vertex << " ";
				graph.GetToVertices(vertex, vertexQ);
				while (!vertexQ.IsEmpty())
				{
					vertexQ.Dequeue(item);
					if (!graph.IsMarked(item))
						queue.Enqueue(item);
				}
			}
		}
	} while (!queue.IsEmpty() && !found);
	if (!found)
		cout << "Path not found." << endl;
}


//-----Priority Queue needed. Will come back to this
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

