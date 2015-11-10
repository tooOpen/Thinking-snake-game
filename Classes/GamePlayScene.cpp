#include "GamePlayScene.h"


Scene* GamePlayScene::createScene() {
	auto scene = Scene::create();

	auto layer = GamePlayScene::create();

	scene->addChild(layer);

	return scene;
}

bool GamePlayScene::init() {

	if (!LayerColor::initWithColor(Color4B(0, 255, 255, 255))) {
		return false;
	}

	this->setKeypadEnabled(true);


	_holdBack = Sprite::create("commons/images/holdback.png");
	_holdBack->setPosition(Vec2(240, 400));
	this->addChild(_holdBack, 0);

	_slideBack = Sprite::create("commons/images/slideback.png");
	_slideBack->setAnchorPoint(Vec2(0.5, 0.0));
	_slideBack->setPosition(Vec2(240, 0));
	this->addChild(_slideBack, 1);




	_stageButton = MenuItemImage::create(
		"playscene/images/stage.png",
		"playscene/images/stageclicked.png",
		CC_CALLBACK_1(GamePlayScene::menuCloseCallback, this));
	_stageButton->setAnchorPoint(Vec2(0.5, 0.5));
	_stageButton->setPosition(Vec2(-190, 360));
	_stageButton->setTag(1);


	_homeButton = MenuItemImage::create(
		"playscene/images/home.png",
		"playscene/images/homeclicked.png",
		CC_CALLBACK_1(GamePlayScene::menuCloseCallback, this));
	_homeButton->setAnchorPoint(Vec2(0.5, 0.5));
	_homeButton->setPosition(Vec2(-130, 360));
	_homeButton->setTag(2);

	_muteButton = MenuItemImage::create(
		"playscene/images/sound.png",
		"playscene/images/sound.png",
		CC_CALLBACK_1(GamePlayScene::menuCloseCallback, this));
	_muteButton->setAnchorPoint(Vec2(0.5, 0.5));
	_muteButton->setPosition(Vec2(200, 360));
	_muteButton->setTag(3);


	_resetButton = MenuItemImage::create(
		"playscene/images/return.png",
		"playscene/images/returnclicked.png",
		CC_CALLBACK_1(GamePlayScene::menuCloseCallback, this));
	_resetButton->setAnchorPoint(Vec2(0.5, 0.5));
	_resetButton->setPosition(Vec2(0, -360));
	_resetButton->setTag(4);

	auto menu = Menu::create(_stageButton, _homeButton, _muteButton, _resetButton,NULL);

	menu->setPosition(Vec2(240, 400));

	this->addChild(menu, 3);

	layer_top = MapLayer::create();
	layer_top->setPosition(Vec2(40, 200));
	layer_top->setContentSize(Size(400, 400));
	layer_top->retain();
	this->addChild(layer_top, 2);


	this->schedule(schedule_selector(GamePlayScene::backgroundSlideSchedule), 20.0f, CC_REPEAT_FOREVER, 20.0f);

	return true;
}
void GamePlayScene::menuCloseCallback(Ref* pSender)
{
	auto bmenuItem = (MenuItemImage*)pSender;

	if(bmenuItem->getTag() ==1 )
		{
		//	AudioManager::getAudioManager()->stopSound();
			auto sscene = StageSelectScene::createScene();
			Director::getInstance()->replaceScene(TransitionSplitRows::create(1.0f,sscene));
		}
		else if(bmenuItem->getTag() ==2 )
		{
		//	AudioManager::getAudioManager()->stopSound();
			auto tscene = TitleScene::createScene();
			Director::getInstance()->replaceScene(tscene);
		}
		else if(bmenuItem->getTag() ==3 )
		{

			if(!_ismute)
				{
				_muteButton->setNormalImage(Sprite::create("playscene/images/mute.png"));
				_ismute =!_ismute;
				}
				else{
					_muteButton->setNormalImage(Sprite::create("playscene/images/sound.png"));
					_ismute =!_ismute;
				}
			//AudioManager::getAudioManager()->mute();
		}
		else if(bmenuItem->getTag() ==4 )
		{

			layer_top->refresh();

		}

}
void GamePlayScene::onExit()
{

}
void GamePlayScene::backgroundSlideSchedule(float f)
{
	if (_backSlide)
	{
		auto transiAction = MoveTo::create(2.2, Vec2(240, 0));
		_slideBack->runAction(transiAction);
		_backSlide = !_backSlide;
	}
	else
	{
		auto transiAction = MoveTo::create(2.0, Vec2(240, 800));
		auto gotoAction = MoveTo::create(0.0, Vec2(240, -1000));
		auto upAction = MoveTo::create(1.0, Vec2(240, -930));
		auto backAction = Sequence::create(transiAction, gotoAction, upAction, NULL);

		_slideBack->runAction(backAction);
		_backSlide = !_backSlide;
	}
}


