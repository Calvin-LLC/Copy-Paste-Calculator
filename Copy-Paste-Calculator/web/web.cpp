#include "web.h"

#ifndef DEV__

std::string c_web::get(const char* url) {
	std::string return_value{};
	char* data{};
	DWORD dw_size{}, dw_bytes_read{};

	HINTERNET hInternet = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_PRECONFIG_WITH_NO_AUTOPROXY, NULL, NULL, NULL);
	HINTERNET hFile = InternetOpenUrlA(hInternet, url, NULL, NULL, INTERNET_FLAG_RELOAD | INTERNET_FLAG_DONT_CACHE | INTERNET_FLAG_SECURE | INTERNET_FLAG_PRAGMA_NOCACHE, NULL);

	if (hInternet && hFile) {
		do {
			char buffer[MAX_PATH]{};
			if (hFile) InternetReadFile(hFile, (LPVOID)buffer, _countof(buffer), &dw_bytes_read);
			char* c_temp = new char[dw_size + dw_bytes_read];
			memcpy(c_temp, data, dw_size);
			memcpy(c_temp + dw_size, buffer, dw_bytes_read);
			delete[] data;
			data = c_temp;
			dw_size += dw_bytes_read;
		} while (dw_bytes_read);
		return_value = std::string(data, dw_size);
		InternetCloseHandle(hFile);
		InternetCloseHandle(hInternet);
	}
	return return_value;
}

#endif