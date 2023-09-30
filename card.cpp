//
// Created by Rosja Dostoyevsjky on 9/28/2023.
//
#include <iostream>

using namespace std;

#include "card.h"

Card::Card() = default;

Card::Card(bool spec, string type) {
    this->special = spec;
    this->value = std::move(type);
    this->color = "none";
}

Card::Card(string color, string value) {
    this->special = false;
    if (value == "plusTwo" || value == "cancel" || value == "reverse") {
        this->special = true;
    }
    this->value = std::move(value);
    this->color = std::move(color);
}

bool Card::isSpecial() const {
    return this->special;
}

bool Card::cardValidity(const Card &card) {
    //IF PRESENT CARD IS SPECIAL
    if (this->isSpecial()) {
        //IF IT IS PLACEHOLDER CARD
        if (this->value == "placeHolder") {
            if (this->color == card.color ||
                card.value == "plusFour") {
                return true;
            }
        }
        //IF IT IS COLOR SPECIAL
        if (this->color != "none") {
            //THEN, IT CAN BE (CANCEL, PLUS-TWO, REVERSE)
            //FOR PLUS-TWO
            if (this->value == "plusTwo" && card.value == "plusTwo" ||
             this->value == "cancel" && card.value == "cancel" ||
             this->value == "cancel" && card.color == this->color ||
             this->value == "reverse" && card.color == this->color ||
             this->value == "reverse" && card.value == "reverse") {
                return true;
            }
//            else if (this->value == "cancel" && card.color == this->color ||
////            this->value == "plusTwo" && card.value == "plusFour" ||
////            this->value == "plusTwo" && card.color == this->color ||
//            this->value == "reverse" && card.color == this->color)
////            this->value == "cancel" && card.value == "plusTwo" ||
////            this->value == "reverse" && card.value == "plusTwo" ||
////            this->value == "reverse" && card.value == "plusFour")
////            this->value == "cancel" && card.value == "plusFour" ||
////            this->value == "cancel" && card.value == "colorChange")
//            {
//                return true;
//            }
            return false;
        }
        //IF IT IS NON-COLOR SPECIAL
        else {
            if (this->value == "plusFour" && card.value == "plusFour" ||
//            this->value == "plusFour" && card.color == this->getColor() ||
            this->value == "colorChange" && card.value == "colorChange" ||
            this->value == "colorChange" && card.value == "cancel" ||
            this->value == "colorChange" && card.color == this->getColor() ||
            this->value == "colorChange" && card.color == "plusFour") {
                return true;
            }
            return false;
        }
    }
    //IF PRESENT CARD IS NON-SPECIAL
    else {
        if (this->color == card.color || this->value == card.value) {
            return true;
        }
        else if (card.value == "plusFour" || card.value == "colorChange") {
            return true;
        }
        else {
            return false;
        }
    }
}

string Card::getValue() {
    return this->value;
}

string Card::getColor() {
    return this->color;
}

string Card::represent() {
    if (this->special && this->color == "none") {
        return this->value;
    }
    else {
        return this->color + this->value;
    }
}

void Card::setColor(string newColor) {
    this->color = std::move(newColor);
}

void Card::removeSpec() {
    this->special = false;
}
