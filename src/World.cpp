#include <SFST/World.hpp>

namespace sfst {
   /**********************************************************************
   *                           World Members                            *
   **********************************************************************/

   /*! \brief World constructor
    *  Class constructor */
   World::World(sf::Vector2u size) :
      _size(size) { }

   /*! \brief Class copy constructor
    *  Class copy constructor
    * \param other Passed world object to copy */
   World::World(const World& other) :
      _size(other._size) { }

   /*! \brief World deconstructor
    *  Class deconstructor */
   World::~World() {  }

   /*! \brief World size Getter
    *  World size Getter
    * \return vector specifying World size */
   sf::Vector2u World::getSize() { return _size; }

   /*! \brief World size Setter
    *  World size Setter
    * \param  size New size vector
    * \return None */
   void World::setSize(const sf::Vector2u& size) { _size = size; }

   /**********************************************************************
   *                       RealisticWorld members                       *
   **********************************************************************/

   /*! \brief Class constructor
    *  Class constructor
    * \param parent Parent */
   RealisticWorld::RealisticWorld(sf::Vector2u windowSize, gravity_t g, density_t air_d) :
      World(windowSize),
         _gravity(g),
         _air_density(air_d) { }

   /*! \brief Class deconstructor
    *  Class deconstructor */
   RealisticWorld::~RealisticWorld() { }

   /*! \brief Copy constructor
    *  Copy constructor
    * \param other Copy target */
   RealisticWorld::RealisticWorld(const RealisticWorld& other) :
      World(other),
         _gravity(other._gravity),
         _air_density(other._air_density) { }

   /*! \brief Gravity value getter
    *  Gravity value getter
    * \return float gravity value */
   float RealisticWorld::getGravity() const { return _gravity; }

   /*! \brief Gravity value setter
    *  Gravity value setter
    * \param g new gravity value */
   void RealisticWorld::setGravity(gravity_t g) { _gravity = g; }

   /*! \brief AirDensity value getter
    *  AirDensity value getter
    * \return float gravity value */
   float RealisticWorld::getAirDensity() const { return _air_density; }

   /*! \brief AirDensity value setter
    *  AirDensity value setter
    * \param g new gravity value */
   void RealisticWorld::setAirDensity(density_t d) { _air_density = d; }

   /*! \brief Check for atmosphere
    *  Check for atmosphere
    * \return Bool have - true, no - false :> */
   bool RealisticWorld::haveAtm() const { return _air_density > 0; }

}
