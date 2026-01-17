#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	char playAgain;
	do{
    cout << "Welcome To the Number Guessing Game!" << endl;
	int level;
int maxNumber;

cout << "Choose difficulty level:" << endl;
cout << "1 - Easy (1 to 10)" << endl;
cout << "2 - Medium (1 to 50)" << endl;
cout << "3 - Hard (1 to 100)" << endl;
cout << "Enter 1, 2, or 3: ";
cin >> level;

// set the max number based on choice
if(level == 1){ maxNumber = 10;}
else if(level == 2){ maxNumber = 50;}
else if(level==3){
maxNumber = 100;}
else {
    cout << "Invalid choice. Defaulting to Hard (1-100)." << endl;
    maxNumber = 100;
}

    srand(time(0));
    int secret = rand() % maxNumber + 1;  // generate secret number
    int guess = 0;
    int attempts = 0;

    // Ask player if they want to see the secret number (for testing)
    char show;
    cout << "Do you want to see the secret number to test the correct condition? (y/n): ";
    cin >> show;
    if(show == 'y' || show == 'Y')
        cout << "DEBUG: Secret number = " << secret << endl;

    cout << "Guess a number between 1 and 100: ";

    while(guess != secret) {
        cin >> guess;

        // Input validation
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Please enter a valid number: ";
            continue;
        }

        attempts++; // increment attempts

        if(guess > secret)
            cout << "Too High! Try again: ";
        else if(guess < secret)
            cout << "Too Low! Try again: ";
        else {
            cout << "Congratulations! You guessed the number right!" << endl;
            cout << "Number of attempts: " << attempts << endl;
            cout << endl;
        }
    }
cout<<"Do you want to play again(y/n):";
cin>>playAgain;
cout<<endl;
	}while(playAgain=='y'||playAgain=='Y');
	
    return 0;
}