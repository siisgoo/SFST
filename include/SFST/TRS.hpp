#ifndef TRS_HPP_9XHVS2HO
#define TRS_HPP_9XHVS2HO

#include "Vectors.hpp"
#include "Matrix.hpp"

#define Homog2DSize 3
#define Homog3DSize 4

namespace sfst {
    class Trs : public Matrix<float> { //interface
        protected:
            Trs(int mtx_r, int mtx_c);
        public:
            virtual ~Trs();

            /* add HouseholderReflection:  <10-01-22 siisgoo> */

            virtual void reset();

            virtual Vectorf extractScale() const     = 0;
            virtual Vectorf extractTranslate() const = 0;
            virtual Vectorf extractRotation() const  = 0;

            virtual void applyScale(const Vectorf& v)     = 0;
            virtual void applyTranslate(const Vectorf& v) = 0;
            virtual void applyRotation(const float rad)  = 0;

            virtual void applyToVector(Vectorf& v) const = 0;

            virtual float& operator()(int row, int col) = 0;
            virtual float& operator()(int row, int col) const = 0;
        protected:
            /* remove some uneed matrix operations to private members:  <10-01-22 siisgoo> */
    }; /* end class Trs */

    class Trs2D : public Trs {
        public:
            Trs2D();
            virtual ~Trs2D();

            virtual Vectorf extractScale() const;
            virtual Vectorf extractTranslate() const;
            virtual Vectorf extractRotation() const;

            virtual void applyScale(const Vectorf& v);
            virtual void applyTranslate(const Vectorf& v);
            virtual void applyRotation(const float rad);

            virtual void applyToVector(Vectorf& v) const;

            virtual float& operator()(int row, int col);
            virtual float& operator()(int row, int col) const;
        private:
    }; /* end class Trs2D */

    class Trs3D :public Trs {
        public:
            Trs3D();
            virtual ~Trs3D();

            virtual Vectorf extractScale() const;
            virtual Vectorf extractTranslate() const;
            virtual Vectorf extractRotation() const;

            virtual void applyScale(const Vectorf& v);
            virtual void applyTranslate(const Vectorf& v);
            virtual void applyRotation(const float rad);

            virtual void applyToVector(Vectorf& v) const;

            virtual float& operator()(int row, int col);
            virtual float& operator()(int row, int col) const;
        private:
    }; /* end class Trs3D */
} /* sfst */ 

#endif /* end of include guard: TRS_HPP_9XHVS2HO */
