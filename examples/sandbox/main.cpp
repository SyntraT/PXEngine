#include "iostream"
#include "PXEngine.h"
#include "core/debug/debug.h"

int main() {
	PXEngine px;
	px.init();
	px.run();

	Logger::Instance().Stop();

	return 0;
}