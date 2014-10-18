#include <UserInterface/Widgets/FilteringList.h>

#include <Logging/Log.h>
#include <UserInterface/Widgets/FilteringListStuffer.h>

FilteringList::FilteringList(const cocos2d::Rect& boundingBox, const FilteringListStuffer& dataSource)
  : boundingBox_(boundingBox),
    dataSource_(dataSource),
    list_(nullptr),
    textBox_(nullptr)
{

}

FilteringList::~FilteringList()
{

}

void FilteringList::Initialise()
{
  list_ = cocos2d::ui::ListView::create();
  list_->setDirection(cocos2d::ui::ScrollView::Direction::VERTICAL);
  list_->setTouchEnabled(true);
  list_->setBounceEnabled(true);
  list_->setBackGroundImage("background.png");
  list_->setBackGroundImageScale9Enabled(true);
  list_->setContentSize(boundingBox_.size);
  //listView->addEventListener((ui::ListView::ccListViewCallback)CC_CALLBACK_2(EthnicityListScene::selectedItemEvent, this));
  list_->addEventListener((cocos2d::ui::ScrollView::ccScrollViewCallback)CC_CALLBACK_2(FilteringList::ScrollHitTheBottom, this));
  list_->addEventListener((cocos2d::ui::ListView::ccListViewCallback)CC_CALLBACK_2(FilteringList::ListItemSelected, this));

  dataSource_.StuffList(*list_, 15);
}

void FilteringList::AddToRenderTree(cocos2d::Node* parent)
{
  parent->addChild(list_);
}

#include <Windows.h>

void FilteringList::ScrollHitTheBottom(cocos2d::Ref* node, cocos2d::ui::ScrollView::EventType eventType)
{
  SYSTEMTIME systemTime;
  GetSystemTime(&systemTime);
  LOGD("%d : Scroll event! %d", systemTime.wMilliseconds, eventType);

  if (eventType == cocos2d::ui::ScrollView::EventType::SCROLL_TO_BOTTOM)
  {
    LOGD("%d : Scroll to bottom!!", systemTime.wMilliseconds);
    dataSource_.StuffList(*list_, 15);
  }
  else if (eventType == cocos2d::ui::ScrollView::EventType::SCROLL_TO_TOP)
  {
    LOGD("%d : Scroll to top!!", systemTime.wMilliseconds);
  }
  // {SYSTEMTIME systemTime; GetSystemTime(&systemTime); char output[320]; int length = snprintf(output, 300, __VA_ARGS__); output[length] = '\n'; output[length + 1] = '\0'; OutputDebugStringA(output); }
}

void FilteringList::ListItemSelected(cocos2d::Ref* node, cocos2d::ui::ListView::EventType eventType)
{
  LOGD("%d : ListItemSelected", eventType);
}