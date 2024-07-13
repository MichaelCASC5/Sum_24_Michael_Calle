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
	Events.h
	OrcaKeys.h
	Unit.h
	Map.h
	Physics.h
	Camera.h
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
	Events.cpp
	Unit.cpp
	Map.cpp
	Physics.cpp
	Camera.cpp
)

add_library(Orca SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Orca
	PUBLIC
		$<$<CONFIG:Debug>:ORCA_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:ORCA_DEBUG=1>
		ORCA_GLFW
	PRIVATE
		ORCA_LIB
		ORCA_OPENGL
)

if(MSVC)
	target_compile_definitions(Orca PUBLIC ORCA_MSVC)
endif()

target_include_directories(Orca PRIVATE ${CMAKE_SOURCE_DIR}/Orca)
target_include_directories(Orca PUBLIC ${CMAKE_SOURCE_DIR}/Orca/include)
target_include_directories(Orca PRIVATE ${CMAKE_SOURCE_DIR}/glfw/include)
target_include_directories(Orca PRIVATE ${CMAKE_SOURCE_DIR}/glad/include)
target_include_directories(Orca PRIVATE ${CMAKE_SOURCE_DIR}/stbi)

target_link_libraries(Orca glfw glad stbi)

target_precompile_headers(Orca PRIVATE pch.h)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Orca)
