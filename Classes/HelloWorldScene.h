#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Define.h"
#include "ColorButton.h"
#include "VisibleRect.h"


class HelloWorld : public cocos2d::Layer
{
public:

    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(HelloWorld);

private : 
	ColorButton* createRect(Color4B color4B1, Color4B color4B2, int horizontal, int vertical);
	void createLabel(ColorButton* layer, std::vector<const char *> labelTitleVec, Color3B color3B, int horizontal, int vertical);
	void createLastRectLabel(ColorButton* layer, Color3B color3B);


	void menuCloseCallback(Ref* pSender);
};

#endif // __HELLOWORLD_SCENE_H__
