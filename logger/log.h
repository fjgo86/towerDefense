#pragma once
#include <string>
#include <windows.h> // WinApi header
#include <sstream>

#include "Logger.h"



/*
    Colores de salida
    * IMPORTANTE: Por ahora son solo válidos para Windows 10 (Versiones anteriores no admiten colores en el cmd), habría que dar soporte para unix más adelante.
*/

#define LogColorTextDefault 15      // Color para el texto normal.
#define LogColorFileDefault 10      // Color para el texto que muestra la ruta del fichero.
#define LogColorLineDefault 10      // Color para el texto que muestra la linea del Log.
#define LogColorMethodDefault 14    // Color para el texto que muestra el nombre del método desde el que se crea el Log.

/*
* @brief Logs en consola
* Clase encargada de enviar los Log a pantalla (TODO: a un archivo en un futuro):
* Macros de información detallada (Envían __FILE__, __LINE__ y __func__ al texto a mostrar):
* _DEBUGLOG(txt)
* _EVENTLOG(txt)
* _WARNINGLOG(txt)
* _WARNINGLOG(txt)
* _CRITICALLOG(txt)
* Macro de información simple:
* _LOG(x, txt):

* Uso:
* - Añadir #include <logger/Log.h> (modificando la ruta por la necesaria para cada fichero).
* - Llamar a cualquier macro (eg):
* _DEBUGLOG("hola\n"); para un log detallado de tipo Debug.
* _LOG(Log::LOGLVL_EVENT, "Que tal\n"); para un log simple.
*/
class Log {
public:
    /*
    * @brief Tipos de Log (Importancia).
    */
    enum LogLevel {
        LOGLVL_EVENT,
        LOGLVL_DEBUG,
        LOGLVL_WARNING,
        LOGLVL_ERROR,
        LOGLVL_CRITICAL,
        LOGLVL_QTY
    };

    /*
    * @brief Nombre de cada tipo de Log.
    */
    const char* LogLevelStrings[LOGLVL_QTY] = {
        "",         // LOGLVL_EVENT
        "Debug: ",  // LOGLVL_DEBUG
        "Warning: ",// LOGLVL_WARNING
        "Error: ",  // LOGLVL_ERROR
        "Critical: "// LOGLVL_CRITICAL
    };

    /*
    * @brief Color para cada tipo de Log
    */
    WORD LogColor[LOGLVL_QTY] = {
        0,	// LOGLVL_EVENT
        11,	// LOGLVL_DEBUG
        14,	// LOGLVL_WARNING
        12,	// LOGLVL_ERROR
        13	// LOGLVL_CRITICAL
	};

private:
    LogLevel _logLevel;     // Guarda el LogLevel o importancia del Log
	std::string _txt;       // Guarda el texto que se pretende mostrar en el Log (Independientemente del encabezado que se muestre).
    bool _isDetailed;       // True = muestra los atributos de la sección 'Información detallada' entre _logLevel y _txt.

    // Información detallada
    const char *_file,      // Guarda el nombre del archivo (y su ruta) desde el que se produce el Log.
        *_method;           // Guarda el nombre del método desde el que se produce el Log.
    int _line;              // Guarda el número de la linea desde la que se produce al Log.


public:
    Log(LogLevel logLvl, const char* file, int line, const char* method, const char* txt);
    Log(LogLevel logLvl, const char* txt);
    ~Log();

    /*
    Imprime los datos del Log en la consola del programa.
    */
    void printText();

private:
    /*
        Devuelve el _logLevel.
    */
    Log::LogLevel getLevel();
    /*
        Devuelve el texto que corresponde al _logLevel.
    */
    const char* getLevelString();
    /*
        Devuelve el texto que se pretende mostrar en el Log.
    */
    std::string getText();
    /*
        Devuelve el color que corresponde al _logLevel.
    */
    WORD getLevelColor();
    /*
        Devuelve si el log es detallado (_isDetailed) o no.
    */
    bool isDetailed();

    // Información detallada
    /*
        Devuelve el fichero del Log (_file).
    */
	const char* getFile();
    /*
        Devuelve la linea del Log (_line).
    */
    int getLine();
    /*
    * @brief Devuelve el Method del Log.
    * Devuelve el nombre del método desde el que se ejecuta el Log.
    * @return el nombre.
    */
    const char* getMethod();
};

/*
    Crea un Log Detallado:
        x = LogLevel
        f = __FILE__
        l = __LINE__
        m = __func__
        txt = Texto a mostrar
*/
#define _LOGDETAILED(x, f, l, m, txt) { \
	std::stringstream s; \
	s << txt; \
    gLog.addLog(new Log(x, f, l, m, s.str().c_str())); \
 }

/*
    Crea un Log Simple:
        x = LogLevel
        txt = Texto a mostrar
*/
#define _LOG(x, txt) { \
	std::stringstream s; \
	s << txt; \
    gLog.addLog(new Log(x, s.str().c_str())); \
 }

/*
    Crea un _LOGDETAILED del tipo LOGLVL_DEBUG
*/
#define _DEBUGLOG(txt) { \
    _LOGDETAILED(Log::LOGLVL_DEBUG, __FILE__, __LINE__, __func__, txt); \
}
/*
Crea un _LOGDETAILED del tipo LOGLVL_EVENT
*/
#define _EVENTLOG(txt) { \
    _LOGDETAILED(Log::LOGLVL_EVENT, __FILE__, __LINE__, __func__, txt); \
}
/*
Crea un _LOGDETAILED del tipo LOGLVL_WARNING
*/
#define _WARNINGLOG(txt) { \
    _LOGDETAILED(Log::LOGLVL_WARNING, __FILE__, __LINE__, __func__, txt); \
}
/*
Crea un _LOGDETAILED del tipo LOGLVL_ERROR
*/
#define _ERRORLOG(txt) { \
    _LOGDETAILED(Log::LOGLVL_ERROR, __FILE__, __LINE__, __func__, txt); \
}
/*
Crea un _LOGDETAILED del tipo LOGLVL_CRITICAL
*/
#define _CRITICALLOG(txt) { \
    _LOGDETAILED(Log::LOGLVL_CRITICAL, __FILE__, __LINE__, __func__, txt); \
}

