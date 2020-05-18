#include <iostream>
#include <vector>
#include "aisolver\aisolver.hpp"

int main()
{
	// S = 0  Q = 1  W = 2
	// T = 3  R = 4  G = 5
	
	std::vector<int> nodes = { 0,1,2,3,4,5 };
	std::vector<std::string> alias = { "S","Q","W","T","R","G"};
	int initialNode = 0;
	int goalNode = 5;

	std::vector<std::vector<float>> adj = { { 0,1,6,7,0,0 },
										    { 0,0,4,0,1,0 }, 
										    { 0,0,0,3,0,2 },
										    { 0,0,0,0,0,2 },
										    { 0,0,2,0,0,1 }, 
										    { 0,0,0,0,0,0 }, };
	std::vector<int> path;

	aisolver::BFSSolver* bfs = new aisolver::BFSSolver(nodes, alias, adj, initialNode, goalNode);
	path = bfs->solve();
	//bfs->showQueue();
	//bfs->showPath();

	std::cin.get();
	return 0;
}