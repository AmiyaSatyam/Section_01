#include <iostream>
#include <string>
#include "FHitAndMissGame.h"

using int32 = int;

int main()
{
	FHitAndMissGame HMGame;
	HMGame.Reset();
	HMGame.PrintIntro();
	HMGame.PlayGame();


	return 0;
}