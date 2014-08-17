//
//  FoodViewer.h
//  Final
//
//  Created by Jin on 2014. 8. 17..
//
//

#pragma once

#include "cocos2d.h"
#include "ColumnItem.h"

class FoodViewer : public cocos2d::CCNode
{
public:
    std::vector<ColumnItem*> _colItems;
    
private:
    void Test(cocos2d::CCObject* sender);
    void CheckIntersect(float dt);

public:
    virtual bool init();
};