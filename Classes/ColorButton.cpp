#include "ColorButton.h"

ColorButton::ColorButton()
{
}

ColorButton::~ColorButton()
{
}


ColorButton* ColorButton::createWithColor(const Color4B& start,const Color4B& end){
	auto colorButton = new (std::nothrow) ColorButton();
	if (colorButton && colorButton->initWithColor(start, end)){
		colorButton->autorelease();
		return colorButton;
	}

	CC_SAFE_DELETE(colorButton);

	return nullptr;
}

bool ColorButton::initWithColor(const Color4B& start, const Color4B& end){
	if (!LayerGradient::initWithColor(start, end)){
		return false;
	}

	return true;
}

void ColorButton::onEnter(){

	LayerGradient::onEnter();


	// Dang ky su kien touch cho doi tuong ColorButton
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(ColorButton::onTouchBegan , this);
	listener->onTouchMoved = CC_CALLBACK_2(ColorButton::onTouchMoved , this);
	listener->onTouchEnded = CC_CALLBACK_2(ColorButton::onTouchEnded , this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener , this);

}

void ColorButton::onExit(){
	LayerGradient::onExit();
}

/////////////////////////////////////////////////////////
// Lay pham vi cua phan tu touch
/////////////////////////////////////////////////////////
bool ColorButton::containsTouchLocation(Touch* touch)
{
    return getRect().containsPoint(convertTouchToNodeSpaceAR(touch));
}
Rect ColorButton::getRect()
{
    auto s = getContentSize();
    return Rect(0, -s.height, s.width, s.height); // Rect(x,y,width,height);
}

bool ColorButton::onTouchBegan(Touch* touch, Event* event){
	log("============Touch Began==============");

	if (!containsTouchLocation(touch)){
		return false;
	}

	switch (this->getTag())
	{
	case 0:
		log("======== Move To CommonGameScene =========");
		Director::getInstance()->replaceScene(CommonGameScene::createScene());
		break;
	case 1:
		log("======== Move To GameScene =========");
		Director::getInstance()->replaceScene(GameScene::createScene());
		break;
	case 2:
		log("======== Move To ZenGameScene =========");
		Director::getInstance()->replaceScene(ZenGameScene::createScene());
		break;
	default:
		break;
	}

	return true;
}

void ColorButton::onTouchMoved(Touch* touch, Event* event){

}

void ColorButton::onTouchEnded(Touch* touch, Event* event){

}

