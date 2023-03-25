#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
using namespace std;

#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

string randomizeCase(const string& inputString)
{
    // Initialize a string that will hold each letter
    string newString;

    // Iterate through each letter in the user's inputted
    // string and randomize its case
    for (int i = 0; i < inputString.length(); i++) {
        // Generate a random number between 1-3 to determine
        // whether to make the letter uppercase or lowercase
        int upperOrLower = rand() % 3 + 1;

        // If the number generated was 1, make the letter
        // selected lowercase
        if (upperOrLower == 1) {
            newString.push_back(tolower(inputString[i]));
        }

        // If the number generated was 2, make the letter
        // selected uppercase
        if (upperOrLower == 2) {
            newString.push_back(toupper(inputString[i]));
        }

        // If the number generated was 3, do not change
        // the letter's case
        if (upperOrLower == 3) {
            newString.push_back(inputString[i]);
        }
    }

    // Return the new randomized string
    return newString;
}

int main(int argc, char *argv[])
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Check if the required argument was passed
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input_string>" << endl;
        return 1;
    }

    // Convert the input string to a C++ string object
    string inputString(argv[1]);

    // Randomize the casing of the letters in the input string
    string newString = randomizeCase(inputString);

    // Print the new string in beautiful colors
    cout << CYAN << "Your new string is: " << GREEN << newString << RESET << endl;

    // Exit
    return 0;
}
