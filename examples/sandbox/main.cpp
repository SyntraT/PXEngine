#include "iostream"
#include "PXEngine.h"

int main() {
	PXEngine px;
	std::cout << "Starting PXEngine...!" << std::endl;
	px.init();
	px.run();
	return 0;
}