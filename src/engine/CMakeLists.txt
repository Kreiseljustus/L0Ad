file(GLOB_RECURSE ENGINE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_library(engine STATIC ${ENGINE_SOURCES})

find_package(OpenGL REQUIRED)

add_definitions(-DGLEW_STATIC)

include_directories(${CMAKE_SOURCE_DIR}/vendor/glew)
link_directories(${CMAKE_SOURCE_DIR}/vendor/glew)
include_directories(${CMAKE_SOURCE_DIR}/vendor/imgui)
link_directories(${CMAKE_SOURCE_DIR}/vendor/imgui)


file(GLOB  IMGUI_SOURCES "${CMAKE_SOURCE_DIR}/vendor/imgui/*.cpp")
file(GLOB  IMGUI_HEADERS "${CMAKE_SOURCE_DIR}/vendor/imgui/*.h")

file(GLOB IMGUI_BACKENDS_SOURCE "${CMAKE_SOURCE_DIR}/vendor/imgui/backends/*.cpp")
file(GLOB IMGUI_BACKENDS_HEADERS "${CMAKE_SOURCE_DIR}/vendor/imgui/backends/*.h")

target_link_libraries(engine glfw glm ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${CMAKE_SOURCE_DIR}/vendor/glew/glew32s.lib)
target_sources(engine PRIVATE ${IMGUI_SOURCES} ${IMGUI_HEADERS} ${IMGUI_BACKENDS_HEADERS} ${IMGUI_BACKENDS_SOURCE})