# Gym Membership Management System

A C++ console application that allows gym owners to manage member information efficiently.

## Overview

This Gym Membership Management System is a command-line application built in C++ that enables gym administrators to maintain a database of members, including their personal details and membership information. The system provides a simple interface for performing common membership management tasks.

## Features

- **Add New Members**: Register new gym members with validated personal information
- **View All Members**: Display a formatted table of all registered members
- **Update Member Details**: Modify existing member information
- **Delete Members**: Remove members from the system
- **Input Validation**: Ensures data integrity with robust validation for names, ages, and phone numbers

## Requirements

- C++ compiler with C++11 support (e.g., GCC, Clang, or MSVC)
- Standard C++ libraries

## How to Compile

### Using g++ (GNU Compiler Collection)

```bash
g++ -std=c++11 main.cpp -o gym_system
```

### Using Clang

```bash
clang++ -std=c++11 main.cpp -o gym_system
```

### Using Visual Studio (Windows)

1. Open Visual Studio
2. Create a new C++ project
3. Add the main.cpp file to your project
4. Build the solution (F7 or Ctrl+Shift+B)

## How to Run

After compiling, run the executable:

```bash
./gym_system  # On Linux/Mac
```
or
```bash
gym_system.exe  # On Windows
```

## Usage

The application presents a menu-driven interface with the following options:

1. **Add New Member**: Enter member details such as name, age, phone number, and membership type
2. **View All Members**: Display all currently registered members in a tabular format
3. **Update Member Details**: Modify an existing member's information by entering their member ID
4. **Delete Member**: Remove a member from the system by entering their member ID
5. **Exit**: Close the application

## Validation Rules

- **Names**: Must contain only letters and spaces
- **Ages**: Must be between 1 and 120
- **Phone Numbers**: Must be exactly 10 digits

## Class Structure

- **Member**: Represents an individual gym member with personal and membership details
- **GymMembershipSystem**: Manages the collection of members and provides system operations

## Future Enhancements

Potential improvements for future versions:

- Persistent storage (file or database)
- Search functionality
- Membership renewal and payment tracking
- Attendance tracking
- Reports and statistics
- User authentication for staff

## License

Null

## Author

ME ._.
