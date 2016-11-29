#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)

set(CMAKE_CONFIGURATION_TYPES Debug;Release)	# Tipos de build
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W4")	 # Flags para el compilador

set(SFML_ROOT "include/SFML-2.4.1") #Ruta de la librería SFML_(x64).

# Editar antes de generar:
set(MYSQL_ROOT "C:/Program Files/MySQL/Connector.C++ 1.1") #Ruta de MySQL.

project(TowerDefense)	# (En MSVC): Nombre del archivo .sln.

include_directories("${PROJECT_BINARY_DIR}")

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/cmake_modules" ${CMAKE_MODULE_PATH})	# Ruta para el archivo findSFML.cmake.

#Find any version 2.X of SFML.
#See the FindSFML.cmake file for additional details and instructions.
set(SFML_STATIC_LIBRARIES TRUE)			# Forzado el uso de librerías estáticas.
find_package(SFML 2.4 COMPONENTS system window graphics network audio)		# Busca las librerías y headers de SFML y los incluye al proyecto.

# Define sources and executables
include("logger/CMakeLists.txt")		# Archivos del Logger.
include("network/CMakeLists.txt")		# Archivos Network y Packets.
include("db/CMakeLists.txt")			# Archivos de BDs.
include("loginServer/CMakeLists.txt")	# Archivos para el LoginServer.
include("gameClient/CMakeLists.txt")	# Archivos para el GameClient.

# LOGINSERVER START
add_executable("LoginServer"		# Genera el ejecutable para el Login Server.
						${loginServer_SOURCES})


# Settings MySQL c++ Connector
include_directories(${MYSQL_ROOT}/include)
target_link_libraries("LoginServer" ${MYSQL_ROOT}/lib/opt/mysqlcppconn.lib)		# Añade la librería estática del MySQL c++ Connector..
TARGET_COMPILE_DEFINITIONS("LoginServer" PUBLIC CPPCONN_PUBLIC_FUNC= _LOGINSERVER)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries("LoginServer" ${SFML_LIBRARIES})		# Añade las librerías básicas de sfml (sfml-grafics-s(-d para las build Debug), etc).
  target_link_libraries("LoginServer" ${SFML_DEPENDENCIES})	# Requerido cuando SFML_STATIC_LIBRARIES = TRUE, cuando se crean builds estáticas se deben definir todas las librerías requeridas (openal32, jpeg, etc).
endif()
# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
# LOGINSERVER END

# GAMECLIENT START
add_executable("GameClient" 		# Genera el ejecutable para el Login Server.
						${gameClient_SOURCES})
TARGET_COMPILE_DEFINITIONS("GameClient" PUBLIC _GAMECLIENT)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries("GameClient" ${SFML_LIBRARIES})		# Añade las librerías básicas de sfml (sfml-grafics-s(-d para las build Debug), etc).
  target_link_libraries("GameClient" ${SFML_DEPENDENCIES})	# Requerido cuando SFML_STATIC_LIBRARIES = TRUE, cuando se crean builds estáticas se deben definir todas las librerías requeridas (openal32, jpeg, etc).
endif()

# El Cliente no usa MySQL, así que no se añade.

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
		
# GAMECLIENT END


# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
include(CPack)