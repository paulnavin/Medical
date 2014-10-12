#include <UserInterface/Scenes/EthnicityListScene.h>

#include <Logging/Log.h>
USING_NS_CC;

Scene* EthnicityListScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = EthnicityListScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool EthnicityListScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(EthnicityListScene::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    //
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

    cocos2d::ui::ListView* listView = cocos2d::ui::ListView::create();
    listView->setDirection(ui::ScrollView::Direction::VERTICAL);
    listView->setTouchEnabled(true);
    listView->setBounceEnabled(true);
    listView->setBackGroundImage("HelloWorld.png");
    listView->setBackGroundImageScale9Enabled(true);
    listView->setSize(visibleSize);
    listView->setContentSize(visibleSize);
    listView->addEventListener((ui::ListView::ccListViewCallback)CC_CALLBACK_2(EthnicityListScene::selectedItemEvent, this));
    this->addChild(listView);
    


    // add custom item
    for (int i = 0; i < 10; ++i)
    {
      cocos2d::ui::Button* custom_button = cocos2d::ui::Button::create("CloseNormal.png", "CloseSelected.png");
      custom_button->setName("Title Button");
      custom_button->setScale9Enabled(true);
      custom_button->setContentSize(Size(100, 50));

      cocos2d::ui::Layout* custom_item = cocos2d::ui::Layout::create();
      custom_item->setContentSize(custom_button->getContentSize());
      custom_button->setPosition(Vec2(custom_item->getContentSize().width / 2.0f, custom_item->getContentSize().height / 2.0f));
      custom_item->addChild(custom_button);

      listView->pushBackCustomItem(custom_item);
    }

    return true;
}


void EthnicityListScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void EthnicityListScene::selectedItemEvent(cocos2d::Ref* node, cocos2d::ui::ListView::EventType eventType)
{
  LOGD("Eat this!");
}
