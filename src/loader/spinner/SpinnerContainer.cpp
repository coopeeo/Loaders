#include <Geode/Geode.hpp>

#include "./SpinnerContainer.hpp"

#include <cctype>
#include <algorithm>
#include <matjson.hpp>

using namespace geode::prelude;

SpinnerContainer* SpinnerContainer::create() {
    auto ret = new SpinnerContainer();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
};

bool SpinnerContainer::init() {
    m_spinner = Spinner::create();

    this->addChild(m_spinner);

    return true;
}

void SpinnerContainer::show() {
    m_spinner->animate();
}

SpinnerContainer::SpinnerContainer() {

}
