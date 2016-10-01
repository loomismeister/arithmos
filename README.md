# arithmos
A lightweight, data-driven replacement for Microsoft Project

# Build Requirements
* Git
    * https://git-scm.com/
* cmake
    * https://cmake.org/download/

# Setup

## Install MinGW
The Minimalist GNU for Windows (MinGW) development tools provide a set of tools that are not dependent on third party C-Runtime DLLs (such as Cygwin).

1. Download the latest MinGW mingw-get-setup installer from https://sourceforge.net/projects/mingw/files/Installer/
2. Run the installer. The recommended installation path is C:\MinGW, however, you may install to any location.
    * Ensure that the "mingw32-base" and "mingw32-gcc-g++" and "msys-base" are selected under Basic Setup.
    * Click "Apply Changes" in the "Installation" menu and follow the remaining instructions to complete the installation.
3. Add the appropriate item to the Windows operating system Path environment variable. It can be found under Control Panel -> System and Security -> System -> Advanced System Settings in the "Environment Variables..." section. The path is:
[mingw_install_dir]\bin

## Install CMake

1. Download CMake 3.0.x from http://www.cmake.org/cmake/resources/software.html.
2. Install CMake, ensuring that the option "Add CMake to system PATH" is selected when installing. It's up to the user to select whether it's installed into the PATH for all users or just the current user.
3. Follow the remaining instructions of the installer.
4. You may need to reboot your system for the PATH changes to take effect.

## Clone project and build Makefiles
```bash
cd [to a directory where you will keep the project]
git clone [paste url][press enter]
mkdir build
cd arithmos/build
cmake -G "Eclipse CDT4 - MinGW Makefiles" ..
```

You can now open this project file in eclipse and use build to create an executable.
You can also just run MinGW to build in command line without eclipse:
```bash
mingw32-make all
```
