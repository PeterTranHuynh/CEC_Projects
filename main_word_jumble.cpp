// Word Jumble
// The classic word jumble game where the player can ask for a hint.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int score = 0;
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 6;
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."}
		{"potato", "French fries."}
	};
	
	srand(static_cast<unsigned int>(time(0)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];	// Word to guess
	string theHint = WORDS[choice][HINT];	// Hint for word

	string jumble = theWord;	// jumbled version of word
	int length = jumble.size();
	for (int i = 0; i < length; ++i)
	{
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "The jumble is: " << jumble;

	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	while ((guess != theWord) && (guess != "quit"))
	{
		if(guess == "hint")
		{
			cout << theHint;
		}
		else
		{
			cout << "\nSorry, that's not it." << endl;
			score--;
			cout << "Your score is: " << score << endl;
			return score;
		}
		
		cout << "\n\nYour guess: ";
		cin >> guess;
	}

	if(guess == theWord)
	{
		cout << "\nThat's all folks! You guessed it!" << endl;
		score++;
		cout << "Your score is: " << score << endl;
		return score;
	}
	cout <<"\nThanks for playing.\n";
	
	return 0;
}