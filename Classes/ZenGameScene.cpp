/*
 * ZenGameScene.cpp
 *
 *  Created on: 5 Jun 2015
 *      Author: chu
 */


#include "ZenGameScene.h"

Scene* ZenGameScene::createScene(){
	auto scene = Scene::create();
	auto layer = ZenGameScene::create();

	scene->addChild(layer);

	return scene;
}

bool ZenGameScene::init(){
	if (!Layer::init()){
		return false;
	}

	return true;
}

