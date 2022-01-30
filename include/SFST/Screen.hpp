#ifndef WINDOW_HPP_EBNCCQUR
#define WINDOW_HPP_EBNCCQUR

#include <SFML/Graphics/RenderWindow.hpp>

namespace sfst {

    class Screen {
        public:
            Screen(const std::string& title, const sf::Vector2u& size); //add other settings
            Screen(const Screen& other);
            ~Screen();

            //wrappers
            bool         isOpen();
            void         Close();
            bool         pollEvent(sf::Event& e);

            void         setView(const sf::View& v);
            sf::View     getView();
            sf::View     getDefaultView();

            void         setTitle(const std::string& title);
            std::string  getTitle();

            void         setStyle(const int style);
            int          getStyle();

            void         BeginDraw();
            void         EndDraw();
            void         Draw(sf::Drawable& drawable);

            int          getFramerateLimit();
            void         setFramerateLimit(int fsp);

            void         setSize(sf::Vector2u size);
            void         setSize(unsigned int w, unsigned int h);
            sf::Vector2u getSize();
            //--//

            void                setSettings(const sf::ContextSettings& cs);
            sf::ContextSettings getSettings();

            void applyStyle();
            void updateWindowState();

            sf::RenderWindow* getRenderWindow();
        private:
            void Create();
            void Destroy();

            sf::RenderWindow*   _renderWindow;
            sf::Vector2u        _windowSize;
            int                 _windowStyle;
            sf::ContextSettings _windowContextSettings;
            std::string         _windowTitle;
            int                 _windowFramerateLimit;
    };

} /* sfst */ 

#endif /* end of include guard: WINDOW_HPP_EBNCCQUR */
