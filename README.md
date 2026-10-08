TapNGo/
├── include/
│   ├── Seat.h
│   ├── SeatManager.h
│   ├── Payment.h
│   ├── CardPayment.h
│   ├── CardVerifier.h
│   ├── Passenger.h
│   ├── Transaction.h
│   ├── TransactionQueue.h
│   ├── DriverControl.h
│   └── DepartureController.h
├── src/
│   ├── seat/
│   │   ├──Seat.cpp
│   │   ├──SeatManager.cpp
│   ├── fare/
│   │   ├──Payment.cpp
│   ├── verification/
│   │   ├──CardPayment.cpp
│   │   ├──CardVerifier.cpp
│   ├── passenger/
│   │   ├──Passenger.cpp
│   ├── transaction/
│   │   ├──Transaction.cpp
│   │   ├──TransactionQueue.cpp
│   ├── control/
│   │   ├──DepartureController.cpp
│   │   ├──DriverControl.cpp
│
├── tests/
│   ├── test_seat.cpp
│   ├── test_verification.cpp
│   ├── test_queue.cpp
│   └── test_integration.cpp
│
├── main.cpp
└── README.md