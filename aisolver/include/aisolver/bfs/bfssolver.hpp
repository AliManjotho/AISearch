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
		std::vector<int> nodes;
		std::vector<std::string> alias;
		std::vector<std::vector<float>> adjacency;
		std::vector<int> path;

	private:
		bool contains(std::vector<int> vector, int value);

	public:
		BFSSolver(std::vector<int> nodes, std::vector<std::string> alias, std::vector<std::vector<float>> adjacency, int initialNode, int goalNode);
		
		void showQueue();
		void showPath();
		std::vector<int> solve();
	};

}

#endif //AISOLVER_BFS_BFSSOLVER_HPP

