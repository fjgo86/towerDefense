#include <iostream>
#include "Log.h"

HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

Log::Log(LogLevel logLvl, const char* file, int line, const char* method, const char* txt) {
    if (logLvl >= Log::LOGLVL_QTY) {
        _logLevel = LogLevel(LOGLVL_QTY - 1);   // Comprobando que el LogLevel no exceda a los definidos, se pondrá por defecto al último LogLevel existente (el de más alta importancia).
    }
    else {
        _logLevel = logLvl;
    }
	_file = file;
    _line = line;
    _method = method;
    _isDetailed = true;
    _txt = txt;
}

Log::Log(LogLevel logLvl, const char* txt) {
    if (logLvl >= Log::LOGLVL_QTY) {
        _logLevel = LogLevel(LOGLVL_QTY - 1);   // Comprobando que el LogLevel no exceda a los definidos, se pondrá por defecto al último LogLevel existente (el de más alta importancia).
    }
    else {
        _logLevel = logLvl;
    }
    _file = "";
    _line = 0;
    _method = "";
    _isDetailed = false;
	_txt = txt;
}

Log::~Log() {
}

Log::LogLevel Log::getLevel() {
	return _logLevel;
}

const char * Log::getLevelString() {
	return LogLevelStrings[_logLevel];
}

std::string Log::getText() {
	return _txt;
}

WORD Log::getLevelColor() {
    return LogColor[_logLevel];
}

const char * Log::getFile() {
    return _file;
}

int Log::getLine() {
    return _line;
}

const char * Log::getMethod() {
    return _method;
}

bool Log::isDetailed() {
    return _isDetailed;
}

void Log::printText() {

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
    std::cout << getText();
}
