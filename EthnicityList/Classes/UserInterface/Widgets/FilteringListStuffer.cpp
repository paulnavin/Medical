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
  cocos2d::Size listSize;
  listSize.width = listToStuffFullOfGoodness.getLayoutSize().width;
  listSize.height = listToStuffFullOfGoodness.getLayoutSize().height;

  // add custom item
  for (size_t i = 0; i < itemCount; ++i)
  {
    cocos2d::ui::Layout* newListItem = CreateSingleListItem(listSize, "Hello", "Bastards");
    listToStuffFullOfGoodness.pushBackCustomItem(newListItem);
  }
}

cocos2d::ui::Layout* FilteringListStuffer::CreateSingleListItem(const cocos2d::Size& listSize, const char* firstString, const char* secondString) const
{
  static const float margin = 10.0f;
  static const float doubleMargin = 20.0f;

  cocos2d::ui::Layout* layout = cocos2d::ui::Layout::create();
  layout->setLayoutType(cocos2d::ui::Layout::Type::HORIZONTAL);

  cocos2d::Label* label = cocos2d::Label::createWithTTF(firstString, "fonts/Roboto-Regular.ttf", 24.0f);
  cocos2d::Label* label2 = cocos2d::Label::createWithTTF(secondString, "fonts/Roboto-Regular.ttf", 24.0f);

  cocos2d::Size labelSize;
  labelSize.width = listSize.width - doubleMargin;
  labelSize.height = label->getContentSize().height;


  label->setAnchorPoint(cocos2d::Vec2(0.0f, 0.5f));
  label->setPositionX(margin);
  label->setPositionY(margin);
  label->setTextColor(cocos2d::Color4B(0, 0, 0, 255));

  label2->setAnchorPoint(cocos2d::Vec2(1.0f, 0.5f));
  label2->setPositionX(labelSize.width + margin);
  label2->setPositionY(margin);
  label2->setTextColor(cocos2d::Color4B(0, 0, 0, 255));


  cocos2d::Size layoutSize = labelSize;
  layoutSize.width = listSize.width;
  layoutSize.height = labelSize.height + doubleMargin;
  layout->setContentSize(layoutSize);

  layout->addChild(label);
  layout->addChild(label2);

  return layout;
}