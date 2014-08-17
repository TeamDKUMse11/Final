#pragma once


#include "cocos2d.h"

class Menu : public cocos2d::CCLayerColor
{
public:
    static cocos2d::CCScene* scene();
    
public:
    virtual bool init();
    CREATE_FUNC(Menu);
        
private:
    void Stud(cocos2d::CCObject* sender);
    void Domi(cocos2d::CCObject* sender);
    void Empl(cocos2d::CCObject* sender);
    void Kitc(cocos2d::CCObject* sender);
    void Other(cocos2d::CCObject* sender);
};