#include <iostream>
#include "aisolver\aisolver.hpp"

int main()
{
	aisolver::BFSSolver* bfs = new aisolver::BFSSolver();
	bfs->showQueue();

	std::cin.get();
	return 0;
}