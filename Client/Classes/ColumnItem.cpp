//
//  ColumnItem.cpp
//  Final
//
//  Created by Jin on 2014. 8. 17..
//
//

#include "ColumnItem.h"

using namespace cocos2d;

bool ColumnItem::init()
{
    if( CCNode::init() == false )
        return false;
    
    back = CCSprite::create("ColItemBack.png");
    addChild(back);
        
    CCLabelTTF* title = CCLabelTTF::create("test", "", 45.0f);
    title->setColor(ccc3(0, 0, 0));
    title->setPosition(ccp(-250, 52));
    addChild(title);
    
    CCLabelTTF* info = CCLabelTTF::create("응아아아아아아ㅏ아앙아아아아아아아아아ㅏㅇ아아아응아아아아아아ㅏ아앙아아아아아아아아아ㅏㅇ아아아응아아아아아아ㅏ아앙아아아아아아아아아ㅏㅇ아아아", "", 25.0f, CCSizeMake(480, 60), kCCTextAlignmentLeft);
    info->setPosition(ccp(0, -2.0f));
    info->setAnchorPoint(ccp(0.0f, 1.0f));
    title->addChild(info);
    
    CCLabelTTF* price = CCLabelTTF::create("2,222원", "", 30.0f);
    info->addChild(price);
    price->setPosition(ccp(0, -1.0f));
    price->setAnchorPoint(ccp(0, 1));
    
    CCSprite* sel = CCSprite::create("Call.png");
    sel->setPosition(ccp(250, 0));
    addChild(sel);
    
    setContentSize(back->getContentSize());
    
    return true;
}