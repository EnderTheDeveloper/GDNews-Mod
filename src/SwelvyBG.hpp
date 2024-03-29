#pragma once

#include <Geode/ui/General.hpp>

using namespace geode::prelude;

class SwelveNode : public CCSprite
{
    public:
        float speed;
        int repeatCount;

        bool init(CCSpriteFrame* name)
        {
            if (!CCSprite::initWithSpriteFrame(name))
                return false;

            return true;
        }

        static SwelveNode* createWithSpriteFrame(CCSpriteFrame* name)
        {
            auto pRet = new SwelveNode();

            pRet->init(name);
            pRet->autorelease();

            return pRet;
        }
};

class SwelvyBG : public CCSpriteBatchNode {
protected:
    bool init();

    void updateSpritePosition(float dt);

public:
    static SwelvyBG* create();
};
