#include "HelloWorldScene.h"

USING_NS_CC;

/*
Khởi tạo Scene HelloWorld
*/
Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Tạo 1 mảng kiểu const char* với 3 phần tử
	std::vector<const char*> labelTitleVector;
	labelTitleVector.push_back("Nomal");
	labelTitleVector.push_back("Common");
	labelTitleVector.push_back("Zen");


	Color4B color4B1;
	Color4B color4B2;
	Color3B color3B;

	int drawWhite = 0;

	// Duyệt 2 vòng lặp với vertical = [0,1] , horizontal = [0,1]
	for (int vertical = 0; vertical < 2 ; vertical++){
		for (int  horizontal = 0; horizontal < 2 ; horizontal++){

			if (0 == drawWhite){
				color4B1 = Color4B(255, 255, 255, 255); // white
				color3B = Color3B(0, 0, 0); // black
			}
			else{
				color4B1 = Color4B(0, 0, 0, 255); // back
				color3B = Color3B(255, 255, 255); // white
			}

			color4B2 = Color4B(255, 179, 167, 255);

			ColorButton* layer = createRect(color4B1, color4B2, horizontal, vertical);

			if (horizontal + vertical*2 != labelTitleVector.size()){
				createLabel(layer, labelTitleVector, color3B, horizontal, vertical);
			}
			else{
				createLastRectLabel(layer, color3B);
			}

			drawWhite++;

			if (drawWhite > 2){
				drawWhite = 0;
			}

		}
	}


    return true;
}


ColorButton* HelloWorld::createRect(Color4B color4B1, Color4B color4B2, int horizontal, int vertical) {
	Size rect = VisibleRect::getVisibleRect().size;


	ColorButton * layer = ColorButton::createWithColor(color4B1, color4B1);
	layer->setTag(horizontal + vertical * 2);
	layer->setAnchorPoint(Vec2(0.0f, 1.0f));
	layer->ignoreAnchorPointForPosition(false);
	layer->setContentSize(rect / 2);
	layer->setPosition(VisibleRect::leftTop() + Vec2(rect.width / 2 * horizontal, -rect.height / 2 * vertical));
	addChild(layer);

	return layer;
}

void HelloWorld::createLabel(ColorButton* layer, std::vector<const char *> labelTitleVec, Color3B color3B, int horizontal, int vertical)
{
	auto label = LabelTTF::create(labelTitleVec.at(horizontal + vertical * 2), "Arial", bigTitleSize_macro);
	label->setColor(color3B);
	label->setAnchorPoint(Vec2(0.5f, 0.5f));
	label->setPosition(Vec2(layer->getContentSize().width / 2,
	layer->getContentSize().height / 2));

	layer->addChild(label, 1);
}

void HelloWorld::createLastRectLabel(ColorButton* layer,Color3B color3B)
{
    std::vector<const char *> labelTitleVec;
    labelTitleVec.push_back("Huong dan");
    labelTitleVec.push_back("Bang xep hang");
    labelTitleVec.push_back("So diem");
    labelTitleVec.push_back("Them tro choi");

    auto menu = Menu::create();
    menu->setPosition(Vec2::ZERO);
    layer->addChild(menu, 1);

    for(int i = 0 ;i<4;i++)
    {
        auto closeItem = MenuItemFont::create(labelTitleVec.at(i),
                                              CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
        closeItem->setFontSizeObj(bigTitleSize_macro);
        closeItem->setColor(color3B);
        closeItem->setTag(i);
        closeItem->setPosition(Vec2(layer->getContentSize().width/2 , layer->getContentSize().height-layer->getContentSize().height*(i+2)/(labelTitleVec.size()+2)));

        menu->addChild(closeItem);
    }

}


void HelloWorld::menuCloseCallback(Ref* pSender){

}
