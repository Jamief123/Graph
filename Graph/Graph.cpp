// Graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "GraphType.h"

void hardcodeGraph(GraphType<string> &graph);
using namespace std;
int main()
{
	GraphType<string> graph;
	hardcodeGraph(graph);
	
}

void hardcodeGraph(GraphType<string> &graph) {
	graph.AddVertex("Dallas");
	graph.AddVertex("Austin");
	graph.AddVertex("Chicago");
	graph.AddVertex("Denver");
	graph.AddVertex("Atlanta");
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

