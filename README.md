# win32-named-pipes-example
Simple example code for working with named pipes in C++ using the Win32 API.

For a full explanation see the accompanying blog post here:

 * http://avidinsight.uk/2012/03/introduction-to-win32-named-pipes-cpp/


## Author
[Peter R. Bloomfield](http://peter.avidinsight.uk).


## License
The code is made freely available under the MIT open source license (see accompanying LICENSE file for details).
It is intended only for educational purposes. and is provide as-is with no guarantee about its reliability, correctness, or suitability for any purpose.


## Server and client
There is example code for two programs, named "server" and "client".

The server program will open a named pipe, wait for something else to connect to it, and then send some data over it.
The client program will look for a named pipe, connect to it, and then wait to receive some data through it.

The code for each of these programs can be found in `src/server.cpp` and `src/client.cpp` respectively.


## Building the programs
### Visual Studio 2015
Solution/project files are included for VC12 (Visual Studio 2015). The Community edition is excellent and is free for individuals and small teams. You can download it from here:

 * https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx

In the `vc12` folder in the repository, you will find a solution file called `win32-named-pipe-example.sln`. Open it in Visual Studio. Open the "Build" menu and click "Build Solution". Both programs should be compiled and linked.

The resulting executables will be put in `vc12/Debug` or `vc12/Release`, depending on which configuration you built.


## Running the example programs
After building both programs, first run the server program. It will open a console window and you should see it report that it has opened a pipe and is waiting for a connection.
Leave the server window open and run the client program. It will open a console window as well. It should indicate that it has connected to the pipe and received some data.
Go back to the server window and you should see it report that it has sent data.

Note: If you are working with Visual Studio, I recommend running the programs outside the IDE; i.e. in Explorer, navigate to `vc12/Debug` or `vc12/Release` and double-click the executables. This is because it's tricky to run two different programs from within a single Visual Studio solution (I'm sure there's a way to do it -- I just haven't found it!).




