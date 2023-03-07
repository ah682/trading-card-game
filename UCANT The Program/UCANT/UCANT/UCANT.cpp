// UCANT.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

vector<string> readCardType(string filename, int startChar, int endChar);

vector<string> readCardName(string filename);

vector<string> readCardPower(string filename);

time_t readSeedFile(string filename);

int Random(int max);

string drawCard(string player, vector <string> file_contents);

string drawName(string player, vector <string> file_contents);

string drawPower(string player, vector<string> powers);

void startRound(int round);

void graveYard();

void gameOver();

class CCard {
public:
    std::string type;
    std::string name;
    int power;
    int resilience;
    int boost;
};

int main() {
    std::ifstream file("plagiarist.txt");
    int num_cards = 0;
    std::string line;

    // Count the number of cards in the file
    while (std::getline(file, line)) {
        num_cards++;
    }

    // Allocate memory for the cards
    CCard* cards = new CCard[num_cards];

    // Read in the card data
    file.clear();
    file.seekg(0);
    for (int i = 0; i < num_cards; i++) {
        std::getline(file, line);
        std::stringstream ss(line);
        ss >> cards[i].type >> cards[i].name >> cards[i].power >> cards[i].resilience >> cards[i].boost;
    }

    // Example usage: print out the data
    for (int i = 0; i < num_cards; i++) {
        std::cout << cards[i].type << " " << cards[i].name << " " << cards[i].power << " " << cards[i].resilience << " " << cards[i].boost << std::endl;
    }

    // Free the memory
    delete[] cards;

    return 0;
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
            // Create a stringstream from the line
            stringstream ss(line);

            // Extract the second and third words separated by whitespace
            string word1, word2, word3;
            ss >> word1 >> word2 >> word3;

            // Combine the two words into one string and add it to the vector
            string name = word2 + " " + word3;
            file_contents.push_back(name);
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

vector<string> readCardPower(string filename) {
    vector<string> file_contents;

    // Read from the file
    ifstream file_stream(filename);
    if (file_stream.is_open()) {
        string line;
        while (getline(file_stream, line)) {
            // Create a stringstream from the line
            stringstream ss(line);

            // Extract the fourth word separated by whitespace
            string word1, word2, word3, power;
            ss >> word1 >> word2 >> word3 >> power;

            file_contents.push_back(power);
        }

        file_stream.close();
    }
    else {
        std::cout << "Unable to open file " << filename << '\n';
    }

    return file_contents;
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

string drawPower(string player, vector<string> powers) {
    // Check if the vector is empty
    if (powers.empty()) {
        cout << "Error: " << player << " has no powers to draw." << endl;
        return "";
    }

    // Chooses random number
    int randomPower = Random(powers.size());

    // Chooses random power
    string power = powers[randomPower];

    // Remove the power from the vector
    powers.erase(powers.begin() + randomPower);

    // Announces which player has drawn a power and which power
    cout << player << " has drawn the power: " << power << endl;
    return power;
}
void gameOver()
{
    cout << "Game Over!" << endl << " " << "wins";
}
