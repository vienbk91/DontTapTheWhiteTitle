/*
 * GameScene.h
 *
 *  Created on: 5 Jun 2015
 *      Author: chu
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_

#include "cocos2d.h"

USING_NS_CC;


class GameScene : public Layer {
public:
	static Scene* createScene();
	virtual bool init();


	CREATE_FUNC(GameScene);

private:
};



#endif /* GAMESCENE_H_ */
