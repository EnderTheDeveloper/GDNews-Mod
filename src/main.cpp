#include <Geode/Geode.hpp>
#include <Geode/ui/SceneManager.hpp>
#include <Geode/ui/TextRenderer.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/binding/ProfilePage.hpp>
#include <Geode/binding/CCContentLayer.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/ui/MDTextArea.hpp>
#include <Geode/utils/casts.hpp>
#include <Geode/utils/cocos.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/utils/ranges.hpp>
#include <Geode/utils/string.hpp>
#include "SwelvyBG.hpp"



using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {



	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto newsbtnsprite = CCSprite::create("newsbutton.png"_spr);

		auto newsbtn = CCMenuItemSpriteExtra::create(
			newsbtnsprite,
			this,
			menu_selector(MyMenuLayer::onNewsButton)
		);



		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(newsbtn);

		newsbtn->setID("newsbtn"_spr);

		menu->updateLayout();

		return true;
	};



	


    void onNewsButton(CCObject* sender) {


		





		

		auto newssource = Mod::get()->getSettingValue<std::string>("news-source");

		std::string newssourcetext = newssource;
	






		auto newsresult = web::fetch(newssourcetext.c_str());
		auto newstext = newsresult.value();

		auto newsdescresult = web::fetch("https://enderthedeveloper.github.io/GDNews/description.txt");
		auto newsdesctext2 = newsdescresult.value();
		




		auto currentscene = CCScene::get();
		auto menulayerscn = currentscene->getChildByID("MenuLayer");
		menulayerscn->setVisible(false);

			
		

    	auto newswinSize = CCDirector::get()->getWinSize();
        auto director = CCDirector::get();
		
        auto layer2 = CCMenu::create();
		layer2->setPosition(0, 0);		
        layer2->setID("endrei.news/stuff");
		layer2->updateLayout();
		layer2->addChild(SwelvyBG::create());

		auto scene = CCLayer::create();
		scene->setID("NewsScene");
	
		scene->addChild(layer2);
		currentscene->addChild(scene);
	
		
		
		


		auto NewsMenu = CCMenu::create();



		layer2->addChild(NewsMenu);
		

		auto SquareBG = CCScale9Sprite::create(
			"GJ_square012.png"_spr
		);
		SquareBG->setContentSize({400,235});
		SquareBG->setOpacity(70);

		auto SquareBGO = CCScale9Sprite::create(
			"square02_001.png"
		);
		SquareBGO->setContentSize({100,200});
		SquareBGO->setPosition(-135, 0);
		SquareBGO->setOpacity(80);
		

		NewsMenu->addChild(SquareBG);
		NewsMenu->addChild(SquareBGO);

		std::string newstxt = newstext;
		std::string newsdesctxt = newsdesctext2;


		auto newsthingtext = MDTextArea::create(newstext.c_str(), {263, 200});
		newsthingtext->setPosition(53, 0);
		newsthingtext->setID("news-text");

		auto newsdesctext = MDTextArea::create(newsdesctext2.c_str(), {90, 110});
		newsdesctext->setPosition({-135, -3});
		newsdesctext->setID("news-description");
		

		auto title = CCLabelBMFont::create("GDNews", "bigFont-uhd.fnt");
		NewsMenu->addChild(title);
		auto version = CCLabelBMFont::create("v.0.0.1", "goldFont-uhd.fnt");
		NewsMenu->addChild(version);
		auto logo = CCSprite::create("modlogo.png"_spr);
		NewsMenu->addChild(logo);

		auto profilebtnspr = CCSprite::createWithSpriteFrameName("accountBtn_requests_001.png");
		profilebtnspr->setScale(0.75);

		auto profilebtn = CCMenuItemSpriteExtra::create(
			profilebtnspr,
			this,
			menu_selector(MyMenuLayer::onProfileBtn)
		);






		logo->setScale(0.325);
		logo->setPosition({-160, 75});

		title->setScale(0.325);
		title->setPosition(-123, 80);

		version->setScale(0.325);
		version->setPosition(-128, 70);





		auto backbtnspr = CCSprite::create("GJ_arrow_01_1234.png"_spr);
		backbtnspr->setScale(0.45);


		auto backbtn = CCMenuItemSpriteExtra::create(
			backbtnspr,
			this,
			menu_selector(MyMenuLayer::onBackBtn)
		);
		backbtn->setPosition(-190, 105);

		auto morebtnspr = CCSprite::createWithSpriteFrameName("accountBtn_settings_001.png");
		morebtnspr->setScale(0.75);

		auto morebtn = CCMenuItemSpriteExtra::create(
			morebtnspr,
			this,
			menu_selector(MyMenuLayer::onMoreBtn)
		);
	

		auto ytbtn = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("gj_ytIcon_001.png"),
			this,
			menu_selector(MyMenuLayer::onYtBtn)
		);

		auto discordbtn = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("gj_discordIcon_001.png"),
			this,
			menu_selector(MyMenuLayer::onDiscordBtn)
		);


		auto bottom = CCMenu::create();
		NewsMenu->addChild(bottom);

		bottom->setLayout(
			RowLayout::create()
				->setGap(5.f)
				->setGrowCrossAxis(true)
				->setAxisAlignment(AxisAlignment::Center)
		);
		bottom->setContentSize({ 200.f, 0.f });
		bottom->setPositionY(-80);
		bottom->setPositionX(-135.5);
		bottom->setScale(0.625);
		






		ytbtn->setScale(0.75);
		ytbtn->m_baseScale = 0.75;


	
		discordbtn->setScale(0.75);
		discordbtn->m_baseScale = 0.75;
		morebtn->setScale(0.75);
		morebtn->m_baseScale = 0.75;


		

		NewsMenu->addChild(backbtn);
		bottom->addChild(ytbtn);
		bottom->addChild(morebtn);
		bottom->addChild(discordbtn);
		bottom->addChild(profilebtn);
		NewsMenu->setID("NewsMenu");
	

		morebtn->setID("morebtn"_spr);

		discordbtn->setID("discordbtn"_spr);
		ytbtn->setID("ytbtn"_spr);
		backbtn->setID("backbtn"_spr);

		bottom->updateLayout();

		
//cmake --build build --config RelWithDebInfo
		

		
		
	

		NewsMenu->updateLayout();
		NewsMenu->addChild(newsthingtext);
		NewsMenu->addChild(newsdesctext);
		auto descthing = NewsMenu->getChildByID("news-description");
		auto descbg = getChildOfType<CCScale9Sprite>(descthing, 0);
		descbg->setOpacity(0);

		
		layer2->updateLayout();
		
    };

	void onBackBtn(CCObject* sender){

		

		
		auto currentscene1 = CCScene::get();
		auto menulayerscn = currentscene1->getChildByID("MenuLayer");
		menulayerscn->setVisible(true);

		auto newsscenev = currentscene1->getChildByID("NewsScene");
		newsscenev->removeMeAndCleanup();
		
				

		
        


	};

		void onMoreBtn(CCObject* sender){
			openSettingsPopup(Mod::get());
			
	};



		void onProfileBtn(CCObject* pSender) {

			int id = 14709748;


			ProfilePage::create(id, false)->show();
		};
		





	

		void onYtBtn(CCObject* sender){

			geode::utils::web::openLinkInBrowser("https://www.youtube.com/channel/UCwmAgno0YhfQDcrSWlkC-3A");



		
	};




		void onDiscordBtn(CCObject* sender){

			geode::utils::web::openLinkInBrowser("https://discord.gg/mAcBAVujx4");



		
	};






		
	
};