#include "GameColorButton.h"

GameColorButton::GameColorButton(void)
{
}

GameColorButton::~GameColorButton(void)
{
}

/*


*/
GameColorButton* GameColorButton::createWithColor(const Color4B& start, const Color4B& end){
	GameColorButton* layer = new (std::nothrow) GameColorButton();
	if (layer && layer->initWithColor(start,end)){
		layer->autorelease();
		return layer;
	}

	CC_SAFE_DELETE(layer);
	return nullptr;
}

bool GameColorButton::initWithColor(const Color4B& start, const Color4B& end){
	if (!LayerGradient::initWithColor(start , end)){
		return false;
	}
	return true;
}

void GameColorButton::onEnter(){

	LayerGradient::onEnter();


	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(GameColorButton::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameColorButton::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameColorButton::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}


void GameColorButton::onExit(){
	LayerGradient::onExit();
}

Rect GameColorButton::getRect(){
	auto s = getContentSize();
	return Rect(0, -s.height, s.width, s.height);
}


DrawNode* GameColorButton::createDrawNode(const Vec2& pos){
	auto drawNode = DrawNode::create();
	float width = getRect().size.width;
	float height = getRect().size.height;
	Vec2 origin = getRect().origin;


	Size size = getRect().size;
	Vec2 points[4] = {
		origin ,
		origin + Vec2(width , 0) ,
		origin + Vec2(width , height) ,
		origin + Vec2(0 , height) ,
	};

	drawNode->drawPolygon(points, 4, Color4F(0, 0, 0, 0), 0.5, Color4F::BLACK);
	drawNode->setPosition(pos);

	this->addChild(drawNode);

	return drawNode;
}