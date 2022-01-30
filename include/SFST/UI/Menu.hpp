/* using https://github.com/brookskindle/SFML-Menu */
#ifndef _MENU_H_
#define _MENU_H_ value

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderScreen.hpp>

#include <Screen.hpp>

#include <vector>
#include <string>
#include <algorithm>
#include <functional>

class MenuOption {
    public:
        MenuOption(std::string text = "", bool finishOnSelect = false,
                std::function<void(void)> callback = nullptr) :
            _text(text), _finishOnSelect(finishOnSelect), _callback(callback) {  }
        ~MenuOption() {  }

        void select() { if (_callback) { _callback(); } }
        bool finishOnSelect() { return _finishOnSelect; }
        void setText(std::string text) { _text = text; }
        const std::string& getText() const { return _text; }
        void setCallback(std::function<void(void)> callback) { _callback = callback; }
    private:
        std::function<void(void)> _callback;
        std::string _text;
        bool        _finishOnSelect;
};

class MenuLayout {
    friend class Menu;
    public:
        MenuLayout(unsigned int spacing = 50,
                const sf::Vector2f &origin = sf::Vector2f(0.5, 0.5));
        MenuLayout(const MenuLayout &copy);
        void setSpacing(unsigned int spacing);
        void setOrigin(const sf::Vector2f &origin);
        static const MenuLayout VerticleCentered;
        static const MenuLayout VerticleLeft;
        static const MenuLayout VerticleRight;
    private:
        void apply(std::vector<sf::Text*>* options,
                sf::Vector2u windowSize);
        unsigned int _spacing;
        sf::Vector2f _origin;
};

class Menu : public Window {
    public:
        Menu();
        Menu(Window* parent = nullptr);
        ~Menu() {}

        void display();
        void update();
        Menu& addOption(MenuOption* newOpt);
        void clearOptions();

        void setBackground(const sf::Texture& bg);
        void setTimeout(sf::Time time,
                std::function<void(void)> callback);
        void setExitCallback(std::function<void(void)> callback);
        void setLayout(MenuLayout style);
        void setTemplateText(const sf::Text &t);
        void setTemplateTextHovered(const sf::Text &t);
    private:
        void setupTexts();
        void setupBackground();
        void drawOptions();
        void drawBackground();

        void MouseClick(sf::Event& e);

        sf::Texture               _background;
        sf::Sprite                _backgroundSprite;

        sf::Time                  _timeout;
        std::function<void(void)> _timeoutCallback;
        std::function<void(void)> _exitCallback;

        sf::Text                  _title;
        int                       _currentEntry;
        std::vector<MenuOption*>  _options;

        MenuLayout                _layout;
        std::vector<sf::Text*>*   _texts;
        sf::Text                  _templateText;
        sf::Text                  _templateTextHovered;
};

#endif /* ifndef _MENU_H_ */
