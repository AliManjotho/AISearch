#include <iostream>
#include <vector>
#include "aisolver\aisolver.hpp"


int main()
{
	std::vector<std::string> nodes = { "S","Q","W","T","R","G"};
	std::string initialNode = "S";
	std::string goalNode = "G";

	std::vector<std::vector<float>> adj = { { 0,1,6,7,0,0 },
										    { 0,0,4,0,1,0 }, 
										    { 0,0,0,3,0,2 },
										    { 0,0,0,0,0,2 },
										    { 0,0,2,0,0,1 }, 
										    { 0,0,0,0,0,0 } };
	std::vector<int> path;

	aisolver::BFSSolver* bfs = new aisolver::BFSSolver(nodes, adj, initialNode, goalNode);
	path = bfs->solve();
	
	std::cout << "The BFS path = ";
	bfs->showPath();
	std::cout << "Path cost = " << bfs->getPathCost() << std::endl;
		

	std::cin.get();
	return 0;
}