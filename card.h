//
// Created by Rosja Dostoyevsjky on 9/28/2023.
//

#include <iostream>
using namespace std;

#ifndef UNO_CARD_H
#define UNO_CARD_H
class Card {
private:
    bool special {};
    string name {};
    string color {};
public:
    Card();
    Card(bool spec, string name, string color);

    bool isSpecial();

    string getName();
    
    string getColor();
};
#endif //UNO_CARD_H
