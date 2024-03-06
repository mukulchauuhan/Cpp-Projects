/*The task problem statement is - Create a program that generates a random number and asks the user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    cout << "Bonjour! How is your day going ? - Ok let's play a Number Guessing Game" << endl;
    cout << "Instructions of the game are as follows : \n1. You have to guess the number(between 1 to 100) that will be generated when you play the game. \n2. If your guess is correct - Wohoo! You won it , else try again :)" << endl;

    srand(time(0));                       // Seeding the random number generator
    int Random_Number = rand() % 100 + 1; // Generating a random number between 1 to 100
    int user_guess = 0;

    bool keepRunning = true; // Control variable for the loop
    int choice{};
    while (keepRunning)
    {
        cout << "Enter your choice (1 for playing, 2 for exit): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Generating a random number......" << endl;
            while (user_guess != Random_Number)
            {
                cout << "Guess the number (between 1 and 100)" << endl;
                cin >> user_guess;
                if (cin.fail())
                {
                    cin.clear();             // Clearing the error flags
                    cin.ignore(10000, '\n'); /*Discarding the wrong input given by the user. The use of 10000 isn't strict; it's just a large number assumed to be bigger than any reasonable line of input for the scenario.
                    If we expect the user might input more characters than this in a single line (which is quite rare for most console applications), we could increase this number.
                    However, for typical uses, such as numbers or short strings, 10000 is more than sufficient to clear the buffer.*/
                    cout << "Please enter a valid number: ";
                    continue;
                }
                if (user_guess < Random_Number)
                {
                    cout << "The guess is too low! Try again: ";
                }
                else if (user_guess > Random_Number)
                {
                    cout << "The guess is too high! Try again: ";
                }
                else
                {
                    cout << "Congratulations! You've guessed the number correctly.\nWanna play again? ";
                }
            }
            break;

        case 2:
        {
            cout << "It was an amazing time playing with you :) May we meet again!";
            keepRunning = false; // This will end terminate the loop thus ending up the whole program. We can set it true to repeatedly ask the choice for the game until they quite the app.
            break;
        }
        default:
        {
            cout << "You have entered wrong input. Please enter either -> 1 for playing or 2 for exiting the game." << endl;
            break;
        }
        }
    }
    return 0;
}
