#pragma once

#include <iostream>
#include <string>
#include "FHitAndMissGame.h"

using int32 = int;
using FText = std::string;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FHitAndMissGame HMGame;

int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	
	return 0;
}

void PrintIntro()
{
	std::cout << "Welcome to Hit and Misse Word Game :-)\n";
	std::cout << std::endl;
	std::cout << "Can you guess the " << HMGame.GetHiddenWordLength();
	std::cout << " letter Isogram ?\n";
	std::cout << std::endl;

	return;
}

void PlayGame()
{
	HMGame.Reset();
	int32 MaxTries = HMGame.GetMaxTries();

	while (!HMGame.IsGameWon() && HMGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		FHitAndMissCount HitMissCount = HMGame.SubmitValidGuess(Guess);

		std::cout << "Hits: " << HitMissCount.Hits << std::endl;
		std::cout << "Misses " << HitMissCount.Misses << "\n\n";

	}
	PrintGameSummary();
	return;
}

FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		int32 CurrentTry = HMGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << HMGame.GetMaxTries();
		std::cout << "\tEnter your Guess: ";
		std::getline(std::cin, Guess);

		Status = HMGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << HMGame.GetHiddenWordLength() << " letter word\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters\n\n";
			break;
		case EGuessStatus::Not_LowerCase:
			std::cout << "Please enter all lower case letters\n\n";
			break;
		default:
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	
	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintGameSummary()
{
	if (HMGame.IsGameWon())
	{
		std::cout << "WELL DONE YOU WIN!\n";
	}
	else
	{
		std::cout << "You Lose\n";
	}

	return;
}