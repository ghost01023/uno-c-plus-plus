//
// Created by Rosja Dostoyevsjky on 9/28/2023.
//

#include <iostream>
#include <vector>
using namespace std;

#include "card.h"

#ifndef UNO_PLAYER_H
#define UNO_PLAYER_H


class Player {
private:
    string name {};
public:
    vector <Card> cards {};
    Player();
    string getName();
    explicit Player(string name);
    void AddCard(Card &newCard);
    void PlayCard(int &position);
    void ShowCards();
};

#endif //UNO_PLAYER_H
