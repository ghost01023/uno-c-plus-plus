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
    string value {};
    string color {};
public:
    Card();
    Card(bool spec, string type);
    Card(string color, string value);
    [[nodiscard]] bool isSpecial() const;
    bool cardValidity(const Card &card);
    void removeSpec();
    string getValue();
    string getColor();
    void setColor(string newColor);
    string represent();
};
#endif //UNO_CARD_H
