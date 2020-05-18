#ifndef AISOLVER_BESTFS_GREEDYBFSQUEUEITEM_HPP
#define AISOLVER_BESTFS_GREEDYBFSQUEUEITEM_HPP

#include <vector>
#include <string>
#include "aisolver\core\core.hpp"

namespace aisolver
{
	class AI_API GreedyBFSQueueItem
	{
	public:
		std::vector<int> path;
		float gn;
		float hn;

		GreedyBFSQueueItem(std::vector<int> path, float gn, float hn);

		int getLastNode();
		void extendPath(int node, float gn, float hn);

	public:
		static GreedyBFSQueueItem& min(std::vector<GreedyBFSQueueItem> &queueItems);
	};
}

#endif //AISOLVER_BESTFS_GREEDYBFSQUEUEITEM_HPP