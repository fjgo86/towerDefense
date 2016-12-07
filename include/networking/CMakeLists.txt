

# /network files
#message("Preparando archivos network")
set( network_SOURCES 
	include/networking/config.h 
	include/networking/packets.h
	include/networking/packetIn.h
	include/networking/packetIn.cpp
	include/networking/packetOut.h
	include/networking/packetOut.cpp)
SOURCE_GROUP (network FILES ${network_SOURCES})

