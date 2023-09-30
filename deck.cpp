//
// Created by Rosja Dostoyevsjky on 9/28/2023.
//
#include <ctime>
#include <random>
#include "deck.h"

Deck::Deck() {
    string color{};
    int count{0};
    //CREATE RED, BLUE, YELLOW AND GREEN CARDS (0-9) AND PUSH INTO arr
    for (int j {0}; j < 2; j++) {
        for (int i{1}; i < 37; i++) {
            if (i < 10) color = "red";
            else if (i < 19) color = "green";
            else if (i < 28) color = "blue";
            else color = "yellow";
            arr[count] = Card(color, to_string((count % 9) + 1));
            count++;
        }
    }
      cout << "made init 1-9 cards" << endl;
    cout << count << endl;
    //CREATE RED, BLUE, YELLOW, AND GREEN CANCEL, REVERSE, 0, AND PLUS-TWO CARDS
    string colors[4] {"red", "green", "blue", "yellow"};
    for (int i {0}; i < 4; i++) {
        for (int j {0}; j < 2; j++) {
            arr[count] = Card(colors[i], "plusTwo");
            count++;
        }
        for (int k {0}; k < 2; k++) {
            arr[count] = Card(colors[i], "cancel");
            count++;
        }
        for (int l {0}; l < 2; l++) {
            arr[count] = Card(colors[i], "reverse");
            count++;
        }
        cout << "made cancel, reverse, plustwo cards" << endl;
        cout << "count is at " << count << endl;
        arr[count] = Card(colors[i], "0");
        count++;
    }
    cout << "made all color diffs" << endl;
    cout << "count stands at " << count << endl;
    //CREATE 4 PLUS-4 AND 4 COLOR-CHANGE CARDS
    for (int i {0}; i < 4; i++) {
        arr[count] = Card(true, "plusFour");
        count++;
        arr[count] = Card(true, "colorChange");
        count++;
        cout << "count is at " << count << endl;
    }
}

void Deck::getFullDeck() {
    for (int i{0}; i < totalCards; i++) {
//        if (!arr[i].isSpecial()) {
//            cout << arr[i].getColor() << arr[i].getValue() << endl;
//        } else {
//            cout << arr[i].getValue() << endl;
//        }
        cout << arr[i].represent() << endl;
    }
}

void Deck::shuffleFullDeck() {
    cout << "Shuffling fullDeck" << endl;
    //WANI'S SIMPLE ALGO FOR SHUFFLING ELEMENTS IN AN ARRAY:
    //SINGLE-SWAP OF TWO ELEMENTS DETERMINED BY (position, random-gen)
    //AND SIMILARLY ITERATING FOR THE COMPLETE SIZE OF THE ARRAY
    srand(time(0));
    for (int i {0}; i < totalCards; i++) {
        Card temp{this->arr[i]};
        int random {rand() % this->totalCards};
        this->arr[i] = arr[random];
        arr[random] = temp;
    }
    cout << "fullDeck shuffled successfully" << endl;
}

Card Deck::GetRandomCard() {
    srand(time(0));
    //GET RANDOM CARD FROM DECK
    int random {rand() % totalCards};
    Card randomCard = arr[random];
//    cout << "THIS IS " << randomCard.getValue() << randomCard.getColor() << endl;
    this->totalCards--;
    //SUBTRACT CARD FROM THE ARRAY
    for (int i {random}; i < this->totalCards; i++) {
        this->arr[i] = this->arr[i +1];
    }
    //SHOW WHICH CARD WAS PULLED FROM THE ARRAY
//    cout << randomCard.getColor() << randomCard.getValue() << " was pulled out." << endl;
    //PRINT THE RESIZED ARRAY AGAIN.
//    for (int i {0}; i < this->totalCards; i++) {
//        cout << "AT " << i << endl;
//        cout << this->arr[i].getValue() << this->arr[i].getColor() << endl;
//    }
    return randomCard;
}
