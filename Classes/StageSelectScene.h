
#ifndef STAGESELECTSCENE_H_
#define STAGESELECTSCENE_H_

#pragma once


#include "cocos2d.h"
#include "TitleScene.h"
#include "GamePlayScene.h"
USING_NS_CC;

class StageSelectScene : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(StageSelectScene)
	MenuItemImage* _stage1button;
	MenuItemImage* _stage2button;
	MenuItemImage* _stage3button;
	MenuItemImage* _stage4button;
	MenuItemImage* _stage5button;
	MenuItemImage* _stage6button;
	MenuItemImage* _stage7button;
	MenuItemImage* _stage8button;
	MenuItemImage* _stage9button;
	bool _ismute = false;
	MenuItemImage* _homeButton;
	MenuItemImage* _muteButton;

	Sprite* medal;
	void menuCloseCallback(cocos2d::Ref* pSender);
};
#endif /* STAGESELECTSCENE_H_ */
