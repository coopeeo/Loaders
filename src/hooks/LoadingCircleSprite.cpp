#include <Geode/Geode.hpp>
#include <Geode/modify/LoadingCircleSprite.hpp>
#include <Geode/binding/LoadingCircleSprite.hpp>
#include "../loader/spinner/Spinner.hpp"
using namespace geode::prelude;


class $modify(LoadingCircleSprite) {
    
    static LoadingCircleSprite* create() {
        //LoadingCircleSprite::create();
        log::info("There was a loading circle sprite created but over written!");
        return typeinfo_cast<LoadingCircleSprite*>(Spinner::create());
    }

};