#ifndef __FILTERING_LIST_VIEW_H__
#define __FILTERING_LIST_VIEW_H__

#include <ThirdParty/Cocos2d-x/Cocos2d-x.h>

class FilteringListStuffer;

// Container for a text box and a listview, where the text box can filter the results
// in the list.
// Inherits from cocos2d::Object so it can accept touch events.
class FilteringList : public cocos2d::Object
{
public:
  FilteringList(const cocos2d::Rect& boundingBox, const FilteringListStuffer& dataSource);
  ~FilteringList();

public:
  void Initialise();
  void AddToRenderTree(cocos2d::Node* parent);

public:
  //void SetHeader();

protected:
  void ScrollHitTheBottom(cocos2d::Ref* node, cocos2d::ui::ScrollView::EventType eventType);
  void ListItemSelected(cocos2d::Ref* node, cocos2d::ui::ListView::EventType eventType);

private:
  const cocos2d::Rect&        boundingBox_;
  const FilteringListStuffer& dataSource_;
  cocos2d::ui::ListView*      list_;
  cocos2d::Rect               listBoundingBox_;
  cocos2d::ui::UICCTextField* textBox_;
  cocos2d::Rect               textBoxBoundingBox_;
};

#endif // __FILTERING_LIST_VIEW_H__
