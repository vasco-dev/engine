#include "GameLoop.h"

int main(int argv, char** args) {
	GameLoop::GetInstance()->RunGameLoop();
	return 0;
}