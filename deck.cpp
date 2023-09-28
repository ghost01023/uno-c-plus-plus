//
// Created by Rosja Dostoyevsjky on 9/28/2023.
//
#include <ctime>
#include "deck.h"

Deck::Deck() {
    string color{};
    int count{0};
    //CREATE RED, BLUE, YELLOW AND GREEN CARDS AND PUSH INTO arr
    for (int i{0}; i < 40; i++) {
        if (count < 10) color = "red";
        else if (count < 20) color = "green";
        else if (count < 30) color = "blue";
        else color = "yellow";
        arr[i] = Card(false, color, to_string(i % 10));
        count++;
    }
}

void Deck::getFullDeck() {
    for (int i{0}; i < 40; i++) {
        cout << arr[i].getColor() << arr[i].getName() << endl;
    }
}

void Deck::shuffleFullDeck() {
    cout << "Shuffling fullDeck" << endl;
    //WANI'S SIMPLE ALGO FOR SHUFFLING ELEMENTS IN AN ARRAY:
    //SINGLE-SWAP OF TWO ELEMENTS DETERMINED BY (position, random-gen)
    //AND SIMILARLY ITERATING FOR THE COMPLETE SIZE OF THE ARRAY
    srand(time(0));
    for (int i {0}; i < 40; i++) {
        Card temp{this->arr[i]};
        int random {rand() % 40};
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
//    cout << "THIS IS " << randomCard.getName() << randomCard.getColor() << endl;
    this->totalCards--;
    //SUBTRACT CARD FROM THE ARRAY
    for (int i {random}; i < this->totalCards; i++) {
        this->arr[i] = this->arr[i +1];
    }
    //SHOW WHICH CARD WAS PULLED FROM THE ARRAY
//    cout << randomCard.getColor() << randomCard.getName() << " was pulled out." << endl;
    //PRINT THE RESIZED ARRAY AGAIN.
//    for (int i {0}; i < this->totalCards; i++) {
//        cout << "AT " << i << endl;
//        cout << this->arr[i].getName() << this->arr[i].getColor() << endl;
//    }
    return randomCard;
}
