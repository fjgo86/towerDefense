# /gamestates/game/units/torres files
#message("Preparando archivos de Torres")
set( gc_gs_game_units_torres_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/torre1.cpp 
	${CMAKE_CURRENT_LIST_DIR}/torre1.h)
SOURCE_GROUP (client\\gamestates\\game\\units\\torres FILES ${gc_gs_game_units_torres_SOURCES})