#include <iostream>
#include "FHitAndMIssGame.h"

FHitAndMissGame::FHitAndMissGame()
{
	Reset();
}

void FHitAndMissGame::Reset()
{
	MyCurrentTry = 1;
	MaxTries = 7;
	MyHiddenWord = "plan";
	return;
}

void FHitAndMissGame::PrintIntro()
{
	std::cout << "Welcome to the Hit And Miss Game :-)\n";
	std::cout << "Guess the 4 letter Isogram:\n";
	return;
}

int32 FHitAndMissGame::PlayGame()
{
	std::cout << "Enter Your Guess: \n";
	do
	{
		std::cout << "Try " << MyCurrentTry << " Out of " << MaxTries << " Tries:   ";
		std::getline(std::cin, Guess);

		FCheckValidity(Guess);
		std::cout << "\nHits: " << HMCount.Hits << "\nMisses: " << HMCount.Misses << std::endl;
		MyCurrentTry++;
		HMCount.Hits = 0;
		HMCount.Misses = 0;
	} while (MyCurrentTry <= MaxTries);
	return 0;
}

void FHitAndMissGame::CheckGuessForError(std::string Guess)
{
	if(Guess.size()!=MyHiddenWord.size())
		
}

int32 FHitAndMissGame::PrintError(EError)
{
	EError C;
	switch (C)
	{
	case FHitAndMissGame::Not_Isogram:
		std::cout << "Your word should be an Isogram.";
		break;
	case FHitAndMissGame::Invalid_Length:
		std::cout << "Word Length must be " << MyHiddenWord.size() << " .";
		break;
	case FHitAndMissGame::Mixed_Cases:
		//Fix the Error
		break;
	default:
		break;
	}
	return 0;
}

void FHitAndMissGame::FCheckValidity(std::string Guess)
{
	for (int32 i = 0; i < 4; i++)
	{
		for (int32 j = 0; j < 4; j++)
		{
			if (MyHiddenWord[i] == Guess[j] && i == j)
			{
				HMCount.Hits++;
			}
			else if (MyHiddenWord[i] == Guess[j] && i != j)
			{
				HMCount.Misses++;
			}
		}
	}
	return;
}
