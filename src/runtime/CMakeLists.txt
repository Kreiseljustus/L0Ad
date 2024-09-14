file(GLOB RUNTIME_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(runtime ${RUNTIME_SOURCES})

target_include_directories(runtime PRIVATE ${CMAKE_SOURCE_DIR}/src/engine)

find_package(OpenGL REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/vendor/glew)

target_link_libraries(runtime engine ${OPENGL_LIBRARIES})