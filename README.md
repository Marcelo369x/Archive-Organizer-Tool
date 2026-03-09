#  Archive Organizer Tool

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![JSON](https://img.shields.io/badge/Data-JSON-yellow?style=for-the-badge&logo=json&logoColor=black)
![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge)
![Version](https://img.shields.io/badge/Version-0.1.0-orange?style=for-the-badge)

> **Automatically organize your messy folders in seconds.** Drop your files in a folder, run the tool, and watch them get sorted into clean categorized subfolders.

---

##  Requirements

![MSYS2](https://img.shields.io/badge/MSYS2-recommended-purple?style=flat-square&logo=gnubash&logoColor=white)
![MinGW](https://img.shields.io/badge/MinGW--W64-supported-blue?style=flat-square)

- A **C++ compiler** that supports C++17, such as:
  - [MSYS2](https://www.msys2.org/) ✅ recommended
  - [MinGW-W64](https://www.mingw-w64.org/)
- [`json.hpp`](https://github.com/nlohmann/json/releases/latest) — single header from nlohmann *(already included in the repo)*
- `archive_types.json` — extension map *(already included in the repo)*

---

##  Steps

###  Verify your compiler is recognized

Open CMD or MSYS2 and run:
```bash
g++ --version
```
If it prints a version number, you're good to go ✅

---

###  Compile the code

```bash
g++ ToolFileOrganizer.cpp -o ToolFileOrganizer -std=c++17
```

---

###  Run the tool

```bash
./ToolFileOrganizer.exe
```

---

###  Enter the route you want to organize

The tool will ask you for a folder path:
```
[+] Enter the route that you want to organize: C:/Users/YourName/Downloads
```

It will then automatically sort all files into subfolders named after their type, like:
```
Downloads/
├── imagenes_raster/
├── documentos_word/
├── pdfs/
├── codigo_cpp/
└── ...
```

---

##  Important

>  **BE CAREFUL:** The files you want to organize **must be directly inside the folder you provide**, not in subfolders. The tool only reads the top level of the directory.

---

##  That's it — enjoy your organized folder!

---

*Coded by **Marcelo Folcarelli***
