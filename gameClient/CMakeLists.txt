# Configurador de Carpetas y Archivos mostrados en el IDE.

# Main Files
#message("Preparando archivos Main")
set( gc_main_SOURCES 
	gameClient/main.cpp
	gameClient/game.cpp
	gameClient/game.h )
SOURCE_GROUP (client FILES ${gc_main_SOURCES})

# /gamestates files
#message("Preparando archivos GameStates")
set( gc_gs_SOURCES 
	gameClient/gamestates/gamestate.h 
	gameClient/gamestates/gamestate.cpp
	gameClient/gamestates/gamestates_manager.h 
	gameClient/gamestates/gamestates_manager.cpp )
SOURCE_GROUP (client\\gamestates FILES ${gc_gs_SOURCES})

# MENU START
# /gamestates/menu files
#message("Preparando archivos del Menu")
set( gc_gs_menu_SOURCES 
	gameClient/gamestates/menu/mainmenu_manager.cpp 
	gameClient/gamestates/menu/mainmenu_manager.h
	gameClient/gamestates/menu/connection_manager.cpp 
	gameClient/gamestates/menu/connection_manager.h
	gameClient/gamestates/menu/state_lobby.cpp 
	gameClient/gamestates/menu/state_lobby.h
	gameClient/gamestates/menu/viewsWrapper.cpp 
	gameClient/gamestates/menu/viewsWrapper.h
	gameClient/gamestates/menu/login_manager.cpp 
	gameClient/gamestates/menu/login_manager.h )
SOURCE_GROUP (client\\gamestates\\menu FILES ${gc_gs_menu_SOURCES})

# /gamestates/menu/ui files
#message("Preparando archivos del Menu")
set( gc_gs_menu_ui_SOURCES 
	gameClient/gamestates/menu/ui/botonmenu.cpp 
	gameClient/gamestates/menu/ui/botonmenu.h 
	gameClient/gamestates/menu/ui/loginbox.cpp 
	gameClient/gamestates/menu/ui/loginbox.h 
	gameClient/gamestates/menu/ui/loginbox_component.cpp 
	gameClient/gamestates/menu/ui/loginbox_component.h )
SOURCE_GROUP (client\\gamestates\\menu\\ui FILES ${gc_gs_menu_ui_SOURCES})
# MENU END

# GAME START
# /gamestates/game files
#message("Preparando archivos del Game")
set( gc_gs_game_SOURCES 
	gameClient/gamestates/game/game_manager.cpp 
	gameClient/gamestates/game/game_manager.h
	gameClient/gamestates/game/animatedsprite.cpp 
	gameClient/gamestates/game/animatedsprite.h
	gameClient/gamestates/game/colectorbasura.cpp 
	gameClient/gamestates/game/colectorbasura.h
	gameClient/gamestates/game/sprite_manager.cpp 
	gameClient/gamestates/game/sprite_manager.h
	gameClient/gamestates/game/texture_manager.cpp 
	gameClient/gamestates/game/texture_manager.h
	gameClient/gamestates/game/unit.cpp 
	gameClient/gamestates/game/unit.h)
SOURCE_GROUP (client\\gamestates\\game FILES ${gc_gs_game_SOURCES})

# /gamestates/game/map files
#message("Preparando archivos del Mapa")
set( gc_gs_game_map_SOURCES 
	gameClient/gamestates/game/map/map.cpp 
	gameClient/gamestates/game/map/map.h
	gameClient/gamestates/game/map/grid.cpp 
	gameClient/gamestates/game/map/grid.h
	gameClient/gamestates/game/map/tile.cpp 
	gameClient/gamestates/game/map/tile.h)
SOURCE_GROUP (client\\gamestates\\game\\map FILES ${gc_gs_game_map_SOURCES})

# /gamestates/game/units files
#message("Preparando archivos de units")
set( gc_gs_game_units_SOURCES 
	gameClient/gamestates/game/units/unit_manager.cpp 
	gameClient/gamestates/game/units/unit_manager.h
	gameClient/gamestates/game/units/enemigo.cpp 
	gameClient/gamestates/game/units/enemigo.h
	gameClient/gamestates/game/units/torre.cpp 
	gameClient/gamestates/game/units/torre.h)
SOURCE_GROUP (client\\gamestates\\game\\units FILES ${gc_gs_game_units_SOURCES})

# /gamestates/game/units/enemigos files
#message("Preparando archivos de Enemigos")
set( gc_gs_game_units_enemigos_SOURCES 
	gameClient/gamestates/game/units/enemigos/dragon.cpp 
	gameClient/gamestates/game/units/enemigos/dragon.h)
SOURCE_GROUP (client\\gamestates\\game\\units\\enemigos FILES ${gc_gs_game_units_enemigos_SOURCES})

# /gamestates/game/units/torres files
#message("Preparando archivos de Torres")
set( gc_gs_game_units_torres_SOURCES 
	gameClient/gamestates/game/units/torres/torre1.cpp 
	gameClient/gamestates/game/units/torres/torre1.h)
SOURCE_GROUP (client\\gamestates\\game\\units\\torres FILES ${gc_gs_game_units_torres_SOURCES})

#GAME END
# /network/clients files
#message("Preparando archivos network/clients")
set( gc_clients_SOURCES 
	gameClient/network/clients/client.h 
	gameClient/network/clients/client.cpp )
SOURCE_GROUP (network\\clients FILES ${gc_clients_SOURCES})

# /network/packets files
#message("Preparando archivos network/packets")
set( gc_packets_SOURCES 
	gameClient/network/packets/loginReq.h 
	gameClient/network/packets/loginReq.cpp
	gameClient/network/packets/loginResp.h 
	gameClient/network/packets/loginResp.cpp )
SOURCE_GROUP (network\\packets FILES ${gc_packets_SOURCES})

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