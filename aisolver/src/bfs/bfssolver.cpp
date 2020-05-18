#include <iostream>
#include "aisolver\bfs\bfssolver.hpp"

namespace aisolver
{
	BFSSolver::BFSSolver(std::vector<std::string> nodes, std::vector<std::vector<float>> adjacency, std::string initialNode, std::string goalNode)
	{
		this->nodes = nodes;
		this->initialNode = nodeAliastoInt(initialNode);
		this->goalNode = nodeAliastoInt(goalNode);		
		this->nodes_int = generateNodes(this->nodes);		
		this->adjacency = adjacency;
	}




	std::vector<int> BFSSolver::solve()
	{
		//Empty the path
		this->path.empty();

		//Push start node to queue
		this->queue.push_back(initialNode);
		this->visited.push_back(initialNode);
			
		int currentNode = -1;
		
		//Repeat until queue is empty or goal found
		while (!this->queue.empty())
		{			
			//Pop item from queue
			currentNode = this->queue.at(0);
			this->queue.erase(this->queue.begin() + 0);

			//Add current Node to queue
			this->path.push_back(currentNode);

			std::vector<float> row = this->adjacency.at(currentNode);

			for(int i = 0; i < row.size(); i++)
			{
				//Add node to queue if it is child of current node and 
				//it is not already visited 
				if (row.at(i) != 0.0f && !contains(this->visited, i))
				{
					this->queue.push_back(i);
					this->visited.push_back(i);

					if (i == goalNode)
					{
						this->path.push_back(i);
						return this->path;
					}
				}
			}
		}
		
		return this->path;
	}

	float BFSSolver::getPathCost()
	{
		float cost = 0.0f;

		for (int i = 0; i < this->path.size() - 1; i++)
			cost += this->adjacency.at(i).at(i + 1);

		return cost;
	}


	void BFSSolver::showQueue()
	{
		std::cout << "QUEUE : ";
		for (int i = 0; i < this->queue.size(); i++)
			std::cout << this->nodes.at(this->queue.at(i)) << " ";
		std::cout << std::endl;
	}

	void BFSSolver::showVisited()
	{
		std::cout << "VISITED : ";
		for (int i = 0; i < this->visited.size(); i++)
			std::cout << this->nodes.at(this->visited.at(i)) << " ";
		std::cout << std::endl;
	}

	void BFSSolver::showPath()
	{
		for (int i = 0; i < this->path.size(); i++)
		{
			if (i != 0) std::cout << "->";
			std::cout << this->nodes.at(this->path.at(i));
		}
			
		std::cout << std::endl;
	}

	bool BFSSolver::contains(std::vector<int> vector, int value)
	{
		for each(int val in vector)
			if (val == value) 
				return true;

		return false;
	}

	std::vector<int> BFSSolver::generateNodes(std::vector<std::string> alias)
	{
		std::vector<int> nds;

		for (int i = 0; i < alias.size(); i++)
			nds.push_back(i);

		return nds;
	}

	int BFSSolver::nodeAliastoInt(std::string node)
	{
		for (int i = 0; i < this->nodes.size(); i++)
		{
			if (this->nodes.at(i) == node)
				return i;
		}
	}
}