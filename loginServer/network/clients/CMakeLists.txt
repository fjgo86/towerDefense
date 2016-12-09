
# /network/clients files
#message("Preparando archivos network/clients")
set( ls_clients_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/client.h 
	${CMAKE_CURRENT_LIST_DIR}/client.cpp
	${CMAKE_CURRENT_LIST_DIR}/client_list.h 
	${CMAKE_CURRENT_LIST_DIR}/client_list.cpp )
SOURCE_GROUP (network\\clients FILES ${ls_clients_SOURCES})
