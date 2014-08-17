//
//  FoodViewer.cpp
//  Final
//
//  Created by Jin on 2014. 8. 17..
//
//

#include "FoodViewer.h"

using namespace cocos2d;

bool FoodViewer::init()
{
    if(CCNode::init() == false)
        return false;
    
    float h = CCTextureCache::sharedTextureCache()->addImage("ColItemBack.png")->getContentSize().height;


    for(int i=0; i<5; ++i)
    {
        ColumnItem* c = new ColumnItem;
        c->setPosition(ccp(0, -i * h - i * 10 - 10));
        CCLOG("%f", c->getPositionY());
        c->init();
        _colItems.push_back(c);
        addChild(c);
    }
    
    
    return true;
}