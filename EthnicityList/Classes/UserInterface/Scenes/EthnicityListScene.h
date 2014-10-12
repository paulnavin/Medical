#ifndef __ETHNICITY_LIST_SCENE_H__
#define __ETHNICITY_LIST_SCENE_H__

#include <ThirdParty/Cocos2d-x/Cocos2d-x.h>

class EthnicityListScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(EthnicityListScene);
};

#endif // __ETHNICITY_LIST_SCENE_H__
