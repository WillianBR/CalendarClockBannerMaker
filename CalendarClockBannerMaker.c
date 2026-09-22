#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include <windowsx.h>
#include <commdlg.h>
#include <shellapi.h>
#include <shlobj.h>
#include <objidl.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#include "resource.h"

/* ============================== CONSTANTS ================================= */

#define APP_CLASS_NAME              L"CalendarClockBannerMakerWindow"
#define APP_WINDOW_TITLE            L"Calendar & Clock Banner Builder v3.2"
#define APP_ABOUT_TITLE             L"About - Calendar & Clock Banner Builder"
#define APP_ABOUT_TEXT              L"Calendar & Clock Banner Builder v3.2\tCopyright (c) 2026 Willian Silva Rodrigues (@WillianBR).\tAll rights reserved."
#define APP_URL_TEXT                L"https://github.com/WillianBR/CalendarClockBannerMaker.git"
#define APP_SAVE_FILTER             L"PNG Image (*.png)\0*.png\0All files (*.*)\0*.*\0\0"
#define APP_SAVE_DEFAULT_EXT        L"png"
#define APP_SAVE_DEFAULT_NAME       L"CalendarClockBanner.png"
#define APP_SAVE_ERROR              L"Unable to save the PNG image."
#define APP_COPY_ERROR              L"Unable to copy the image to the Clipboard."
#define APP_GDIPLUS_ERROR           L"Unable to initialize GDI+."
#define APP_TRAY_TOOLTIP            L"Calendar & Clock Banner Builder"
#define APP_MENU_FILE               L"&File"
#define APP_MENU_EDIT               L"&Edit"
#define APP_MENU_HELP               L"&Help"
#define APP_MENU_SAVE               L"&Save\tCtrl+S"
#define APP_MENU_EXIT               L"E&xit"
#define APP_MENU_COPY               L"&Copy\tCtrl+C"
#define APP_MENU_ABOUT              L"&About"
#define APP_TRAY_SHOW               L"&Show"
#define APP_TRAY_EXIT               L"E&xit"
#define APP_PNG_CLIPBOARD_FORMAT    L"PNG"
#define APP_SINGLE_INSTANCE_MUTEX   L"Local\\CalendarClockBannerMaker-{98430947-1979-0502-9905-202610341461}"
#define APP_EXISTING_WINDOW_RETRIES 40
#define APP_EXISTING_WINDOW_DELAY_MS 50
#define APP_INI_EXTENSION            L".ini"
#define APP_INI_GENERAL_SECTION      L"General"
#define APP_INI_VERSION_KEY          L"Version"
#define APP_INI_VERSION_VALUE        L"3.1"
#define APP_INI_NAME_KEY             L"Name"
#define APP_INI_TIMEZONE_KEY         L"TimeZone"
#define FORMAT_CLOCK_LABEL           L"%s (%s)"
#define CLOCK_INVALID_DAY            L"???"
#define FORMAT_DIGITAL_TIME          L"%02u:%02u"
#define APP_STARTUP_LINK_NAME         L"CalendarClockBannerMaker.lnk"
#define APP_STARTUP_DESCRIPTION       L"Calendar & Clock Banner Builder"
#define GDIPLUS_DLL_NAME             L"gdiplus.dll"
#define KERNEL32_DLL_NAME            L"kernel32.dll"
#define ADVAPI32_DLL_NAME            L"advapi32.dll"
#define TIMEZONE_REGISTRY_BASE       L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Time Zones\\"
#define TIMEZONE_DYNAMIC_DST         L"\\Dynamic DST"
#define TIMEZONE_TZI_VALUE           L"TZI"
#define PROC_REG_OPEN_KEY_EX_W       "RegOpenKeyExW"
#define PROC_REG_QUERY_VALUE_EX_W    "RegQueryValueExW"
#define PROC_REG_CLOSE_KEY           "RegCloseKey"
#define FORMAT_YEAR_VALUE            L"%u"
#define GDIPLUS_PROC_START           "GdiplusStartup"
#define GDIPLUS_PROC_SHUTDOWN        "GdiplusShutdown"
#define GDIPLUS_PROC_CREATE_BITMAP   "GdipCreateBitmapFromHBITMAP"
#define GDIPLUS_PROC_SAVE_FILE       "GdipSaveImageToFile"
#define GDIPLUS_PROC_SAVE_STREAM     "GdipSaveImageToStream"
#define GDIPLUS_PROC_DISPOSE_IMAGE   "GdipDisposeImage"
#define GDIPLUS_PROC_SET_RESOLUTION  "GdipBitmapSetResolution"
#define FONT_ARIAL                  L"Arial"
#define FONT_COURIER_NEW            L"Courier New"
#define FORMAT_DAY_NUMBER           L"%d"
#define FORMAT_MONTH_YEAR           L"%s %04u"
#define CLOCK_LABEL_BR              L"BR"
#define CLOCK_LABEL_LA_US           L"LA_US"
#define CLOCK_LABEL_NY_US           L"NY_US"
#define CLOCK_LABEL_LON_UK          L"LON_UK"
#define CLOCK_LABEL_FRA_DE          L"FRA_DE"
#define CLOCK_LABEL_MSK_RU          L"MSK_RU"
#define CLOCK_LABEL_SHA_CN          L"SHA_CN"
#define CLOCK_LABEL_TYO_JP          L"TYO_JP"

#define TIMEZONE_BRAZIL             L"E. South America Standard Time"
#define TIMEZONE_LOS_ANGELES        L"Pacific Standard Time"
#define TIMEZONE_NEW_YORK           L"Eastern Standard Time"
#define TIMEZONE_LONDON             L"GMT Standard Time"
#define TIMEZONE_FRANKFURT          L"W. Europe Standard Time"
#define TIMEZONE_MOSCOW             L"Russian Standard Time"
#define TIMEZONE_SHANGHAI           L"China Standard Time"
#define TIMEZONE_TOKYO              L"Tokyo Standard Time"

#define INI_SECTION_CLOCK2          L"Clock2"
#define INI_SECTION_CLOCK3          L"Clock3"
#define INI_SECTION_CLOCK4          L"Clock4"
#define INI_SECTION_CLOCK5          L"Clock5"
#define INI_SECTION_CLOCK6          L"Clock6"
#define INI_SECTION_CLOCK7          L"Clock7"
#define INI_SECTION_CLOCK8          L"Clock8"

static const wchar_t *const WEEKDAY_NAMES[7] =
{
    L"Sun", L"Mon", L"Tue", L"Wed", L"Thu", L"Fri", L"Sat"
}
;
static const wchar_t *const MONTH_NAMES[12] =
{
    L"January", L"February", L"March", L"April", L"May", L"June", L"July", L"August", L"September", L"October", L"November", L"December"
}
;

#define APP_CLIENT_WIDTH            1024
#define APP_CLIENT_HEIGHT           600
#define APP_MIN_CLIENT_WIDTH        900
#define APP_MIN_CLIENT_HEIGHT       520
#define WINDOW_MARGIN_RIGHT         12
#define WINDOW_MARGIN_BOTTOM        12
#define TIMER_ID_MINUTE             1
#define TIMER_INTERVAL_MS           60000U
#define TRAY_ICON_ID                1U
#define WM_APP_TRAY                 (WM_APP + 10U)
#define EXPORT_DPI                  96U
#define BITS_PER_PIXEL              32U
#define CLOCK_AREA_PERCENT          43
#define CLOCK_COLUMNS               2
#define CONTENT_MARGIN              16
#define SECTION_GAP                 12
#define FOOTER_HEIGHT               34
#define CALENDAR_HEADER_HEIGHT      52
#define CALENDAR_WEEKDAY_HEIGHT     32
#define CALENDAR_ROWS               6
#define CALENDAR_COLUMNS            7
#define CLOCK_TICKS                 60
#define CLOCK_HOURS                 12
#define CLOCK_MAJOR_TICK_EVERY      5
#define CLOCK_OUTER_PEN_WIDTH       3
#define CLOCK_MAJOR_TICK_WIDTH      3
#define CLOCK_MINOR_TICK_WIDTH      1
#define CLOCK_HOUR_HAND_WIDTH       6
#define CLOCK_MINUTE_HAND_WIDTH     4
#define CLOCK_CENTER_RADIUS         6
#define CLOCK_MIN_RADIUS            36
#define CALENDAR_BORDER_WIDTH       1
#define FOOTER_FONT_PT              11
#define WEEKDAY_FONT_PT             11
#define DAY_FONT_PT                 13
#define MONTH_FONT_PT               18
#define CLOCK_NUMBER_FONT_PT        8
#define CLOCK_LABEL_FONT_PT         9
#define CLOCK_DIGITAL_FONT_PT       10
#define CLOCK_COUNT                 8
#define CLOCK_LABEL_HEIGHT          16
#define CLOCK_DIGITAL_HEIGHT        18
#define CLOCK_INFO_HEIGHT           (CLOCK_DIGITAL_HEIGHT + CLOCK_LABEL_HEIGHT)
#define CLOCK_VERTICAL_GAP          4
#define CLOCK_HORIZONTAL_GAP        8
#define CLOCK_LABEL_GAP             2
#define PI_VALUE                    3.14159265358979323846
#define FULL_CIRCLE_RADIANS         (2.0 * PI_VALUE)
#define HALF_PI_RADIANS             (PI_VALUE / 2.0)
#define CLOCK_FACE_RADIUS_FACTOR    0.45
#define CLOCK_NUMBER_RADIUS_FACTOR  0.70
#define CLOCK_MINOR_TICK_INNER      0.88
#define CLOCK_MAJOR_TICK_INNER      0.82
#define CLOCK_TICK_OUTER            0.96
#define CLOCK_HOUR_HAND_FACTOR      0.53
#define CLOCK_MINUTE_HAND_FACTOR    0.76
#define PNG_ENCODER_CLSID_D1        0x557cf406
#define PNG_ENCODER_CLSID_D2        0x1a04
#define PNG_ENCODER_CLSID_D3        0x11d3
#define GDIPLUS_VERSION             1U
#define GDIPLUS_OK                  0
#define PNG_MEMORY_GROW_BYTES       0U
#define DIB_HEADER_SIZE             ((DWORD)sizeof(BITMAPINFOHEADER))

#define COLOR_WINDOW_BG             RGB(238, 242, 247)
#define COLOR_CALENDAR_BG           RGB(255, 255, 255)
#define COLOR_CALENDAR_BORDER       RGB(190, 198, 208)
#define COLOR_TEXT_NORMAL           RGB(20, 20, 20)
#define COLOR_SUNDAY                RGB(210, 0, 0)
#define COLOR_SATURDAY              RGB(0, 70, 210)
#define COLOR_TODAY_BG              RGB(0, 90, 210)
#define COLOR_TODAY_TEXT            RGB(255, 230, 0)
#define COLOR_CLOCK_FACE            RGB(255, 255, 255)
#define COLOR_CLOCK_OUTLINE         RGB(35, 35, 35)
#define COLOR_CLOCK_TICKS           RGB(70, 70, 70)
#define COLOR_CLOCK_NUMBERS         RGB(20, 20, 20)
#define COLOR_HOUR_HAND             RGB(0, 70, 190)
#define COLOR_MINUTE_HAND           RGB(0, 145, 70)
#define COLOR_CLOCK_CENTER          RGB(25, 25, 25)
#define COLOR_FOOTER_TEXT           RGB(55, 55, 55)
#define COLOR_CLOCK_LABEL           RGB(25, 25, 25)
#define COLOR_CLOCK_DIGITAL         RGB(25, 25, 25)

/* Minimal GDI+ flat API declarations, loaded dynamically from gdiplus.dll. */
typedef void GpImage;
typedef void GpBitmap;
typedef int GpStatus;
typedef struct GdiplusStartupInputC
{
    UINT32 GdiplusVersion;
    void *DebugEventCallback;
    BOOL SuppressBackgroundThread;
    BOOL SuppressExternalCodecs;
}
GdiplusStartupInputC;
typedef GpStatus(WINAPI *PFN_GdiplusStartup)(ULONG_PTR *, const GdiplusStartupInputC *, void *);
typedef void (WINAPI *PFN_GdiplusShutdown)(ULONG_PTR);
typedef GpStatus(WINAPI *PFN_GdipCreateBitmapFromHBITMAP)(HBITMAP, HPALETTE, GpBitmap **);
typedef GpStatus(WINAPI *PFN_GdipSaveImageToFile)(GpImage *, const WCHAR *, const CLSID *, const void *);
typedef GpStatus(WINAPI *PFN_GdipSaveImageToStream)(GpImage *, IStream *, const CLSID *, const void *);
typedef GpStatus(WINAPI *PFN_GdipDisposeImage)(GpImage *);
typedef GpStatus(WINAPI *PFN_GdipBitmapSetResolution)(GpBitmap *, float, float);

static const CLSID PNG_ENCODER_CLSID =
{
    PNG_ENCODER_CLSID_D1, PNG_ENCODER_CLSID_D2, PNG_ENCODER_CLSID_D3, {
        0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e
    }
}
;

typedef struct ClockConfig
{
    const wchar_t *label;
    const wchar_t *timeZoneKey;
}
ClockConfig;

static const ClockConfig CLOCK_CONFIG[CLOCK_COUNT] =
{
    { CLOCK_LABEL_BR,     TIMEZONE_BRAZIL },
    { CLOCK_LABEL_LA_US,  TIMEZONE_LOS_ANGELES },
    { CLOCK_LABEL_NY_US,  TIMEZONE_NEW_YORK },
    { CLOCK_LABEL_LON_UK, TIMEZONE_LONDON },
    { CLOCK_LABEL_FRA_DE, TIMEZONE_FRANKFURT },
    { CLOCK_LABEL_MSK_RU, TIMEZONE_MOSCOW },
    { CLOCK_LABEL_SHA_CN, TIMEZONE_SHANGHAI },
    { CLOCK_LABEL_TYO_JP, TIMEZONE_TOKYO }
};

static const wchar_t *const INI_CLOCK_SECTIONS[CLOCK_COUNT] =
{
    NULL,
    INI_SECTION_CLOCK2,
    INI_SECTION_CLOCK3,
    INI_SECTION_CLOCK4,
    INI_SECTION_CLOCK5,
    INI_SECTION_CLOCK6,
    INI_SECTION_CLOCK7,
    INI_SECTION_CLOCK8
};

typedef struct AppState
{
    HWND hwnd;
    HINSTANCE instance;
    HDC backDC;
    HBITMAP backBitmap;
    HBITMAP backOldBitmap;
    int backW, backH;
    HDC calendarDC;
    HBITMAP calendarBitmap;
    HBITMAP calendarOldBitmap;
    int calendarW, calendarH;
    WORD cachedYear, cachedMonth, cachedDay;
    SYSTEMTIME utcNow;
    SYSTEMTIME clockTimes[CLOCK_COUNT];
    TIME_ZONE_INFORMATION timeZones[CLOCK_COUNT];
    BOOL timeZoneValid[CLOCK_COUNT];
    wchar_t clockNames[CLOCK_COUNT][32];
    wchar_t clockTimeZoneKeys[CLOCK_COUNT][128];
    wchar_t iniPath[MAX_PATH];
    NOTIFYICONDATAW tray;
    UINT pngClipboardFormat;
    HMODULE gdiplusModule;
    ULONG_PTR gdiplusToken;
    PFN_GdiplusShutdown pGdiplusShutdown;
    PFN_GdipCreateBitmapFromHBITMAP pCreateBitmap;
    PFN_GdipSaveImageToFile pSaveFile;
    PFN_GdipSaveImageToStream pSaveStream;
    PFN_GdipDisposeImage pDisposeImage;
    PFN_GdipBitmapSetResolution pSetResolution;
}
AppState;

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static int min_i(int a, int b)
{
    return a < b ? a : b;
}

static int points_to_pixels(HDC dc, int pt)
{
    return -MulDiv(pt, GetDeviceCaps(dc, LOGPIXELSY), 72);
}

static HFONT make_font(HDC dc, const wchar_t *face, int pt, int weight)
{
    return CreateFontW(points_to_pixels(dc, pt), 0, 0, 0, weight, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, face);
}

static int days_in_month(WORD y, WORD m)
{
    static const int d[12] =
    {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    }
    ;
    int n = d[m - 1];
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
        n = 29;
    return n;
}

static int weekday_of_date(WORD y, WORD m, WORD d)
{
    SYSTEMTIME st =
    {
        0
    }
    ;
    FILETIME ft;
    st.wYear = y;
    st.wMonth = m;
    st.wDay = d;
    if (!SystemTimeToFileTime(&st, &ft))
        return 0;
    ULARGE_INTEGER u;
    u.LowPart = ft.dwLowDateTime;
    u.HighPart = ft.dwHighDateTime;
    return (int)((u.QuadPart / 10000000ULL / 86400ULL + 1ULL) % 7ULL);
}

static void destroy_surface(HDC *dc, HBITMAP *bmp, HBITMAP *old)
{
    if (*dc)
    {
        if (*old)
            SelectObject(*dc, *old);
        if (*bmp)
            DeleteObject(*bmp);
        DeleteDC(*dc);
    }
    *dc = NULL;
    *bmp = NULL;
    *old = NULL;
}

static BOOL ensure_surface(HDC ref, HDC *dc, HBITMAP *bmp, HBITMAP *old, int *cw, int *ch, int w, int h)
{
    if (*dc && *bmp && *cw == w && *ch == h)
        return TRUE;
    destroy_surface(dc, bmp, old);
    *dc = CreateCompatibleDC(ref);
    if (!*dc)
        return FALSE;
    *bmp = CreateCompatibleBitmap(ref, w, h);
    if (!*bmp)
    {
        destroy_surface(dc, bmp, old);
        return FALSE;
    }
    *old = (HBITMAP)SelectObject(*dc, *bmp);
    *cw = w;
    *ch = h;
    return TRUE;
}

static void assign_proc_address(void *destination, FARPROC source)
{
    memcpy(destination, &source, sizeof(source));
}

static BOOL gdiplus_start(AppState *s)
{
    GdiplusStartupInputC in =
    {
        GDIPLUS_VERSION, NULL, FALSE, FALSE
    }
    ;
    PFN_GdiplusStartup start = NULL;
    FARPROC proc;

    s->gdiplusModule = LoadLibraryW(GDIPLUS_DLL_NAME);
    if (!s->gdiplusModule)
        return FALSE;

    proc = GetProcAddress(s->gdiplusModule, GDIPLUS_PROC_START);
    assign_proc_address(&start, proc);
    proc = GetProcAddress(s->gdiplusModule, GDIPLUS_PROC_SHUTDOWN);
    assign_proc_address(&s->pGdiplusShutdown, proc);
    proc = GetProcAddress(s->gdiplusModule, GDIPLUS_PROC_CREATE_BITMAP);
    assign_proc_address(&s->pCreateBitmap, proc);
    proc = GetProcAddress(s->gdiplusModule, GDIPLUS_PROC_SAVE_FILE);
    assign_proc_address(&s->pSaveFile, proc);
    proc = GetProcAddress(s->gdiplusModule, GDIPLUS_PROC_SAVE_STREAM);
    assign_proc_address(&s->pSaveStream, proc);
    proc = GetProcAddress(s->gdiplusModule, GDIPLUS_PROC_DISPOSE_IMAGE);
    assign_proc_address(&s->pDisposeImage, proc);
    proc = GetProcAddress(s->gdiplusModule, GDIPLUS_PROC_SET_RESOLUTION);
    assign_proc_address(&s->pSetResolution, proc);

    if (!start || !s->pGdiplusShutdown || !s->pCreateBitmap || !s->pSaveFile ||
            !s->pSaveStream || !s->pDisposeImage || !s->pSetResolution)
        return FALSE;
    return start(&s->gdiplusToken, &in, NULL) == GDIPLUS_OK;
}

static void gdiplus_stop(AppState *s)
{
    if (s->gdiplusToken && s->pGdiplusShutdown)
        s->pGdiplusShutdown(s->gdiplusToken);
    if (s->gdiplusModule)
        FreeLibrary(s->gdiplusModule);
}

typedef struct RegistryTziFormat
{
    LONG bias;
    LONG standardBias;
    LONG daylightBias;
    SYSTEMTIME standardDate;
    SYSTEMTIME daylightDate;
} RegistryTziFormat;

typedef LSTATUS(WINAPI *PFN_RegOpenKeyExW)(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY);
typedef LSTATUS(WINAPI *PFN_RegQueryValueExW)(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD);
typedef LSTATUS(WINAPI *PFN_RegCloseKey)(HKEY);

static BOOL query_registry_binary(
    PFN_RegQueryValueExW queryValue,
    HKEY key,
    const wchar_t *valueName,
    void *buffer,
    DWORD bufferSize)
{
    DWORD type = 0;
    DWORD size = bufferSize;

    if (queryValue(key, valueName, NULL, &type, (LPBYTE)buffer, &size) != ERROR_SUCCESS)
    {
        return FALSE;
    }

    return type == REG_BINARY && size == bufferSize;
}

static BOOL load_time_zone_for_year(
    const wchar_t *timeZoneKey,
    WORD year,
    TIME_ZONE_INFORMATION *result)
{
    HMODULE advapi32Module;
    PFN_RegOpenKeyExW openKey = NULL;
    PFN_RegQueryValueExW queryValue = NULL;
    PFN_RegCloseKey closeKey = NULL;
    FARPROC proc;
    wchar_t registryPath[256];
    wchar_t dynamicPath[300];
    wchar_t yearName[16];
    HKEY zoneKey = NULL;
    HKEY dynamicKey = NULL;
    RegistryTziFormat tzi;
    BOOL loaded = FALSE;

    if (!timeZoneKey || !result)
    {
        return FALSE;
    }

    advapi32Module = LoadLibraryW(ADVAPI32_DLL_NAME);
    if (!advapi32Module)
    {
        return FALSE;
    }

    proc = GetProcAddress(advapi32Module, PROC_REG_OPEN_KEY_EX_W);
    assign_proc_address(&openKey, proc);
    proc = GetProcAddress(advapi32Module, PROC_REG_QUERY_VALUE_EX_W);
    assign_proc_address(&queryValue, proc);
    proc = GetProcAddress(advapi32Module, PROC_REG_CLOSE_KEY);
    assign_proc_address(&closeKey, proc);

    if (!openKey || !queryValue || !closeKey)
    {
        FreeLibrary(advapi32Module);
        return FALSE;
    }

    lstrcpyW(registryPath, TIMEZONE_REGISTRY_BASE);
    lstrcatW(registryPath, timeZoneKey);

    if (openKey(HKEY_LOCAL_MACHINE, registryPath, 0, KEY_READ, &zoneKey) != ERROR_SUCCESS)
    {
        FreeLibrary(advapi32Module);
        return FALSE;
    }

    ZeroMemory(&tzi, sizeof(tzi));

    lstrcpyW(dynamicPath, registryPath);
    lstrcatW(dynamicPath, TIMEZONE_DYNAMIC_DST);
    wsprintfW(yearName, FORMAT_YEAR_VALUE, (unsigned)year);

    if (openKey(HKEY_LOCAL_MACHINE, dynamicPath, 0, KEY_READ, &dynamicKey) == ERROR_SUCCESS)
    {
        loaded = query_registry_binary(queryValue, dynamicKey, yearName, &tzi, sizeof(tzi));
        closeKey(dynamicKey);
        dynamicKey = NULL;
    }

    if (!loaded)
    {
        loaded = query_registry_binary(queryValue, zoneKey, TIMEZONE_TZI_VALUE, &tzi, sizeof(tzi));
    }

    closeKey(zoneKey);
    FreeLibrary(advapi32Module);

    if (!loaded)
    {
        return FALSE;
    }

    ZeroMemory(result, sizeof(*result));
    result->Bias = tzi.bias;
    result->StandardBias = tzi.standardBias;
    result->DaylightBias = tzi.daylightBias;
    result->StandardDate = tzi.standardDate;
    result->DaylightDate = tzi.daylightDate;
    return TRUE;
}

static void build_ini_path(wchar_t *path, DWORD capacity)
{
    wchar_t *lastSlash;
    wchar_t *lastDot;

    if (!path || capacity == 0)
    {
        return;
    }

    path[0] = L'\0';
    if (GetModuleFileNameW(NULL, path, capacity) == 0)
    {
        return;
    }

    lastSlash = wcsrchr(path, L'\\');
    lastDot = wcsrchr(path, L'.');

    if (lastDot && (!lastSlash || lastDot > lastSlash))
    {
        *lastDot = L'\0';
    }

    if ((DWORD)(lstrlenW(path) + lstrlenW(APP_INI_EXTENSION) + 1) < capacity)
    {
        lstrcatW(path, APP_INI_EXTENSION);
    }
}

static void copy_default_clock_config(AppState *s)
{
    int i;

    for (i = 0; i < CLOCK_COUNT; ++i)
    {
        lstrcpynW(s->clockNames[i], CLOCK_CONFIG[i].label, ARRAYSIZE(s->clockNames[i]));
        lstrcpynW(s->clockTimeZoneKeys[i],
                  CLOCK_CONFIG[i].timeZoneKey,
                  ARRAYSIZE(s->clockTimeZoneKeys[i]));
    }
}

static void create_default_ini(const AppState *s)
{
    int i;

    WritePrivateProfileStringW(APP_INI_GENERAL_SECTION,
                               APP_INI_VERSION_KEY,
                               APP_INI_VERSION_VALUE,
                               s->iniPath);

    for (i = 1; i < CLOCK_COUNT; ++i)
    {
        WritePrivateProfileStringW(INI_CLOCK_SECTIONS[i],
                                   APP_INI_NAME_KEY,
                                   CLOCK_CONFIG[i].label,
                                   s->iniPath);
        WritePrivateProfileStringW(INI_CLOCK_SECTIONS[i],
                                   APP_INI_TIMEZONE_KEY,
                                   CLOCK_CONFIG[i].timeZoneKey,
                                   s->iniPath);
    }
}

static void load_clock_configuration(AppState *s)
{
    int i;
    DWORD attributes;

    copy_default_clock_config(s);
    build_ini_path(s->iniPath, ARRAYSIZE(s->iniPath));

    if (s->iniPath[0] == L'\0')
    {
        return;
    }

    attributes = GetFileAttributesW(s->iniPath);
    if (attributes == INVALID_FILE_ATTRIBUTES)
    {
        create_default_ini(s);
        return;
    }

    for (i = 1; i < CLOCK_COUNT; ++i)
    {
        GetPrivateProfileStringW(INI_CLOCK_SECTIONS[i],
                                 APP_INI_NAME_KEY,
                                 CLOCK_CONFIG[i].label,
                                 s->clockNames[i],
                                 ARRAYSIZE(s->clockNames[i]),
                                 s->iniPath);

        GetPrivateProfileStringW(INI_CLOCK_SECTIONS[i],
                                 APP_INI_TIMEZONE_KEY,
                                 CLOCK_CONFIG[i].timeZoneKey,
                                 s->clockTimeZoneKeys[i],
                                 ARRAYSIZE(s->clockTimeZoneKeys[i]),
                                 s->iniPath);
    }

    /* Clock 0 (BR) is deliberately fixed and never read from the INI file. */
    lstrcpynW(s->clockNames[0], CLOCK_LABEL_BR, ARRAYSIZE(s->clockNames[0]));
    lstrcpynW(s->clockTimeZoneKeys[0],
              TIMEZONE_BRAZIL,
              ARRAYSIZE(s->clockTimeZoneKeys[0]));
}

static void initialize_time_zones(AppState *s)
{
    int i;
    SYSTEMTIME utcNow;

    GetSystemTime(&utcNow);

    for (i = 0; i < CLOCK_COUNT; ++i)
    {
        s->timeZoneValid[i] = load_time_zone_for_year(
                                  s->clockTimeZoneKeys[i],
                                  utcNow.wYear,
                                  &s->timeZones[i]);
    }
}

static void update_clock_times(AppState *s)
{
    int i;

    GetSystemTime(&s->utcNow);

    for (i = 0; i < CLOCK_COUNT; ++i)
    {
        if (!s->timeZoneValid[i])
        {
            ZeroMemory(&s->clockTimes[i], sizeof(s->clockTimes[i]));
            continue;
        }

        if (!SystemTimeToTzSpecificLocalTime(
                    &s->timeZones[i],
                    &s->utcNow,
                    &s->clockTimes[i]))
        {
            ZeroMemory(&s->clockTimes[i], sizeof(s->clockTimes[i]));
        }
    }
}

static void make_clock_label(
    const AppState *s,
    int index,
    wchar_t *buffer,
    int bufferCount)
{
    const wchar_t *dayName;

    if (!buffer || bufferCount <= 0 || index < 0 || index >= CLOCK_COUNT)
    {
        return;
    }

    dayName = CLOCK_INVALID_DAY;
    if (s->timeZoneValid[index] && s->clockTimes[index].wDayOfWeek < 7)
    {
        dayName = WEEKDAY_NAMES[s->clockTimes[index].wDayOfWeek];
    }

    wsprintfW(buffer, FORMAT_CLOCK_LABEL, s->clockNames[index], dayName);
}

static BOOL ensure_startup_shortcut(void)
{
    wchar_t exePath[MAX_PATH];
    wchar_t startupPath[MAX_PATH];
    wchar_t linkPath[MAX_PATH];
    wchar_t workingDirectory[MAX_PATH];
    wchar_t *lastSlash;
    IShellLinkW *shellLink = NULL;
    IPersistFile *persistFile = NULL;
    HRESULT hr;
    BOOL success = FALSE;

    if (GetModuleFileNameW(NULL, exePath, ARRAYSIZE(exePath)) == 0)
    {
        return FALSE;
    }

    if (FAILED(SHGetFolderPathW(NULL,
                                CSIDL_STARTUP | CSIDL_FLAG_CREATE,
                                NULL,
                                SHGFP_TYPE_CURRENT,
                                startupPath)))
    {
        return FALSE;
    }

    if (lstrlenW(startupPath) + 1 + lstrlenW(APP_STARTUP_LINK_NAME) + 1 > MAX_PATH)
    {
        return FALSE;
    }

    lstrcpyW(linkPath, startupPath);
    lstrcatW(linkPath, L"\\");
    lstrcatW(linkPath, APP_STARTUP_LINK_NAME);

    lstrcpynW(workingDirectory, exePath, ARRAYSIZE(workingDirectory));
    lastSlash = wcsrchr(workingDirectory, L'\\');
    if (lastSlash)
    {
        *lastSlash = L'\0';
    }

    hr = CoCreateInstance(&CLSID_ShellLink,
                          NULL,
                          CLSCTX_INPROC_SERVER,
                          &IID_IShellLinkW,
                          (void **)&shellLink);
    if (FAILED(hr) || !shellLink)
    {
        return FALSE;
    }

    hr = shellLink->lpVtbl->SetPath(shellLink, exePath);
    if (SUCCEEDED(hr))
    {
        hr = shellLink->lpVtbl->SetWorkingDirectory(shellLink, workingDirectory);
    }
    if (SUCCEEDED(hr))
    {
        hr = shellLink->lpVtbl->SetDescription(shellLink, APP_STARTUP_DESCRIPTION);
    }
    if (SUCCEEDED(hr))
    {
        hr = shellLink->lpVtbl->QueryInterface(shellLink,
                                               &IID_IPersistFile,
                                               (void **)&persistFile);
    }
    if (SUCCEEDED(hr) && persistFile)
    {
        hr = persistFile->lpVtbl->Save(persistFile, linkPath, TRUE);
        success = SUCCEEDED(hr);
    }

    if (persistFile)
    {
        persistFile->lpVtbl->Release(persistFile);
    }
    shellLink->lpVtbl->Release(shellLink);

    return success;
}

static void draw_hand(HDC dc, int cx, int cy, double angle, int len, int width, COLORREF color)
{
    HPEN p = CreatePen(PS_SOLID, width, color), old = (HPEN)SelectObject(dc, p);
    MoveToEx(dc, cx, cy, NULL);
    LineTo(dc, cx + (int)(cos(angle)*len), cy + (int)(sin(angle)*len));
    SelectObject(dc, old);
    DeleteObject(p);
}

static void draw_clock(HDC dc, const RECT *r, const SYSTEMTIME *t, const wchar_t *label)
{
    int w = r->right - r->left, h = r->bottom - r->top, cx = (r->left + r->right) / 2, cy = (r->top + r->bottom - CLOCK_INFO_HEIGHT) / 2, rad = (int)(min_i(w, h - CLOCK_INFO_HEIGHT) * CLOCK_FACE_RADIUS_FACTOR);
    if (rad < CLOCK_MIN_RADIUS)
        rad = CLOCK_MIN_RADIUS;
    HBRUSH face = CreateSolidBrush(COLOR_CLOCK_FACE), oldb = (HBRUSH)SelectObject(dc, face);
    HPEN out = CreatePen(PS_SOLID, CLOCK_OUTER_PEN_WIDTH, COLOR_CLOCK_OUTLINE), oldp = (HPEN)SelectObject(dc, out);
    Ellipse(dc, cx - rad, cy - rad, cx + rad, cy + rad);
    SelectObject(dc, oldb);
    DeleteObject(face);
    SelectObject(dc, oldp);
    DeleteObject(out);
    HPEN thin = CreatePen(PS_SOLID, CLOCK_MINOR_TICK_WIDTH, COLOR_CLOCK_TICKS), thick = CreatePen(PS_SOLID, CLOCK_MAJOR_TICK_WIDTH, COLOR_CLOCK_TICKS);
    for (int i = 0; i < CLOCK_TICKS; i++)
    {
        BOOL major = (i % CLOCK_MAJOR_TICK_EVERY) == 0;
        double a = i * FULL_CIRCLE_RADIANS / CLOCK_TICKS - HALF_PI_RADIANS;
        int r1 = (int)(rad * (major ? CLOCK_MAJOR_TICK_INNER : CLOCK_MINOR_TICK_INNER)), r2 = (int)(rad * CLOCK_TICK_OUTER);
        HPEN p = (HPEN)SelectObject(dc, major ? thick : thin);
        MoveToEx(dc, cx + (int)(cos(a)*r1), cy + (int)(sin(a)*r1), NULL);
        LineTo(dc, cx + (int)(cos(a)*r2), cy + (int)(sin(a)*r2));
        SelectObject(dc, p);
    }
    DeleteObject(thin);
    DeleteObject(thick);
    SetBkMode(dc, TRANSPARENT);
    SetTextColor(dc, COLOR_CLOCK_NUMBERS);
    HFONT f = make_font(dc, FONT_ARIAL, CLOCK_NUMBER_FONT_PT, FW_BOLD), of = (HFONT)SelectObject(dc, f);
    for (int n = 1; n <= CLOCK_HOURS; n++)
    {
        wchar_t b[4];
        wsprintfW(b, FORMAT_DAY_NUMBER, n);
        double a = (n % CLOCK_HOURS) * FULL_CIRCLE_RADIANS / CLOCK_HOURS - HALF_PI_RADIANS;
        int rr = (int)(rad * CLOCK_NUMBER_RADIUS_FACTOR), tx = cx + (int)(cos(a) * rr), ty = cy + (int)(sin(a) * rr);
        RECT tr =
        {
            tx - 20, ty - 12, tx + 20, ty + 12
        }
        ;
        DrawTextW(dc, b, -1, &tr, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    SelectObject(dc, of);
    DeleteObject(f);
    double minute = (double)t->wMinute, hour = (double)(t->wHour % CLOCK_HOURS) + minute / 60.0;
    draw_hand(dc, cx, cy, hour * FULL_CIRCLE_RADIANS / CLOCK_HOURS - HALF_PI_RADIANS, (int)(rad * CLOCK_HOUR_HAND_FACTOR), CLOCK_HOUR_HAND_WIDTH, COLOR_HOUR_HAND);
    draw_hand(dc, cx, cy, minute * FULL_CIRCLE_RADIANS / 60.0 - HALF_PI_RADIANS, (int)(rad * CLOCK_MINUTE_HAND_FACTOR), CLOCK_MINUTE_HAND_WIDTH, COLOR_MINUTE_HAND);
    HBRUSH cap = CreateSolidBrush(COLOR_CLOCK_CENTER), ob = (HBRUSH)SelectObject(dc, cap);
    Ellipse(dc, cx - CLOCK_CENTER_RADIUS, cy - CLOCK_CENTER_RADIUS, cx + CLOCK_CENTER_RADIUS, cy + CLOCK_CENTER_RADIUS);
    SelectObject(dc, ob);
    DeleteObject(cap);
    {
        wchar_t digitalTime[16];
        RECT digitalRect =
        {
            r->left,
            cy + rad + CLOCK_LABEL_GAP,
            r->right,
            cy + rad + CLOCK_LABEL_GAP + CLOCK_DIGITAL_HEIGHT
        };
        RECT labelRect =
        {
            r->left,
            digitalRect.bottom,
            r->right,
            r->bottom
        };
        HFONT digitalFont = make_font(dc, FONT_ARIAL, CLOCK_DIGITAL_FONT_PT, FW_BOLD);
        HFONT oldFont = (HFONT)SelectObject(dc, digitalFont);

        wsprintfW(digitalTime, FORMAT_DIGITAL_TIME, t->wHour, t->wMinute);
        SetTextColor(dc, COLOR_CLOCK_DIGITAL);
        DrawTextW(dc, digitalTime, -1, &digitalRect, DT_CENTER | DT_TOP | DT_SINGLELINE);
        SelectObject(dc, oldFont);
        DeleteObject(digitalFont);

        {
            HFONT labelFont = make_font(dc, FONT_ARIAL, CLOCK_LABEL_FONT_PT, FW_BOLD);
            oldFont = (HFONT)SelectObject(dc, labelFont);
            SetTextColor(dc, COLOR_CLOCK_LABEL);
            DrawTextW(dc, label, -1, &labelRect, DT_CENTER | DT_TOP | DT_SINGLELINE);
            SelectObject(dc, oldFont);
            DeleteObject(labelFont);
        }
    }
}

static BOOL is_valid_calendar_date(const SYSTEMTIME *time)
{
    return time &&
           time->wYear >= 1601 &&
           time->wMonth >= 1 &&
           time->wMonth <= 12 &&
           time->wDay >= 1 &&
           time->wDay <= 31;
}

static void render_calendar_cache(AppState *s, HDC ref, int w, int h)
{
    BOOL changed;
    if (w <= 0 || h <= 0)
        return;
    if (!is_valid_calendar_date(&s->clockTimes[0]))
        return;
    changed = !s->calendarDC || s->calendarW != w || s->calendarH != h || s->cachedYear != s->clockTimes[0].wYear || s->cachedMonth != s->clockTimes[0].wMonth || s->cachedDay != s->clockTimes[0].wDay;
    if (!changed)
        return;
    if (!ensure_surface(ref, &s->calendarDC, &s->calendarBitmap, &s->calendarOldBitmap, &s->calendarW, &s->calendarH, w, h))
        return;
    RECT all =
    {
        0, 0, w, h
    }
    ;
    HBRUSH bg = CreateSolidBrush(COLOR_CALENDAR_BG);
    FillRect(s->calendarDC, &all, bg);
    DeleteObject(bg);
    HPEN border = CreatePen(PS_SOLID, CALENDAR_BORDER_WIDTH, COLOR_CALENDAR_BORDER), op = (HPEN)SelectObject(s->calendarDC, border);
    HBRUSH hollow = (HBRUSH)SelectObject(s->calendarDC, GetStockObject(HOLLOW_BRUSH));
    Rectangle(s->calendarDC, 0, 0, w, h);
    SelectObject(s->calendarDC, hollow);
    SelectObject(s->calendarDC, op);
    DeleteObject(border);
    SetBkMode(s->calendarDC, TRANSPARENT);
    wchar_t title[64];
    wsprintfW(title, FORMAT_MONTH_YEAR, MONTH_NAMES[s->clockTimes[0].wMonth - 1], (unsigned)s->clockTimes[0].wYear);
    HFONT mf = make_font(s->calendarDC, FONT_ARIAL, MONTH_FONT_PT, FW_BOLD), oldf = (HFONT)SelectObject(s->calendarDC, mf);
    RECT mr =
    {
        8, 6, w - 8, CALENDAR_HEADER_HEIGHT
    }
    ;
    SetTextColor(s->calendarDC, COLOR_TEXT_NORMAL);
    DrawTextW(s->calendarDC, title, -1, &mr, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    SelectObject(s->calendarDC, oldf);
    DeleteObject(mf);
    int gridTop = CALENDAR_HEADER_HEIGHT, cellW = w / CALENDAR_COLUMNS, cellH = (h - CALENDAR_HEADER_HEIGHT - CALENDAR_WEEKDAY_HEIGHT) / CALENDAR_ROWS;
    HFONT wf = make_font(s->calendarDC, FONT_ARIAL, WEEKDAY_FONT_PT, FW_BOLD);
    oldf = (HFONT)SelectObject(s->calendarDC, wf);
    for (int c = 0; c < CALENDAR_COLUMNS; c++)
    {
        RECT cr =
        {
            c * cellW, gridTop, (c == 6 ? w : (c + 1)*cellW), gridTop + CALENDAR_WEEKDAY_HEIGHT
        }
        ;
        SetTextColor(s->calendarDC, c == 0 ? COLOR_SUNDAY : (c == 6 ? COLOR_SATURDAY : COLOR_TEXT_NORMAL));
        DrawTextW(s->calendarDC, WEEKDAY_NAMES[c], -1, &cr, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    SelectObject(s->calendarDC, oldf);
    DeleteObject(wf);
    HFONT df = make_font(s->calendarDC, FONT_ARIAL, DAY_FONT_PT, FW_BOLD);
    oldf = (HFONT)SelectObject(s->calendarDC, df);
    int first = weekday_of_date(s->clockTimes[0].wYear, s->clockTimes[0].wMonth, 1), count = days_in_month(s->clockTimes[0].wYear, s->clockTimes[0].wMonth);
    for (int day = 1; day <= count; day++)
    {
        int idx = first + day - 1, row = idx / CALENDAR_COLUMNS, col = idx % CALENDAR_COLUMNS;
        RECT cr =
        {
            col * cellW, gridTop + CALENDAR_WEEKDAY_HEIGHT + row * cellH, (col == 6 ? w : (col + 1)*cellW), gridTop + CALENDAR_WEEKDAY_HEIGHT + (row + 1) *cellH
        }
        ;
        wchar_t b[4];
        wsprintfW(b, FORMAT_DAY_NUMBER, day);
        if (day == s->clockTimes[0].wDay)
        {
            RECT hi = cr;
            InflateRect(&hi, -4, -3);
            HBRUSH hb = CreateSolidBrush(COLOR_TODAY_BG);
            FillRect(s->calendarDC, &hi, hb);
            DeleteObject(hb);
            SetTextColor(s->calendarDC, COLOR_TODAY_TEXT);
        }
        else
            SetTextColor(s->calendarDC, col == 0 ? COLOR_SUNDAY : (col == 6 ? COLOR_SATURDAY : COLOR_TEXT_NORMAL));
        DrawTextW(s->calendarDC, b, -1, &cr, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    }
    SelectObject(s->calendarDC, oldf);
    DeleteObject(df);
    s->cachedYear = s->clockTimes[0].wYear;
    s->cachedMonth = s->clockTimes[0].wMonth;
    s->cachedDay = s->clockTimes[0].wDay;
}

static void render_scene(AppState *s, HDC dc, int w, int h)
{
    RECT all = { 0, 0, w, h };
    HBRUSH bg = CreateSolidBrush(COLOR_WINDOW_BG);
    int contentTop = CONTENT_MARGIN;
    int contentBottom = h - CONTENT_MARGIN - FOOTER_HEIGHT;
    int usableW = w - 2 * CONTENT_MARGIN - SECTION_GAP;
    int clockAreaW = usableW * CLOCK_AREA_PERCENT / 100;
    int calW = usableW - clockAreaW;
    RECT calR =
    {
        CONTENT_MARGIN + clockAreaW + SECTION_GAP,
        contentTop,
        w - CONTENT_MARGIN,
        contentBottom
    };
    int clockAreaH = contentBottom - contentTop;
    int clockRows = CLOCK_COUNT / CLOCK_COLUMNS;
    int clockSlotW = (clockAreaW - CLOCK_HORIZONTAL_GAP) / CLOCK_COLUMNS;
    int clockSlotH = (clockAreaH - (clockRows - 1) * CLOCK_VERTICAL_GAP) / clockRows;
    int i;

    FillRect(dc, &all, bg);
    DeleteObject(bg);

    render_calendar_cache(s, dc, calW, contentBottom - contentTop);
    if (s->calendarDC)
    {
        BitBlt(dc,
               calR.left,
               calR.top,
               calW,
               contentBottom - contentTop,
               s->calendarDC,
               0,
               0,
               SRCCOPY);
    }

    for (i = 0; i < CLOCK_COUNT; ++i)
    {
        int row = i / CLOCK_COLUMNS;
        int col = i % CLOCK_COLUMNS;
        int left = CONTENT_MARGIN + col * (clockSlotW + CLOCK_HORIZONTAL_GAP);
        int top = contentTop + row * (clockSlotH + CLOCK_VERTICAL_GAP);
        RECT clockR =
        {
            left,
            top,
            left + clockSlotW,
            top + clockSlotH
        };
        wchar_t clockLabel[64];

        make_clock_label(s, i, clockLabel, ARRAYSIZE(clockLabel));
        draw_clock(dc, &clockR, &s->clockTimes[i], clockLabel);
    }

    {
        HFONT ff = make_font(dc, FONT_COURIER_NEW, FOOTER_FONT_PT, FW_NORMAL);
        HFONT of = (HFONT)SelectObject(dc, ff);
        RECT fr =
        {
            CONTENT_MARGIN,
            h - FOOTER_HEIGHT,
            w - CONTENT_MARGIN,
            h - CONTENT_MARGIN / 2
        };

        SetBkMode(dc, TRANSPARENT);
        SetTextColor(dc, COLOR_FOOTER_TEXT);
        DrawTextW(dc,
                  APP_URL_TEXT,
                  -1,
                  &fr,
                  DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_END_ELLIPSIS);
        SelectObject(dc, of);
        DeleteObject(ff);
    }
}

static HBITMAP render_export_bitmap(AppState *s, int w, int h)
{
    HDC screen = GetDC(NULL), mem = CreateCompatibleDC(screen);
    BITMAPINFO bi;
    ZeroMemory(&bi, sizeof(bi));
    bi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bi.bmiHeader.biWidth = w;
    bi.bmiHeader.biHeight = -h;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = BITS_PER_PIXEL;
    bi.bmiHeader.biCompression = BI_RGB;
    void *bits = NULL;
    HBITMAP bmp = CreateDIBSection(screen, &bi, DIB_RGB_COLORS, &bits, NULL, 0);
    if (bmp)
    {
        HBITMAP old = (HBITMAP)SelectObject(mem, bmp);
        render_scene(s, mem, w, h);
        SelectObject(mem, old);
    }
    DeleteDC(mem);
    ReleaseDC(NULL, screen);
    return bmp;
}

static BOOL bitmap_to_gp(AppState *s, HBITMAP bmp, GpBitmap **gp)
{
    if (s->pCreateBitmap(bmp, NULL, gp) != GDIPLUS_OK)
        return FALSE;
    s->pSetResolution(*gp, (float)EXPORT_DPI, (float)EXPORT_DPI);
    return TRUE;
}

static BOOL save_png(AppState *s, const wchar_t *path)
{
    RECT r;
    GetClientRect(s->hwnd, &r);
    HBITMAP bmp = render_export_bitmap(s, r.right, r.bottom);
    if (!bmp)
        return FALSE;
    GpBitmap *gp = NULL;
    BOOL ok = bitmap_to_gp(s, bmp, &gp);
    if (ok)
        ok = s->pSaveFile((GpImage *)gp, path, &PNG_ENCODER_CLSID, NULL) == GDIPLUS_OK;
    if (gp)
        s->pDisposeImage((GpImage *)gp);
    DeleteObject(bmp);
    return ok;
}

static HGLOBAL png_hglobal(AppState *s, HBITMAP bmp)
{
    GpBitmap *gp = NULL;
    IStream *stream = NULL;
    HGLOBAL src = NULL, dst = NULL;
    if (!bitmap_to_gp(s, bmp, &gp))
        return NULL;
    if (CreateStreamOnHGlobal(NULL, TRUE, &stream) != S_OK)
        goto done;
    if (s->pSaveStream((GpImage *)gp, stream, &PNG_ENCODER_CLSID, NULL) != GDIPLUS_OK)
        goto done;
    if (GetHGlobalFromStream(stream, &src) != S_OK)
        goto done;
    SIZE_T n = GlobalSize(src);
    dst = GlobalAlloc(GMEM_MOVEABLE, n);
    if (dst)
    {
        void *a = GlobalLock(src), *b = GlobalLock(dst);
        if (a && b)
            CopyMemory(b, a, n);
        if (b)
            GlobalUnlock(dst);
        if (a)
            GlobalUnlock(src);
    }
done:
    if (stream)
        stream->lpVtbl->Release(stream);
    if (gp)
        s->pDisposeImage((GpImage *)gp);
    return dst;
}

static HGLOBAL dib_hglobal(HBITMAP bmp)
{
    BITMAP bm;
    if (!GetObjectW(bmp, sizeof(bm), &bm))
        return NULL;
    DWORD row = ((bm.bmWidth * BITS_PER_PIXEL + 31) / 32) * 4, bytes = row * bm.bmHeight, total = DIB_HEADER_SIZE + bytes;
    HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, total);
    if (!h)
        return NULL;
    BYTE *p = (BYTE *)GlobalLock(h);
    BITMAPINFOHEADER *hdr = (BITMAPINFOHEADER *)p;
    ZeroMemory(hdr, sizeof(*hdr));
    hdr->biSize = sizeof(*hdr);
    hdr->biWidth = bm.bmWidth;
    hdr->biHeight = bm.bmHeight;
    hdr->biPlanes = 1;
    hdr->biBitCount = BITS_PER_PIXEL;
    hdr->biCompression = BI_RGB;
    HDC dc = GetDC(NULL);
    BITMAPINFO bi;
    ZeroMemory(&bi, sizeof(bi));
    bi.bmiHeader = *hdr;
    if (!GetDIBits(dc, bmp, 0, bm.bmHeight, p + DIB_HEADER_SIZE, &bi, DIB_RGB_COLORS))
    {
        ReleaseDC(NULL, dc);
        GlobalUnlock(h);
        GlobalFree(h);
        return NULL;
    }
    ReleaseDC(NULL, dc);
    GlobalUnlock(h);
    return h;
}

static BOOL copy_image(AppState *s)
{
    RECT r;
    GetClientRect(s->hwnd, &r);
    HBITMAP bmp = render_export_bitmap(s, r.right, r.bottom);
    if (!bmp)
        return FALSE;
    HGLOBAL png = png_hglobal(s, bmp), dib = dib_hglobal(bmp);
    DeleteObject(bmp);
    if (!png && !dib)
        return FALSE;
    if (!OpenClipboard(s->hwnd))
    {
        if (png)
            GlobalFree(png);
        if (dib)
            GlobalFree(dib);
        return FALSE;
    }
    EmptyClipboard();
    BOOL ok = FALSE;
    if (png && SetClipboardData(s->pngClipboardFormat, png))
    {
        png = NULL;
        ok = TRUE;
    }
    if (dib && SetClipboardData(CF_DIB, dib))
    {
        dib = NULL;
        ok = TRUE;
    }
    CloseClipboard();
    if (png)
        GlobalFree(png);
    if (dib)
        GlobalFree(dib);
    return ok;
}

static void do_save(AppState *s)
{
    wchar_t path[MAX_PATH];
    lstrcpynW(path, APP_SAVE_DEFAULT_NAME, MAX_PATH);
    OPENFILENAMEW o;
    ZeroMemory(&o, sizeof(o));
    o.lStructSize = sizeof(o);
    o.hwndOwner = s->hwnd;
    o.lpstrFilter = APP_SAVE_FILTER;
    o.lpstrFile = path;
    o.nMaxFile = MAX_PATH;
    o.lpstrDefExt = APP_SAVE_DEFAULT_EXT;
    o.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;
    if (GetSaveFileNameW(&o) && !save_png(s, path))
        MessageBoxW(s->hwnd, APP_SAVE_ERROR, APP_WINDOW_TITLE, MB_OK | MB_ICONERROR);
}

static void tray_add(AppState *s)
{
    ZeroMemory(&s->tray, sizeof(s->tray));
    s->tray.cbSize = sizeof(s->tray);
    s->tray.hWnd = s->hwnd;
    s->tray.uID = TRAY_ICON_ID;
    s->tray.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
    s->tray.uCallbackMessage = WM_APP_TRAY;
    s->tray.hIcon = LoadIconW(s->instance, MAKEINTRESOURCEW(IDI_APP_ICON));
    lstrcpynW(s->tray.szTip, APP_TRAY_TOOLTIP, ARRAYSIZE(s->tray.szTip));
    Shell_NotifyIconW(NIM_ADD, &s->tray);
}

static void tray_menu(AppState *s)
{
    HMENU m = CreatePopupMenu();
    AppendMenuW(m, MF_STRING, IDM_TRAY_SHOW, APP_TRAY_SHOW);
    AppendMenuW(m, MF_SEPARATOR, 0, NULL);
    AppendMenuW(m, MF_STRING, IDM_TRAY_EXIT, APP_TRAY_EXIT);
    POINT p;
    GetCursorPos(&p);
    SetForegroundWindow(s->hwnd);
    TrackPopupMenu(m, TPM_RIGHTBUTTON, p.x, p.y, 0, s->hwnd, NULL);
    DestroyMenu(m);
}

static HMENU create_menu_bar(void)
{
    HMENU bar = CreateMenu(), file = CreatePopupMenu(), edit = CreatePopupMenu(), help = CreatePopupMenu();
    AppendMenuW(file, MF_STRING, IDM_FILE_SAVE, APP_MENU_SAVE);
    AppendMenuW(file, MF_SEPARATOR, 0, NULL);
    AppendMenuW(file, MF_STRING, IDM_FILE_EXIT, APP_MENU_EXIT);
    AppendMenuW(edit, MF_STRING, IDM_EDIT_COPY, APP_MENU_COPY);
    AppendMenuW(help, MF_STRING, IDM_HELP_ABOUT, APP_MENU_ABOUT);
    AppendMenuW(bar, MF_POPUP, (UINT_PTR)file, APP_MENU_FILE);
    AppendMenuW(bar, MF_POPUP, (UINT_PTR)edit, APP_MENU_EDIT);
    AppendMenuW(bar, MF_POPUP, (UINT_PTR)help, APP_MENU_HELP);
    return bar;
}

static void position_window(HWND hwnd)
{
    RECT work, wr =
    {
        0, 0, APP_CLIENT_WIDTH, APP_CLIENT_HEIGHT
    }
    ;
    SystemParametersInfoW(SPI_GETWORKAREA, 0, &work, 0);
    AdjustWindowRectEx(&wr, WS_OVERLAPPEDWINDOW, TRUE, 0);
    int ww = wr.right - wr.left, wh = wr.bottom - wr.top, x = work.right - ww - WINDOW_MARGIN_RIGHT, y = work.bottom - wh - WINDOW_MARGIN_BOTTOM;
    SetWindowPos(hwnd, NULL, x, y, ww, wh, SWP_NOZORDER | SWP_NOACTIVATE);
}

static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
    AppState *s = (AppState *)GetWindowLongPtrW(hwnd, GWLP_USERDATA);
    switch (msg)
    {
    case WM_CREATE:
    {
        CREATESTRUCTW *cs = (CREATESTRUCTW *)lp;
        s = (AppState *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(*s));
        if (!s)
            return -1;
        s->hwnd = hwnd;
        s->instance = (HINSTANCE)cs->hInstance;
        load_clock_configuration(s);
        initialize_time_zones(s);
        update_clock_times(s);
        s->pngClipboardFormat = RegisterClipboardFormatW(APP_PNG_CLIPBOARD_FORMAT);
        SetWindowLongPtrW(hwnd, GWLP_USERDATA, (LONG_PTR)s);
        if (!gdiplus_start(s))
        {
            MessageBoxW(hwnd, APP_GDIPLUS_ERROR, APP_WINDOW_TITLE, MB_OK | MB_ICONERROR);
            return -1;
        }
        SetTimer(hwnd, TIMER_ID_MINUTE, TIMER_INTERVAL_MS, NULL);
        tray_add(s);
        return 0;
    }
    case WM_GETMINMAXINFO:
    {
        MINMAXINFO *m = (MINMAXINFO *)lp;
        RECT r =
        {
            0, 0, APP_MIN_CLIENT_WIDTH, APP_MIN_CLIENT_HEIGHT
        }
        ;
        AdjustWindowRectEx(&r, WS_OVERLAPPEDWINDOW, TRUE, 0);
        m->ptMinTrackSize.x = r.right - r.left;
        m->ptMinTrackSize.y = r.bottom - r.top;
        return 0;
    }
    case WM_SIZE:
        if (s && wp != SIZE_MINIMIZED)
        {
            HDC dc = GetDC(hwnd);
            ensure_surface(dc, &s->backDC, &s->backBitmap, &s->backOldBitmap, &s->backW, &s->backH, LOWORD(lp), HIWORD(lp));
            ReleaseDC(hwnd, dc);
        }
        return 0;
    case WM_ERASEBKGND:
        return 1;
    case WM_TIMER:
        if (s && wp == TIMER_ID_MINUTE)
        {
            SYSTEMTIME oldBrazil = s->clockTimes[0];
            update_clock_times(s);
            if (oldBrazil.wYear != s->clockTimes[0].wYear)
            {
                initialize_time_zones(s);
                update_clock_times(s);
            }
            if (oldBrazil.wYear != s->clockTimes[0].wYear || oldBrazil.wMonth != s->clockTimes[0].wMonth || oldBrazil.wDay != s->clockTimes[0].wDay)
            {
                s->cachedYear = 0;
                s->cachedMonth = 0;
                s->cachedDay = 0;
            }
            InvalidateRect(hwnd, NULL, FALSE);
        }
        return 0;
    case WM_DISPLAYCHANGE:
    case WM_SETTINGCHANGE:
        position_window(hwnd);
        return 0;
    case WM_COMMAND:
        if (!s)
            break;
        switch (LOWORD(wp))
        {
        case IDM_FILE_SAVE:
            do_save(s);
            return 0;
        case IDM_FILE_EXIT:
        case IDM_TRAY_EXIT:
            DestroyWindow(hwnd);
            return 0;
        case IDM_EDIT_COPY:
            if (!copy_image(s))
                MessageBoxW(hwnd, APP_COPY_ERROR, APP_WINDOW_TITLE, MB_OK | MB_ICONERROR);
            return 0;
        case IDM_HELP_ABOUT:
            // MessageBoxW(hwnd,APP_ABOUT_TEXT,APP_ABOUT_TITLE,MB_OK|MB_ICONINFORMATION);
            ShellAboutW(
                hwnd,
                APP_ABOUT_TITLE,
                APP_ABOUT_TEXT,
                LoadIconW(s->instance, MAKEINTRESOURCEW(IDI_APP_ICON))
            );
            return 0;
        case IDM_TRAY_SHOW:
            ShowWindow(hwnd, SW_RESTORE);
            SetForegroundWindow(hwnd);
            return 0;
        }
        break;
    case WM_APP_TRAY:
        if (!s)
            break;
        if (lp == WM_LBUTTONDBLCLK)
        {
            ShowWindow(hwnd, SW_RESTORE);
            SetForegroundWindow(hwnd);
        }
        else if (lp == WM_RBUTTONUP || lp == WM_CONTEXTMENU)
            tray_menu(s);
        return 0;
    case WM_PAINT:
        if (s)
        {
            PAINTSTRUCT ps;
            HDC dc = BeginPaint(hwnd, &ps);
            RECT r;
            GetClientRect(hwnd, &r);
            int w = r.right, h = r.bottom;
            ensure_surface(dc, &s->backDC, &s->backBitmap, &s->backOldBitmap, &s->backW, &s->backH, w, h);
            if (s->backDC)
            {
                render_scene(s, s->backDC, w, h);
                BitBlt(dc, 0, 0, w, h, s->backDC, 0, 0, SRCCOPY);
            }
            EndPaint(hwnd, &ps);
            return 0;
        }
        break;
    case WM_CLOSE:
        ShowWindow(hwnd, SW_HIDE);
        return 0;
    case WM_DESTROY:
        if (s)
        {
            KillTimer(hwnd, TIMER_ID_MINUTE);
            Shell_NotifyIconW(NIM_DELETE, &s->tray);
            destroy_surface(&s->calendarDC, &s->calendarBitmap, &s->calendarOldBitmap);
            destroy_surface(&s->backDC, &s->backBitmap, &s->backOldBitmap);
            gdiplus_stop(s);
            HeapFree(GetProcessHeap(), 0, s);
            SetWindowLongPtrW(hwnd, GWLP_USERDATA, 0);
        }
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(hwnd, msg, wp, lp);
}


static HWND find_existing_main_window(void)
{
    int attempt;

    for (attempt = 0; attempt < APP_EXISTING_WINDOW_RETRIES; ++attempt)
    {
        HWND hwnd = FindWindowW(APP_CLASS_NAME, NULL);

        if (hwnd)
        {
            return hwnd;
        }

        Sleep(APP_EXISTING_WINDOW_DELAY_MS);
    }

    return NULL;
}

static void show_existing_instance(HWND hwnd)
{
    if (!hwnd)
    {
        return;
    }

    if (IsIconic(hwnd))
    {
        ShowWindow(hwnd, SW_RESTORE);
    }
    else
    {
        ShowWindow(hwnd, SW_SHOW);
    }

    SetForegroundWindow(hwnd);
}

int WINAPI wWinMain(HINSTANCE hi, HINSTANCE hp, PWSTR cmd, int show)
{
    HANDLE singleInstanceMutex;
    DWORD mutexError;

    singleInstanceMutex = CreateMutexW(NULL, TRUE, APP_SINGLE_INSTANCE_MUTEX);
    mutexError = GetLastError();

    if (singleInstanceMutex && mutexError == ERROR_ALREADY_EXISTS)
    {
        HWND existingWindow = find_existing_main_window();

        show_existing_instance(existingWindow);
        CloseHandle(singleInstanceMutex);
        return 0;
    }


    HRESULT comResult;
    BOOL comInitialized;

    (void)hp;
    (void)cmd;

    comResult = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    comInitialized = SUCCEEDED(comResult);

    WNDCLASSEXW wc;
    ZeroMemory(&wc, sizeof(wc));
    wc.cbSize = sizeof(wc);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hi;
    wc.hIcon = LoadIconW(hi, MAKEINTRESOURCEW(IDI_APP_ICON));
    wc.hIconSm = wc.hIcon;
    wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = APP_CLASS_NAME;
    if (!RegisterClassExW(&wc))
    {
        if (comInitialized)
            CoUninitialize();
        return 1;
    }
    HWND hwnd = CreateWindowExW(0, APP_CLASS_NAME, APP_WINDOW_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, APP_CLIENT_WIDTH, APP_CLIENT_HEIGHT, NULL, create_menu_bar(), hi, NULL);
    if (!hwnd)
    {
        if (comInitialized)
            CoUninitialize();
        return 2;
    }
    if (comInitialized)
        ensure_startup_shortcut();
    position_window(hwnd);
    ShowWindow(hwnd, show);
    UpdateWindow(hwnd);
    ACCEL a[2] =
    {
        { FVIRTKEY | FCONTROL, 'S', IDM_FILE_SAVE },
        { FVIRTKEY | FCONTROL, 'C', IDM_EDIT_COPY }
    };
    HACCEL ha = CreateAcceleratorTableW(a, 2);
    MSG m;
    while (GetMessageW(&m, NULL, 0, 0) > 0)
    {
        if (!TranslateAcceleratorW(hwnd, ha, &m))
        {
            TranslateMessage(&m);
            DispatchMessageW(&m);
        }
    }
    DestroyAcceleratorTable(ha);
    if (comInitialized)
        CoUninitialize();
    return (int)m.wParam;
}

//EOF