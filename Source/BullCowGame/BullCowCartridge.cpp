// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame(); // Setting Up the Game
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Checking PlayerGuess
    {
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("You have won!"));
            EndGame();
        }
        else
        {
            if (Input.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The Hidden Word is %i charactest long. \nYou have lost!"), HiddenWord.Len());
                EndGame();
            }
        }
    }

    // Check if Isogram
    // Promprt to GuessAgain
    // Check if right number of characters
    // Promprt to GuessAgain

    // Remove Life

    // Check if Lives > 0
    // If YES GuessAgain
    // Show Lives Left
    // If NO Show GameOver and HiddenWord

    // Promprt to GuessAgain

    // Check User Input
    // PlayAgain or Quit
}

void UBullCowCartridge::SetupGame()
{
    // Welcome the Player
    PrintLine(TEXT("Hello, cowpoke!"));

    HiddenWord = TEXT("machine"); // Set HiddenWord
    Lives = 5; // SetLives
    bGameOver = false;

    PrintLine(TEXT("Press Tab to start print in terminal."));
    PrintLine(TEXT("Guess the %i letter word..."), HiddenWord.Len());
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press Enter to play again."));
}