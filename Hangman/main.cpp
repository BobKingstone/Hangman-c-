//
//  main.cpp
//  Hangman
//
//  Created by Bob on 18/06/2015.
//  Copyright (c) 2015 Bob. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <locale>

using namespace std;

void displayGuessMessage(int *guessCount)
{
    switch (*guessCount) {
        case 1:
            cout << "4 guesses left\n";
            break;
        case 2:
            cout << "3 guesses left\n";
            break;
        case 3:
            cout << "2 guesses left\n";
            break;
        case 4:
            cout << "1 guess left\n";
            break;
        default:
            cout << "end of game, you lose\n";
            break;
    }
}


int main(int argc, const char * argv[]) {

    string word;
    string blanks;
    char placeholder;
    char guess;
    int noOfGuesses;
    bool won;
    
    placeholder = '*';
    won = false;
    noOfGuesses = 0;
    
    //GET WORD TO GUESS
    cout << "Enter word to guess:";
    cin >> word;
    
    for( int i =0; i <= word.length()-1; i++)
    {
        word[i] = tolower(word[i]);
        
        blanks = blanks + placeholder;
    }
    
    cout << "The word to guess is:\n" << blanks << endl;
    
    while ( !won && noOfGuesses != 5 ) {
        
        //ASK USER TO GUESS LETTER
        cout << "Guess a letter:\n";
        cin >> guess;
        
        //CHECK IF LETTER IS IN WORD
        size_t found = word.find(guess);
        
        if (found !=string::npos)
        {
            blanks[found] = guess;
            
            cout << guess << " is in the word\n" << blanks << "\n" << endl;
            
            size_t f = blanks.find(placeholder);
            
            if ( f == string::npos )
            {
                won = true;
            }
            
        }
        else
        {
            cout << "letter not found\n";
            
            noOfGuesses = noOfGuesses + 1;
            
            displayGuessMessage(&noOfGuesses);
        }
    }

    if (won)
    {
        cout << "congratulations you won";
    }
    else
    {
        cout << "you lost the word was\n" << word << endl;
    }
    
    return 0;
}
