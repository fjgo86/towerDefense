# Configurador de Carpetas y Archivos mostrados en el IDE.

# Main Files
#message("Preparando archivos Main")
set( gc_main_SOURCES 
	gameClient/main.cpp
	gameClient/game.cpp
	gameClient/game.h )
SOURCE_GROUP (client FILES ${gc_main_SOURCES})

include(${CMAKE_CURRENT_LIST_DIR}/gamestates/CMakeLists.txt)	# ${gc_gs_SOURCES} - ${gc_gs_SOURCES}/*
include(${CMAKE_CURRENT_LIST_DIR}/network/CMakeLists.txt)		# network - ${gc_clients_SOURCES} - ${gc_packets_SOURCES}

set(gameClient_SOURCES 
		${gc_main_SOURCES} 
		${gc_gs_SOURCES}
		${gc_gs_menu_SOURCES}
		${gc_gs_menu_ui_SOURCES}
		${gc_gs_game_SOURCES}
		${gc_gs_game_map_SOURCES}
		${gc_gs_game_units_SOURCES}
		${gc_gs_game_units_enemigos_SOURCES}
		${gc_gs_game_units_torres_SOURCES}
		${network_SOURCES}
		${gc_packets_SOURCES}
		${gc_clients_SOURCES}
		${packets_SOURCES}
		${logger_SOURCES}
	)