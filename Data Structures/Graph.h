#ifndef _GRAPH_H_
#define _GRAPH_H_

#include<vector>
class graph{
	int size;
	std::vector<std::vector<int>> undirected_list;
	enum{UNDIRECTED_LIST,UNDIRECTED_MAT,DIRECTED_LIST,DIRECTED_MAT};
public:
	graph(int size);
	void addEdge(int node1, int node2);
	std::vector<int> connected_component();
};

#endif