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

# /network/clients files
#message("Preparando archivos network/clients")
set( ls_clients_SOURCES 
	loginServer/network/clients/client.h 
	loginServer/network/clients/client.cpp
	loginServer/network/clients/client_list.h 
	loginServer/network/clients/client_list.cpp )
SOURCE_GROUP (network\\clients FILES ${ls_clients_SOURCES})

set(loginServer_SOURCES 
		${ls_main_SOURCES} 
		${logger_SOURCES}
		${ls_accounts_SOURCES}
		${network_SOURCES}
		${ls_clients_SOURCES}
		${db_SOURCES}
		${packets_SOURCES}
	)