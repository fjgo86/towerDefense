# Configurador de Carpetas y Archivos mostrados en el IDE.

# Main Files
#message("Preparando archivos Main")
set( ls_main_SOURCES 
	loginServer/main.cpp
	loginServer/loginServer.cpp
	loginServer/loginServer.h )
SOURCE_GROUP (server FILES ${ls_main_SOURCES})

# /accounts files
#message("Preparando archivos de accounts")
set( ls_accounts_SOURCES 
	loginServer/accounts/account.h 
	loginServer/accounts/account.cpp )
SOURCE_GROUP (server\\accounts FILES ${ls_accounts_SOURCES})

# /network files
#message("Preparando archivos network")
set( ls_network_SOURCES 
	loginServer/network/serverListener.h 
	loginServer/network/serverListener.cpp )
SOURCE_GROUP (network FILES ${ls_network_SOURCES})

# /network/clients files
#message("Preparando archivos network/clients")
set( ls_clients_SOURCES 
	loginServer/network/clients/client.h 
	loginServer/network/clients/client.cpp
	loginServer/network/clients/client_list.h 
	loginServer/network/clients/client_list.cpp )
SOURCE_GROUP (network\\clients FILES ${ls_clients_SOURCES})

# /network/packets files
#message("Preparando archivos network/packets")
set( ls_packets_SOURCES 
	loginServer/network/packets/loginReq.h 
	loginServer/network/packets/loginReq.cpp
	loginServer/network/packets/loginResp.h 
	loginServer/network/packets/loginResp.cpp )
SOURCE_GROUP (network\\packets FILES ${ls_packets_SOURCES})

set(loginServer_SOURCES 
		${ls_main_SOURCES} 
		${logger_SOURCES}
		${ls_accounts_SOURCES}
		${network_SOURCES}
		${ls_network_SOURCES}
		${ls_clients_SOURCES}
		${ls_packets_SOURCES}
		${db_SOURCES}
		${packets_SOURCES}
	)