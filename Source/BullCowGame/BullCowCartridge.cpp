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
        ProcessGuess(Input);
    }
}

void UBullCowCartridge::SetupGame()
{
    // Welcome the Player
    PrintLine(TEXT("Hello, cowpoke!"));

    HiddenWord = TEXT("machine"); // Set HiddenWord
    Lives = HiddenWord.Len(); // SetLives
    bGameOver = false;

    PrintLine(TEXT("Press Tab to start print in terminal."));
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Guess the %i letter word..."), HiddenWord.Len());
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress Enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
        {
            PrintLine(TEXT("You have won!"));
            EndGame();
            return;
        }

        if (Guess.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
            PrintLine(TEXT("Wrong answer, try again! You have %i lives remaining."), Lives);
            return;
        }

        --Lives;
        PrintLine(TEXT("Lost a life!"));

        if (Lives <= 0)
        {
            ClearScreen();
            PrintLine(TEXT("You have no lives left :("));
            PrintLine(TEXT("The hidden word was: $s"), *HiddenWord);

            EndGame();
            return;
        }

        PrintLine(TEXT("Wrong answer, try again! You have %i lives remaining."), Lives);
}