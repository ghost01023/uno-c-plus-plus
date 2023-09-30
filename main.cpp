#include <iostream>
#include <vector>
//#include <windows.h>

using namespace std;

#include "player.h"
#include "protodeck.h"
#include "card.h"
#include "deck.h"

//int randomSevenCards(ProtoDeck &r, ProtoDeck &y,
//                     ProtoDeck &g, ProtoDeck &b, Player &value);



int main() {
    cout << "Welcome to UNO!" << std::endl;
    Deck CompleteDeck{};
    CompleteDeck.getFullDeck();
    CompleteDeck.shuffleFullDeck();
    CompleteDeck.getFullDeck();
//    CompleteDeck.getFullDeck();
//    CompleteDeck.shuffleFullDeck();
//    cout << "After shuffling, the cards are as follows: " << endl;
//    CompleteDeck.getFullDeck();
    Card activeCard = CompleteDeck.GetRandomCard();
    int totalPlayers{};
    cout << "Enter the total number of players in the game: " << endl;
    cin >> totalPlayers;
    Player users[10]{};
    //ASK FOR EACH PLAYER'S NAME
    for (int i{0}; i < totalPlayers; i++) {
        cout << "Enter Player " << i + 1 << "'s value" << endl;
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
    int turnIndex{totalPlayers * 1000};
    int cardBuffer {1};
    bool gameOn{true};

    //START MAIN GAME
    while (gameOn) {
        if (activeCard.getValue() == "plusFour") {
            string newColor {};
            cout << "Enter color you want to switch to: " << endl;
            cin >> newColor;
            activeCard.setColor(newColor);
            activeCard.removeSpec();
            cout << "Plus four3 added to buffer now equal to " << cardBuffer << endl;
            cardBuffer += 3;
        }
        else if (activeCard.getValue() == "plusTwo") {
            cardBuffer += 1;
            cout << "Plus two added to buffer now equal to " << cardBuffer << endl;
        }
        else if (activeCard.getValue() == "colorChange") {
            string newColor {};
            cout << "Enter color you want to switch to: " << endl;
            cin >> newColor;
            activeCard.setColor(newColor);
            activeCard.removeSpec();
        }
        else if (activeCard.getValue() == "cancel") {
            turnIndex ++;
        } else if (activeCard.getValue() == "reverse") {
            //REVERSE PLAYER ARRAY
            int rev {totalPlayers - 1};
            for (int i {0}; i < totalPlayers / 2; i++) {
                Player temp = users[i];
                users[i] = users[rev];
                users[rev] = temp;
                turnIndex-= 2;
            }
        }
        cout << "Current Card: " << activeCard.represent() << endl;
//        short ctrlPressed = GetKeyState(VK_LCONTROL);
//        bool isToggled = ctrlPressed & 1;
//        bool isDown = ctrlPressed & 0x8000;
//        if (isDown) {
//            cout << "l-control is pressed." << endl;
//        }
//        short capP = GetKeyState(VK_CAPITAL);
//        bool iT = capP & 1;
//        bool iD = capP & 0x8000;
//        if (iT) {
//            cout << "caps lock is toggled!" << endl;
//        }
        int playerNumber{turnIndex % totalPlayers};
        cout << users[playerNumber].getName() << "'s DECK: " << endl;
        users[playerNumber].ShowCards();
        int position{};
        cin >> position;
        //SKIP TURN FOR NOW
        if (position == 0) {
            turnIndex++;
//            cardBuffer++;
            for (int i {0}; i < cardBuffer; i++) {
                Card newCard {CompleteDeck.GetRandomCard()};
                users[playerNumber].AddCard(newCard);
            }
            cardBuffer = 1;
            continue;
        }
        //CHECK FOR OUT-OF-BOUND
        if (position > size(users[playerNumber].cards)) {
            turnIndex--;
            continue;
        }
        //GENERATE PLACEHOLDER ON CONDITIONALS
        Card placeHolder{};
        if (activeCard.getValue() == "plusFour" || activeCard.getValue() == "plusTwo"
        || activeCard.getValue() == "colorChange") {
            cout << "Changing to placeholder card as active card" << endl;
            placeHolder = Card(activeCard.getColor(), "placeholder");
            activeCard = placeHolder;
        }
//        if (activeCard.)
        //RESUME GAME NORMALLY IF ABOVE CHECKS PASS
//        //IF NORMAL CARD EXISTS ON DRAW PILE (0-9)
//        if (activeCard.isSpecial())
        if (activeCard.cardValidity(users[playerNumber].cards.at(position - 1))) {
            cout << "Well played." << endl;
            activeCard = users[playerNumber].cards.at(position - 1);
            users[playerNumber].PlayCard(position);
            if (size(users[playerNumber].cards) == 0) {
                cout << users[playerNumber].getName() << " WINS THE GAME." << endl;
                gameOn = false;
            }
            turnIndex++;
        } else {
            cout << "Wrong card choice. Try again." << endl;
        }
//        if (users[playerNumber].cards.at(position - 1).getValue() == activeCard.getValue()
//            || users[playerNumber].cards.at(position - 1).getColor() == activeCard.getColor()) {
//
//        }
    }
    return 0;
}

