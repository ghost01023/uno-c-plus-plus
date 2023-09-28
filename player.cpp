//
// Created by Rosja Dostoyevsjky on 9/28/2023.
//
#include "player.h"
#include "card.h"

Player::Player() {};


Player::Player(string name) {
    this->name = std::move(name);
};

string Player::getName() {
    return this->name;
}

void Player::AddCard(Card &newCard) {
    this->cards.push_back(newCard);
    cout << "Added " << newCard.getColor() << newCard.getName() << endl;
}

void Player::ShowCards() {
    cout << "Showing cards held by " << this->name << endl;
    for (size_t i{0}; i < size(cards); i++) {
        cout << i + 1 << ":       " << cards.at(i).getColor() << cards.at(i).getName() << endl;
    }
}

void Player::PlayCard(int &position) {
//    cout << "Removing " << name.getColor() << name.getName() << endl;
    vector<Card>::iterator pos;
    pos = this->cards.begin() + (position - 1);
    this->cards.erase(pos);
    cout << "Removed card successfully." << endl;
}
