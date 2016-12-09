# /network/packets files
#message("Preparando archivos network/packets")
set( gc_packets_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/loginReq.h 
	${CMAKE_CURRENT_LIST_DIR}/loginReq.cpp
	${CMAKE_CURRENT_LIST_DIR}/loginResp.h 
	${CMAKE_CURRENT_LIST_DIR}/loginResp.cpp )
SOURCE_GROUP (network\\packets FILES ${gc_packets_SOURCES})