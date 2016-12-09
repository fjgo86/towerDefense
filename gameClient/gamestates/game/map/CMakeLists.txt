# /gamestates/game/map files
#message("Preparando archivos del Mapa")
set( gc_gs_game_map_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/map.cpp 
	${CMAKE_CURRENT_LIST_DIR}/map.h
	${CMAKE_CURRENT_LIST_DIR}/grid.cpp 
	${CMAKE_CURRENT_LIST_DIR}/grid.h
	${CMAKE_CURRENT_LIST_DIR}/tile.cpp 
	${CMAKE_CURRENT_LIST_DIR}/tile.h)
SOURCE_GROUP (client\\gamestates\\game\\map FILES ${gc_gs_game_map_SOURCES})