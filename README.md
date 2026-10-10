# TapNGo – A Bus Fare Verification and Payment System

## 1. Project Overview

TapNGo is a proposed C++-based bus fare verification and payment system designed to reduce boarding delays and improve fare verification in public transportation.

The system aims to track seat occupancy, verify passenger fares through a simulated card-tapping mechanism, and display seat verification status on a driver panel. It will help the driver determine whether the bus is ready to depart.

## 2. Problem Statement

Traditional bus fare collection can create delays during boarding, especially when multiple passengers need to complete fare verification. It can also be difficult to monitor whether all occupied seats have completed the verification process.

TapNGo aims to address these challenges through a seat-level verification system that tracks occupancy and fare verification status.

## 3. Objectives

- To maintain the occupancy status of individual bus seats.
- To distinguish between verified and unverified occupied seats.
- To simulate card-based fare verification.
- To display seat status through a driver status panel.
- To determine departure readiness based on fare verification status.
- To apply Data Structures and Object-Oriented Programming concepts in a practical problem.

## 4. Proposed System Design

The proposed system will use three seat states:

- **Empty:** No passenger is occupying the seat.
- **Occupied – Unverified:** A passenger occupies the seat, but fare verification is pending.
- **Occupied – Verified:** The passenger occupies the seat and fare verification is complete.

The system will aim to allow departure only when every occupied seat has been verified.

## 5. Proposed Modules

| Module | Responsibility |
|---|---|
| Seat Management | Maintain seat information and seat states. |
| Occupancy Management | Track changes in seat occupancy. |
| Fare Management | Handle fare-related information. |
| Card Verification | Simulate card tapping and fare verification. |
| Data Management | Maintain and validate system data. |
| Database Module | Provide a planned location for database-related functionality, if implemented. |
| Driver Status Panel | Display seat occupancy and verification status. |
| Departure Management | Determine whether the bus is ready to depart. |

## 6. Technologies and Concepts

**Programming Language:** C++

**Core Concepts:**
- Object-Oriented Programming (OOP)
- Classes and Objects
- Encapsulation and Data Abstraction
- Arrays
- Linked Lists
- Queues
- Conditional Statements and Functions
- Modular Programming

**Development Environment:** Visual Studio Code with a suitable C++ compiler.

## 7. Proposed Project Structure

The following folder structure is planned for organizing the project modules and tests.

```text
TapNGo/
│
├── src/
│   ├── Seat/
│   ├── Occupancy/
│   ├── Fare/
│   ├── Verification/
│   ├── Data/
│   ├── Database/
│   ├── Driver/
│   └── Departure/
│
├── tests/
│   ├── test_seat.cpp
│   ├── test_verification.cpp
│   ├── test_queue.cpp
│   └── test_integration.cpp
│
├── main.cpp
└── README.md
```



## 8. Team Contributions

- **Karnika Jain – Team Lead:** Planned system architecture, OOP design, and seat management logic.
- **Anirudh Bahuguna – Developer:** Planned card verification functionality and integration of fare verification with seat status updates.
- **Aaditya Budakoti – Data Management and Testing:** Planned data management, seat-state validation, and test-case preparation.
- **Aparajita Pant – Developer and Documentation:** Planned departure readiness logic, driver status panel, module integration.

## 9. Current Project Status

The project is currently in the planning and documentation stage. The system design, proposed modules, and team responsibilities are being documented. Implementation, integration, and testing will be carried out during the development phase.

## 10. Future Scope

- Integration with physical smart cards or NFC-based payment devices.
- Connection to a real-time seat occupancy detection system.
- Database integration for storing verification and transaction records.
- Improved driver dashboard and reporting features.
- Testing with larger simulated passenger loads.

---

**Project:** TapNGo – A Bus Fare Verification and Payment System  
**Academic Session:** 2026–2027  
**Semester:** III  
**Department:** Computer Science and Engineering  
**Institution:** Graphic Era (Deemed to be University), Dehradun
