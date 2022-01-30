/* #include <TRS.hpp> */
#include "../../include/SFST/TRS.hpp"

namespace sfst
{
   /**********************************************************************
   *                                Trs                                 *
   **********************************************************************/

   Trs::Trs(int r, int c) :
      Matrix<float>::Matrix(r, c)
   { }

   Trs::~Trs()
   {  }

   void
   Trs::reset()
   {
      this->apply([](int r, int c, float val) -> float {
               if (r - c == 0) {
                  return 1.0f;
               } else {
                  return 0.0f;
               }
      });
   }

/**********************************************************************
*                              END Trs                               *
**********************************************************************/

   /**********************************************************************
   *                               Trs2D                                *
   **********************************************************************/

   Trs2D::Trs2D() :
      Trs(Homog2DSize, Homog2DSize) // homogeneous two-dimensional
   { }

   Trs2D::~Trs2D()
   {  }

   float& Trs2D::operator()(int row, int col)
   {
      assert(row <= rows && col <= cols);
      return this->m_matrix[row * this->cols + col];
   }

   float& Trs2D::operator()(int row, int col) const
   {
      assert(row <= rows && col <= cols);
      return this->m_matrix[row * this->cols + col];
   }

   Vectorf
   Trs2D::extractScale() const
   {
      Vectorf ret(2);
      ret(0) = (*this)(0, 0); // x
      ret(1) = (*this)(1, 1); // y
      return ret;
   }

   Vectorf
   Trs2D::extractTranslate() const
   {
      Vectorf ret(2);
      ret(0) = (*this)(0, 0); // x
      ret(1) = (*this)(1, 1); // y
      return ret;
   }

   Vectorf
   Trs2D::extractRotation() const
   {
      Vectorf ret(2);
      ret(0) = (*this)(0, 0); // x
      ret(1) = (*this)(1, 1); // y
      return ret;
   }

   void
   Trs2D::applyScale(const Vectorf& v)
   {
      (*this)(0, 0) = v(0);
      (*this)(1, 1) = v(1);
   }

   void
   Trs2D::applyTranslate(const Vectorf& v)
   {
      (*this)(0, 2) = v(0);
      (*this)(1, 2) = v(0);
   }

   void
   Trs2D::applyRotation(const float rad)
   {
      float cosa = std::cos(rad);
      float sina = std::sin(rad);
      (*this)(0, 0) = cosa;
      (*this)(0, 1) = sina;
      (*this)(1, 0) = -sina;
      (*this)(1, 1) = cosa;
   }

   void
   Trs2D::applyToVector(Vector<float>& v) const
   {
      v = (*this) * v;
   }

/**********************************************************************
*                             Trs2D END                              *
**********************************************************************/

   /**********************************************************************
   *                               Trs3D                                *
   **********************************************************************/

   Trs3D::Trs3D() :
      Trs(Homog3DSize, Homog3DSize) // homogeneous two-dimensional
   { }

   Trs3D::~Trs3D()
   {  }

   float& Trs3D::operator()(int row, int col)
   {
      assert(row <= rows && col <= cols);
      return this->m_matrix[row * this->cols + col];
   }

   float& Trs3D::operator()(int row, int col) const
   {
      assert(row <= rows && col <= cols);
      return this->m_matrix[row * this->cols + col];
   }

   Vectorf
   Trs3D::extractScale() const
   {
      Vectorf ret(2);
      ret(0) = (*this)(0, 0); // x
      ret(1) = (*this)(1, 1); // y
      return ret;
   }

   Vectorf
   Trs3D::extractTranslate() const
   {
      Vectorf ret(2);
      ret(0) = (*this)(0, 0); // x
      ret(1) = (*this)(1, 1); // y
      return ret;
   }

   Vectorf
   Trs3D::extractRotation() const
   {
      Vectorf ret(2);
      ret(0) = (*this)(0, 0); // x
      ret(1) = (*this)(1, 1); // y
      return ret;
   }

   void
   Trs3D::applyScale(const Vectorf& v)
   {

   }

   void
   Trs3D::applyTranslate(const Vectorf& v)
   {

   }

   void
   Trs3D::applyRotation(const float rad)
   {

   }

   void          Trs3D::applyToVector(Vector<float>& v) const
   {

   }

/**********************************************************************
*                             Trs3D END                              *
**********************************************************************/

} /* END sfst */ 
