#pragma once

#include <iostream>
#include <string>
#include <vector>


class Card {


public:
    std::string suit;
    int value;

    Card(std::string suit, int value);

    virtual std::string str() const = 0;


    virtual void play() = 0;


    virtual ~Card() {}




};
