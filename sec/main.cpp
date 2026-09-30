#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

// Stage 1 skeleton: adds an "FB Frame Counter" button to the pause menu.
// Later stages hang recording, macro import, analysis and playback off this.
class $modify(FrameLabPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        auto spr = ButtonSprite::create("Frames", "goldFont.fnt", "GJ_button_01.png", 0.7f);
        auto btn = CCMenuItemSpriteExtra::create(
            spr, this, menu_selector(FrameLabPauseLayer::onFrameLab)
        );
        btn->setID("frame-lab-button"_spr);

        auto menu = this->getChildByID("right-button-menu");
        if (menu) {
            menu->addChild(btn);
            menu->updateLayout();
        } else {
            auto fallback = CCMenu::create();
            fallback->addChild(btn);
            auto win = CCDirector::get()->getWinSize();
            fallback->setPosition({win.width - 50.f, win.height / 2});
            this->addChild(fallback);
        }
    }

    void onFrameLab(CCObject*) {
        FLAlertLayer::create(
            "FB Frame Counter",
            "Skeleton build. Recording, macro import and frame analysis are coming in the next stages.",
            "OK"
        )->show();
    }
};
