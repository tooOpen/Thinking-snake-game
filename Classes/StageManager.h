///*
// * StageManager.h
// *
// *  Created on: Aug 1, 2015
// *      Author: hangSoon
// */

#ifndef STAGEMANAGER_H_
#define STAGEMANAGER_H_

#include <vector>
#include <string>
#include<stdlib.h>
#include "cocos2d.h"

class StageManager
{
public:
	static StageManager* getStageManager()	//for 싱글톤
	{
		if (!s_StageManager)
		{
			s_StageManager = new StageManager();
		}
		return s_StageManager;
	}
	virtual ~StageManager();
	std::vector<std::string> stageVector;
private:
	static StageManager* s_StageManager;	//for 싱글톤

	std::string fullStr;	//파일 풀 데이터
	void strSplit();		//파일 데이터를 split하는 함수
	StageManager();
};

#endif /* STAGEMANAGER_H_ */
