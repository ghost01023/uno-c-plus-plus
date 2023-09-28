//
// Created by Rosja Dostoyevsjky on 9/28/2023.
//
#include <iostream>

using namespace std;

#include "card.h"

Card::Card() {
//    cout << "Default no args constructor called." << endl;
}
Card::Card(bool spec, string name, string color) {
    special = spec,
    this->name = std::move(name),
    this->color = std::move(color);
};

bool Card::isSpecial() {
    return this->special;
}

string Card::getName() {
    return this->name;
}

string Card::getColor() {
    return this->color;
}
