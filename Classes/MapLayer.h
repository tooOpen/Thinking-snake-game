#ifndef MAPLAYER_H_
#define MAPLAYER_H_

#pragma once

#include "cocos2d.h"
#include "StageManager.h"
//#include "AudioManager.h"
#include <string>
#include<stdlib.h>
USING_NS_CC;

class SnakeSprite
{
public:
	int posX;
	int posY;
	int value;
	Sprite* snake;
	Label* valueText;
	SnakeSprite(int x, int y, int v) :posX(x), posY(y), value(v)
	{
		snake = Sprite::create("playscene/images/snakeheadfinal.png");
		Size parentsize;
		parentsize = snake->getContentSize();
		valueText =  Label::createWithTTF(String::createWithFormat("%d", value)->getCString(), "fonts/arial.ttf", 70);
		valueText->setTextColor(Color4B::BLACK);
		valueText->setPosition(Vec2(parentsize.width / 2, parentsize.height / 2));
		snake->addChild(valueText);
	}
	SnakeSprite()
	{

	}
	void setText(int v)
	{
		value = value - v == 0 ?0:value-v;
		valueText->setString(String::createWithFormat("%d", value)->getCString());
	}
};
class MapLayer : public cocos2d::LayerColor
{
public:
	virtual bool init();
	CREATE_FUNC(MapLayer)
	Sprite* feedArray[25];
	int selectedSnake;
	bool dragState;
	int snakeCount;
	int field[5][5];
	int feedCount;
	int beforeIndexX;
	int beforeIndexY;

	int stage = 0; //sharedpreference
	SnakeSprite snakeArr[5];
	LabelTTF* _stageNum;
	std::string matchFeed(int value); //그림이름
	void refresh();
	virtual void on_exit();
	virtual bool onTouchBegan(Touch* touch, Event* unused_event);
	virtual void onTouchMoved(Touch* touch, Event* unused_event);
	virtual void onTouchCancelled(Touch* touch, Event* unused_event);
	virtual void onTouchEnded(Touch* touch, Event *unused_event);
	void resetfield();
	virtual void onExit();

	void gameclear(float f);
};
#endif
