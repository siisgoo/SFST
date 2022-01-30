#include <gtest/gtest.h>
#include <system_error>

/* #include <SFST/Matrix.hpp> */
/* #include <SFST/Vectors.hpp> */
#include "../include/SFST/Math.hpp"

/**********************************************************************
*                               Matrix                               *
**********************************************************************/

    /**********************************************************************
    *                           Initialization                           *
    **********************************************************************/

    TEST(Matrix, Initialization) {
        sfst::Matrix<float> mtx(3, 5);
        sfst::Matrix<float> mtxQ(4, 4);
        sfst::Matrix<int> mtxI{ { 1, 2, 3 }, { 8, 3, 0 }, { 7, 0, 6 } };

        EXPECT_EQ(mtxI(0, 0), 1);
        EXPECT_EQ(mtxI(1, 1), 3);
        EXPECT_EQ(mtxI(2, 0), 7);

        EXPECT_EQ(mtx.rows, 3);
        EXPECT_EQ(mtx.cols, 5);
        EXPECT_EQ(mtx.isQuad(), false);
        EXPECT_EQ(mtxQ.isQuad(), true);

        for (int l_r = 0; l_r < mtx.rows; ++l_r) {
            for (int l_c = 0; l_c < mtx.cols; ++l_c) {
                if (l_r - l_c == 0) {
                    EXPECT_EQ(mtx(l_r, l_c), 1);
                } else {
                    EXPECT_EQ(mtx(l_r, l_c), 0);
                }
            }
        }
    }

    /**********************************************************************
    *                               Assign                               *
    **********************************************************************/

    TEST(Matrix, Assign) {
        sfst::Matrix<float> mtx(3, 3);
        mtx(2, 1) = 8; //{2, 1}
        mtx[3] = 4;    //{0, 2}
        mtx[5] = 4;    //{1, 1}

        EXPECT_EQ(mtx(2, 1), 8);
        EXPECT_EQ(mtx[2 * mtx.cols + 1], mtx(2, 1));
        EXPECT_EQ(mtx[3], 4);

        mtx[5] = 8;

        EXPECT_EQ(mtx(2, 1), mtx[5]);
    }

    /**********************************************************************
    *                               Logic                                *
    **********************************************************************/

    TEST(Matrix, Logic) {
        const sfst::Matrix<float> mtx1{
            { 1.33f, 2,         3.3f, },
            { 3,     2.000002f, 1,    },
            { 1.33f, 2,         3.3f, },
        };

        const sfst::Matrix<float> mtx2{
            { 1.33f, 2,        3.3f, },
            { 3,     2.000002, 1,    },
            { 1.33f, 2,        3.3f, },
        };

        EXPECT_TRUE(mtx1  == mtx2);
        EXPECT_FALSE(mtx1 != mtx2);

        //apply test
        sfst::Matrix<float> mtx3(4, 4);
        std::cout << mtx3 << std::endl;

        const float apply_value = -28.8f;
        mtx3.apply([apply_value](int r, int c, float val) -> float {
            if (r % 2 == 0) {
                return apply_value;
            } else {
                return val;
            }
        });
        std::cout << mtx3 << std::endl;

        for (int i = 0; i < mtx3.rows; ++i) {
            for (int j = 0; j < mtx3.cols; ++j) {
                if (i % 2 == 0) { //applied value
                    EXPECT_FLOAT_EQ(mtx3(i, j), apply_value);
                } else if (i - j == 0) { //diagonal
                    EXPECT_FLOAT_EQ(mtx3(i, j), 1);
                } else { //other
                    EXPECT_FLOAT_EQ(mtx3(i, j), 0);
                }
            }
        }
    }

    /**********************************************************************
    *                                Math                                 *
    **********************************************************************/

    TEST(Matrix, Math) {
        // OPERANDS //
        const sfst::Matrix<float> mtx1 {
            { 2.1f,   3,    1.21f },
            { -2.5f,  0.2f, 9  },
            { 1.002f, 3,    1  },
        };

        const sfst::Matrix<float> mtx2 {
            { 7.2f, 2, 5 },
            { 8.4f, 1, 1 },
            { 5, 0, 3.5f },
        };

        const sfst::Matrix<int> mtx3 {
            { 1, 2, 3 },
            { 3, 2, 1 },
            { 7, 8, 9 },
        };

        // BASIC MATH OPERATIONS //
        EXPECT_TRUE(( mtx1 + mtx2 ) == sfst::Matrix<float>({
            { 9.3f,   5.f,    6.21f },
            { 5.9f,   1.2f, 10.f },
            { 6.002f, 3.f,    4.5f},
        }));

        EXPECT_TRUE(( mtx1 - mtx2 ) == sfst::Matrix<float>({
            { -5.1f,   1,     -3.79, },
            { -10.9f,  -0.8f, 8,     },
            { -3.998f, 3,     -2.5f, },
        }));

        EXPECT_TRUE(( mtx1 * mtx2 ) == sfst::Matrix<float>({
            { 46.37f,   7.2f,   17.735f,  },
            { 28.68f,   -4.8f,  19.2f,    },
            { 37.4144f, 5.004f, 11.51f },
        }));

        EXPECT_TRUE(( mtx3 * 9 ) == sfst::Matrix<int>({
            { 9,  18, 27, },
            { 27, 18, 9,  },
            { 63, 72, 81, },
        }));

        EXPECT_TRUE(mtx3.getPowerOf(3) == sfst::Matrix<int>({
            { 342,  372,  402,  },
            { 210,  228,  246,  },
            { 1170, 1272, 1374, },
        }));

        // TRANSOPOS CHECK //
        EXPECT_TRUE(mtx1.getTransposition() == sfst::Matrix<float>({
                { 2.1f,  -2.5, 1.002f, },
                { 3,     0.2f, 3,      },
                { 1.21f, 9,    1,      },
        }));
        // -- -- -- -- -- -- -- -- -- //

        // MINOR CHECK // //redo with minor_mtx
        const float minor_0_0_exp = -26.8f;
        const float minor_2_2_exp = 7.92f;
        const float minor_2_1_exp = 21.925f;
        const float minor_2_0_exp = 26.758f;
        const float minor_0_2_exp = -7.7004f;
        EXPECT_FLOAT_EQ(mtx1.minor(0, 0), minor_0_0_exp);
        EXPECT_FLOAT_EQ(mtx1.minor(2, 2), minor_2_2_exp);
        EXPECT_FLOAT_EQ(mtx1.minor(2, 1), minor_2_1_exp);
        EXPECT_FLOAT_EQ(mtx1.minor(2, 0), minor_2_0_exp);
        EXPECT_FLOAT_EQ(mtx1.minor(0, 2), minor_0_2_exp);
        // -- -- -- -- -- -- -- -- -- //

        // COFACTOR CHECK //
        sfst::Matrix<float> cofactors_mtx1(mtx1);
        cofactors_mtx1.apply(
            [cofactors_mtx1](int r, int c, float val) -> float {
                return cofactors_mtx1.cofactor(r, c);
        });
        EXPECT_TRUE(cofactors_mtx1 == sfst::Matrix<float>({
            { -(134.f/5.f),  5759.f/500.f,    -(19251.f/2500.f), },
            { 63.f/100.f,    44379.f/50000.f, -(1647.f/500.f),   },
            { 13379.f/500.f, -(877.f/40.f),   198.f/25.f,        },
        }));
        // -- -- -- -- -- -- -- -- -- //

        // TO TRIANGLE CHECK //
        /* const sfst::Matrix<int> mtx3_triangle { { 1, 0, -1 }, { 0, -4, -8, }, { 0, 0, 0, } }; */
        /* EXPECT_TRUE(mtx3.getTriangl() == mtx3_triangle); */
        // -- -- -- -- -- -- -- -- -- //

        // DETERMINAT CHECK //
        const float mtx1_det_exp = -(7760871.0f/250000.0f);
        const float mtx2_det_exp = -(243.0f/5.0f);
        const int   mtx3_det_exp = 0;
        EXPECT_FLOAT_EQ(mtx1.determinant(), mtx1_det_exp);
        EXPECT_FLOAT_EQ(mtx2.determinant(), mtx2_det_exp);
        EXPECT_FLOAT_EQ(mtx3.determinant(), mtx3_det_exp);
        // -- -- -- -- -- -- -- -- -- //

    }

/**********************************************************************
*                             Matrix4x4                              *
**********************************************************************/

    /**********************************************************************
    *                           Initialization                           *
    **********************************************************************/

    TEST(Matrix4x4, Initialization) {
        sfst::Matrix4x4<float> m4x4;
        sfst::Matrix4x4<float> m4x4I {
            { 8, 2, 3, 0 },
            { 1, 9, 2, 5 },
            { 8, 2, 3, 7 },
            { 7, 6, 4, 2 },
        };

        EXPECT_EQ(m4x4(0, 0), 1);
        EXPECT_EQ(m4x4(1, 1), 1);
        EXPECT_EQ(m4x4(2, 2), 1);
        EXPECT_EQ(m4x4(3, 3), 1);

        EXPECT_EQ(m4x4I(0, 0), 8);
        EXPECT_EQ(m4x4I(1, 1), 9);
        EXPECT_EQ(m4x4I(2, 2), 3);
        EXPECT_EQ(m4x4I(3, 3), 2);
    }

    /**********************************************************************
    *                               Assign                               *
    **********************************************************************/

    TEST(Matrix4x4, Assign) {
        sfst::Matrix4x4<float> mtx;
        mtx(2, 1) = 8.f;
        mtx[3] = 4.f;
        mtx[5] = 4.f;

        EXPECT_FLOAT_EQ(mtx(2, 1), 8.f);
        EXPECT_FLOAT_EQ(mtx[2 * mtx.cols + 1], mtx(2, 1));
        EXPECT_FLOAT_EQ(mtx[3], 4.f);

        mtx[5] = 8.f;

        EXPECT_FLOAT_EQ(mtx(2, 1), mtx[5]);

        sfst::Matrix4x4<float> mtx1 {
            {1, 2, 3, 4,},
            {4, 1, 1, 4,},
            {8, 9, 8, 9,},
            {0, 1, 0, 1,},
        };

        sfst::Matrix4x4<float> mtx2(mtx1);
        EXPECT_TRUE(mtx1 == mtx2);

        sfst::Matrix4x4<float> mtx3;
        mtx3 = mtx1;
        EXPECT_TRUE(mtx3 == mtx1);
    }

    /**********************************************************************
    *                               Logic                                *
    **********************************************************************/

    TEST(Matrix4x4, Logic) {
        const sfst::Matrix4x4<float> mtx1{
            { 1, 5, 3.3f, 7,  },
            { 0, 3, 8,    2,  },
            { 2, 6, 2,    7,  },
            { 3, 4, 7,    21, },
        };

        const sfst::Matrix4x4<float> mtx2{
            { 1, 5, 3.3f, 7,  },
            { 0, 3, 8,    2,  },
            { 2, 6, 2,    7,  },
            { 3, 4, 7,    21, },
        };

        EXPECT_TRUE(mtx1 == mtx2);
        EXPECT_FALSE(mtx1 != mtx2);
    }

    /**********************************************************************
    *                                Math                                 *
    **********************************************************************/

    TEST(Matrix4x4, Math) {
        const sfst::Matrix4x4<float> mtx1 {
            { 2,  3, 18, 3, },
            { -2, 0, 9,  3, },
            { 1,  3, 1,  3, },
            { 0,  1, 9,  2, },
        };

        const sfst::Matrix4x4<float> mtx2 {
            { 7, 2, 5, 2 },
            { 8, 1, 1, 2 },
            { 5, 0, 3, 2 },
            { 8, 5, 4, 6 },
        };

        const sfst::Matrix4x4<int> mtx3 {
            { 7, 2, 5, 2 },
            { 8, 1, 1, 2 },
            { 5, 0, 3, 2 },
            { 8, 5, 4, 6 },
        };

        sfst::Matrix4x4<float> mtx_res;
        mtx_res = mtx1 * mtx2;
        EXPECT_TRUE(mtx_res == sfst::Matrix4x4<float>({
            { 152, 22, 79, 64, },
            { 55,  11, 29, 32, },
            { 60,  20, 23, 28, },
            { 69,  11, 36, 32, },

        }));
    }

/**********************************************************************
*                          END MATRIX TEST                           *
**********************************************************************/

/**********************************************************************
*                              Vectors                               *
**********************************************************************/

    /**********************************************************************
    *                           Initialization                           *
    **********************************************************************/

    TEST(Vector, Initialization) {
        sfst::Vector<float> v1(4);
        sfst::Vector<float> vI { 1, 3.2f, 0 };

        EXPECT_EQ(v1.size, 4);
        EXPECT_EQ(vI.size, 3);
        EXPECT_EQ(vI.size, 3);
    }

    /**********************************************************************
    *                               Assign                               *
    **********************************************************************/

    TEST(Vector, Assign) {
        sfst::Vector<float> v1(4);
        sfst::Vector<float> vI { 2, 3, 8 };

        v1(0) = 3;
        v1(1) = 2;
        v1(2) = 88;
        v1(3) = 1.5f;

        EXPECT_EQ(v1(0), 3);
        EXPECT_EQ(v1(1), 2);
        EXPECT_EQ(v1(2), 88);
        EXPECT_EQ(v1(3), 1.5);
        v1(0) = 1.5f;
        EXPECT_EQ(v1(0), v1(3));

        EXPECT_EQ(v1(1), vI(0));

        EXPECT_EQ(vI(2), 8);
        EXPECT_EQ(vI(1), 3);

        EXPECT_EQ(vI(0), 2);
    }

    /**********************************************************************
    *                             Operations                             *
    **********************************************************************/

    TEST(Vector, Operations) {
        sfst::Vector<float> v1 { 32, 8, 1 };
        sfst::Vector<float> v2 { 32, 8, 1 };
        sfst::Vector<float> v3 { 823, 2, 0 };

        EXPECT_TRUE(v1 == v2);
        EXPECT_FALSE(v1 == v3);
        EXPECT_TRUE(v1 != v3);

        v3 = v1;
        EXPECT_TRUE(v3 == v1);
    }

    /**********************************************************************
    *                                Math                                *
    **********************************************************************/

    TEST(Vector, Math) {
        const sfst::Vector<float> v1 { 32, 8,  1 };
        const sfst::Vector<float> v2 { 2,  77, 10 };
        const sfst::Matrix<float> m1 {
            { 5, 0, 12 },
            { 1, 2, 82 },
            { 2, 5, 10 },
        };

        const sfst::Vector<float> ve_sum        { 34,  85,   11,   };
        const sfst::Vector<float> ve_sub        { 30,  -69,  -9,   };
        const sfst::Vector<float> ve_mul        { 3,   -318, 2448, };
        const sfst::Vector<float> ve_mul_by_mtx { 172, 130,  114,  };

        EXPECT_TRUE(v1 + v2 == ve_sum);
        EXPECT_TRUE(v1 - v2 == ve_sub);
        EXPECT_TRUE(v1 * v2 == ve_mul);
        EXPECT_TRUE(v1 * m1 == ve_mul_by_mtx);
    }

/**********************************************************************
*                          END VECTORS TEST                          *
**********************************************************************/

/**********************************************************************
*                                TRS                                 *
**********************************************************************/

    /**********************************************************************
    *                               APPLY                                *
    **********************************************************************/

    TEST(TRS, Apply) {
        sfst::Trs2D trs1;
        sfst::Vectorf v1(3);

        trs1.applyTranslate({1.f, 2.f});
        trs1.applyToVector(v1);
    }

/**********************************************************************
*                            END TRS TEST                            *
**********************************************************************/

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
