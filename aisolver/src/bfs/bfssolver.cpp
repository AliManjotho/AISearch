#include <iostream>
#include "aisolver\bfs\bfssolver.hpp"

namespace aisolver
{
	BFSSolver::BFSSolver()
	{
		this->q.push(5);
	}

	void BFSSolver::showQueue()
	{
		std::cout << this->q.size() << std::endl;
	}
}