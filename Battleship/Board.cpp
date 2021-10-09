#include "Board.h"

void Battleships::Board::print() const
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << table[i][j] << " ";

        cout << endl;
    }
    cout << endl;
}

void Battleships::Board::shot(const Position& pos)
{

}

void Battleships::Board::makeTable()
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            table[i][j] = false;
        }
}

void Battleships::Board::addToTable(const Ship& SS)
{
   for (int j = 0; j < SS.size; j++)
   {
       table[SS.area[j]->x][SS.area[j]->y] = true;
   }
}

bool Battleships::Board::check(const Position& pos, const char& way, Ship_type& type) const
{
    switch (way)
    {
    case 'V':
    {
        if (pos.x > size || pos.x<0 || (pos.y + type)>size || pos.y < 0)
        {
            throw "Board is to small for the ship";
        }
        else
            for (int i = 0; i < type; i++)
            {
                if (table[pos.x][pos.y + i] == true)
                    throw "This posision is not already avaible";
            }
    }break;
    case 'H':
    {
        if ((pos.x + type) > size || pos.x<0 || pos.y>size || pos.y < 0)
        {
            throw "Board is to small for the ship";
        }
        else
            for (int i = 0; i < type; i++)
            {
                if (table[pos.x + i][pos.y] == true)
                    throw "This posision is not already avaible";
            }
    }break;
    case 'O':
    {
        if ((pos.x + type) > size || pos.x<0 || (pos.y + type)>size || pos.y < 0)
        {
            throw "Board is to small for the ship";
        }
        else
            for (int i = 0; i < type; i++)
            {
                if (table[pos.x + i][pos.y + i] == true)
                    throw "This posision is not already avaible";
            }
    }break;
    }
}

void Battleships::Board::add_ships()
{
    int ships_created[4];
    for (int i = 0; i < 4; i++)
        ships_created[i] = i+1;

    ships_created[2] = 0;
    ships_created[3] = 0;

    for (;;)
    {
        cout << "Select ship to create: " << endl;
        cout << "1. Four-masted ("  <<    ships_created[0] << " left)" << endl; 
        cout << "2. Three-masted (" <<    ships_created[1] << " left)" << endl;
        cout << "3. Two-masted ("   <<    ships_created[2] << " left)" << endl;
        cout << "4. Single-masted ("<<    ships_created[3] << " left)" << endl;

        int choise;
        std::cin >> choise;

        while (choise != 1 && choise != 2 && choise != 3 && choise != 4)
        {
            cout << "Please select 1,2,3 or 4" << endl;
            std::cin >> choise;

            while (ships_created[choise + 1] == 0)
            {
                cout << "You cannot add more ships this type" << endl;
                std::cin >> choise;
            }
        }

        Battleships::Ship_type type = static_cast<Battleships::Ship_type > (choise);

        cout << "Select way of placing the ship." << endl;
        cout << "V - vertically" << endl;
        cout << "H - horizontally" << endl;
        cout << "O - Obliquely" << endl;

        char sign;
        std::cin.get(sign);
        sign = toupper(sign);

        if (std::strchr("VHO", sign) == NULL)
        {
            cout << "Please select V,H or O." << endl;
            std::cin.get(sign);
            sign = toupper(sign);
        }

        Position pos;

        cout << "Please enter starting position of the ship" << endl;
        cout << "x ";
        std::cin >> pos.x;
        cout << "y ";
        std::cin >> pos.y;

        try
        {
            check(pos, sign, type);
        }
        catch (const std::string& str)
        {
            cout << str;
            cout << "Try again" << endl;
            continue;
        }
        
        Ship* s = new Ship;
        s->set_position(pos, sign, type);
        addToTable(*s);
        ships_created[choise - 1]--;

        if (ships_created[0] == 0 && ships_created[1] == 0 && ships_created[2] == 0 && ships_created[3] == 0)
            break;
    }
}
