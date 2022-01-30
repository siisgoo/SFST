#include <SFST/Processor.hpp>

namespace sfst {

   /**********************************************************************
   *                       Processor Costructors                        *
   **********************************************************************/

   /*! \brief Class constructor
    *  The base Class for Hanle program do sequinces
    * \param wrld Optional World object
    * \param scree Optional Screen object */
   Processor::Processor() :
      _assetManager(new AssetManager()),
      _cheatsheet(new Cheatsheet()) { }

   /*! \brief Processor decostructor
    *  Class deconstructor */
   Processor::~Processor()
   {
      delete _assetManager;
      delete _cheatsheet;
   }

   /*! \brief Copy constructor
    *  Copy constructor
    * \param other Copy target */
   Processor::Processor(const Processor& other) :
      /* _assetManager(other._assetManager), */
      _world(other._world),
      _screens(other._screens),
      _clock(other._clock),
      _elapsed(other._elapsed) { }

   /**********************************************************************
   *                         Processor Memebers                         *
   **********************************************************************/

   /*! \brief Screen getter
    *  Get scree object
    * \return sf::Time */
   Screen& Processor::getScreen(int i) { return _screens[i]; }

   /*! \brief Screen var setter
    *  \param Screen var setter */
   void Processor::addScreen(Screen& s) { _screens.push_back(s); }

   /*! \brief World getter
    * World getter
    * \return Member World object */
   World& Processor::getWorld() { return _world; }

   /*! \brief World setter
    *  \param new World object */
   void Processor::setWorld(World& w) { _world = w; }

   /*! \brief Get elapsed time
    *  Get elapsed time
    * \return sf::Time */
   sf::Time Processor::getElapsed() { return _elapsed; }

   /*! \brief Restart clock
    *  Restart clock */
   void Processor::restartClock() { _elapsed = _clock.restart(); }

}; /* sfst */ 
