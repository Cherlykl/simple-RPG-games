#include "monster.h"

void Monster::move(int opt)
{
    switch (opt){
    case 1:
        if(_pos_x<23)
            this->_pos_x += 1;
        break;
    case 2:
        if(_pos_x>=1)
            this->_pos_x -= 1;
        break;
    case 3:
        if(_pos_y>=3)
            this->_pos_y -= 1;
        break;
    case 4:
        if(_pos_y<16)
            this->_pos_y += 1;
        break;
    }
}
