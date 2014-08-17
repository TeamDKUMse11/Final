#include "Menu.h"
#include "FoodScene.h"

USING_NS_CC;

CCScene* Menu::scene()
{
    CCScene *scene = CCScene::create();
    
    Menu *layer = Menu::create();
    scene->addChild(layer);

    return scene;
}

bool Menu::init()
{
    if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)) )
        return false;

    const CCSize& screenSize = CCDirector::sharedDirector()->getWinSize();
#define POS(X, Y) ccp(screenSize.width * X, screenSize.height * Y)
    
    CCMenuItemImage* stud = CCMenuItemImage::create("Bt1.png", "Bt1.png", this, menu_selector(Menu::Stud));
    stud->setPosition(POS(-0.22f, 0.12f));

    CCMenuItemImage* domi = CCMenuItemImage::create("Bt1.png", "Bt1.png", this, menu_selector(Menu::Domi));
    domi->setPosition(POS(0.22f, 0.12f));
    
    CCMenuItemImage* empl = CCMenuItemImage::create("Bt1.png", "Bt1.png", this, menu_selector(Menu::Empl));
    empl->setPosition(POS(-0.22f, -0.12f));
    
    CCMenuItemImage* kitchen = CCMenuItemImage::create("Bt1.png", "Bt1.png", this, menu_selector(Menu::Kitc));
    kitchen->setPosition(POS(0.22f, -0.12f));
    
    CCMenuItemImage* other = CCMenuItemImage::create("Bt1.png", "Bt1.png", this, menu_selector(Menu::Other));
    other->setPosition(POS(0.0f, -0.36f));
    
    CCArray* ary = CCArray::create(stud, domi, empl, kitchen, other, NULL);
    
    CCMenu* menu = CCMenu::createWithArray(ary);
    addChild(menu);
    
    const CCPoint screenCenterTop = ccp(screenSize.width / 2.0f, screenSize.height);
    CCSprite* title = CCSprite::create("title.jpg");
    title->setPosition(screenCenterTop - ccp(0, title->getContentSize().height));
    addChild(title);
    

    const char* test = "{\"morning\": {\"백반\": {\"menu\": \"백반\",\"price\": 1900,\"contents\": \"쌀밥(쌀:국내산) 얼갈이된장국 동그랑땡강정 숙주나물 무맛김치(배추:국내산,고춧가루:중국산)\"}},\"noon\": {\"백반\": {\"menu\": \"백반\",\"price\": 1900,\"contents\": \"쌀밥(쌀:국내산) 얼갈이된장국 동그랑땡강정 숙주나물 무맛김치(배추:국내산,고춧가루:중국산)\"},\"알천\": [{\"menu\": \"치즈돈까스\",\"price\": 3000,\"contents\": \"치즈돈까스(돈육:국내산) 쌀밥(쌀:국내산) 양배추샐러드 감자튀김 얼갈이된장국 무맛김치(배추:국내산,고춧가루:중국산)\"},{\"menu\": \"스파게티 핫도그샌드위치\",\"price\": 3000,\"contents\": \"스파게티 핫도그샌드위치 얼갈이된장국 무맛김치(배추:국내산,고춧가루:중국산)\"}],\"소담\": [{\"menu\": \"규동\",\"price\": 3000,\"contents\": \"규동(쌀:국내산/우육:호주산) 얼갈이된장국 무맛김치(배추:국내산,고춧가루:중국산)\"}],\"일품\": [{\"menu\": \"순대해장국\",\"price\": 3500,\"contents\": \"순대해장국(돈육,돈창:국내산) 쌀밥(쌀:국내산) 무맛김치(배추:국내산,고춧가루:중국산)\"}]},\"evening\": {\"백반\": {\"menu\": \"백반\",\"price\": 1900,\"contents\": \"쌀밥(쌀:국내산) 유부된장국 햄야채볶음 미역줄기볶음 무맛김치(배추:국내산,고춧가루:중국산)\"},\"알천\": [{\"menu\": \"가쓰오볶음밥\",\"price\": 3000,\"contents\": \"가쓰오볶음밥(쌀:국내산) 핫도그 유부된장국 무맛김치(배추:국내산,고춧가루:중국산)\"}],\"소담\": [{\"menu\": \"치즈햄김치찌개\",\"price\": 3000,\"contents\": \"치즈햄김치찌개(김치-배추:국내산,고춧가루:중국산) 쌀밥(쌀:국내산) 무맛김치(배추:국내산,고춧가루:중국산)\"}]}}";
    
    return true;
}

void Menu::Stud(cocos2d::CCObject* sender)
{
    CCLog("Stud");
    CCDirector::sharedDirector()->pushScene(FoodScene::scene());
}

void Menu::Domi(cocos2d::CCObject* sender)
{
    CCLog("Domi");
}

void Menu::Empl(cocos2d::CCObject* sender)
{
    CCLog("Empl");
}

void Menu::Kitc(cocos2d::CCObject* sender)
{
    CCLog("Kitc");
}

void Menu::Other(cocos2d::CCObject* sender)
{
    CCLog("Other");
}
