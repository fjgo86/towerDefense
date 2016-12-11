#pragma once
#include <string>
#include <windows.h> // WinApi header
#include <sstream>
#include <iostream>



/*
    Colores de salida
    * IMPORTANTE: Por ahora son solo válidos para Windows 10 (Versiones anteriores no admiten colores en el cmd), habría que dar soporte para unix más adelante.
*/

#define LogColorTextDefault 15      // Color para el texto normal.
#define LogColorFileDefault 10      // Color para el texto que muestra la ruta del fichero.
#define LogColorLineDefault 10      // Color para el texto que muestra la linea del Log.
#define LogColorMethodDefault 14    // Color para el texto que muestra el nombre del método desde el que se crea el Log.

/*
    Flags para los logs.
*/
#define LOGFLAG_DETAILED        0x01    // Envía información detallada sobre el fichero que envía el Log.
#define LOGFLAG_PRINTCONSOLE    0x02    // Envía el log a la consola.
//#define LOGFLAG_PRINTFILE       0x04    // Envía el log a un archivo físico.

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
    unsigned int _flags;    // Flags del Log.

    // Información detallada
    const char *_file,      // Guarda el nombre del archivo (y su ruta) desde el que se produce el Log.
        *_method;           // Guarda el nombre del método desde el que se produce el Log.
    int _line;              // Guarda el número de la linea desde la que se produce al Log.


public:
    Log(LogLevel logLvl, const char* file, int line, const char* method, const char* txt, unsigned int flags = LOGFLAG_PRINTCONSOLE) {
        if (logLvl >= Log::LOGLVL_QTY) {
            _logLevel = LogLevel(LOGLVL_QTY - 1);   // Comprobando que el LogLevel no exceda a los definidos, se pondrá por defecto al último LogLevel existente (el de más alta importancia).
        }
        else {
            _logLevel = logLvl;
        }
        _file = file;
        _line = line;
        _method = method;
        _txt = txt;
        _flags = flags;
        if (isFlag(LOGFLAG_DETAILED))
            _isDetailed = true;
        else
            _isDetailed = false;
    }
    Log(LogLevel logLvl, const char* txt, unsigned int flags = LOGFLAG_PRINTCONSOLE) {
        if (logLvl >= Log::LOGLVL_QTY) {
            _logLevel = LogLevel(LOGLVL_QTY - 1);   // Comprobando que el LogLevel no exceda a los definidos, se pondrá por defecto al último LogLevel existente (el de más alta importancia).
        }
        else {
            _logLevel = logLvl;
        }
        _file = "";
        _line = 0;
        _method = "";
        _txt = txt;
        _flags = flags;
        _isDetailed = false;
    }
    ~Log(){
    }

    /*
    Imprime los datos del Log en la consola del programa.
    */
    void printText() {
        //if (isFlag(LOGFLAG_PRINTCONSOLE)) {

            HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(consola, getLevelColor());          // Asigna el Log Level Color
            std::cout << getLevelString();                              // Imprime el Log Level Name

            if (isDetailed()) {
                SetConsoleTextAttribute(consola, LogColorFileDefault);  // Asigna el Log File Color a Default
                std::cout << getFile() << ":";                          // Imprime separador.

                SetConsoleTextAttribute(consola, LogColorLineDefault);  // Asigna el Log Line Color a Default
                std::cout << getLine() << ":";                          // Imprime separador.

                SetConsoleTextAttribute(consola, LogColorMethodDefault);// Asigna el Log Method Color a Default
                std::cout << getMethod() << " = ";                      // Imprime separador.
            }

            SetConsoleTextAttribute(consola, LogColorTextDefault);      // Asigna el Log Text Color a Default
            std::cout << getText() << std::endl;
        //}
        /*
        TODO: if (isFlag(LOGFLAG_PRINTFILE))
        */
    }

private:
    /*
        Devuelve el _logLevel.
    */
    Log::LogLevel getLevel() {
        return _logLevel;
    }
    /*
        Devuelve el texto que corresponde al _logLevel.
    */
    const char* getLevelString() {
        return LogLevelStrings[_logLevel];
    }
    /*
        Devuelve el texto que se pretende mostrar en el Log.
    */
    std::string getText() {
        return _txt;
    }
    /*
        Devuelve el color que corresponde al _logLevel.
    */
    WORD getLevelColor() {
        return LogColor[_logLevel];
    }
    /*
        Devuelve si el log es detallado (_isDetailed) o no.
    */
    bool isDetailed() {
        return _isDetailed;
    }

    // Información detallada
    /*
        Devuelve el fichero del Log (_file).
    */
	const char* getFile() {
        return _file;
    }
    /*
        Devuelve la linea del Log (_line).
    */
    int getLine() {
        return _line;
    }
    /*
    * @brief Devuelve el Method del Log.
    * Devuelve el nombre del método desde el que se ejecuta el Log.
    * @return el nombre.
    */
    const char* getMethod() {
        return _method;
    }
    /*
    * @brief Comprueba si tiene el flag especificado.
    * @param flag
    * @return true si lo tiene, false si no.
    */
    bool isFlag(int flag) {
        return (_flags & flag) ? true : false;
    }
};