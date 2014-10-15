#include <UserInterface/Widgets/FilteringListStuffer.h>

#include <Logging/Log.h>

FilteringListStuffer::FilteringListStuffer()
{
}

FilteringListStuffer::~FilteringListStuffer()
{
}

void FilteringListStuffer::StuffList(cocos2d::ui::ListView& listToStuffFullOfGoodness, const size_t itemCount) const
{
  // add custom item
  for (size_t i = 0; i < itemCount; ++i)
  {
    cocos2d::ui::Button* custom_button = cocos2d::ui::Button::create("CloseNormal.png", "CloseSelected.png");
    custom_button->setName("Title Button");
    custom_button->setScale9Enabled(true);
    custom_button->setContentSize(cocos2d::Size(100, 50));

    cocos2d::ui::Layout* custom_item = cocos2d::ui::Layout::create();
    custom_item->setContentSize(custom_button->getContentSize());
    custom_button->setPosition(cocos2d::Vec2(custom_item->getContentSize().width / 2.0f, custom_item->getContentSize().height / 2.0f));
    custom_item->addChild(custom_button);

    listToStuffFullOfGoodness.pushBackCustomItem(custom_item);
  }
}
