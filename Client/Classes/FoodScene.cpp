//
//  FoodViewer.cpp
//  Final
//
//  Created by Jin on 2014. 8. 17..
//
//

#include "FoodScene.h"

using namespace cocos2d;

CCScene* FoodScene::scene()
{
    CCScene *scene = CCScene::create();
    
    FoodScene *layer = FoodScene::create();
    scene->addChild(layer);
    
    return scene;
}

FoodScene::FoodScene() : _fv(NULL)
{
    
}

FoodScene::~FoodScene()
{
    if(_fv)
        delete _fv;
}

bool FoodScene::init()
{
    if(CCLayerColor::initWithColor(ccc4(0, 0, 0, 0)) == false)
        return false;
    
    const CCSize& screenSize = CCDirector::sharedDirector()->getWinSize();
    const CCPoint screenCenterTop = ccp(screenSize.width / 2.0f, screenSize.height);
    CCSprite* title = CCSprite::create("title.jpg");
    title->setPosition(screenCenterTop);
    title->setAnchorPoint(ccp(0.5f, 1.0f));
    addChild(title);
    
    
    CCSprite* subTitle = CCSprite::create("SubTitle.png");
    subTitle->setPosition(title->getPosition() - ccp(0, title->getContentSize().height + 10));
    subTitle->setAnchorPoint(ccp(0.5f, 1.0f));
    addChild(subTitle);
        
    _fv = new FoodViewer;
    _fv->init();
    
    float h = CCTextureCache::sharedTextureCache()->addImage("ColItemBack.png")->getContentSize().height;
    float w = CCTextureCache::sharedTextureCache()->addImage("ColItemBack.png")->getContentSize().width;
    
    _fv->setPosition(ccp(w/2 + 20, -h / 2 - 10));
    _fv->setAnchorPoint(ccp(0.5f, 0.0f));
    subTitle->addChild(_fv, -2);
    
    originfoodviewerpos = _fv->getPosition();
     beforefoodviewerpos = _fv->getPosition();
    limitMinY = _fv->getPosition().y;
    limitMaxY = 33;
    //5개일때 33
    
    setTouchEnabled(true);
    
    return true;
}


void FoodScene::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
        CCLOG("end");
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);
    CCPoint touchPoint = touch->getLocation();

    sp = touchPoint;
}

void FoodScene::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);
    CCPoint touchPoint = touch->getLocation();
    
    float movey = touchPoint.y - sp.y;
    CCPoint mp = beforefoodviewerpos + ccp(0, movey);
    if(mp.y < limitMinY )
        mp = originfoodviewerpos;
    else if(mp.y > limitMaxY)
        mp = ccp(originfoodviewerpos.x, limitMaxY);
    
    CCLOG("%f", mp.y);
    
    _fv->setPosition(mp);
}

void FoodScene::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
{
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);
    CCPoint touchPoint = touch->getLocation();
    sp = touchPoint;
    beforefoodviewerpos = _fv->getPosition();
    
    CCLOG("end");
}
