set(HEADER_FILES
	include/Orca.h
	OrcaApp.h
	Utilities.h
	OrcaWindow.h
	WindowImplementation.h
	ThirdParty/codeGLFW/WindowGLFW.h
)

set(SOURCE_FILES
	OrcaApp.cpp
	OrcaWindow.cpp
	ThirdParty/code/GLFW/WindowGLFW.cpp
)

add_library(Orca SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Orca
	PUBLIC
		$<$<CONFIG:Debug>:ORCA_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:ORCA_DEBUG=1>
	PRIVATE
		ORCA_LIB
		ORCA_GLFW
)

if(MSVC)
	target_compile_definitions(Orca PUBLIC ORCA_MSVC)
endif()

target_include_directories(Orca PRIVATE ${CMAKE_SOURCE_DIR}/Orca)
target_include_directories(Orca PRIVATE ${CMAKE_SOURCE_DIR}/glfw/include)

target_link_libraries(Orca glfw)

target_precompile_headers(Orca PRIVATE pch.h)
