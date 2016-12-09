# Configurador de Carpetas y Archivos mostrados en el IDE.

# Main Files
#message("Preparando archivos Main")
set( ls_main_SOURCES 
	loginServer/main.cpp
	loginServer/loginServer.cpp
	loginServer/loginServer.h )
SOURCE_GROUP (server FILES ${ls_main_SOURCES})

include(${CMAKE_CURRENT_LIST_DIR}/accounts/CMakeLists.txt)	# ${ls_accounts_SOURCES}
include(${CMAKE_CURRENT_LIST_DIR}/network/CMakeLists.txt)	# ${ls_network_SOURCES} + ${ls_clients_SOURCES} + ${ls_packets_SOURCES}

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