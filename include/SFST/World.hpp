#ifndef WORLD_HPP_RDPKFPG5
#define WORLD_HPP_RDPKFPG5

#include "Gravity.hpp"
#include "Density.hpp"

#include <SFML/System/Vector2.hpp>

namespace sfst {

    /**********************************************************************
    *                               World                                *
    **********************************************************************/

    class World {
      protected:
          sf::Vector2u _size;
      public:
          World(sf::Vector2u windowSize = { 100, 100 });
          World(const World& other);

          void          setSize(const sf::Vector2u& size);
          sf::Vector2u  getSize();

          virtual ~World();
      private:
    };

    /**********************************************************************
    *                           RealisticWorld                           *
    **********************************************************************/

    class RealisticWorld : public World {
      protected:
          using World::_size;
      public:
          RealisticWorld(sf::Vector2u windowSize = {100, 100},
                  gravity_t gravity     = Gravity::ByPanet::Earth,
                  density_t air_density = Density::Gases::Air);
          RealisticWorld(const RealisticWorld& other);

          float getGravity() const;
          void  setGravity(float g);
          float getAirDensity() const;
          void  setAirDensity(density_t ad);

          bool  haveAtm() const;

          virtual ~RealisticWorld();
      private:
          float     _gravity;
          density_t _air_density;
    };

}

#endif /* end of include guard: WORLD_HPP_RDPKFPG5 */
