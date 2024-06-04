add_executable(BestGame main.cpp)

target_include_directories(BestGame PRIVATE ../Orca/include)

target_link_libraries(BestGame Orca)
