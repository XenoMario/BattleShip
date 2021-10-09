#include "Ship.h"

//std::vector<std::vector<bool>> Battleships::Ship::Table = std::vector<std::vector<bool>>(10, std::vector<bool>(10, 0));
       /*{0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0 };*/

Battleships::Ship::Ship(): size(0)
{
    area = {}; // the object is zero-initialized
}

/*void Battleships::Ship::check_pos(const Position& pos, const char& way, Ship_type& type) const
{
    switch (way)
    {
        case 'V':
        {
            if (pos.x > board_size || pos.x<0 || (pos.y + type)>board_size || pos.y < 0)
            {
                throw "Board is to small for the ship";
            }
            else
            for (int i = 0; i < type; i++)
            {
                if (Table[pos.x][pos.y + i] == true)
                throw "This posision is not already avaible";
            }
        }break;
        case 'H':
        {
            if ((pos.x + type) > board_size || pos.x<0 || pos.y>board_size || pos.y < 0)
            {
                throw "Board is to small for the ship";
            }
            else
            for (int i = 0; i < type; i++)
            {
                if (Table[pos.x + i][pos.y] == true)
                    throw "This posision is not already avaible";
            }
        }break;
        case 'O':
        {
            if ((pos.x + type) > board_size || pos.x<0 || (pos.y + type)>board_size || pos.y < 0)
            {
                throw "Board is to small for the ship";
            }
            else 
            for (int i = 0; i < type; i++)
            {
                if (Table[pos.x + i][pos.y + i] == true)
                    throw "This posision is not already avaible";
            }
        }break;
    }
}*/

void Battleships::Ship::set_position(const Position& pos, const char& way, Ship_type& type)
{
    switch (type)
    {
        case 1:
        {
            size = 4;
            area = new Position * [size];
        }break;
        case 2:
        {
            size = 3;
            area = new Position * [size];
        }break;
        case 3:
        {
            size = 2;
            area = new Position * [size];
        }break;
        case 4:
        {
            size = 1;
            area = new Position * [size];
        }break;
    }

    area[0] = new Position;
    area[0]->x = pos.x;
    area[0]->y = pos.y;

    switch (way)
    {
    case 'V':
    {
        for (int i = 1; i < size; i++)
        {
            area[i] = new Position;
            area[i]->y = pos.y + i;
            area[i]->x = pos.x;
        }
    }break;
    case 'H':
    {
        for (int i = 1; i < size; i++)
        {
            area[i] = new Position;
            area[i]->y = pos.y;
            area[i]->x = pos.x + 1;
        }
    }break;
    case 'O':
    {
        for (int i = 1; i < size; i++)
        {
            area[i] = new Position;
            area[i]->y = pos.y + 1;
            area[i]->x = pos.x + 1;
        }
    }break;
    }
    cout << "Ship added correctly" << endl;
}

Battleships::Ship::~Ship()
{
    for (int i = 0; i < size; i++)
        delete[] area[i];

    delete[] area;
    area = nullptr;
}