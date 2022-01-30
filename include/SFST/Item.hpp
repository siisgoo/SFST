#ifndef ITEM_HPP_RZIWBY4V
#define ITEM_HPP_RZIWBY4V

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Math.hpp"
#include "World.hpp"

namespace sfst {

    /**********************************************************************
    *                             WroldItem                              *
    **********************************************************************/

    class WorldItem {
        protected:
            sf::Sprite  _Sprite;
            sf::Texture _Texture;

            Vectorf     _pos;
            sf::Vector2f _size;
        public:
            WorldItem(const sf::Vector2f size, const Vectorf pos);
            WorldItem(const sf::Vector2f size, const Vectorf pos, const sf::Sprite);
            WorldItem(const sf::Vector2f size, const Vectorf pos, const sf::Sprite, const sf::Texture);
            WorldItem(const WorldItem& other);

            /* its needed?:  <30-12-21 siisgoo> */
            virtual void Update() = 0;
            /* virtual void Reset()  = 0; */
            /* --- */

            void        setTexture(const sf::Texture& t);
            sf::Texture getTexture();

            void         setPosition(const Vectorf&);
            Vectorf    getPosition() const;
            void         setSize(const sf::Vector2f&);
            sf::Vector2f getSize() const;

            virtual void Draw(sf::RenderWindow& w) = 0;

            virtual ~WorldItem();
    };

    /**********************************************************************
    *                          StaticWorldItem                           *
    **********************************************************************/

    class StaticWorldItem : public WorldItem {
        protected:
            using WorldItem::_Sprite;
            using WorldItem::_Texture;
            using WorldItem::_pos;
            using WorldItem::_size;
        public:
            StaticWorldItem(sf::Vector2f size, Vectorf pos);
            StaticWorldItem(sf::Vector2f size, Vectorf pos, sf::Sprite);
            StaticWorldItem(sf::Vector2f size, Vectorf pos, sf::Sprite, sf::Texture);

            StaticWorldItem(const StaticWorldItem& other);
            StaticWorldItem(const StaticWorldItem* other);

            virtual ~StaticWorldItem();
        private:
    };

    /**********************************************************************
    *                          DynamicWorldItem                          *
    **********************************************************************/

    class DynamicWorldItem : public WorldItem {
        protected:
            virtual Vectorf calcPosByMotion(); //pos = pos + velosity ;)

            Vectorf _velocity;
            Vectorf _direction;
            float     _maxVelocity;

            using WorldItem::_Sprite;
            using WorldItem::_Texture;
            using WorldItem::_pos;
            using WorldItem::_size;
        public:
            DynamicWorldItem(sf::Vector2f size, Vectorf pos, const float maxVelocity = 1);
            DynamicWorldItem(sf::Vector2f size, Vectorf pos, sf::Sprite, const float maxVelocity = 1);
            DynamicWorldItem(sf::Vector2f size, Vectorf pos, sf::Sprite, sf::Texture, const float maxVelocity = 1);

            DynamicWorldItem(const DynamicWorldItem& other);
            DynamicWorldItem(const DynamicWorldItem* other);

            void  setMaxVelocity(float mV);
            float getMaxVelocity() const;

            virtual ~DynamicWorldItem();
        private:
    };

    /**********************************************************************
    *                         RealisticWorldItem                         *
    **********************************************************************/

    class RealisticWorldItem : public DynamicWorldItem {
        protected:
            virtual Vectorf calcPosByMotion(); //pos = pos + velosity ;)
            virtual float calcMaxVelocity(const RealisticWorld& w);

            /* redo with volume and density:  <01-01-22 siisgoo> */
            unsigned int _mass;

            using WorldItem::_Sprite;
            using WorldItem::_Texture;

            using DynamicWorldItem::_velocity;
            using DynamicWorldItem::_direction;
            using DynamicWorldItem::_maxVelocity;
        public:
            RealisticWorldItem(sf::Vector2f size, Vectorf pos, const unsigned int mass = 1);
            RealisticWorldItem(sf::Vector2f size, Vectorf pos, sf::Sprite, const unsigned int mass = 1);
            RealisticWorldItem(sf::Vector2f size, Vectorf pos, sf::Sprite, sf::Texture, const unsigned int mass = 1);

            RealisticWorldItem(const RealisticWorldItem& other);

            virtual ~RealisticWorldItem();
        private:
    };

} /* sfst */ 

#endif /* end of include guard: ITEM_HPP_RZIWBY4V */
