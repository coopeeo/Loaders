#include <Geode/Geode.hpp>
#include <Geode/modify/LoadingCircle.hpp>
#include <Geode/binding/LoadingCircle.hpp>
#include "../loader/spinner/Spinner.hpp"
#include "../loader/spinner/SpinnerContainer.hpp"
using namespace geode::prelude;


class $modify(LoadingCircle) {
    
    static LoadingCircle* create() {
        //LoadingCircle::create();
        log::info("There was a loading circle created but over written!");
        return typeinfo_cast<LoadingCircle*>(SpinnerContainer::create());
        //return SpinnerContainer::create();
    }

};