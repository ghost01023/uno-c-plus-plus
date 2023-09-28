//
// Created by Rosja Dostoyevsjky on 9/28/2023.
//

#include <iostream>
using namespace std;

#ifndef UNO_DECK_H
#define UNO_DECK_H

class ProtoDeck {
public:
    string name[7] {};
    string cards[25] {"0", "1", "1", "2", "2", "3",
                       "3", "4", "4", "5", "5", "6",
                       "6", "7", "7", "8", "8", "9",
                       "9", "reverse", "reverse", "cancel",
                       "cancel", "plusTwo", "plusTwo"};
    explicit ProtoDeck(string name);
    void DisplayName();
};
#endif //UNO_DECK_H
