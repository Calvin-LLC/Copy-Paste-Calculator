#include <Windows.h>
#include <filesystem>

#pragma comment(lib, "winmm.lib")	// link playsound
#include "web/web.h"				// uses wininet lib
#include "clipboard.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int windowStyle) {

	// checks if the sound file exists, if not, it downloads it automatically
	if (!std::filesystem::exists("nice_beep.wav")) {
		URLDownloadToFile(NULL, L"https://www.calvinllc.net/nice_beep.wav", L"nice_beep.wav", NULL, NULL);
		MessageBox(0, L"Could't find nice beep file, downloaded it automatically", 0, MB_ICONINFORMATION);
	}

	// infinite loop 
	for (;!GetAsyncKeyState(VK_END); Sleep(200)) {

		// if u press f12 itll grab it from the API
		if (GetAsyncKeyState(VK_F12)) {
			std::string url = "https://api.mathjs.org/v4/?expr=";
			url.append(get_clipboard_text());
			copy_to_clipboard(web.get(url.c_str()));
			PlaySoundW(L"nice_beep.wav", NULL, SND_ASYNC | SND_FILENAME);
		}
	}
}