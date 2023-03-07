// UCANT.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

vector<string> readCardType(string filename, int startChar, int endChar);

vector<string> readCardName(string filename);

time_t readSeedFile(string filename);

int Random(int max);

string drawCard(string player, vector <string> file_contents);

string drawName(string player, vector <string> file_contents);

void startRound(int round);

void graveYard();

void gameOver();

class CCard {

    public: 
    string cards;
    string power;
    string resilence;
    string type;
    string name;
};

struct SProfessor {
    string name;
    int prestige;
};

int main()
{
    // Initialises Random Number for seed
    time_t seed = readSeedFile("seed.txt");
    srand(102000);

    // Welcomes message
    cout << "Welcome to U-Can't. Let the winnowing begin...' " << endl << endl;

    // Reads file which holds deck for player 1 named plagiarist card types
    vector <string> player1_file_contents_type = readCardType("plagiarist.txt", 1, 1);

    // Reads file which holds deck for player 1 named plagiarist card names
    vector <string> player1_file_contents_name = readCardName("plagiarist.txt");

    // Read files which holds deck for player 2 named piffle-paper type
    vector <string> player2_file_contents_type = readCardType("piffle-paper.txt", 1, 1);

    //drawCard("Player 1", player2_file_contents);
    const int deckSize = 49;
    // Array of CCard Objects
    CCard* cardsplayer1 = new CCard[deckSize];
    CCard* cardsplayer2 = new CCard[deckSize];

     // Draw cards for player 1
    for (int i = 0; i < deckSize; i++) {
        cardsplayer1[i].type = drawCard("Player 1", player1_file_contents_type);
        cardsplayer1[i].name = drawName("Player 1", player1_file_contents_name);
    }

    // Draw cards for player 2
    for (int i = 0; i < deckSize; i++) {
        cardsplayer2[i].type = drawCard("Player 2", player2_file_contents_type);
    }

    // Deallocate Memory
    delete[] cardsplayer1;
    delete[] cardsplayer2;
}


int Random(int max)
{
    return int(float(rand()) / (RAND_MAX + 1) * float(max));
}

vector<string> readCardType(string filename, int startChar, int endChar) {
    vector<string> file_contents;

    // Read from the file
    ifstream file_stream(filename);
    if (file_stream.is_open()) {
        // Set the starting point in the file
        file_stream.seekg(startChar, ios::beg);

        // Read the characters within the specified range
        int charCount = endChar - startChar + 1;
        char* buffer = new char[charCount];
        file_stream.read(buffer, charCount);

        // Iterate to the end of the line
        char c;
        while (file_stream.get(c) && c != '\n') {}

        // Convert the character buffer to a string
        string file_contents_str(buffer, charCount);
        file_contents.push_back(file_contents_str);

        delete[] buffer;

        // Read the remaining lines in the file
        while (file_stream.good()) {
            string line;
            getline(file_stream, line);
            if (line.size() >= charCount) {
                file_contents.push_back(line.substr(0, charCount));
            }
        }

        file_stream.close();
    }
    else {
        std::cout << "Unable to open file " << filename << '\n';
    }

    return file_contents;
}

vector<string> readCardName(string filename) {
    vector<string> file_contents;

    // Read from the file
    ifstream file_stream(filename);
    if (file_stream.is_open()) {
        string line;
        while (getline(file_stream, line)) {
            // Find the positions of the first and second whitespace characters
            size_t pos1 = line.find_first_of(" \t");
            size_t pos2 = line.find_first_of(" \t", pos1 + 1);

            // If two whitespace characters are found, extract the card name
            if (pos2 != string::npos) {
                string name = line.substr(pos2 + 1);
                file_contents.push_back(name);
            }
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

    if (file_contents_random == "1") {
        // Announces which player has drawn a card and which card
        cout << player << " has drawn:" << endl << file_contents_random << endl;
        return file_contents_random;
    }
    // Return an empty string if card type is not 1
    return "";
}

string drawName(string player, vector <string> file_contents) {
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
    cout << "Game Over!" << endl << " " << "wins";
}
