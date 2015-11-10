#include "StageSelectScene.h"

Scene* StageSelectScene::createScene() {
	auto scene = Scene::create();

	auto layer = StageSelectScene::create();

	scene->addChild(layer);

	return scene;
}

bool StageSelectScene::init() {

	if (!LayerColor::initWithColor(Color4B(18, 21, 14, 255))) {
		return false;
	}
	medal = Sprite::create("stageselectscene/images/medal.png");
	medal->setPosition(Vec2(240, 700));
	this->addChild(medal);

	int gap = 90;

	MenuItemImage* itemArr[9];
	_stage1button = MenuItemImage::create("stageselectscene/images/stage1.png",
			"stageselectscene/images/stage1clicked.png",
			CC_CALLBACK_1(StageSelectScene::menuCloseCallback, this));
	_stage1button->setPosition(Vec2(-gap, gap));
	_stage1button->setTag(1);
	itemArr[0] = _stage1button;

	_stage2button = MenuItemImage::create("stageselectscene/images/stage2.png",
			"stageselectscene/images/stage2clicked.png",
			CC_CALLBACK_1(StageSelectScene::menuCloseCallback, this));
	_stage2button->setPosition(Vec2(0, gap));
	_stage2button->setTag(2);
	itemArr[1] = _stage2button;

	_stage3button = MenuItemImage::create("stageselectscene/images/stage3.png",
			"stageselectscene/images/stage3clicked.png",
			CC_CALLBACK_1(StageSelectScene::menuCloseCallback, this));
	_stage3button->setPosition(Vec2(gap, gap));
	_stage3button->setTag(3);
	itemArr[2] = _stage3button;

	_stage4button = MenuItemImage::create("stageselectscene/images/stage4.png",
			"stageselectscene/images/stage4clicked.png",
			CC_CALLBACK_1(StageSelectScene::menuCloseCallback, this));
	_stage4button->setPosition(Vec2(-gap, 0));
	_stage4button->setTag(4);
	itemArr[3] = _stage4button;

	_stage5button = MenuItemImage::create("stageselectscene/images/stage5.png",
			"stageselectscene/images/stage5clicked.png",
			CC_CALLBACK_1(StageSelectScene::menuCloseCallback, this));
	_stage5button->setPosition(Vec2(0, 0));
	_stage5button->setTag(5);
	itemArr[4] = _stage5button;

	_stage6button = MenuItemImage::create("stageselectscene/images/stage6.png",
			"stageselectscene/images/stage6clciked.png",
			CC_CALLBACK_1(StageSelectScene::menuCloseCallback, this));
	_stage6button->setPosition(Vec2(gap, 0));
	_stage6button->setTag(6);
	itemArr[5] = _stage6button;

	_stage7button = MenuItemImage::create("stageselectscene/images/stage7.png",
			"stageselectscene/images/stage7clicked.png",
			CC_CALLBACK_1(StageSelectScene::menuCloseCallback, this));
	_stage7button->setPosition(Vec2(-gap, -gap));
	_stage7button->setTag(7);
	itemArr[6] = _stage7button;

	_stage8button = MenuItemImage::create("stageselectscene/images/stage8.png",
			"stageselectscene/images/stage8clicked.png",
			CC_CALLBACK_1(StageSelectScene::menuCloseCallback, this));
	_stage8button->setPosition(Vec2(0, -gap));
	_stage8button->setTag(8);
	itemArr[7] = _stage8button;

	_stage9button = MenuItemImage::create("stageselectscene/images/stage9.png",
			"stageselectscene/images/stage9clicked.png",
			CC_CALLBACK_1(StageSelectScene::menuCloseCallback, this));
	_stage9button->setPosition(Vec2(gap, -gap));
	_stage9button->setTag(9);
	itemArr[8] = _stage9button;

	auto menu2 = Menu::create(_stage1button, _stage2button, _stage3button,
			_stage4button, _stage5button, _stage6button, _stage7button,
			_stage8button, _stage9button, NULL);

	menu2->setPosition(Vec2(240, 400));

	this->addChild(menu2, 3);

	_homeButton = MenuItemImage::create("playscene/images/home.png",
			"playscene/images/homeclicked.png",
			CC_CALLBACK_1(StageSelectScene::menuCloseCallback, this));
	_homeButton->setAnchorPoint(Vec2(0.5, 0.5));
	_homeButton->setPosition(Vec2(-200, 360));
	_homeButton->setTag(10);

	_muteButton = MenuItemImage::create("playscene/images/sound.png",
			"playscene/images/soundclicked.png",
			CC_CALLBACK_1(StageSelectScene::menuCloseCallback, this));
	_muteButton->setAnchorPoint(Vec2(0.5, 0.5));
	_muteButton->setPosition(Vec2(200, 360));
	_muteButton->setTag(11);


	auto menu = Menu::create(_homeButton, _muteButton, NULL);

	menu->setPosition(Vec2(240, 400));

	this->addChild(menu, 3);
	
	int tempvalue = UserDefault::getInstance()->getIntegerForKey("openstage",0);
	for (int i = tempvalue+1; i < 9; i++)
	{
		itemArr[i]->setNormalImage(Sprite::create("stageselectscene/images/notopen.png"));
		itemArr[i]->setEnabled(false);
	}

//	AudioManager::getAudioManager()->playEffectAudio(SOUND_STAGEAUDIO);

	return true;
}
void StageSelectScene::menuCloseCallback(cocos2d::Ref* pSender) {
	auto bmenuItem = (MenuItemImage*) pSender;
	bool isstageselect = false;

	if (bmenuItem->getTag() == 1) {
//		AudioManager::getAudioManager()->stopSound();
		UserDefault::getInstance()->setIntegerForKey("nowstage", 0);
		isstageselect = true;
	} else if (bmenuItem->getTag() == 2) {
	//	AudioManager::getAudioManager()->stopSound();
		UserDefault::getInstance()->setIntegerForKey("nowstage", 1);
		isstageselect = true;
	} else if (bmenuItem->getTag() == 3) {
//		AudioManager::getAudioManager()->stopSound();
		UserDefault::getInstance()->setIntegerForKey("nowstage", 2);
		isstageselect = true;
	} else if (bmenuItem->getTag() == 4) {
	//	AudioManager::getAudioManager()->stopSound();
		UserDefault::getInstance()->setIntegerForKey("nowstage", 3);
		isstageselect = true;
	} else if (bmenuItem->getTag() == 5) {
	//	AudioManager::getAudioManager()->stopSound();
		UserDefault::getInstance()->setIntegerForKey("nowstage", 4);
		isstageselect = true;
	} else if (bmenuItem->getTag() == 6) {
	//	AudioManager::getAudioManager()->stopSound();
		UserDefault::getInstance()->setIntegerForKey("nowstage", 5);
		isstageselect = true;
	} else if (bmenuItem->getTag() == 7) {
	//	AudioManager::getAudioManager()->stopSound();
		UserDefault::getInstance()->setIntegerForKey("nowstage", 6);
		isstageselect = true;
	} else if (bmenuItem->getTag() == 8) {
	//	AudioManager::getAudioManager()->stopSound();
		UserDefault::getInstance()->setIntegerForKey("nowstage", 7);
		isstageselect = true;
	} else if (bmenuItem->getTag() == 9) {
//		AudioManager::getAudioManager()->stopSound();
		UserDefault::getInstance()->setIntegerForKey("nowstage", 8);
		isstageselect = true;
	} else if (bmenuItem->getTag() == 10) {
	//	AudioManager::getAudioManager()->stopSound();
		auto titles = TitleScene::createScene();
		Director::getInstance()->replaceScene(
				TransitionPageTurn::create(1.0f, titles, false));
	} else if (bmenuItem->getTag() == 11) {
		if (!_ismute) {
			_muteButton->setNormalImage(
					Sprite::create("playscene/images/mute.png"));
			_ismute = !_ismute;
		} else {
			_muteButton->setNormalImage(
					Sprite::create("playscene/images/sound.png"));
			_ismute = !_ismute;
		}
//		AudioManager::getAudioManager()->mute();
	}

	if (isstageselect) {
		auto gscene = GamePlayScene::createScene();
		Director::getInstance()->replaceScene(gscene);
	}
}
