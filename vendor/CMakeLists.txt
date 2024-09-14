add_subdirectory(glfw)
#add_subdirectory(imgui)

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE ${CMAKE_SOURCE_DIR}/vendor/glm ${CMAKE_SOURCE_DIR}/vendor/glew ${CMAKE_SOURCE_DIR}/vendor/imgui)