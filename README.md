# Blitz3D TSS

This is a **fork** of [Blitz3D TSS](https://github.com/Saalvage/Blitz3D), made by [ZiYueCommentary](https://github.com/ZiYueCommentary/Blitz3D).

## Extending Blitz3D TSS
Please read [this document](EXTENDING.md).

## How to Build

### Prepare

- Visual Studio Community 2019 Or Later
  - Desktop development with C++
  - C++ MFC for latest v142 build tools (x86 & x64)
  - C++ ATL for latest v142 build tools (x86 & x64)
  - ASP.NET and web development

- CMake 3.16 Or Later

### Steps

#### For Blitz3D

1. Open the repository's directory.
2. mkdir build.
3. cd build.
4. cmake -G "Visual Studio 16 2019" -A Win32 ..
5. cmake --build . --config Release 
6. Done! 

#### For CompilerGUI And Installer

1. Open blitz3d.sln.
2. Select Release and AnyCPU.
3. Press F7.
4. Done!

- **Note:** 
  
  Nothing
