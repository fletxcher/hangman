
	       
    # include <cstdio>
	# include <cstdlib>
	# include <iostream>
	# include <iomanip>
	# include <string>
	# include <algorithm>
	# include <vector>
	# include <stdlib.h>
	using namespace std;
	
	/* display welcome message and instructions */
	void intro(){
		system("cls");
		cout << "welcome to hangman!" << endl << endl;
	}

	/* the build function takes an integer as an input and outputs the corresponding section of the ascii art */
	int build(int section){
		switch(section){
			case 1: 
			{
				cout << setiosflags(ios::right) << setw(80) << " ========= " << endl;
			}
			break;

			case 2: 
			{
				cout << setiosflags(ios::right) << setw(80) <<  "         | " << endl;
                		cout << setiosflags(ios::right) << setw(80) <<  " ========= " << endl;
			}
			break;

			case 3: 
			{
				cout << setiosflags(ios::right) << setw(80) <<  "    / |  | " << endl;
	            		cout << setiosflags(ios::right) << setw(80) <<  "         | " << endl;
                		cout << setiosflags(ios::right) << setw(80) <<  " ========= " << endl;
			}
			break;

			case 4: 
			{
				cout << setiosflags(ios::right) << setw(80) <<  "    /||  | " << endl;
	        		cout << setiosflags(ios::right) << setw(80) <<  "    / |  | " << endl;
	        		cout << setiosflags(ios::right) << setw(80) <<  "         | " << endl;
            			cout << setiosflags(ios::right) << setw(80) <<  " ========= " << endl;
			}
			break;

			case 5: 
			{
				cout << setiosflags(ios::right) << setw(80) <<  "     O   | " << endl;
	        		cout << setiosflags(ios::right) << setw(80) <<  "    /||  | " << endl;
	        		cout << setiosflags(ios::right) << setw(80) <<  "    / |  | " << endl;
	        		cout << setiosflags(ios::right) << setw(80) <<  "         | " << endl;
            			cout << setiosflags(ios::right) << setw(80) <<  " ========= " << endl;
			}
			break;
	
			case 6: 
			{
				cout << setiosflags(ios::right) << setw(80) <<  "     |   | " << endl;
	        		cout << setiosflags(ios::right) << setw(80) <<  "     O   | " << endl;
	        		cout << setiosflags(ios::right) << setw(80) <<  "    /||  | " << endl;
	        		cout << setiosflags(ios::right) << setw(80) <<  "    / |  | " << endl;
	        		cout << setiosflags(ios::right) << setw(80) <<  "         | " << endl;
            			cout << setiosflags(ios::right) << setw(80) <<  " ========= " << endl;
			}
			break;

			case 7: 
			{
				cout << setiosflags(ios::right) << setw(80) <<  "     +---+ " << endl;
            			cout << setiosflags(ios::right) << setw(80) <<  "     |   | " << endl;
		        	cout << setiosflags(ios::right) << setw(80) <<  "     O   | " << endl;
		        	cout << setiosflags(ios::right) << setw(80) <<  "    /||  | " << endl;
		        	cout << setiosflags(ios::right) << setw(80) <<  "    / |  | " << endl;
		        	cout << setiosflags(ios::right) << setw(80) <<  "         | " << endl;
		            	cout << setiosflags(ios::right) << setw(80) <<  " ========= " << endl;
			}
			break;
		}
		return section;
	}
	
void game_loop() {
    int x;
    int z;

    /* choose a random word from the word bank using rand(), break it down into characters, then pass it into the vector 'secretWord', currently only using one word for experimentation */
    vector<char> secretWord;
    vector <string> wordBank = 
	{
		"abandon", "ability", "absence", "academy", "account", "accused", "achieve",
		"balance", "balloon", "banking", "bargain", "barrier", "battery", "bedroom",
		"cabinet", "calmness", "campaign", "capable", "capital", "capture", "careful",
		"daytime", "decibel", "decimal", "declare", "default", "defeat", "defense",
		"eagerly", "earring", "economy", "edition", "educate", "elderly", "element",
		"factory", "faculty", "failure", "fantasy", "fashion", "fateful", "federal",
		"gallery", "garbage", "gardens", "garment", "gateway", "general", "genuine",
		"haircut", "hallway", "handbag", "happily", "harbour", "harmony", "harvest",
		"iceberg", "illegal", "imagine", "impress", "improve", "include", "initial",
		"jaguar", "january", "jealous", "jewelry", "journal", "journey", "justice",
		"karaoke", "kayaker", "keeping", "kitchen", "knitted", "knowing", "kumquat",
		"lacking", "laptops", "largest", "lasting", "lawyers", "leading", "learned",
		"machine", "madness", "magical", "magnify", "mailbox", "manager", "mandate",
		"napkins", "nations", "natural", "nearest", "needing", "network", "neutral",
		"oakwood", "oatmeal", "obesity", "obscure", "offense", "officer", "offload",
		"pacific", "painter", "parents", "parking", "partial", "partner", "passion",
		"quality", "quantum", "quarter", "queens", "quickly", "quietly", "quizzes",
		"railway", "rainbow", "rations", "reasons", "receipt", "recover", "reflect",
		"sailing", "sandbox", "scandal", "scatter", "science", "seaside", "section",
		"talents", "tandems", "tangled", "tariffs", "teacher", "teacups", "tearing",
		"unicorn", "uniform", "unison", "unusual", "updated", "upgrade", "upwards",
		"vacancy", "vaccine", "vacuums", "valleys", "vampire", "vanilla", "variety",
		"waiting", "walkway", "wanting", "warrior", "wealthy", "weapons", "website",
		"xenonfx", "xylitol", "xylene", "xystics", "xenopus", "xenogam", "xerarch",
		"yachting", "yakking", "yawning", "yearned", "yellow", "yelling", "yipster",
		"zealots", "zealous", "zeniths", "zeroing", "zigzags", "zilches", "zipping" 
	};
	int index = rand() % wordBank.size();
    string randString = wordBank[index];
    for (z = 0; z < randString.size(); z++) {
        secretWord.push_back(randString[z]);
    }
    
    /* initialize an empty vector to store the letters as the player is piecing the word together */
    vector<char> charVector(secretWord.size(), '_');
    
    /* set maximum number of incorrect guesses to seven */
    int maxGuesses = 7;

    /* initialize an empty vector to store guessed letters */
    vector<char> previousGuess;

    /* initialize a variable to store guessed letters */
    char guessedLetter;

    /* initialize a variable to track incorrect guesses */
    int incorrectGuesses = 0;
    
    while (incorrectGuesses < maxGuesses and charVector != secretWord) {
    
    /* display the current state of the guessed word */
    for (char c : charVector) {
    cout << c << " ";
    }
    cout << endl;

    /* take the 'guessedLetter' and store it into a vector 'previousGuess' */
    cout << endl << "guess a letter: ";
    cin >> guessedLetter;
    
    /* if 'guessedLetter' is anywhere in the vector 'previousGuess' then it is an invalid guess and therefore warrants the following message */
    if (find(previousGuess.begin(), previousGuess.end(), guessedLetter) != previousGuess.end()){
    	cout << "letter has been previously guessed" << endl;
		incorrectGuesses++;
        cout << "number of incorrect guesses: " << incorrectGuesses << endl;
        cout << "remaining guesses: " << maxGuesses - incorrectGuesses << endl;
        build(incorrectGuesses);
    } 
    else {
    previousGuess.push_back(guessedLetter);
    /* if 'guessedLetter' is found anywhere within 'secretWord' then the guess is correct */
    if (find(secretWord.begin(), secretWord.end(), guessedLetter) != secretWord.end()) {
    	/* if 'guessedLetter' is correct then output 'correct letter!' and insert the character into the charVector, which will be displayed so that the player can visualize which letters belong to a particular index */
        cout << endl << "correct letter!" << endl;
        for (x = 0; x < secretWord.size(); x++) {
            if (secretWord[x] == guessedLetter) {
                charVector[x] = guessedLetter;
            }
        }
    } 
    else {
    	    /* output 'wrong letter!', the number of 'incorrectGuesses', the amount of guesses remaining, and build a portion of hangman */
            cout << "wrong letter!" << endl;
            incorrectGuesses++;
            cout << "number of incorrect guesses: " << incorrectGuesses << endl;
            cout << "remaining guesses: " << maxGuesses - incorrectGuesses << endl;
            build(incorrectGuesses);
            }
        }
    }
    
    	/* the '==' gets overloaded which allows for direct vector comparison */
		if (secretWord == charVector) {
			cout << endl;
			for (char v: charVector){
				cout << v << " ";
			}
			cout << endl << "you win!" << endl;
		} 
		else {
			cout << endl << "defeat!" << endl;
			cout << "The word was: " << randString << endl;
		}
    }
    
    /* allow the player to choose between another game and exiting the program */	
	void choose(){
		/* initialize a variable to track the players choice */
		string choice;
		
		/* make the choice to either play again or exit */
		cout << endl << "game over!" << endl;
		cout << endl<< "would you like to play again?" << endl;
		cout << endl << "type 'yes' or 'no': ";
		cin >> choice;
		while (true){
			if (choice == "yes"){
			/* clear the terminal and display intro once more */
			intro();
			/* call back the main game loop */
			game_loop();
			choose();
			}
			else if (choice == "no"){
				exit(0);
			}
		}
	}
		
	/* run the application in the command prompt */	
	int main(){
		intro();
		game_loop();
		choose();
		
		return 0;
	}	

