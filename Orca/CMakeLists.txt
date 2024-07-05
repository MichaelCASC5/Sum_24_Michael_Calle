set(HEADER_FILES
	include/Orca.h
	OrcaApp.h
	Utilities.h
	OrcaWindow.h
	WindowImplementation.h
	ThirdParty/codeGLFW/WindowGLFW.h
	Image.h
	ImageImplementation.h
	ThirdParty/codeOpenGL/ImageOpenGL.h
	Shaders.h
	ShadersImplementation.h
	ThirdParty/codeOpenGL/ShadersOpenGL.h
	Renderer.h
	RendererImplementation.h
	ThirdParty/codeOpenGL/RendererOpenGL.h
)

set(SOURCE_FILES
	OrcaApp.cpp
	OrcaWindow.cpp
	ThirdParty/codeGLFW/WindowGLFW.cpp
	Image.cpp
	ThirdParty/codeOpenGL/ImageOpenGL.cpp
	Shaders.cpp
	ThirdParty/codeOpenGL/ShadersOpenGL.cpp
	Renderer.cpp
	ThirdParty/codeOpenGL/RendererOpenGL.cpp
)

add_library(Orca SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Orca
	PUBLIC
		$<$<CONFIG:Debug>:ORCA_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:ORCA_DEBUG=1>
	PRIVATE
		ORCA_LIB
		ORCA_GLFW
		ORCA_OPENGL
)

if(MSVC)
	target_compile_definitions(Orca PUBLIC ORCA_MSVC)
endif()

target_include_directories(Orca PRIVATE ${CMAKE_SOURCE_DIR}/Orca)
target_include_directories(Orca PRIVATE ${CMAKE_SOURCE_DIR}/glfw/include)
target_include_directories(Orca PRIVATE ${CMAKE_SOURCE_DIR}/glad/include)

target_link_libraries(Orca glfw glad stbi)

target_precompile_headers(Orca PRIVATE pch.h)
