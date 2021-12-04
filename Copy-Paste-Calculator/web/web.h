#ifndef WEB_H
#define WEB_H

#include <Windows.h>
#include <tchar.h>
#include <string>
#include <thread>
#include <iostream>

#include "urlmon.h" 
#pragma comment (lib, "urlmon.lib")

#include <WinInet.h>
#pragma comment (lib, "Wininet.lib")

class c_web {
public:
	c_web() = default;
	~c_web() = default;

	std::string get(const char* url);
};
extern inline auto web = c_web();

#endif