#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <Windows.h>
#include <string>

std::string get_clipboard_text() {
	OpenClipboard(nullptr);
	HANDLE hData = GetClipboardData(CF_TEXT);
	char* pszText = static_cast<char*>(GlobalLock(hData));
	std::string text(pszText);
	GlobalUnlock(hData);
	CloseClipboard();

	return text;
}

void copy_to_clipboard(std::string text) {
	const size_t len = strlen(text.c_str()) + 1;
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(hMem), text.c_str(), len);
	GlobalUnlock(hMem);
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
}

#endif