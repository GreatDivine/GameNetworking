add_executable( Assignment_01 main.cpp )

add_custom_command(TARGET Assignment_01 PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}../RakNet-master/Source $<TARGET_FILE_DIR:Assignment_01>)

include_directories ( ../RakNet-master/Source )

target_link_libraries(Assignment_01 ws2_32)