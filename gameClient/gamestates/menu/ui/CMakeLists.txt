
# /gamestates/menu/ui files
#message("Preparando archivos del Menu")
set( gc_gs_menu_ui_SOURCES
	${CMAKE_CURRENT_LIST_DIR}/big_button.cpp 
	${CMAKE_CURRENT_LIST_DIR}/big_button.h 
	${CMAKE_CURRENT_LIST_DIR}/botonmenu.cpp 
	${CMAKE_CURRENT_LIST_DIR}/botonmenu.h 
	${CMAKE_CURRENT_LIST_DIR}/loginbox.cpp 
	${CMAKE_CURRENT_LIST_DIR}/loginbox.h 
	${CMAKE_CURRENT_LIST_DIR}/loginbox_component.cpp 
	${CMAKE_CURRENT_LIST_DIR}/loginbox_component.h )
SOURCE_GROUP (client\\gamestates\\menu\\ui FILES ${gc_gs_menu_ui_SOURCES})