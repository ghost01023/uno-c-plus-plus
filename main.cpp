#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

#include "player.h"
#include "protodeck.h"
#include "card.h"
#include "deck.h"

//int randomSevenCards(ProtoDeck &r, ProtoDeck &y,
//                     ProtoDeck &g, ProtoDeck &b, Player &name);



int main() {
    cout << "Welcome to UNO!" << std::endl;
    Deck CompleteDeck{};
//    CompleteDeck.getFullDeck();
//    CompleteDeck.shuffleFullDeck();
//    cout << "After shuffling, the cards are as follows: " << endl;
//    CompleteDeck.getFullDeck();
    Card startingCard = CompleteDeck.GetRandomCard();
    int totalPlayers{};
    cout << "Enter the total number of players in the game: " << endl;
    cin >> totalPlayers;
    Player users[5]{};
    //ASK FOR EACH PLAYER'S NAME
    for (int i{0}; i < totalPlayers; i++) {
        cout << "Enter Player " << i + 1 << "'s name" << endl;
        string name{};
        cin >> name;
        users[i] = Player{name};
    }
    //GIVE EACH PLAYER THEIR SEVEN CARDS
    for (int k{0}; k < totalPlayers; k++) {
        for (int i{0}; i < 7; i++) {
            Card randomCard = CompleteDeck.GetRandomCard();
            users[k].AddCard(randomCard);
        }
        cout << "Added seven cards to " << users[k].getName() << endl;
    }
    int turnIndex{0};
    bool gameOn{true};

    //START MAIN GAME
    while (gameOn) {
        cout << "current color is " << startingCard.getColor()
             << " value is " << startingCard.getName() << endl;
        int playerNumber{turnIndex % totalPlayers};
        cout << users[playerNumber].getName() << "'s DECK: " << endl;
        users[playerNumber].ShowCards();
        int position{};
        cin >> position;
        //SKIP TURN FOR NOW
        if (position == 0) {
            turnIndex++;
            continue;
        }
        //CHECK FOR OUT-OF-BOUND
        if (position > size(users[playerNumber].cards)) {
            turnIndex--;
            continue;
        }
        if (users[playerNumber].cards.at(position - 1).getName() == startingCard.getName()
            || users[playerNumber].cards.at(position - 1).getColor() == startingCard.getColor()) {
            cout << "Well played." << endl;
            startingCard = users[playerNumber].cards.at(position - 1);
            users[playerNumber].PlayCard(position);
            if (size(users[playerNumber].cards) == 0) {
                cout << users[playerNumber].getName() << " WINS THE GAME." << endl;
                gameOn = false;
            }
            turnIndex++;
        }
    }
    return 0;
}

