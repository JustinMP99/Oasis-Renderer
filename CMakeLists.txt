# set cmake minimum version
cmake_minimum_required(VERSION 3.10.0)

#set project name and version along with languages
project(OpenGLRenderer VERSION 0.0.1 LANGUAGES C CXX)

#set cmake c++ standard version
set(CMAKE_CXX_STANDARD 17)

#set cmake standard required
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Find Packages
find_package(OpenGL REQUIRED)

if (APPLE)

    find_package(glfw3 REQUIRED)

elseif (WIN32)

endif ()

#Add Executable
add_executable(OpenGLRenderer
        Core/Main.cpp
        Source/Source/SystemManager.cpp
        Source/Source/GameObject.cpp
        Source/Source/Graphics.cpp
        Source/Source/Material.cpp
        Source/Source/Vertex.cpp
        Source/Source/WindowManager.cpp

        Source/Source/glad.c

        #ImGui
        #Additional/Includes/imgui/imgui.cpp
        #Additional/Includes/imgui/imgui_draw.cpp
        #Additional/Includes/imgui/imgui_impl_glfw.cpp
        #Additional/Includes/imgui/imgui_impl_opengl3.cpp
        #Additional/Includes/imgui/imgui_tables.cpp
        #Additional/Includes/imgui/imgui_widgets.cpp

        Additional/Includes/stb_image/stb_image.cpp
        Source/Headers/Mesh.h

        Source/Source/Mesh.cpp)

# Set Path Variables
set(GLAD_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Additional/Includes/glad")
set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Additional/Includes/GLFW")
set(KHR_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Additional/Includes/KHR")
set(GLM_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Additional/Includes/glm")
set(FRAG_DIR "${CMAKE_SOURCE_DIR}/Source/Shaders/Fragment Shaders")

set(IMGUI_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Additional/Includes/imgui")
set(GLFW_LIBRARY "${CMAKE_SOURCE_DIR}/Additional/Library/glfw3.lib")
set(STB_IMAGE_DIR "${PROJECT_SOURCE_DIR}/Additional/Includes/stb_image")
set(IMAGE_DIR "${PROJECT_SOURCE_DIR}/Additional/Images")

# Include Directories
target_include_directories(OpenGLRenderer PRIVATE

        ${GLAD_INCLUDE_DIR}

        ${GLFW_INCLUDE_DIR}

        #${IMGUI_INCLUDE_DIR}

        ${GLM_INCLUDE_DIR}

        ${STB_IMAGE_DIR}

        ${IMAGE_DIR}

        ${KHR_INCLUDE_DIR}

        ${FRAG_DIR}

)

if (APPLE)

    find_package(glfw3 REQUIRED)
    target_link_libraries(OpenGLRenderer glfw OpenGL::GL)
    target_link_libraries(OpenGLRenderer glfw)

elseif (WIN32)

	target_compile_definitions(OpenGLRenderer PRIVATE
			PROJECT_ROOT="${CMAKE_SOURCE_DIR}"
	)

    #Link Libraries
    target_link_libraries(OpenGLRenderer PRIVATE

            ${GLFW_LIBRARY}
            ${OPENGL_gl_LIBRARY}

    )

endif ()



