/*
 * CommonGameScene.h
 *
 *  Created on: 5 Jun 2015
 *      Author: chu
 */

#ifndef COMMONGAMESCENE_H_
#define COMMONGAMESCENE_H_

#include "cocos2d.h"

USING_NS_CC;

class CommonGameScene : public Layer {
public:
	static Scene* createScene();
	virtual bool init();

	CREATE_FUNC(CommonGameScene);

private:
};


#endif /* COMMONGAMESCENE_H_ */
