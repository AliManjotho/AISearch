#include <iostream>
#include <vector>
#include "aisolver\aisolver.hpp"


int main()
{
	std::vector<int> nodes = { 0,1,2,3,4,5 };
	std::vector<std::string> alias = { "S","A","B","C","D","G" };
	std::vector<int> heuristics = { 10,2,3,1,4,0 };
	int initialNode = 0;
	int goalNode = 5;

	std::vector<std::vector<float>> adjacency = { { 0,2,5,0,0,0 },
												  { 0,0,0,2,4,0 },
												  { 0,0,0,0,0,5 },
												  { 0,0,0,0,3,0 },
												  { 0,0,0,0,0,2 },
												  { 0,0,0,0,0,0 } };

	aisolver::GreedyBFSSolver* greedybfs = new aisolver::GreedyBFSSolver(nodes, alias, heuristics, adjacency, initialNode, goalNode);
	greedybfs->solve();
	greedybfs->show();
	

	std::cin.get();
	return 0;
}