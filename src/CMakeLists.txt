file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS *.cpp *.h)

add_library(PXEngine STATIC ${ENGINE_SRC})

if (ENABLE_TRACY)
    target_link_libraries(PXEngine PUBLIC TracyClient)
endif()

if (WIN32)
    target_link_libraries(PXEngine PRIVATE Ws2_32 DbgHelp)
endif()

target_include_directories(PXEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
