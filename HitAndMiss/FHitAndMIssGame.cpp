#pragma once

#include "FHitAndMIssGame.h"
#include <map>

#define TMap std::map
using int32 = int;

FHitAndMissGame::FHitAndMissGame()
{
	Reset();
}

int32 FHitAndMissGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,4},{4,7},{5,10},{6,16},{7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FHitAndMissGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FHitAndMissGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FHitAndMissGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FHitAndMissGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if(!IsLowerCase(Guess))	
	{
		return EGuessStatus::Not_LowerCase;
	}
	else if(Guess.length()!=GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

void FHitAndMissGame::Reset()
{
	const FString HIDDEN_WORD = "sprint";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;	
	bGameIsWon = false;
	return;
}

FHitAndMissCount FHitAndMissGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FHitAndMissCount HitAndMissCount;
	int32 WordLength = MyHiddenWord.length();	

	for (int32 i = 0; i < WordLength; i++)
	{
		for (int32 j = 0; j < WordLength; j++)
		{
			if (Guess[i] == MyHiddenWord[j] && i == j)
			{
				HitAndMissCount.Hits++;
			}
			else if(Guess[i] == MyHiddenWord[j] && i != j)
			{
				HitAndMissCount.Misses++;
			}
		}
	}
	if (HitAndMissCount.Hits == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return HitAndMissCount;
}

bool FHitAndMissGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FHitAndMissGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}



