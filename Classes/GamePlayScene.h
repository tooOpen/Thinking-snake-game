

#ifndef GAMEPLAYSCENE_H_
#define GAMEPLAYSCENE_H_

#pragma once


#include "cocos2d.h"
#include "MapLayer.h"
#include "StageSelectScene.h"
#include "TitleScene.h"
USING_NS_CC;

class GamePlayScene : public cocos2d::LayerColor
{
public:

	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GamePlayScene)
	bool _backSlide = false;
	bool _ismute = false;
	MenuItemImage* _stageButton;
	MenuItemImage* _homeButton;
	MenuItemImage* _muteButton;
	MenuItemImage* _resetButton;
	Sprite* _holdBack;
	Sprite* _slideBack;
	MapLayer* layer_top;
	virtual void onExit();
	void menuCloseCallback(cocos2d::Ref* pSender);
	void backgroundSlideSchedule(float f);
};
#endif




