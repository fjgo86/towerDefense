
# /gamestates/menu files
#message("Preparando archivos del Menu")
set( gc_gs_menu_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/mainmenu_manager.cpp 
	${CMAKE_CURRENT_LIST_DIR}/mainmenu_manager.h
	${CMAKE_CURRENT_LIST_DIR}/connection_manager.cpp 
	${CMAKE_CURRENT_LIST_DIR}/connection_manager.h
	${CMAKE_CURRENT_LIST_DIR}/state_lobby.cpp 
	${CMAKE_CURRENT_LIST_DIR}/state_lobby.h
	${CMAKE_CURRENT_LIST_DIR}/viewsWrapper.cpp 
	${CMAKE_CURRENT_LIST_DIR}/viewsWrapper.h
	${CMAKE_CURRENT_LIST_DIR}/login_manager.cpp 
	${CMAKE_CURRENT_LIST_DIR}/login_manager.h )
SOURCE_GROUP (client\\gamestates\\menu FILES ${gc_gs_menu_SOURCES})

include(${CMAKE_CURRENT_LIST_DIR}/ui/CMakeLists.txt) # ${gc_gs_menu_ui_SOURCES}