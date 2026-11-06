#include <Geode/Geode.hpp>
#include <Geode/modify/EditorUI.hpp>

using namespace geode::prelude;

class $modify(AutoDecoEditor, EditorUI) {
    bool init(LevelEditorLayer* layer) {
        if (!EditorUI::init(layer))
            return false;

        auto sprite = ButtonSprite::create(
            "CHANGE STYLE",
            "goldFont.fnt",
            "GJ_button_01.png",
            0.7f
        );

        auto button = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            menu_selector(AutoDecoEditor::changeStyle)
        );

        auto menu = CCMenu::create();
        menu->addChild(button);

        auto size = CCDirector::sharedDirector()->getWinSize();

        menu->setPosition(
            size.width / 2,
            70
        );

        this->addChild(menu, 100);

        return true;
    }

    void changeStyle(CCObject*) {
        static int currentStyle = 0;

        const char* styles[] = {
            "Glow",
            "Fire",
            "Neon",
            "Nature",
            "Tech",
            "Dark",
            "Modern"
        };

        currentStyle = (currentStyle + 1) % 7;

        FLAlertLayer::create(
            "Auto Deco",
            fmt::format(
                "Selected style: {}",
                styles[currentStyle]
            ),
            "OK"
        )->show();
    }
};
