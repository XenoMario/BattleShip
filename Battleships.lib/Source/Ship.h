#pragma once

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

namespace Battleships
{

    struct Position
    {
        int x;
        int y;
    };

    enum Ship_type
    {
        FOUR_MASTED = 1,
        THREE_MASTED = 2,
        TWO_MASTED = 3,
        SINGLE_MASTED = 4,
    };

    class Ship
    {

        Position** area;
        int size;
        int board_size = 10;

    public:
        
        Ship();

        void setSize(const int& s) { size = s; }
        int Size() const { return size; }
        void set_position(const Position&, const char& way, Ship_type& type);
        friend class Board;

        ~Ship();
    };
}

