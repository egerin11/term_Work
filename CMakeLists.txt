cmake_minimum_required(VERSION 3.27)
project(term_qt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(term_qt src/main.cpp
        src/ui/mainwindow/mainwindow.cpp
        src/ui/mainwindow/mainwindow.h
        src/ui/mainwindow/mainwindow.ui
        src/ui/secondscreen/secondscreen.cpp
        src/ui/secondscreen/secondscreen.h
        src/ui/secondscreen/secondscreen.ui
        src/ui/secondscreen/custom_graphic/Events.cpp
        src/ui/secondscreen/Events.h
        src_back/data_model/convert.cpp
        src_back/data_model/convert.h
        src_back/data_model/get_bmp_data/BMPImageProcess.cpp
        src_back/data_model/get_bmp_data/BMPImageProcess.h
        src_back/data/bmp_image.cpp
        src_back/data/image.cpp
        src_back/data/header/ppm_image.h
        src_back/data/header/bmp_image.h
        src_back/data/header/bmp_header.h
        src_back/data/header/pixel.h
        src_back/data/header/image.h
        src_back/data/ppm_image.cpp

)
target_link_libraries(term_qt
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

