# /gamestates/game/units files
#message("Preparando archivos de units")
set( gc_gs_game_units_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/unit_manager.cpp 
	${CMAKE_CURRENT_LIST_DIR}/unit_manager.h
	${CMAKE_CURRENT_LIST_DIR}/enemigo.cpp 
	${CMAKE_CURRENT_LIST_DIR}/enemigo.h
	${CMAKE_CURRENT_LIST_DIR}/torre.cpp 
	${CMAKE_CURRENT_LIST_DIR}/torre.h)
SOURCE_GROUP (client\\gamestates\\game\\units FILES ${gc_gs_game_units_SOURCES})


include(${CMAKE_CURRENT_LIST_DIR}/enemigos/CMakeLists.txt)	# ${gc_gs_game_units_enemigos_SOURCES}
include(${CMAKE_CURRENT_LIST_DIR}/torres/CMakeLists.txt)	# ${gc_gs_game_units_torres_SOURCES}