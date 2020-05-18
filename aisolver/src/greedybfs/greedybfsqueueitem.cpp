#include "aisolver\greedybfs\greedybfsqueueitem.hpp"

namespace aisolver
{
	GreedyBFSQueueItem::GreedyBFSQueueItem(std::vector<int> path, float gn, float hn)
	{
		this->path = path;
		this->gn = gn;
		this->hn = hn;
	}

	int GreedyBFSQueueItem::getLastNode()
	{
		return this->path.at(this->path.size() - 1);
	}

	void GreedyBFSQueueItem::extendPath(int node, float gn, float hn)
	{
		this->path.push_back(node);
		this->gn = this->gn + gn;
		this->hn = hn;
	}

	GreedyBFSQueueItem& GreedyBFSQueueItem::min(std::vector<GreedyBFSQueueItem> &queueItems)
	{
		int minIndex = 0;

		for (int i = 1; i < queueItems.size(); i++)
		{
			if (queueItems.at(i).hn < queueItems.at(minIndex).hn)
				minIndex = i;
		}

		return queueItems.at(minIndex);
	}
}