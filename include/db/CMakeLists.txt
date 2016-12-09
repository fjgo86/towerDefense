
# /db files
#message("Preparando archivos db")
set( db_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/db.h 
	${CMAKE_CURRENT_LIST_DIR}/db.cpp  )
SOURCE_GROUP (db FILES ${db_SOURCES})