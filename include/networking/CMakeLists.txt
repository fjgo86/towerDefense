
# /network files
#message("Preparando archivos network")
set( network_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/config.h 
	${CMAKE_CURRENT_LIST_DIR}/packets.h
	${CMAKE_CURRENT_LIST_DIR}/packetIn.h
	${CMAKE_CURRENT_LIST_DIR}/packetIn.cpp
	${CMAKE_CURRENT_LIST_DIR}/packetOut.h
	${CMAKE_CURRENT_LIST_DIR}/packetOut.cpp)
SOURCE_GROUP (network FILES ${network_SOURCES})

