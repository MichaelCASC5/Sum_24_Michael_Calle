#pragma once

#define GAME_ORCA_START(ClassName) \
int main()\
{\
	ClassName game;\
	game.Run();\
	return 0;\
}

//This whole thing should happen only if we are using Microsoft C++ compiler
#ifdef ORCA_MSVC
	#ifdef ORCA_LIB
		#define ORCA_API __declspec(dllexport)
	#else
		#define ORCA_API __declspec(dllimport)
	#endif
#else
	#define ORCA_API
#endif


#ifdef ORCA_DEBUG==2
	#define ORCA_LOG(x) std::cout<<x<<std::endl;
	#define ORCA_ERROR(x) std::cout<<x<<std::endl;
#elif defined ORCA_DEBUG==1
	#define ORCA_LOG(x)
	#define ORCA_ERROR(x) std::cout<<x<<std::endl;
#else
	#define ORCA_LOG(x)
	#define ORCA_ERROR(x)
#endif
