#include <iostream>
#include <vector>
#include "aisolver\aisolver.hpp"


int main()
{
	std::vector<std::string> nodes = { "A","B","C","D","E","F","G","H" };
	std::string initialNode = "A";
	std::string goalNode = "G";

	std::vector<std::vector<float>> adj = { { 0,1,1,1,0,0,0,0 },
											{ 0,0,0,0,1,1,0,0 },
											{ 0,0,0,0,0,0,1,0 },
											{ 0,0,0,0,0,0,0,1 },
											{ 0,0,0,0,0,0,0,0 },
											{ 0,0,0,0,0,0,0,0 },
											{ 0,0,0,0,0,0,0,0 },
											{ 0,0,0,0,0,0,0,0 } };
	
	std::vector<int> path;

	aisolver::BFSSolver* bfs = new aisolver::BFSSolver(nodes, adj, initialNode, goalNode);
	path = bfs->solve();

	std::cout << "The BFS path = ";
	bfs->showPath();
	std::cout << "Path cost = " << bfs->getPathCost() << std::endl;


	std::cin.get();
	return 0;
}