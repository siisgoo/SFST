add_test( Coubes.Rotation /home/xewii/projects/misc/sfst/build/test/Screen_test [==[--gtest_filter=Coubes.Rotation]==] --gtest_also_run_disabled_tests)
set_tests_properties( Coubes.Rotation PROPERTIES WORKING_DIRECTORY /home/xewii/projects/misc/sfst/build/test SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( Screen_test_TESTS Coubes.Rotation)
