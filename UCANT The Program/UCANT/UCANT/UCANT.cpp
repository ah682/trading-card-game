// UCANT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class CCard {

};

vector<string> readPlayerFile(string filename);

time_t readSeedFile(string filename);

int Random(int max);

void drawCard(string player, vector <string> file_contents);

int main()
{
    // Initialises Random Number
    time_t seed = readSeedFile("seed.txt");
    srand(seed);

    // Welcomes message
    cout << "Welcome to U-Can't. Let the winnowing begin...' " << endl << endl;

    // Read files for player 1
    vector <string> player1_file_contents = readPlayerFile("plagiarist.txt");

    // Read files for player 2
    vector <string> player2_file_contents = readPlayerFile("piffle-paper.txt");

    drawCard("Player 1", player2_file_contents);
}


int Random(int max)
{
    return int(float(rand()) / (RAND_MAX + 1) * float(max));
}

vector <string> readPlayerFile(string filename) {
    vector<string> file_contents;

    
    // Read from the file
    ifstream file_stream(filename);
    if (file_stream.is_open()) {
        string line;
        while (getline(file_stream, line)) {
            file_contents.push_back(line);
        }
        file_stream.close();
    }
    else {
        std::cout << "Unable to open file " << filename << '\n';
    }

    return file_contents;
}

time_t readSeedFile(string filename) {
    time_t seed_value = 0;

    // Read from the file
    ifstream file_stream(filename);
    if (file_stream.is_open()) {
        string line;
        if (getline(file_stream, line)) {
            seed_value = stoi(line);
        }
        file_stream.close();
    }
    else {
        std::cout << "Unable to open file " << filename << '\n';
    }

    return seed_value;
}

void drawCard(string player, vector <string> file_contents) {
    // Chooses random number
    int randomCard = Random(file_contents.size());

    // Check if the vector has enough elements
    if (randomCard >= file_contents.size()) {
        cout << "Error: " << player << " has no cards to draw." << endl;
        return;
    }

    // Chooses random card
    string file_contents_random = file_contents[randomCard];

    // Announces which player has drawn a card and which card
    cout << player << " has drawn:" << endl << file_contents_random << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
