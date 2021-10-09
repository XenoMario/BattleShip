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
        //static std::vector<std::vector<bool>> Table;
        
    public:
        
        Ship();
        //Ship(const Position&, const char&, Ship_type&);
        //inline void set_size(const int& num) { size = num; }

        //void check_pos(const Position&, const char& way, Ship_type& type) const;
        void set_position(const Position&, const char& way, Ship_type& type);
        friend class Board;

        ~Ship();
    };
}

/*void Battleships::tab()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << Battleships::Ship::Table[i][j] << " ";

        cout << endl;
    }
}*/


