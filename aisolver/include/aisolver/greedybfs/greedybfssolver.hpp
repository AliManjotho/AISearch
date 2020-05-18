#ifndef AISOLVER_BESTFS_BESTFSSOLVER_HPP
#define AISOLVER_BESTFS_BESTFSSOLVER_HPP

#include <vector>
#include <string>
#include "aisolver\core\core.hpp"
#include "aisolver\greedybfs\greedybfsqueueitem.hpp"

namespace aisolver 
{
	class AI_API GreedyBFSSolver
	{
	private:
		int initialNode;
		int goalNode;
		std::vector<int> nodes;
		std::vector<std::string> alias;
		std::vector<int> heuristics;
		std::vector<std::vector<float>> adjacency;
		std::vector<int> path;

	private:
		std::vector<aisolver::GreedyBFSQueueItem> queue;
		
	public:
		GreedyBFSSolver(std::vector<int> nodes, std::vector<std::string> alias, std::vector<int> heuristics, std::vector<std::vector<float>> adjacency, int initialNode, int goalNode);
		
		void solve();
		void show();
		
	};

}

#endif //AISOLVER_BESTFS_BESTFSSOLVER_HPP

