file(GLOB EDITOR_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(editor ${EDITOR_SOURCES})

target_include_directories(editor PRIVATE ${CMAKE_SOURCE_DIR}/src/engine)

find_package(OpenGL REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/vendor/glew)
include_directories(${CMAKE_SOURCE_DIR}/vendor/imgui)

target_link_libraries(editor engine ${OPENGL_LIBRARIES})