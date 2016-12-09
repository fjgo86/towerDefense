# /gamestates/game/units/enemigos files
#message("Preparando archivos de Enemigos")
set( gc_gs_game_units_enemigos_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/dragon.cpp 
	${CMAKE_CURRENT_LIST_DIR}/dragon.h)
SOURCE_GROUP (client\\gamestates\\game\\units\\enemigos FILES ${gc_gs_game_units_enemigos_SOURCES})