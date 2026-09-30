# Student Record Management System

A menu-driven C++ application for storing and managing student records. Records are persisted in a portable text file, allowing data to remain available between program runs.

## Features

- Add student records
- Display an individual student's mark sheet
- Update student details
- Delete a record by roll number
- Display all stored records
- Store marks for five subjects
- Use a temporary file during update and delete operations without losing records

## Build and Run

```bash
g++ -std=c++17 -O2 -Wall -Wextra student.cpp -o student
./student
```

On Windows, run:

```text
student.exe
```

The application creates or updates its text data file in the directory from which it is run.

## Project Structure

```text
student.cpp   # Main C++ source
README.md     # Project documentation
License       # License information
```

## Concepts Demonstrated

- C++ structures
- Text-based `fstream` input and output with quoted names
- Portable record serialization with quoted text fields
- Menu-driven program design
- Safe replacement of records with a temporary file