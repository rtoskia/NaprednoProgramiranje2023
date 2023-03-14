#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

// Definiranje na rankovi, oznaki i jokeri
const vector<string> ranks = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Dzandar", "Dama", "Kral"};
const vector<string> suits = {"Srce", "Diamant", "List", "Detelinka"};
const vector<string> jokers = {"Crn Joker", "Crven Joker"};

// Definira funkcija za kreiranje na spil na karti
vector<string> createDeck() {
    vector<string> deck;
    // Dodava karti vo spilot
    for (string rank : ranks) {
        for (string suit : suits) {
            deck.push_back(rank + " - " + suit);
        }
    }
    // Dodava Jokeri vo spilot
    for (string joker : jokers) {
        deck.push_back(joker);
    }
    return deck;
}

// Definira funkicija za da ispecati spilot na karti
void printDeck(vector<string> deck) {
    for (string card : deck) {
        cout << card << endl;
    }
}

// Definira funkcija za mesanje na spilot
void shuffleDeck(vector<string>& deck) {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(deck.begin(), deck.end(), default_random_engine(seed));
}

int main() 
{
    // Sozdava podreden spil na karti
    vector<string> deck = createDeck();
    // Pecati podreden spil na karti
    cout << "*Podreden spil na karti*" << endl;
    printDeck(deck);
    // Go mesa spilot na karti
    shuffleDeck(deck);
    // Go pecati mesaniot spil na karti
    cout <<"\n*Mesan spil na karti*" << endl;
    printDeck(deck);
    return 0;
}