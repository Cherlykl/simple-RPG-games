#include "icon.h"
#include<iostream>
int ICON::GRID_SIZE = 32;


pair<string,ICON> pairArray[] =
{
    make_pair("player",ICON("player",1,13, 1, 2)),
    make_pair("stone",ICON("stone",4,9, 1, 1)),
    make_pair("fruit",ICON("fruit",10,2, 1, 1)),
    make_pair("monster",ICON("monster",8,12,1,2)),
    make_pair("mud1",ICON("mud1",14,12,1,1)),
    make_pair("mud2",ICON("mud2",15,13,1,1)),
    make_pair("light",ICON("light",4,10,1,3)),
    make_pair("house",ICON("house",12,4,4,3)),
    make_pair("tree",ICON("tree",0,9,2,2)),
    make_pair("garden",ICON("garden",11,13,3,3)),
    make_pair("grass",ICON("grass",8,15,3,1)),
    make_pair("clothes",ICON("clothes",13,11,3,1)),
    make_pair("vegetables",ICON("vegetables",6,15,1,1)),
    make_pair("well",ICON("well",2,10,2,3)),
    make_pair("flower",ICON("flower",5,4,1,1))
};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


ICON::ICON(string name, int x, int y, int w, int h){
    this->typeName = name;
    this->srcX = x;
    this->srcY = y;
    this->width = w;
    this->height = h;
}

ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;
    kv = ICON::GAME_ICON_SET.find(type);
    if (kv==ICON::GAME_ICON_SET.end()){

       cout<<"Error: cannot find ICON"<<endl;
       return ICON();
    }
    else{
        return kv->second;
    }
}
