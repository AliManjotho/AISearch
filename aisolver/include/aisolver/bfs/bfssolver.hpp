#ifndef AISOLVER_BFS_BFSSOLVER_HPP
#define AISOLVER_BFS_BFSSOLVER_HPP

#include <queue>
#include "aisolver\core\core.hpp"

namespace aisolver 
{
	class AI_API BFSSolver
	{
	private:
		std::queue<int> q;

	public:
		BFSSolver();
		
		void showQueue();
	};

}

#endif //AISOLVER_BFS_BFSSOLVER_HPP

