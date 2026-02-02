# Student Management System (C)

A menu-driven **Student Management System** implemented in **C** using **binary file handling**.
The program supports persistent storage and basic record management operations for student data.

---

## Overview

This project demonstrates the use of:

* Structures in C
* File handling using binary files
* Menu-driven program design

Student records are stored in a binary file (`students.dat`) and can be added, retrieved, modified, or deleted through a command-line interface.

---

## Features

* Add student records
* Display all stored records
* Search a student by roll number
* Update existing student details
* Delete a student record
* Persistent storage using files

---

## Technologies Used

* Programming Language: C
* Concepts:

  * Structures
  * File I/O (`fopen`, `fread`, `fwrite`, `fseek`)
  * String handling
  * Control flow and functions

---

## Project Structure

```
Student-Management-System/
│
├── student_management.c
├── students.dat   (created at runtime)
└── README.md
```

---

## Compilation and Execution

### Compile

```bash
gcc student_management.c -o student_management
```

### Run

```bash
./student_management
```

---

## Menu Options

```
1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
```

---

## Student Record Format

Each student record contains:

* Roll Number (string)
* Name (string)
* Age (integer)

Records are stored in binary format for efficient access.

---

## Sample Usage

```
Enter Roll Number: SE24UCSE168
Enter Name: Sushanth Lingala
Enter Age: 18
Student added successfully.
```

---

## Limitations

* No input validation for duplicate roll numbers
* Console-based interface only
* No sorting or filtering of records

---

## Author

Sushanth Lingala
B.Tech, Computer Science and Engineering
Mahindra University, Hyderabad

GitHub: [https://github.com/esel4132](https://github.com/esel4132)
LinkedIn: [https://linkedin.com/in/sushanth](https://linkedin.com/in/sushanth)

---

## License

This project is intended for educational use.


