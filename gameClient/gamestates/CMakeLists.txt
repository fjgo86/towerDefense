# /gamestates files
#message("Preparando archivos GameStates")
set( gc_gs_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/gamestate.h 
	${CMAKE_CURRENT_LIST_DIR}/gamestate.cpp
	${CMAKE_CURRENT_LIST_DIR}/gamestates_manager.h 
	${CMAKE_CURRENT_LIST_DIR}/gamestates_manager.cpp )
SOURCE_GROUP (client\\gamestates FILES ${gc_gs_SOURCES})

include(${CMAKE_CURRENT_LIST_DIR}/menu/CMakeLists.txt) # ${gc_gs_menu_SOURCES}
include(${CMAKE_CURRENT_LIST_DIR}/game/CMakeLists.txt) # ${gc_gs_game_SOURCES}