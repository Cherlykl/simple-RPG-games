#include "player.h"

//direction =1,2,3,4 for 上下左右
void Player::move(int direction, int steps){
    switch (direction){
        case 1:
            if(_pos_y>=3)
                this->_pos_y -= steps;
            break;
        case 2:
            if(_pos_y<16)
                this->_pos_y += steps;
            break;
        case 3:
            if(_pos_x>=1)
                this->_pos_x -= steps;
            break;
        case 4:
            if(_pos_x<23)
                this->_pos_x += steps;
            break;
    }
}

