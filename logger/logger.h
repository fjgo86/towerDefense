#pragma once
#include <string>
#include <vector>
#include <windows.h> // WinApi header

class Log;

extern class Logger : public std::vector<Log*> {

private:

public:
	Logger();
	~Logger();

	/*
		A�ade un Log al vector de la clase.
	*/
    void addLog(Log* log);
	/*
		Ejecuta un tick del Logger (Env�a los Log existentes a la consola).
	*/
	void onTick();
	/*
		Borra todos los datos que hay dentro
	*/
	void clearData();
} gLog;