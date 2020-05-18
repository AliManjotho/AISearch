#include <iostream>
#include "aisolver\greedybfs\greedybfssolver.hpp"

namespace aisolver
{
	GreedyBFSSolver::GreedyBFSSolver(std::vector<int> nodes, std::vector<std::string> alias, std::vector<int> heuristics, std::vector<std::vector<float>> adjacency, int initialNode, int goalNode)
	{
		this->nodes = nodes;
		this->alias = alias;
		this->heuristics = heuristics;
		this->adjacency = adjacency;
		this->initialNode = initialNode;
		this->goalNode = goalNode;
	}

	void GreedyBFSSolver::solve()
	{
		//Add initial node to queue
		this->queue.push_back(GreedyBFSQueueItem({ initialNode }, 0.0f, this->heuristics.at(initialNode)));
		
		
		while (true)
		{
			GreedyBFSQueueItem* currentItem = &GreedyBFSQueueItem::min(this->queue);

			int lastNode = currentItem->getLastNode();



			std::vector<float> row = this->adjacency.at(lastNode);
			std::vector<int> childs;

			for (int i = 0; i < row.size(); i++)
			{
				if (row.at(i) != 0.0f)
				{					
					if (i == goalNode)
						return;
					else
						childs.push_back(i);
				}
			}

			int minIndex = 0;
			for (int i = 1; i < childs.size(); i++)
			{
				if (this->heuristics.at(childs.at(i)) < this->heuristics.at(childs.at(minIndex)))
					minIndex = i;
			}

			int newNode = childs.at(minIndex);

			currentItem->extendPath(newNode, this->adjacency.at(lastNode).at(newNode), this->heuristics.at(newNode));
		}
	}

	void GreedyBFSSolver::show()
	{
		GreedyBFSQueueItem* path = &GreedyBFSQueueItem::min(this->queue);
		
		for (int i = 0; i < path->path.size(); i++)
		{
			if (i != 0) std::cout << "->";
			std::cout << this->alias.at(path->path.at(i));
		}
		std::cout << std::endl;

		std::cout << "Cost = " << path->gn << std::endl;
		std::cout << "Heuristic = " << path->hn << std::endl;
	}
	
}