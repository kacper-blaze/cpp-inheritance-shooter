cmake_minimum_required(VERSION 3.5)

project(game VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 OPTIONAL COMPONENTS Widgets Multimedia Multimedia MultimediaWidgets)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Multimedia MultimediaWidgets)

if (Qt${QT_VERSION_MAJOR}_FOUND AND Qt${QT_VERSION_MAJOR}Widgets_FOUND)
    set(PROJECT_SOURCES
        ${HEADERS}
        ${SOURCES_WITHOUT_MAIN}
        gameMain.cpp
        mainwindow.h
        mainwindow.cpp
        mainwindow.ui
        resources.qrc
    )

    if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
        qt_add_executable(${PROJECT_NAME}
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
        )
    else()
        if(ANDROID)
            add_library(${PROJECT_NAME} SHARED
                ${PROJECT_SOURCES}
            )
        else()
            add_executable(${PROJECT_NAME}
                ${PROJECT_SOURCES}
            )
        endif()
    endif()

    target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Multimedia Qt${QT_VERSION_MAJOR}::MultimediaWidgets)

    set_target_properties(${PROJECT_NAME} PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER com.inheritance.game
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
    )

    install(TARGETS ${PROJECT_NAME}
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

    if(QT_VERSION_MAJOR EQUAL 6)
        qt_finalize_executable(${PROJECT_NAME})
    endif()
else()
    message("QT not found")
endif()
