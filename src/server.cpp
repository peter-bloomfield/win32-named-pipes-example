/*
Server Program for Win32 Named Pipes Example.
Copyright (C) 2012 Peter R. Bloomfield.

For an exaplanation of the code, see the associated blog post:
http://avidinsight.uk/2012/03/introduction-to-win32-named-pipes-cpp/

This code is made freely available under the MIT open source license
(see accompanying LICENSE file for details).
It is intended only for educational purposes. and is provide as-is with no
guarantee about its reliability, correctness, or suitability for any purpose.


INSTRUCTIONS:

Run this server program first.
Before closing it, run the accompanying client program.
*/

#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, const char **argv)
{
    wcout << "Creating an instance of a named pipe..." << endl;

    // Create a pipe to send data
    HANDLE pipe = CreateNamedPipe(
        L"\\\\.\\pipe\\my_pipe", // name of the pipe
        PIPE_ACCESS_OUTBOUND, // 1-way pipe -- send only
        PIPE_TYPE_BYTE, // send data as a byte stream
        1, // only allow 1 instance of this pipe
        0, // no outbound buffer
        0, // no inbound buffer
        0, // use default wait time
        NULL // use default security attributes
        );

    if (pipe == NULL || pipe == INVALID_HANDLE_VALUE) {
        wcout << "Failed to create outbound pipe instance.";
        // look up error code here using GetLastError()
        system("pause");
        return 1;
    }

    wcout << "Waiting for a client to connect to the pipe..." << endl;

    // This call blocks until a client process connects to the pipe
    BOOL result = ConnectNamedPipe(pipe, NULL);
    if (!result) {
        wcout << "Failed to make connection on named pipe." << endl;
        // look up error code here using GetLastError()
        CloseHandle(pipe); // close the pipe
        system("pause");
        return 1;
    }

    wcout << "Sending data to pipe..." << endl;

    // This call blocks until a client process reads all the data
    const wchar_t *data = L"*** Hello Pipe World ***";
    DWORD numBytesWritten = 0;
    result = WriteFile(
        pipe, // handle to our outbound pipe
        data, // data to send
        wcslen(data) * sizeof(wchar_t), // length of data to send (bytes)
        &numBytesWritten, // will store actual amount of data sent
        NULL // not using overlapped IO
        );

    if (result) {
        wcout << "Number of bytes sent: " << numBytesWritten << endl;
    } else {
        wcout << "Failed to send data." << endl;
        // look up error code here using GetLastError()
    }

    // Close the pipe (automatically disconnects client too)
    CloseHandle(pipe);

    wcout << "Done." << endl;

    system("pause");
    return 0;
}
