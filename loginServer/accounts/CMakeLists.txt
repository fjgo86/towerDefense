
# /accounts files
#message("Preparando archivos de accounts")
set( ls_accounts_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/account.h 
	${CMAKE_CURRENT_LIST_DIR}/account.cpp )
SOURCE_GROUP (server\\accounts FILES ${ls_accounts_SOURCES})