// UCANT.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

vector<string> readPlayerFile(string filename);

time_t readSeedFile(string filename);

int Random(int max);

string drawCard(string player, vector <string> file_contents);

void startRound(int round);

void graveYard();

void gameOver();

class CCard {

    public: 
    string cards;
    int power;
    int type;
};

struct SProfessor {
    string name;
    int prestige;
};

int main()
{
    // Initialises Random Number for seed
    time_t seed = readSeedFile("seed.txt");
    srand(seed);

    // Welcomes message
    cout << "Welcome to U-Can't. Let the winnowing begin...' " << endl << endl;

    // Reads file which holds deck for player 1 named plagiarist
    vector <string> player1_file_contents = readPlayerFile("plagiarist.txt", 0, 1);

    // Read files which holds deck for player 2 named piffle-paper
    vector <string> player2_file_contents = readPlayerFile("piffle-paper.txt", 0, 1);

    //drawCard("Player 1", player2_file_contents);
    const int deckSize = 49;
    // Array of CCard Objects
    CCard* cardsplayer1 = new CCard[deckSize];
    CCard* cardsplayer2 = new CCard[deckSize];

     // Draw cards for player 1
    for (int i = 0; i < deckSize; i++) {
        cardsplayer1[i].cards = drawCard("Player 1", player1_file_contents);
    }

    // Draw cards for player 2
    for (int i = 0; i < deckSize; i++) {
        cardsplayer2[i].cards = drawCard("Player 2", player2_file_contents);
    }

    // Deallocate Memory
    delete[] cardsplayer1;
    delete[] cardsplayer2;
}


int Random(int max)
{
    return int(float(rand()) / (RAND_MAX + 1) * float(max));
}

vector<string> readPlayerFile(string filename, int startLine, int endLine) {
    vector<string> file_contents;

    // Read from the file
    ifstream file_stream(filename);
    if (file_stream.is_open()) {
        string line;
        int currentLine = 1;
        while (getline(file_stream, line)) {
            if (currentLine >= startLine && currentLine <= endLine) {
                file_contents.push_back(line);
            }
            currentLine++;
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

string drawCard(string player, vector <string> file_contents) {
    // Chooses random number
    int randomCard = Random(file_contents.size());

    // Check if the vector has enough elements
    if (randomCard >= file_contents.size()) {
        cout << "Error: " << player << " has no cards to draw." << endl;
        return "";
    }

    // Chooses random card
    string file_contents_random = file_contents[randomCard];

    // Announces which player has drawn a card and which card
    cout << player << " has drawn:" << endl << file_contents_random << endl;
    return file_contents_random;
}

void gameOver()
{
    cout << "Game Over!" << endl;
}
