#ifndef DENSITY_HPP_EK9VPWTB
#define DENSITY_HPP_EK9VPWTB

namespace sfst
{
    typedef float density_t;

    namespace Density
    {
        namespace Atoms
        {
            static const density_t Al = 2643.0f;
            static const density_t Fe = 7870.0f;
            static const density_t O  = 1.429f;
        } /* Atoms */ 

        namespace Gases
        {
            static const density_t Air    = 1.230f;
            static const density_t Oxygen = 1.429f;
        } /* Gas */ 

        namespace Solids
        {
            static const density_t Aluminum2024_T3 = 2770.0f;
            static const density_t Iron            = Atoms::Fe;
        } /* Solid */ 

        namespace Liquids
        {
            static const density_t Water   = 1000.0f;
            static const density_t Acetone = 789.9f;
        } /* Liquids */
    }; /* Dencity */
}; /* sfst */

#endif /* end of include guard: DENSITY_HPP_EK9VPWTB */
