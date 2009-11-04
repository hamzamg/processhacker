#ifndef PH_H
#define PH_H

#include <phbase.h>
#include <ref.h>
#include <stdarg.h>

// process

#ifndef PROCESS_PRIVATE
extern PPH_OBJECT_TYPE PhProcessType;
#endif

typedef struct _PH_PROCESS
{
	HANDLE ProcessId;
} PH_PROCESS, *PPH_PROCESS;

typedef BOOLEAN (*PPH_ENUM_PROCESSES_CALLBACK)(
    __in PSYSTEM_PROCESS_INFORMATION Process
    );

NTSTATUS PhEnumProcesses(
    __in PPH_ENUM_PROCESSES_CALLBACK Callback,
    __out_opt PBOOLEAN Found
    );

// support

#define PhRaiseStatus(Status) RaiseException(Status, 0, 0, NULL)

PVOID PhAllocate(
    __in SIZE_T Size
    );

VOID PhFree(
    __in PVOID Memory
    );

PVOID PhReAlloc(
    __in PVOID Memory,
    __in SIZE_T Size
    );

#define PH_MAX_MESSAGE_SIZE 400

INT PhShowMessage(
    __in HWND hWnd,
    __in ULONG Type,
    __in PWSTR Format,
    ...
    );

INT PhShowMessage_V(
    __in HWND hWnd,
    __in ULONG Type,
    __in PWSTR Format,
    __in va_list ArgPtr
    );

#define PhShowError(hWnd, Format, ...) PhShowMessage(hWnd, MB_OK | MB_ICONERROR, Format, __VA_ARGS__) 

#endif
