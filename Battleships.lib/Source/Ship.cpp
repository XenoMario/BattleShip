#include "Ship.h"

Battleships::Ship::Ship(): size(0)
{
    area = {}; // the object is zero-initialized
}

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