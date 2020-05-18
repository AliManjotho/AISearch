#include <iostream>
#include "aisolver\bfs\bfssolver.hpp"

namespace aisolver
{
	BFSSolver::BFSSolver(std::vector<int> nodes, std::vector<std::string> alias, std::vector<std::vector<float>> adjacency, int initialNode, int goalNode)
	{
		this->initialNode = initialNode;
		this->goalNode = goalNode;
		this->nodes = nodes;
		this->alias = alias;
	}


	std::vector<int> BFSSolver::solve()
	{
		this->path.empty();
		this->queue.push_back(initialNode);
			
		int currentNode = -1;

		showQueue();
		showPath();
		
		while (!this->queue.empty() || currentNode != goalNode)
		{
			currentNode = this->queue.at(0);
			this->queue.erase(this->queue.begin() + 0);

			this->path.push_back(currentNode);

			std::vector<float> row = this->adjacency.at(currentNode);

			for(int i = 0; i < row.size(); i++)
			{
				if (row.at(i) != 0.0f)
					this->queue.push_back(i);
			}
		}
		
		return this->path;
	}


	void BFSSolver::showQueue()
	{
		for (int i = 0; i < this->queue.size(); i++)
			std::cout << this->alias.at(this->queue.at(i)) << "->";
		std::cout << std::endl;
	}

	void BFSSolver::showPath()
	{
		for (int i = 0; i < this->path.size(); i++)
			std::cout << this->alias.at(this->path.at(i)) << "->";
		std::cout << std::endl;
	}

	bool BFSSolver::contains(std::vector<int> vector, int value)
	{
		for each(int val in vector)
			if (val == value) 
				return true;

		return false;
	}
}