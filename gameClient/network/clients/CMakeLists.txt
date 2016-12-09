# /network/clients files
#message("Preparando archivos network/clients")
set( gc_clients_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/client.h 
	${CMAKE_CURRENT_LIST_DIR}/client.cpp )
SOURCE_GROUP (network\\clients FILES ${gc_clients_SOURCES})