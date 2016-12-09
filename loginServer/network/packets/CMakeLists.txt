
# /network/packets files
#message("Preparando archivos network/packets")
set( ls_packets_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/loginReq.h 
	${CMAKE_CURRENT_LIST_DIR}/loginReq.cpp
	${CMAKE_CURRENT_LIST_DIR}/loginResp.h 
	${CMAKE_CURRENT_LIST_DIR}/loginResp.cpp )
SOURCE_GROUP (network\\packets FILES ${ls_packets_SOURCES})