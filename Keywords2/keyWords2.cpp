#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cctype>

using namespace std;


int main()
{
	bool playAgain = false;
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string UserName;
	string userChoiceToPlayAgain;
	// Create an int var to count the number of simulations being run starting at 1
	int simcounter = 1;
	const int MAX_WRONG = 3; //maximum number of incorrect guesses allowed
	vector<string> words({ "DECODE", "ESPIONAGE","HACK","ENIGMA","MAGIC","BUREAU","AGENT","TURNING","KNOX","TUTTE" }); // Create a collection of 10 words you had written down manually
	
	do
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.clear();
		// Display the simulation # is starting to the recruit.
		cout << "You are on simulation number " << simcounter << endl;
		//setup
		
		/*words.push_back("GUESS");
		words.push_back("HANGMAN");
		words.push_back("DIFFUCULT");*/
		// Ask the recruit to log in using their name
		cout << "Please log in with you username: ";
		cin >> UserName;

		srand(static_cast<unsigned int>(time(0)));

		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		for (int i = 0; i < 3; i++)
		{
			random_shuffle(words.begin(), words.end());

			const string THE_WORD = words[0];
			int wrong = 0;
			string soFar(THE_WORD.size(), '-');
			string used = "";

			// Display Title of the program to the user
			cout << "\nWelcome to the CIA.You are here to break the code scrambler from the terrorists.\n";
			// Display directions to the recruit on how to use Keywords
			cout << UserName <<"\nwill have to guess the letters of the hidden word three times to complete the mission.\n";

			//main loop
			while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
			{
				//     Tell recruit how many incorrect guesses he or she has left
				cout << "\n\nYou have " << (MAX_WRONG - wrong);
				cout << " incorrect guesses left.\n";
				//          Update the word guessed so far with the new letter
				cout << "\nYou've used the following letters:\n" << used << endl;
				//     Show player how much of the secret word he or she has guessed
				cout << "\nSo far, the word is:\n" << soFar << endl;

				//          Get recruit fs guess
				char guess;
				cout << "\n\nEnter your guess: ";
				cin >> guess;
				guess = toupper(guess); //make uppercase since secret word is uppercase

				while (used.find(guess) != string::npos)
				{
					cout << "\nYou've already guessed " << guess << endl;
					cout << "Enter your guess: ";
					cin >> guess;
					guess = toupper(guess);
				}

				used += guess;

				if (THE_WORD.find(guess) != string::npos)
				{
					cout << "That's right! " << guess << " is in the word.\n";
					//update soFar to include newly guessed letter
					for (int i = 0; i < THE_WORD.length(); ++i)
					{
						if (THE_WORD[i] == guess)
						{
							soFar[i] = guess;
						}
					}
				}
				else
				{
					cout << "Sorry, " << guess << " isn't in the word.\n";
					++wrong;
				}
			}

			//shut down
			if (wrong == MAX_WRONG)
			{
				cout << "\nYou failed decoding, the terrorist wins!\n";
			}
			//     Congratulate the recruit on guessing the secret words
			else
			{
				cout << "\nYou decoded it correctly, well done stopping the terrorist!\n";
			}
			cout << "The word was " << THE_WORD << "\n";
		}
		// Ask the recruit if they would like to run the simulation again
		cout << "\nWould you like to play again?(y/n)";
		cin >> userChoiceToPlayAgain;

		//to play again command
		//     Move program execution back up to // Display the simulation # is starting to the recruit. 
		if (userChoiceToPlayAgain == "Y" || userChoiceToPlayAgain == "y")
		{
			playAgain = true;
		}
		else
		{
			playAgain = false;
		}

		

	} while (playAgain);
	
	system("pause");

	return 0;

}