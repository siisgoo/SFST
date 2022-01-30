set(LIB_NAME    SFST)
set(LIB_VERSION 1.0)

set(LIB_SOURCES 
    src/AssetManager.cpp
    src/Cheatsheet.cpp
    src/Processor.cpp
    src/Screen.cpp
    src/World.cpp
    src/Item.cpp
    src/Math/TRS.cpp
    include/SFST/Vectors.inl
    include/SFST/Matrix.inl
)

set(LIB_HEADERS_PUBLIC
)

set(LIB_HEADERS_PRIVATE
    include/SFST/AssetManager.hpp
    include/SFST/Cheatsheet.hpp
    include/SFST/Density.hpp
    include/SFST/Gravity.hpp
    include/SFST/Processor.hpp
    include/SFST/Screen.hpp
    include/SFST/Textbox.hpp
    include/SFST/Item.hpp
    include/SFST/World.hpp
    include/SFST/Matrix.hpp
    include/SFST/Vectors.hpp
    include/SFST/TRS.hpp
    include/SFST/Math.hpp

    include/SFST/Vectors.inl
    include/SFST/Matrix.inl
)

# set(LIBRARY_DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)
# set(LIB_HEADERS_DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/lib)
