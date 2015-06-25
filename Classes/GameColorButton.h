#ifndef _GAMECOLORBUTTON_H_
#define _GAMECOLORBUTTON_H_

#include "cocos2d.h"
#include "VisibleRect.h"
#include "GameScene.h"



USING_NS_CC;

class GameColorButton : public LayerGradient
{
public:
	GameColorButton(void);
	~GameColorButton(void);

	static GameColorButton* createWithColor(const Color4B& start, const Color4B& end);
	virtual bool initWithColor(const Color4B& start, const Color4B& end);

	void onEnter();
	void onExit();


	int isBlack;
	int myLevel;


protected :
	DrawNode* rectStroke;
	GameScene* gameScene;

	DrawNode* createDrawNode(const Vec2& pos);
	Rect getRect();

private:


};

#endif //_GAMECOLORBUTTON_H_
