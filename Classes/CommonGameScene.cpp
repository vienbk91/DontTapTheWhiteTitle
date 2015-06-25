/*
 * CommonGameScene.cpp
 *
 *  Created on: 5 Jun 2015
 *      Author: chu
 */


#include "CommonGameScene.h"

Scene* CommonGameScene::createScene(){
	auto scene = Scene::create();
	auto layer = CommonGameScene::create();

	scene->addChild(layer);

	return scene;
}

bool CommonGameScene::init(){
	if (!Layer::init()){
		return false;
	}


	return true;
}

