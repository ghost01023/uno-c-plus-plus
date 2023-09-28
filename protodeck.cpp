//
// Created by Rosja Dostoyevsjky on 9/28/2023.
//
#include <iostream>

using namespace std;

#include "protodeck.h"

ProtoDeck::ProtoDeck(string name) {
    *this->name = std::move(name);
};

void ProtoDeck::DisplayName() {
    cout << "Running display function for ProtoDeck ";
    cout << *this->name << endl;
}
