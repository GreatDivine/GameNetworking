cmake_minimum_required(VERSION 3.3)

project( Assignment_01 )

add_subdirectory ( ServerClientMessaging )
add_subdirectory ( RakNet-master )

include_directories ("RakNet-master/Source")