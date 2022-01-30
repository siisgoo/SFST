#include <SFST/Screen.hpp>

namespace sfst {

   /**********************************************************************
   *                           Screen members                           *
   **********************************************************************/

   Screen::Screen(const std::string& title, const sf::Vector2u& size) :
      _windowStyle(sf::Style::Default),
      _windowSize(size),
      _windowTitle(title),
      _windowContextSettings(0)
   {
      Create();
   }

   Screen::Screen(const Screen& other) :
      _renderWindow(other._renderWindow),
      _windowSize(other._windowSize),
      _windowStyle(other._windowStyle),
      _windowTitle(other._windowTitle),
      _windowFramerateLimit(other._windowFramerateLimit) { }

   Screen::~Screen()
   {
      Destroy();
   }

   void
   Screen::Create()
   {
      _renderWindow = new (std::nothrow) sf::RenderWindow(sf::VideoMode(_windowSize.x, _windowSize.y),
            _windowTitle, _windowStyle, _windowContextSettings);
      _renderWindow->setFramerateLimit(_windowFramerateLimit);
   }

   void
   Screen::applyStyle()
   {
      updateWindowState();
      Destroy();
      Create();
   }

   void Screen::updateWindowState()
   {
      _windowSize = _renderWindow->getSize();
   }

   bool                Screen::isOpen()                                   { return _renderWindow->isOpen(); }
   void                Screen::Destroy()                                  { Close(); if (_renderWindow) delete _renderWindow; }
   void                Screen::Close()                                    { _renderWindow->close(); }
   bool                Screen::pollEvent(sf::Event& e)                    { return _renderWindow->pollEvent(e); }
   void                Screen::BeginDraw()                                { _renderWindow->clear(sf::Color::Black); }
   void                Screen::EndDraw()                                  { _renderWindow->display(); }
   void                Screen::Draw(sf::Drawable& d)                      { _renderWindow->draw(d); }
   void                Screen::setSize(sf::Vector2u size)                 { _renderWindow->setSize(size); }
   void                Screen::setSize(unsigned int w, unsigned int h)    { _renderWindow->setSize({w, h}); }
   sf::Vector2u        Screen::getSize()                                  { return _renderWindow->getSize(); }
   void                Screen::setStyle(const int s)                      { _windowStyle = s; }
   int                 Screen::getStyle()                                 { return _windowStyle; }
   int                 Screen::getFramerateLimit()                        { return _windowFramerateLimit; }
   void                Screen::setFramerateLimit(int fps)                 { _windowFramerateLimit = fps; _renderWindow->setFramerateLimit(_windowFramerateLimit); }
   void                Screen::setTitle(const std::string& title)         { _windowTitle = title; _renderWindow->setTitle(_windowTitle); }
   std::string         Screen::getTitle()                                 { return _windowTitle; }
   void                Screen::setView(const sf::View& v)                 { _renderWindow->setView(v); }
   sf::View            Screen::getView()                                  { return _renderWindow->getView(); }
   sf::View            Screen::getDefaultView()                           { return _renderWindow->getDefaultView(); }
   void                Screen::setSettings(const sf::ContextSettings& cs) { _windowContextSettings = cs; }
   sf::ContextSettings Screen::getSettings()                              { return _windowContextSettings; }
   sf::RenderWindow*   Screen::getRenderWindow()                          { return _renderWindow; }

}; /* sfst */
