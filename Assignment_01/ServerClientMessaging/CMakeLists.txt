add_executable( Assignment_01 main.cpp )

include_directories ( ../RakNet-master/Source )

target_link_libraries(Assignment_01 ws2_32)

target_link_libraries(Assignment_01 RakNetLibStatic)