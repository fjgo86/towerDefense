# /gamestates/game files
#message("Preparando archivos del Game")
set( gc_gs_game_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/game_manager.cpp 
	${CMAKE_CURRENT_LIST_DIR}/game_manager.h
	${CMAKE_CURRENT_LIST_DIR}/animatedsprite.cpp 
	${CMAKE_CURRENT_LIST_DIR}/animatedsprite.h
	${CMAKE_CURRENT_LIST_DIR}/colectorbasura.cpp 
	${CMAKE_CURRENT_LIST_DIR}/colectorbasura.h
	${CMAKE_CURRENT_LIST_DIR}/sprite_manager.cpp 
	${CMAKE_CURRENT_LIST_DIR}/sprite_manager.h
	${CMAKE_CURRENT_LIST_DIR}/texture_manager.cpp 
	${CMAKE_CURRENT_LIST_DIR}/texture_manager.h
	${CMAKE_CURRENT_LIST_DIR}/unit.cpp 
	${CMAKE_CURRENT_LIST_DIR}/unit.h)
SOURCE_GROUP (client\\gamestates\\game FILES ${gc_gs_game_SOURCES})

include(${CMAKE_CURRENT_LIST_DIR}/map/CMakeLists.txt)	# ${gc_gs_game_map_SOURCES}
include(${CMAKE_CURRENT_LIST_DIR}/units/CMakeLists.txt)	# ${gc_gs_game_units_SOURCES}