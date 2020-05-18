#ifndef AISOLVER_BFS_BFSSOLVER_HPP
#define AISOLVER_BFS_BFSSOLVER_HPP

#include <vector>
#include <string>
#include "aisolver\core\core.hpp"

namespace aisolver 
{
	class AI_API BFSSolver
	{
	private:
		std::vector<int> queue;
		std::vector<int> visited;
		
		int initialNode;
		int goalNode;
		std::vector<int> nodes_int;
		std::vector<std::string> nodes;
		std::vector<std::vector<float>> adjacency;
		std::vector<int> path;

	private:
		bool contains(std::vector<int> vector, int value);
		std::vector<int> generateNodes(std::vector<std::string> alias);
		int nodeAliastoInt(std::string node);		

	public:
		BFSSolver(std::vector<std::string> alias, std::vector<std::vector<float>> adjacency, std::string initialNode, std::string goalNode);
		
		void showQueue();
		void showVisited();
		void showPath();
		std::vector<int> solve();
		float getPathCost();
	};

}

#endif //AISOLVER_BFS_BFSSOLVER_HPP

