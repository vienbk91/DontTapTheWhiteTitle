/*
 * GameScene.cpp
 *
 *  Created on: 5 Jun 2015
 *      Author: chu
 */


#include "GameScene.h"

Scene* GameScene::createScene(){
	auto scene = Scene::create();
	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene::init(){
	if (!Layer::init()){
		return false;
	}






	return true;
}

