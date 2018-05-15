#include "world.h"
#include "icon.h"
#include <iostream>

void World::initWorld(string mapFile){
    //TODO 下面这部分逻辑应该是读入地图文件，生成地图上的对象
    //player 5 5
    this->_player.initObj("player");
    this->_player.setPosX(1);
    this->_player.setPosY(2);

    this->_monster1.initObj("monster");
    this->_monster1.setPosX(12);
    this->_monster1.setPosY(11);

    this->_monster2.initObj("monster");
    this->_monster2.setPosX(13);
    this->_monster2.setPosY(9);
    //stone 4 5

    int mud1_num=25,mud2_num=18,tree_num=12,grass_num=6,flower_num=15,stone_num=26;
    RPGObj obj_1[mud1_num],obj_2[mud2_num],obj_3[tree_num],obj_4[grass_num],obj_5[flower_num],obj_6[stone_num];
    int i=0;
    do
    {
       if(i<mud1_num)
       {
           obj_1[i].initObj("mud1");
           obj_1[i].setPosX(i);
           obj_1[i].setPosY(0);
           this->_objs.push_back(obj_1[i]);

       }

       if(i<mud2_num)
       {
           obj_2[i].initObj("mud2");
           obj_2[i].setPosX(24);
           obj_2[i].setPosY(i);
           this->_objs.push_back(obj_2[i]);
       }

       if(i<tree_num)
       {
           obj_3[i].initObj("tree");
           obj_3[i].setPosX(i+i);
           obj_3[i].setPosY(1);
           this->_objs.push_back(obj_3[i]);
       }

       if(i<grass_num)
       {
           obj_4[i].initObj("grass");
           obj_4[i].setPosX(i+i+i);
           obj_4[i].setPosY(18);
           this->_objs.push_back(obj_4[i]);
       }
       if(i<flower_num)
       {
           obj_5[i].initObj("flower");
           obj_5[i].setPosX(0);
           obj_5[i].setPosY(i+3);
           this->_objs.push_back(obj_5[i]);
       }
       if(i<stone_num)
       {
           if(i<7)
           {
               obj_6[i].initObj("stone");
               obj_6[i].setPosX(i+3);
               obj_6[i].setPosY(i+3);
               this->_objs.push_back(obj_6[i]);
           }
           else
           {
               if(i<14)
               {
                   obj_6[i].initObj("stone");
                   obj_6[i].setPosX(i-7+1);
                   obj_6[i].setPosY(i-7+10);
                   this->_objs.push_back(obj_6[i]);
               }
               else
               {
                   if(i<21)
                   {
                       obj_6[i].initObj("stone");
                       obj_6[i].setPosX(i-14+14);
                       obj_6[i].setPosY(i-14+4);
                       this->_objs.push_back(obj_6[i]);
                   }
                   else
                   {
                       obj_6[i].initObj("stone");
                       obj_6[i].setPosX(i-21+12);
                       obj_6[i].setPosY(15);
                       this->_objs.push_back(obj_6[i]);
                   }
               }
           }

       }
       i=i+1;
    }
    while(i<stone_num);

    RPGObj obj1, obj2, obj3,obj4,obj5,obj_l,obj_h,obj_g,obj_cl,obj_v,obj_w;

    obj1.initObj("fruit");
    obj1.setPosX(4);
    obj1.setPosY(3);

    obj2.initObj("fruit");
    obj2.setPosX(15);
    obj2.setPosY(17);

    obj3.initObj("fruit");
    obj3.setPosX(23);
    obj3.setPosY(4);

    obj4.initObj("fruit");
    obj4.setPosX(2);
    obj4.setPosY(17);

    obj5.initObj("fruit");
    obj5.setPosX(14);
    obj5.setPosY(12);

    obj_l.initObj("light");
    obj_l.setPosX(19);
    obj_l.setPosY(15);

    obj_h.initObj("house");
    obj_h.setPosX(20);
    obj_h.setPosY(15);

    obj_cl.initObj("clothes");
    obj_cl.setPosX(21);
    obj_cl.setPosY(14);

    obj_g.initObj("garden");
    obj_g.setPosX(21);
    obj_g.setPosY(10);

    obj_v.initObj("vegetables");
    obj_v.setPosX(22);
    obj_v.setPosY(11);

    obj_w.initObj("well");
    obj_w.setPosX(21);
    obj_w.setPosY(6);

    this->_objs.push_back(obj1);
    this->_objs.push_back(obj2);
    this->_objs.push_back(obj3);
    this->_objs.push_back(obj4);
    this->_objs.push_back(obj5);
    this->_objs.push_back(obj_l);
    this->_objs.push_back(obj_h);
    this->_objs.push_back(obj_g);
    this->_objs.push_back(obj_cl);
    this->_objs.push_back(obj_v);
    this->_objs.push_back(obj_w);


}


void World::show(QPainter * painter){
    vector<RPGObj>::iterator it;
    for(it=this->_objs.begin();it!=this->_objs.end();it++){
        (*it).show(painter);
    }
   this->_player.show(painter);
   this->_monster1.show(painter);
   this->_monster2.show(painter);
}

void World::handlePlayerMove(int direction, int steps){

    int flag1=0,flag2=0,flag3=0,flag4=0;
    vector<RPGObj>::iterator it;

    if(direction==1)
    {
        for(it=this->_objs.begin();it!=this->_objs.end();it++)
        {
            if( _player.getPosX()==(*it).getPosX()&& _player.getPosY()+1-steps==(*it).getPosY())
            {
                flag1=1;
                if((*it).canCover())
                {
                   // if(_player.getPosX()<25&&_player.getPosX()>0&&_player.getPosY()>0&&_player.getPosY()<18)
                        this->_player.move(direction, steps);
                }

                if((*it).canEat())
                {
                   _objs.erase(it);

                   //if(_player.getPosX()<25&&_player.getPosX()>0&&_player.getPosY()>0&&_player.getPosY()<18)
                       this->_player.move(direction, steps);
                }
            }
        }
        if(flag1==0)
           // if(_player.getPosX()<25&&_player.getPosX()>0&&_player.getPosY()>0&&_player.getPosY()<18)
                this->_player.move(direction, steps);
    }
    if(direction==2)
    {
        for(it=this->_objs.begin();it!=this->_objs.end();it++)
        {
            if( _player.getPosX()==(*it).getPosX()&& _player.getPosY()+1+steps==(*it).getPosY())
            {
                flag2=1;
                if((*it).canCover())
                {
                    //if(_player.getPosX()<25&&_player.getPosX()>0&&_player.getPosY()>0&&_player.getPosY()<18)
                        this->_player.move(direction, steps);
                }
                if((*it).canEat())
                {
                   _objs.erase(it);
                   //if(_player.getPosX()<25&&_player.getPosX()>0&&_player.getPosY()>0&&_player.getPosY()<18)
                       this->_player.move(direction, steps);
                }
            }
        }
        if(flag2==0)
            //if(_player.getPosX()<25&&_player.getPosX()>0&&_player.getPosY()>0&&_player.getPosY()<18)
                this->_player.move(direction, steps);
    }
    if(direction==3)
    {
        for(it=this->_objs.begin();it!=this->_objs.end();it++)
        {
            if( _player.getPosX()-steps==(*it).getPosX()&& _player.getPosY()+1==(*it).getPosY())
            {
                flag3=1;
                if((*it).canCover())
                {
                    //if(_player.getPosX()<25&&_player.getPosX()>0&&_player.getPosY()>0&&_player.getPosY()<18)
                        this->_player.move(direction, steps);
                }
                if((*it).canEat())
                {
                   _objs.erase(it);
                   //if(_player.getPosX()<25&&_player.getPosX()>0&&_player.getPosY()>0&&_player.getPosY()<18)
                       this->_player.move(direction, steps);
                }
            }
        }
        if(flag3==0)
            //if(_player.getPosX()<25&&_player.getPosX()>0&&_player.getPosY()>0&&_player.getPosY()<18)
                this->_player.move(direction, steps);
    }
    if(direction==4)
    {
        for(it=this->_objs.begin();it!=this->_objs.end();it++)
        {
            if( _player.getPosX()+steps==(*it).getPosX()&& _player.getPosY()+1==(*it).getPosY())
            {
                flag4=1;
                if((*it).canCover())
                {
                    //if(_player.getPosX()<25&&_player.getPosX()>0&&_player.getPosY()>0&&_player.getPosY()<18)
                        this->_player.move(direction, steps);
                }
                if((*it).canEat())
                {
                   _objs.erase(it);
                   //if(_player.getPosX()<25&&_player.getPosX()>0&&_player.getPosY()>0&&_player.getPosY()<18)
                       this->_player.move(direction, steps);
                }
            }
        }
        if(flag4==0)
            //if(_player.getPosX()<25&&_player.getPosX()>0&&_player.getPosY()>0&&_player.getPosY()<18)
                this->_player.move(direction, steps);
    }
}
void World::handleMonsterMove(int direction1,int direction2)
{


     if(_monster1.getPosX()==_player.getPosX()&&_monster1.getPosY()==_player.getPosY())
         delete &_player;
     if(_monster2.getPosX()==_player.getPosX()&&_monster2.getPosY()==_player.getPosY())
         delete &_player;

     //if(_monster1.getPosX()<24&&_monster1.getPosX()>1&&_monster1.getPosY()>1&&_monster1.getPosY()<16)
        _monster1.move(direction1);
     //if(_monster2.getPosX()<24&&_monster2.getPosX()>1&&_monster2.getPosY()>1&&_monster2.getPosY()<16)
        _monster2.move(direction2);
}

