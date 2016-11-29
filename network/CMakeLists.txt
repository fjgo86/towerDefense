

# /network files
#message("Preparando archivos network")
set( network_SOURCES 
	network/network.h 
	network/network.cpp )
SOURCE_GROUP (network FILES ${network_SOURCES})

# /network/packets files
#message("Preparando archivos network/packets")
set( packets_SOURCES 
	network/packets/listado_paquetes.h  )
SOURCE_GROUP (network\\packets FILES ${packets_SOURCES})

# /network/packets/loginserver files
#message("Preparando archivos network/packets/loginserver")
set( ls_packets_SOURCES 
	network/packets/packetLogin.h 
	network/packets/packetLogin.cpp )
SOURCE_GROUP (network\\packets\\loginserver FILES ${ls_packets_SOURCES})

# /network/packets/gameclient files
#message("Preparando archivos network/packets/gameclient")
set( gc_packets_SOURCES  )
SOURCE_GROUP (network\\packets\\gameclient FILES ${gc_packets_SOURCES})

# /network/clients files
#message("Preparando archivos network/clients")
set( clients_SOURCES 
	network/clients/client.h 
	network/clients/client.cpp
	network/clients/client_list.h 
	network/clients/client_list.cpp )
SOURCE_GROUP (network\\clients FILES ${clients_SOURCES})

