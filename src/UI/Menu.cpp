#include <Menu.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

//debug
#include <iostream>

const MenuLayout MenuLayout::VerticleCentered = MenuLayout(50, sf::Vector2f(0.50, 0.5));
const MenuLayout MenuLayout::VerticleLeft     = MenuLayout(50, sf::Vector2f(0.25, 0.5));
const MenuLayout MenuLayout::VerticleRight    = MenuLayout(50, sf::Vector2f(0.75, 0.5));

MenuLayout::MenuLayout(unsigned int spacing,
      const sf::Vector2f &origin)
{
      setSpacing(spacing);
      setOrigin(origin);
}

MenuLayout::MenuLayout(const MenuLayout &other)
{
      _spacing = other._spacing;
      _origin = other._origin;
}

void
MenuLayout::setSpacing(unsigned int spacing)
{
   _spacing = spacing;
}

void MenuLayout::setOrigin(const sf::Vector2f &origin) {
   _origin = origin;
   if(_origin.x > 1.0) {
      _origin.x = 1.0;
   }
   if(_origin.y > 1.0) {
      _origin.y = 1.0;
   }
}

void
MenuLayout::apply(std::vector<sf::Text*>* options,
        sf::Vector2u windowSize) {
    if (options->size() == 0) { //no options, do nothing
        return;
    }

    sf::Vector2f orig; //origin position in pixels, instead of percentages
    orig.x = windowSize.x * _origin.x;
    orig.y = windowSize.y * _origin.y;
    //since we have n number of options, calculate where the first one will go
    int n = options->size();
    sf::FloatRect osize = options->at(0)->getGlobalBounds(); //assume all options are the same height
    if (n % 2) { //odd number of options
        orig.y = orig.y - (int)(n / 2) * (osize.height + _spacing);
    }
    else { //even number of options
        orig.y = orig.y - (_spacing/2.0f) - (osize.height/2.0f) - (n/2.0 - 1)*(_spacing+osize.height);
    }

    for (sf::Text *text : *options) { //use reference to update the position
        sf::FloatRect rect = text->getLocalBounds();
        //center text origin on the middle of the text
        text->setOrigin(rect.left + rect.width/2.0f,
                rect.top + rect.height/2.0f);
        text->setPosition(orig); //set option position on the screen
        orig.y += osize.height + _spacing; //calculate next position
    }
}//end apply

Menu::Menu()
{
}

Menu::Menu(Window* parent) :
    Window(parent)
{
}

void
Menu::display() {
    setupBackground();
    setupTexts();

    update();

    //sleep time
    int interval = (1.0 / getFPS()) * 1000.0;

    bool finished = false;
    int i = 0;
    sf::Vector2i mousePos;
    sf::Clock clock;
    while (!finished) {
        update();

        sf::Event e;
        while (pollEvent(e)) {
            Window::HandleEvents(e);

            switch (e.type) {
                case sf::Event::Closed:
                    finished = true;
                    if (_exitCallback) {
                        _exitCallback();
                    }
                    break;

                case sf::Event::Resized:
                case sf::Event::GainedFocus:
                    _layout.apply(_texts, getSize()); //apply the layout on the options
                    update();
                    break;

                case sf::Event::MouseMoved:
                    for (i = 0; i < _texts->size(); i++) {
                        if (_texts->at(i)->getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y)) {
                            std::cout << "Hovered " << _options[i]->getText() << std::endl;
                            break;
                        }
                    }
                    break;

                case sf::Event::MouseButtonReleased:
                    if (e.mouseButton.button == sf::Mouse::Left) {
                        for (i = 0; i < _texts->size(); i++) {
                            if (_texts->at(i)->getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y)) {
                                _options[i]->select();
                                finished = _options[i]->finishOnSelect();
                                break;
                            }
                        }
                    }
                    break;

                default:
                    break;
            }
        }//end while(window.pollEvent(e))

        sf::sleep(sf::milliseconds(interval));
        if (_timeout > sf::seconds(0.0) && clock.getElapsedTime() >= _timeout) {
            //this menu has a timeout and we have reached it
            finished = true;
            if (_timeoutCallback) {
               _timeoutCallback();
            }
        }
    }//end while(!finished)
}//end display

void
Menu::MouseClick(sf::Event& e)
{
    if (e.mouseButton.button == sf::Mouse::Left
            && e.type == sf::Event::MouseButtonReleased) {

    }
}

void
Menu::update()
{
    BeginDraw();
    drawBackground();
    drawOptions();
    EndDraw();
}

void
Menu::drawBackground()
{
    Draw(_backgroundSprite);
}

void
Menu::setupBackground()
{
    _backgroundSprite.setTexture(_background);
    _backgroundSprite.setScale(getSize().x / (float)_background.getSize().x,
            getSize().y / (float)_background.getSize().y);
}

#include <iostream>

void
Menu::setupTexts()
{
    _texts = new std::vector<sf::Text*>;
    for (const auto &o : _options) {
        sf::Text *t = new sf::Text(_templateText);
        t->setString(o->getText());
        _texts->push_back(t);
    }
    _layout.apply(_texts, getSize()); //apply the layout on the options
}

void
Menu::drawOptions()
{
    for(auto *t : *_texts) { //draw the options
        Draw(*t);
    }
}

Menu&
Menu::addOption(MenuOption *option) {
    _options.push_back(option);
    return *this;
}//end addOption

void
Menu::clearOptions() {
    _options.clear();
}//end clearOptions


void
Menu::setBackground(const sf::Texture& bg) {
   _background = bg;
}//end setBackground


void
Menu::setTimeout(sf::Time timeout, std::function<void(void)> callback) {
    _timeout = timeout;
    _timeoutCallback = callback;
}//end setTimeout


void
Menu::setExitCallback(std::function<void(void)> callback) {
    _exitCallback = callback;
}//end setExitCallback


void
Menu::setLayout(MenuLayout layout) {
    _layout = layout;
}//end setLayout


void
Menu::setTemplateText(const sf::Text &t) {
    _templateText = t;
}//end setTemplateText

void
Menu::setTemplateTextHovered(const sf::Text &t) {
    _templateTextHovered = t;
}//end setTemplateText
