#include "MapLayer.h"

void MapLayer::resetfield()
{


	feedCount = 0;
	stage =  UserDefault::getInstance()->getIntegerForKey("nowstage",0);

//	if(stage == 0)
//	{
//		auto helper1 = Sprite::create("playscene/images/helpfinger.png");
//		helper1->setPosition(Vec2(0,500));
//		this->addChild(helper1);
//
//	}
	std::string tempfield = StageManager::getStageManager()->stageVector[stage];

	int fieldcount = 0;
	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<5; j++)
		{
			char at = tempfield[fieldcount++];
			int ttemp = atoi(&at);
			field[i][j] = ttemp;
		}
	}
	snakeCount = atoi(&tempfield[25]);

	for (int i = 0; i<snakeCount; i++)
	{
		SnakeSprite tempsnake(atoi(&tempfield[27 + i * 7]), atoi(&tempfield[29 + i * 7]), atoi(tempfield.substr(31 + i * 7, 32 + i * 7).c_str()));
		snakeArr[i] = tempsnake;
		snakeArr[i].snake->setPosition(Vec2(snakeArr[i].posX * 80 + 40, snakeArr[i].posY * 80 + 40));
		auto start = Sprite::create("playscene/images/startfoot.png");
		start->setPosition(Vec2(snakeArr[i].posX * 80 + 40, snakeArr[i].posY * 80 + 40));
		this->addChild(start, 1);
		this->addChild(snakeArr[i].snake, 3);
	}


	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<5; j++)
		{
			if (field[i][j] != 0)
			{
				Sprite* tempfeed = Sprite::create(matchFeed(field[i][j]));
				tempfeed->setPosition(Vec2(j * 80 + 40, i * 80 + 40));
				feedArray[feedCount++] = tempfeed;

				this->addChild(tempfeed);
			}
		}
	}


	_stageNum = LabelTTF::create(CCString::createWithFormat("%d", stage+1)->getCString(), "fonts/arial.ttf", 300);
	_stageNum->setPosition(Vec2(200, 200));
	_stageNum->setColor(Color3B(54, 100, 139));
	this->addChild(_stageNum, 10);

	auto shrinkAction = ScaleTo::create(0.6, 0.2);
	auto temp = EaseBackOut::create(shrinkAction);
	auto upAction = MoveTo::create(0.5, Vec2(200, 530));
	auto backAction = Sequence::create(temp, DelayTime::create(0.5), upAction, NULL);

	_stageNum->runAction(backAction);
}
void MapLayer::onExit()
{
	_eventDispatcher->removeAllEventListeners();
}
void MapLayer::on_exit()
{
	_eventDispatcher->removeAllEventListeners();
}
bool MapLayer::init()
{
	if (!MapLayer::initWithColor(Color4B(0, 0, 0, 0))) {
		return false;
	}
	feedCount = 0;
	stage = UserDefault::getInstance()->getIntegerForKey("nowstage",0);

	std::string tempfield = StageManager::getStageManager()->stageVector[stage];

	int fieldcount = 0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			char at = tempfield[fieldcount++];
			int ttemp = atoi(&at);
			field[i][j] = ttemp;
		}
	}
	snakeCount = atoi(&tempfield[25]);

	for(int i=0;i<snakeCount;i++)
	{
		SnakeSprite tempsnake(atoi(&tempfield[27 + i * 7]), atoi(&tempfield[29 + i * 7]), atoi(tempfield.substr(31 + i * 7, 32 + i * 7).c_str()));
		snakeArr[i] = tempsnake;
		snakeArr[i].snake->setPosition(Vec2(snakeArr[i].posX*80+40,snakeArr[i].posY*80+40));
		auto start = Sprite::create("playscene/images/startfoot.png");
		start->setPosition(Vec2(snakeArr[i].posX*80+40,snakeArr[i].posY*80+40));
		this->addChild(start, 1);
		this->addChild(snakeArr[i].snake,3);
	}


	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(field[i][j] != 0)
			{
				Sprite* tempfeed = Sprite::create(matchFeed(field[i][j]));
				tempfeed->setPosition(Vec2(j*80+40,i*80+40));
				feedArray[feedCount++] = tempfeed;
				
				this->addChild(tempfeed);
			}
		}
	}
	  auto listener = EventListenerTouchOneByOne::create();

	     listener->setSwallowTouches(true);

	     listener->onTouchBegan = CC_CALLBACK_2(MapLayer::onTouchBegan, this);
	     listener->onTouchMoved = CC_CALLBACK_2(MapLayer::onTouchMoved, this);
	     listener->onTouchCancelled = CC_CALLBACK_2(MapLayer::onTouchCancelled, this);
	     listener->onTouchEnded = CC_CALLBACK_2(MapLayer::onTouchEnded, this);

	     _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


		 _stageNum = LabelTTF::create(CCString::createWithFormat("%d", stage+1)->getCString(), "fonts/arial.ttf", 300);
		 _stageNum->setPosition(Vec2(200, 200));
		 _stageNum->setColor(Color3B(54, 100, 139));
		 this->addChild(_stageNum, 10);

		 auto shrinkAction = ScaleTo::create(0.6, 0.2);
		 auto temp = EaseBackOut::create(shrinkAction);
		 auto upAction = MoveTo::create(0.5, Vec2(200, 530));
		 auto backAction = Sequence::create(temp, DelayTime::create(0.5), upAction, NULL);

		 _stageNum->runAction(backAction);

	//	 AudioManager::getAudioManager()->playEffectAudio(SOUND_PALYAUDIO);

	return true;
 }
bool MapLayer::onTouchBegan(Touch* touch, Event* unused_event){

	auto target = static_cast<Layer *>(unused_event->getCurrentTarget());
	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());

	for (int i = 0; i < snakeCount; i++)
	{
		if (snakeArr[i].snake->boundingBox().containsPoint(locationInNode))
		{
			beforeIndexX = locationInNode.x / 80;
			beforeIndexY = locationInNode.y / 80;
	//		snakeArr[i].snake->setTexture(Director::getInstance()->getTextureCache()->addImage("playscene/images/eatingsnake.png"));
		//	snakeArr[i].snake->setScale(1.5);
			dragState = true;
			selectedSnake = i;
		}
	}
	return true;
}

void MapLayer::onTouchMoved(Touch* touch, Event* unused_event){

	auto target = static_cast<Sprite *>(unused_event->getCurrentTarget());
		Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());

		int snakeIndex = locationInNode.x/80;
		int snakeIndey = locationInNode.y/80;

		if (locationInNode.x > 0 && locationInNode.x < 400 && locationInNode.y>0 && locationInNode.y < 400)
		{
			if (dragState &&selectedSnake!=-1&& field[snakeIndey][snakeIndex] != 0 && snakeArr[selectedSnake].value>0 &&
				abs((beforeIndexX + 1) - (snakeIndex + 1)) + abs((beforeIndexY + 1) - (snakeIndey + 1)) == 1)
			{
			//	AudioManager::getAudioManager()->playEffectAudio(SOUND_EATFRUIT);
				for (int i = 0; i < feedCount; i++)
				{
					if (feedArray[i]->boundingBox().containsPoint(locationInNode))
					{
						snakeArr[selectedSnake].setText(field[snakeIndey][snakeIndex]);
						feedArray[i]->setTexture(Director::getInstance()->getTextureCache()->addImage("playscene/images/eaten.png"));
					}
				}
				beforeIndexX = snakeIndex;
				beforeIndexY = snakeIndey;
				field[snakeIndey][snakeIndex] = 0;
				snakeArr[selectedSnake].snake->setPosition(Vec2(snakeIndex * 80 + 40, snakeIndey * 80 + 40));
			}
		}
}

void MapLayer::onTouchCancelled(Touch* touch, Event* unused_event){}

void MapLayer::onTouchEnded(Touch* touch, Event* unused_event){

//	snakeArr[selectedSnake].snake->setTexture(Director::getInstance()->getTextureCache()->addImage("playscene/images/snakeheadfinal.png"));
//	snakeArr[selectedSnake].snake->setScale(1);
	dragState = false;
	selectedSnake = -1;


	for (int i = 0; i < snakeCount; i++)
	{
		if (snakeArr[i].value != 0)
			break;
		if (i == snakeCount - 1)
		{
			if(stage+1<9)
			{
				UserDefault::getInstance()->setIntegerForKey("nowstage",stage+1);
				if(UserDefault::getInstance()->getIntegerForKey("openstage",0)<stage+1)
				{
					UserDefault::getInstance()->setIntegerForKey("openstage",stage+1);
				}
				this->removeAllChildren();
				resetfield();
			}
			else
			{
				auto gameclearsprite = Sprite::create("playscene/images/gameclear.png");
				gameclearsprite->setPosition(Vec2(200, 200));
				this->addChild(gameclearsprite,10);

				auto particleTest2 = ParticleExplosion::create();

					auto texture2 = Director::getInstance()->getTextureCache()->addImage("playscene/images/particle.png");
					particleTest2->setTexture(texture2);
					if (particleTest2 != NULL)
					{
						particleTest2->setScale(1.0);
						particleTest2->setEmissionRate(100.0);
						particleTest2->setStartSize(50.0);
						particleTest2->setLife(3.0);
						particleTest2->setDuration(-1);
						particleTest2->setEndSize(0.0);
						particleTest2->setPosition(Vec2(200, 200));
						particleTest2->setStartColor(Color4F(25, 125, 79, 255));
						particleTest2->setEndColor(Color4F(35, 213, 48, 255));
						this->addChild(particleTest2, 9);
					}
					UserDefault::getInstance()->setIntegerForKey("openstage", 8);
				//this->scheduleOnce(schedule_selector(MapLayer::gameclear),3.0f);

				//clear

			}
		}
	}
}


std::string MapLayer::matchFeed(int value)
{
	std::string temp  = "";
	switch (value) {
	case 1:
		temp = "playscene/images/one.png";
		break;
	case 2:
		temp = "playscene/images/two.png";
		break;
	case 3:
		temp = "playscene/images/three.png";
		break;
	case 4:
		temp = "playscene/images/four.png";
		break;
	case 5:
		temp = "playscene/images/five.png";
		break;
	case 6:
		temp = "playscene/images/six.png";
		break;
	case 7:
		temp = "playscene/images/seven.png";
		break;
	case 8:
		temp = "playscene/images/eight.png";
		break;
	case 9:
		temp = "playscene/images/nine.png";
		break;
	}
	return temp;
}
void MapLayer::refresh()
{
	this->removeAllChildren();
	resetfield();
}

