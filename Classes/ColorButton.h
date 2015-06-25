#ifndef _COLORBUTTON_H_
#define _COLORBUTTON_H_

#include "cocos2d.h"
#include "CommonGameScene.h"
#include "GameScene.h"
#include "ZenGameScene.h"

USING_NS_CC;


class ColorButton : public LayerGradient
{
public:
	ColorButton();
	~ColorButton();


	static ColorButton* createWithColor(const Color4B& start, const Color4B& end);
	virtual bool initWithColor(const Color4B& start, const Color4B& end);
	virtual void onEnter();
	virtual void onExit();


private:

	bool onTouchBegan(Touch* touch , Event* event);
	void onTouchMoved(Touch* touch , Event* event);
	void onTouchEnded(Touch* touch , Event* event);

	bool containsTouchLocation(Touch* touch);
	Rect getRect();



};

#endif // _COLORBUTTON_H_
