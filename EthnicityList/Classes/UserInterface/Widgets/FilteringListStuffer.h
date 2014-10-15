#ifndef __FILTERING_LIST_STUFFER_H__
#define __FILTERING_LIST_STUFFER_H__

#include <ThirdParty/Cocos2d-x/Cocos2d-x.h>

// Stuffs a FilteringList full of data.
class FilteringListStuffer
{
public:
  FilteringListStuffer();
  virtual ~FilteringListStuffer();

public:
  virtual void StuffList(cocos2d::ui::ListView& listToStuffFullOfGoodness, const size_t itemCount) const;
};

#endif // __FILTERING_LIST_STUFFER_H__
