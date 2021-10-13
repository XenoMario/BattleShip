#pragma once

#include "Ship.h"

namespace Battleships
{
    const int size = 10;

    class Board
    {
        Ship* four_masted[FOUR_MASTED];
        Ship* three_masted[THREE_MASTED];
        Ship* two_masted[TWO_MASTED];
        Ship* single_masted[SINGLE_MASTED];

        bool table[size][size];

    public:

        void makeTable();
        void add_ships();
        bool check(const Position&, const char& way, Ship_type& type) const;
        void addToTable(const Ship&);
        void print() const;
        
        bool shot();
        /*Board(); // Czy konstruktor potrzebny?
        void print() const;*/
    };
}