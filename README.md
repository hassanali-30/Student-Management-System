# Student Record Management System

A menu-driven C++ application for storing and managing student records. Records are persisted using binary file I/O, allowing data to remain available between program runs.

## Features

- Add student records
- Display an individual student's mark sheet
- Update student details
- Delete a record by roll number
- Display all stored records
- Store marks for five subjects
- Use a temporary file during update and delete operations

## Build and Run

```bash
g++ -std=c++17 -O2 -Wall -Wextra student.cpp -o student
./student
```

On Windows, run:

```text
student.exe
```

The application creates or updates its binary data file in the directory from which it is run.

## Project Structure

```text
student.cpp   # Main C++ source
README.md     # Project documentation
License       # License information
```

## Concepts Demonstrated

- C++ structures
- Binary `fstream` input and output
- Record serialization with `read()` and `write()`
- Menu-driven program design
- Safe replacement of records with a temporary file