#ifndef PROCESSOR_HPP_S2ABNETH
#define PROCESSOR_HPP_S2ABNETH

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>

#include "World.hpp"
#include "Screen.hpp"
#include "AssetManager.hpp"
#include "Cheatsheet.hpp"

namespace sfst {

    /**********************************************************************
    *                             Processsor                             *
    **********************************************************************/

    class Processor {
        public:
            virtual void Loop() = 0;

            void    setWorld(World& w);
            World&  getWorld();
            void    addScreen(Screen& s);
            Screen& getScreen(int i);

            virtual ~Processor();
        protected:
            Processor();
            Processor(const Processor& other);

            virtual void Update()      = 0;
            virtual void HandleInput() = 0;
            virtual void Render()      = 0;

            sf::Time getElapsed();
            void     restartClock();

            World _world;
            std::vector<Screen> _screens;
        private:
            sf::Clock     _clock;
            sf::Time      _elapsed;
            AssetManager* _assetManager;
            Cheatsheet*   _cheatsheet;
    };

} /* sfst */ 

#endif /* end of include guard: PROCESSOR_HPP_S2ABNETH */
