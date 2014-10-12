LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

HELLOCPP_FILES  := $(wildcard $(LOCAL_PATH)/hellocpp/*.cpp)
HELLOCPP_FILES  := $(HELLOCPP_FILES:$(LOCAL_PATH)/%=%)

CLASSES_FILES   := $(wildcard $(LOCAL_PATH)/../../Classes/*.cpp)
CLASSES_FILES   := $(CLASSES_FILES:$(LOCAL_PATH)/%=%)

INFRASTRUCTURE_FILES   := $(wildcard $(LOCAL_PATH)/../../Classes/Infrastructure/*.cpp)
INFRASTRUCTURE_FILES   := $(INFRASTRUCTURE_FILES:$(LOCAL_PATH)/%=%)

SCENE_FILES   := $(wildcard $(LOCAL_PATH)/../../Classes/UserInterface/Scenes/*.cpp)
SCENE_FILES   := $(SCENE_FILES:$(LOCAL_PATH)/%=%)

WIDGET_FILES   := $(wildcard $(LOCAL_PATH)/../../Classes/UserInterface/Widgets/*.cpp)
WIDGET_FILES   := $(WIDGET_FILES:$(LOCAL_PATH)/%=%)

LOCAL_SRC_FILES := $(HELLOCPP_FILES)
LOCAL_SRC_FILES += $(CLASSES_FILES)
LOCAL_SRC_FILES += $(INFRASTRUCTURE_FILES)
LOCAL_SRC_FILES += $(SCENE_FILES)
LOCAL_SRC_FILES += $(WIDGET_FILES)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2d/extensions

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static

# LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocosbuilder_static
# LOCAL_WHOLE_STATIC_LIBRARIES += spine_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocostudio_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocos_network_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_ui_static


include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,audio/android)

# $(call import-module,Box2D)
# $(call import-module,editor-support/cocosbuilder)
# $(call import-module,editor-support/spine)
#$(call import-module,editor-support/cocostudio)
# $(call import-module,network)
$(call import-module,extensions)
$(call import-module,ui)
