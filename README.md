# 🎓 Student Record Management System (C++)

This C++ program allows users to manage student records including adding, displaying, updating, deleting, and viewing all records. It uses **binary file handling** to store data persistently in `data.txt`.

---

## 🔍 Features

- ✅ Add new student records  
- ✅ View individual student mark sheet  
- ✅ Update existing student details  
- ✅ Delete student by roll number  
- ✅ Display all student records  
- ✅ File-based persistent storage using binary I/O  

---

## 📚 What You'll Learn

- File handling with binary files  
- Struct usage in C++  
- Input/output stream operations (`fstream`)  
- Data serialization using `write()` and `read()`  
- Menu-driven program design  

---

## 🛠️ How It Works

### 1. **Data Input**
- Takes student name, roll number, and marks for 5 subjects.

### 2. **Binary File Handling**
- Stores data in `data.txt` using binary write/read.

### 3. **Operations**
- Add, view, delete, update records using file streams and temporary files for safe update/delete.

---

## ▶️ How to Compile and Run

```bash
g++ -o student student.cpp
./student
Student-Management/
├── student.cpp       # Main source code
├── data.txt          # Binary file storing student records
├── README.md         # Project documentation
└── LICENSE           # Open-source license
