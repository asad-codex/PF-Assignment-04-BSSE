# Student Record Management System (CRUD File Handling in C++)

**Course:** Programming Fundamentals (CS1104)  
**Assignment:** Assignment No. 4  
**Topic:** File Handling in C++ (CRUD Operations)  
**Institution:** The Superior University, Lahore — Faculty of Computer Science & Information Technology

## 📌 Overview

This repository contains four C++ programs that together implement the four fundamental **CRUD** operations — **C**reate, **R**ead, **U**pdate, **D**elete — on a single text file named `students.txt`. Each record in the file stores a student's **Roll No**, **Name**, and **Marks**.

The project demonstrates practical use of C++ file streams (`ofstream`, `ifstream`, `fstream`) and file-positioning functions (`seekg()`, `seekp()`, `tellg()`) to manage persistent data without a database.

## 📂 Files in this Repository

| File | Operation | Description |
|------|-----------|--------------|
| `Q1_Create.cpp` | **CREATE** | Creates `students.txt` and writes 5 student records entered by the user. |
| `Q2_Read.cpp` | **READ** | Opens `students.txt` and displays all records in a formatted table along with a total record count. |
| `Q3_Update.cpp` | **UPDATE** | Searches for a student by Roll No and updates their Marks in place. |
| `Q4_Delete.cpp` | **DELETE** | Removes a student's record (matched by Roll No) using the temporary-file technique. |

## ⚙️ How It Works

1. **Create** — Opens `students.txt` in output mode (`ios::out`) and writes 5 records, one per line, using `<<`.
2. **Read** — Opens `students.txt` in input mode (`ios::in`) and extracts records with `>>` in a loop until end-of-file.
3. **Update** — Opens the file with `fstream` (`ios::in | ios::out`), searches for a matching Roll No, then uses `seekp()` to move the write pointer back and overwrite the Marks field.
4. **Delete** — Reads the original file record by record, copies every record **except** the matching one into `temp.txt`, then uses `remove()` and `rename()` to replace the original file.

> ⚠️ **Note:** All four programs must be run in the **same folder**, since they all read/write the shared `students.txt` file.

## 📋 Sample Record Format
22  MuhammadAsad    70 |
26  UmerZaheer      60 |
45  MuhammadAli     80 |
66  HammadAli       93 |
12  MuhammadAwais   77 

## 📖 Key Concepts Demonstrated

- File stream classes: `ofstream`, `ifstream`, `fstream`
- File-opening modes: `ios::in`, `ios::out`, `ios::app`, `ios::ate`, `ios::trunc`
- File position pointers: `seekg()`, `seekp()`, `tellg()`, `tellp()`
- Temporary-file technique for deleting records
- Basic input validation (`is_open()` checks)

---
*This project was created as part of a university assignment on file handling in C++.*
