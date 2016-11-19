#pragma once

#include <windows.h>

// Abstract class for logging text.
class Logger
{
public:

	virtual void log(const WCHAR * format, ...);
	virtual void log(const CHAR * format, ...);

protected:

	virtual void write(const WCHAR * str) = 0;
	virtual void write(const CHAR * str);
};

// Dummy logger which does absolutely nothing
class DummyLogger : public Logger
{
public:
	DummyLogger() {};
private:
	void write(const WCHAR * str) {};
};

class FileLog : public Logger
{
public:

	FileLog(const WCHAR * fileName);

private:

	void write(const WCHAR * str);
	void write(const CHAR * str);

	WCHAR filePath[MAX_PATH];
};

class ListboxLog : public Logger
{
public:

	ListboxLog() : window(0) { }
	ListboxLog(HWND window);

	void setWindow(HWND window);

private:

	void write(const WCHAR * str);
	//void write(const CHAR * str);

	HWND window;
};
