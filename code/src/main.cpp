#include <windows.h>
#include <iostream>

LRESULT CALLBACK
MainWindowCallback(_In_ HWND   hwnd,
                   _In_ UINT   message,
                   _In_ WPARAM wparam,
                   _In_ LPARAM lparam)
{
    LRESULT result = 0;

    switch (message)
    {
        case WM_SIZE:
        {
            OutputDebugStringA("WM_SIZE\n");
        } break;
        case WM_DESTROY:
        {
            OutputDebugStringA("WM_DESTROY\n");
        } break;
        case WM_CLOSE:
        {
            DestroyWindow(hwnd);
        } break;
        case WM_ACTIVATEAPP:
        {
            OutputDebugStringA("WM_ACTIVATEAPP\n");
        } break;
        case WM_LBUTTONDOWN:
        {
            MessageBoxA(0, "message", "title", MB_OK);
        } break;
        default:
        {
            result = DefWindowProcA(hwnd, message, wparam, lparam);
        } break;
    }

    return result;
}

int CALLBACK
WinMain(_In_     HINSTANCE instance,
        _In_opt_ HINSTANCE previous_instance,
        _In_     LPSTR     cmd_line,
        _In_     int       cmd_show)
{
    UNREFERENCED_PARAMETER(previous_instance);
    UNREFERENCED_PARAMETER(cmd_line);
    UNREFERENCED_PARAMETER(cmd_show);

    WNDCLASS window = {};

    window.style         = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
    window.lpfnWndProc   = MainWindowCallback;
    window.hInstance     = instance;
    window.lpszClassName = "MainWindowClass";

    if (!RegisterClassA(&window))
        return 1;

    HWND handle = CreateWindowExA(
            0,
            window.lpszClassName,
            "apm_counter",
            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            0,
            0,
            instance,
            0);

    if (!handle)
        return 1;

    MSG message;
    BOOL result;

    while (true)
    {
        result = GetMessageA(&message, 0, 0, 0);

        if (result > 0)
        {
            TranslateMessage(&message);
            DispatchMessageA(&message);
        }
        else if (result < 0)
        {
            // error
        }
        else
        {
            // result == 0 means the exit from the program
            break;
        }
    }

    return message.wParam;
}
