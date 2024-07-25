#include <Geode/Geode.hpp>

#include "./Spinner.hpp"

#include <cctype>
#include <algorithm>
#include <matjson.hpp>

using namespace geode::prelude;

Spinner* Spinner::create() {
    auto ret = new Spinner();
    if (ret && ret->initWithSpriteFrameName("spinner-frame-0.png"_spr)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
};

Spinner* Spinner::createWithAutoStart() {
    auto ret = new Spinner();
    if (ret && ret->initWithSpriteFrameName("spinner-frame-0.png"_spr)) {
        ret->animate();
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
};

void Spinner::animate() {
    // start animations
    this->runAction(CCRepeatForever::create(CCSequence::create(CCRotateBy::create(1.4, 360), nullptr, nullptr)));
    this->schedule(schedule_selector(Spinner::spinnerAnimation), (1/60.f));
}

void Spinner::spinnerAnimation(float dt) {
    if (m_currentSpinnerFrame == 84) {
        m_currentSpinnerFrame = 0;
    } else {
        m_currentSpinnerFrame += 1;
    }
    
    auto newFrameName = fmt::format("spinner-test-one-{}.png"_spr, m_currentSpinnerFrame);
    Ref<CCSpriteFrame> sprframe = CCSpriteFrameCache::get()->spriteFrameByName(newFrameName.c_str());
    this->setDisplayFrame(sprframe);
}