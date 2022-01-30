#include <Item.hpp>

namespace sfst {

   /**********************************************************************
   *                       WorldItem Constructors                       *
   **********************************************************************/

   /*! \brief Class constructor
    *  WorldItem class constructor */
   WorldItem::WorldItem(const sf::Vector2f size, const Vectorf pos) :
      _size(size),
      _pos(pos) { }

   /*! \brief Class constructor
    *  WorldItem class constructor */
   WorldItem::WorldItem(const sf::Vector2f size, const Vectorf pos, const sf::Sprite sprite) :
      /* WorldItem(size, pos), */
         _size(size),
         _pos(pos),
         _Sprite(sprite) { }

   /*! \brief Class constructor
    *  WorldItem class constructor */
   WorldItem::WorldItem(const sf::Vector2f size, const Vectorf pos, const sf::Sprite sprite, const sf::Texture texture) :
      /* WorldItem(size, pos, sprite), */
         _size(size),
         _pos(pos),
         _Sprite(sprite),
         _Texture(texture) { }

   /*! \brief Class deconstructor
    *  WorldItem class deconstructor */
   WorldItem::~WorldItem() { }

   /*! \brief Copy constructor
    *  Copy constructor
    * \param other Copy target */
   WorldItem::WorldItem(const WorldItem& other) :
      _pos(other._pos),
      _size(other._size),
      _Sprite(other._Sprite),
      _Texture(other._Texture) { }

   /**********************************************************************
   *                         WorldItem members                          *
   **********************************************************************/

   /*! \brief Texture setter
    *  Texture setter
    * \param New texture */
   void WorldItem::setTexture(const sf::Texture& t) { _Texture = t; }

   /*! \brief Texture getter
    *  Texture getter
    * \param New texture */
   sf::Texture WorldItem::getTexture() { return _Texture; }

   /*! \brief Position setter
    *  Position setter
    * \param New texture */
   void WorldItem::setPosition(const Vectorf& p) { _pos = p; }

   /*! \brief Position getter
    *  Position getter
    * \param New texture */
   Vectorf WorldItem::getPosition() const { return _pos; }

   /*! \brief Size setter
    *  Size setter
    * \param New texture */
   void WorldItem::setSize(const sf::Vector2f& p) { _size = p; }

   /*! \brief Size getter
    *  Size getter */
   sf::Vector2f WorldItem::getSize() const { return _size; }

   /**********************************************************************
   *                      StaticWorldItem members                       *
   **********************************************************************/

   /*! \brief Class constructor
    *  StaticWorldItem class constructor */
   StaticWorldItem::StaticWorldItem(sf::Vector2f size, Vectorf pos) :
      WorldItem(size, pos) {  }

   /*! \brief Class constructor
    *  StaticWorldItem class constructor */
   StaticWorldItem::StaticWorldItem(sf::Vector2f size, Vectorf pos, sf::Sprite sprite) :
      WorldItem(size, pos, sprite) {  }

   /*! \brief Class constructor
    *  StaticWorldItem class constructor */
   StaticWorldItem::StaticWorldItem(sf::Vector2f size, Vectorf pos, sf::Sprite sprite, sf::Texture texture) :
      WorldItem(size, pos, sprite, texture) { }

   /*! \brief Class constructor
    *  Class constructor */
   StaticWorldItem::~StaticWorldItem() {  }

   /*! \brief Copy constructor
    *  Copy constructor
    * \param other Copy target */
   StaticWorldItem::StaticWorldItem(const StaticWorldItem& other) :
      WorldItem(other) { }

   /**********************************************************************
   *                      DynamicWorldItem members                      *
   **********************************************************************/

   /*! \brief Class constructor
    *  DynamicWorldItem class constructor */
   DynamicWorldItem::DynamicWorldItem(sf::Vector2f size, Vectorf pos, const float maxV) :
      WorldItem(size, pos),
         _maxVelocity(maxV) { }

   /*! \brief Class constructor
    *  DynamicWorldItem class constructor */
   DynamicWorldItem::DynamicWorldItem(sf::Vector2f size, Vectorf pos, sf::Sprite sprite, const float maxV) :
      WorldItem(size, pos, sprite),
         _maxVelocity(maxV) { }

   /*! \brief Class constructor
    *  DynamicWorldItem class constructor */
   DynamicWorldItem::DynamicWorldItem(sf::Vector2f size, Vectorf pos, sf::Sprite sprite, sf::Texture texture, const float maxV) :
      WorldItem(size, pos, sprite, texture),
         _maxVelocity(maxV) { }

   /*! \brief Class constructor
    *  Class constructor */
   DynamicWorldItem::~DynamicWorldItem() {  }

   /*! \brief Copy constructor
    *  Copy constructor
    * \param other Copy target */
   DynamicWorldItem::DynamicWorldItem(const DynamicWorldItem& other) :
      WorldItem(other),
         _velocity(other._velocity),
         _maxVelocity(other._maxVelocity),
         _direction(other._direction) { }

   void  DynamicWorldItem::setMaxVelocity(float mV) { _maxVelocity = mV; }
   float DynamicWorldItem::getMaxVelocity() const   { return _maxVelocity; }

   Vectorf DynamicWorldItem::calcPosByMotion()
   {
      _velocity = (_direction - _pos).getNormalized() * _maxVelocity;
      return _pos + _velocity;
   }

   /**********************************************************************
   *                     RealisticWorldItem members                      *
   **********************************************************************/

   /*! \brief Class constructor
    *  RealisticWorldItem class constructor */
   RealisticWorldItem::RealisticWorldItem(sf::Vector2f size, Vectorf pos, const unsigned int mass) :
      DynamicWorldItem(size, pos),
         _mass(mass) { }

   /*! \brief Class constructor
    *  RealisticWorldItem class constructor */
   RealisticWorldItem::RealisticWorldItem(sf::Vector2f size, Vectorf pos, sf::Sprite sprite, const unsigned int mass) :
      DynamicWorldItem(size, pos, sprite),
         _mass(mass) { }

   /*! \brief Class constructor
    *  RealisticWorldItem class constructor */
   RealisticWorldItem::RealisticWorldItem(sf::Vector2f size, Vectorf pos, sf::Sprite sprite, sf::Texture texture, const unsigned int mass) :
      DynamicWorldItem(size, pos, sprite, texture),
         _mass(mass) { }

   /*! \brief Class deconstructor
    *  Class deconstructor */
   RealisticWorldItem::~RealisticWorldItem() {  }

   /*! \brief Copy constructor
    *  Copy constructor
    * \param other Copy target */
   RealisticWorldItem::RealisticWorldItem(const RealisticWorldItem& other) :
      DynamicWorldItem(other),
         _mass(other._mass) { }

   /*! \brief Calculating object max velosity
    *  Calculating max velosity depend on world setting
    * \param w World object
    * \return Max velosity */
   float RealisticWorldItem::calcMaxVelocity(const RealisticWorld& w)
   {
      /* Add calc drag coefficient for rectangles:  <01-01-22, siisgoo> */
      return sqrt((2 * _mass * w.getGravity()) /
                  (_size.x * _size.y * w.getAirDensity() * 1.05) );
   }

   Vectorf RealisticWorldItem::calcPosByMotion()
   {
      //TODO
      /* _velocity = Vectorf(_direction - _pos).Normalize() * _maxVelocity; */
      Vectorf nv(2);
      return nv;
   }

} /* sfst  */ 
