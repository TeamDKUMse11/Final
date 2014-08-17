//
//  FoodViewer.h
//  Final
//
//  Created by Jin on 2014. 8. 17..
//
//

#pragma once

#include "cocos2d.h"
#include "FoodViewer.h"

using namespace cocos2d;

class FoodScene : public cocos2d::CCLayerColor
{
private:
    FoodViewer* _fv;
    CCPoint sp;
    CCPoint beforefoodviewerpos;
    CCPoint originfoodviewerpos;
    
    float limitMinY;
    float limitMaxY;
    
public:
    FoodScene();
    virtual ~FoodScene();
    
public:
    bool init();

    static cocos2d::CCScene* scene();
    CREATE_FUNC(FoodScene);
    
public:
    virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
};