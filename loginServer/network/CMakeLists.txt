
# /network files
#message("Preparando archivos network")
set( ls_network_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/serverListener.h 
	${CMAKE_CURRENT_LIST_DIR}/serverListener.cpp )
SOURCE_GROUP (network FILES ${ls_network_SOURCES})

include(${CMAKE_CURRENT_LIST_DIR}/clients/CMakeLists.txt)	# ${ls_clients_SOURCES}
include(${CMAKE_CURRENT_LIST_DIR}/packets/CMakeLists.txt)	# ${ls_packets_SOURCES}