#pragma once
#include <string>

using int32 = int;

class FHitAndMissGame
{
public:
	FHitAndMissGame();
	void Reset();
	void PrintIntro();
	void FCheckValidity(std::string);
	enum EError{Not_Isogram, Invalid_Length, Mixed_Cases};
	struct FHitAndMissCount
	{
		int32 Hits;
		int32 Misses;
	}HMCount{0,0};
	
	int32 PlayGame();
	void CheckGuessForError(std::string);
	int32 PrintError(EError);

	std::string Guess = "";
private:
	int32 MyCurrentTry;
	int32 MaxTries;
	std::string MyHiddenWord;
};