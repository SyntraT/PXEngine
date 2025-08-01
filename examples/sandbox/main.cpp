#include "iostream"
#include "PXEngine.h"
#include "core/debug/debug.h"

int main() {
	PXEngine px;
	Debug::SetLevel(LogLevel::Warning);
	Debug::Info("Starting PXEngine...!");
	px.init();
	Debug::Warning("not init");
	px.run();
	return 0;
}