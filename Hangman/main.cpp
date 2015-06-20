//
//  main.cpp
//  Hangman
//
//  Created by Bob on 18/06/2015.
//  Copyright (c) 2015 Bob. All rights reserved.
//

#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main(int argc, const char * argv[]) {

    string word;
    char guess;
    int noOfGuesses;
    
    //GET WORD TO GUESS
    cout << "Enter word to guess:";
    cin >> word;
    
    for( int i =0; i <= word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
        
    while (noOfGuesses != 5) {
        
        //ASK USER TO GUESS LETTER
        cout << "Guess a letter:\n";
        cin >> guess;
        
        //CHECK IF LETTER IS IN WORD
        size_t found = word.find(guess);
        
        while (found !=string::npos) {
            cout << guess << " is in the word, guess again" << endl;
            cin >> guess;
            found = word.find(guess);
        }
        
        cout << "letter not found\n";
        
        noOfGuesses = noOfGuesses + 1;
        
        switch (noOfGuesses) {
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
    
    return 0;
}
