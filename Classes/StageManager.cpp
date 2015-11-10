///*
// * StageManager.cpp
// *
// *  Created on: Aug 1, 2015
// *      Author: hangSoon
// */
//
#include "StageManager.h"

USING_NS_CC;
StageManager::StageManager() {
	//파일의 데이터를 읽어 온다
	std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename("stage.txt");
	unsigned char* pBuffer = NULL;
	ssize_t bufferSize;
	pBuffer = CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(),"r",&bufferSize);
	CCString* tempstr = CCString::createWithData(pBuffer, bufferSize);
	fullStr = tempstr->getCString();
	strSplit(); //slpit함수로 쪼개 (이미지 id = key, 좌표 구조체 = value)맵에 저장
}
StageManager* StageManager::s_StageManager;
StageManager::~StageManager() {
	// TODO Auto-generated destructor stub
}


void StageManager::strSplit()
{
	int nCount = 0;
	int nGetIndex = 0;

	std::string sTemp = "";
	std::string sCopy = fullStr;
	while (true) {

		if(nCount<6) //이름, x, y 3개씩 마다 인덱스가 증가한다.
		{
			nGetIndex = sCopy.find("\n"); //","를 기준으로 split

			if (nGetIndex != -1) {
				sTemp += sCopy.substr(0, nGetIndex-1);
				sCopy = sCopy.substr(nGetIndex + 1); //","다음 부터 다시 시작
				++nCount;
			} else {	//마지막인 경우
			//	stageVector.push_back(sTemp);
				break;
			}
		}else
		{
			stageVector.push_back(sTemp);
			sTemp = "";
			nCount=0;
		}
	}
}


