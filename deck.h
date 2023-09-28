//
// Created by Rosja Dostoyevsjky on 9/28/2023.
//
#include "card.h"

#ifndef UNO_FULLDECK_H
#define UNO_FULLDECK_H
class Deck {
private:
    Card arr[108];
    int totalCards {40};
public:
    Deck();
    Card GetCard();
    Card GetRandomCard();
    void shuffleFullDeck();
    void getFullDeck();
};
#endif //UNO_FULLDECK_H
