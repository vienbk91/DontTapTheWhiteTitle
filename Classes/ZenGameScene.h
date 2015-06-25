/*
 * ZenGameScene.h
 *
 *  Created on: 5 Jun 2015
 *      Author: chu
 */

#ifndef ZENGAMESCENE_H_
#define ZENGAMESCENE_H_

#include "cocos2d.h"

USING_NS_CC;

class ZenGameScene : public Layer {
public:
	static Scene* createScene();
	virtual bool init();

	CREATE_FUNC(ZenGameScene);

private:
};


#endif /* ZENGAMESCENE_H_ */
