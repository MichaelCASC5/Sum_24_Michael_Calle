set(HEADER_FILES
	include/Orca.h
	OrcaApp.h
	Utilities.h
)

set(SOURCE_FILES
	OrcaApp.cpp
)

add_library(Orca SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_compile_definitions(Orca
	PUBLIC
		$<$<CONFIG:Debug>:ORCA_DEBUG=2>
		$<$<CONFIG:RelWithDebInfo>:ORCA_DEBUG=1>
	PRIVATE
		ORCA_LIB
)

if(MSVC)
	target_compile_definitions(Orca PUBLIC ORCA_MSVC)
endif()

target_precompile_headers(Orca PRIVATE pch.h)
