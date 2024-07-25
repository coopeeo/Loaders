#pragma once
#include <Geode/Geode.hpp>
#include <Geode/binding/LoadingCircle.hpp>
#include "./Spinner.hpp"
using namespace geode::prelude;

class SpinnerContainer : public LoadingCircle {
protected:
    Spinner* m_spinner;
public:
    SpinnerContainer(void);
    static SpinnerContainer* create();
    bool init();
    void show();
};