# TapNGo: How It Works

Ever seen a bus crawl to a stop because everyone is queued up at the door while the conductor checks fares? TapNGo is our fix for that.

Instead of checking everyone at the entrance, we check at the **seat**. You sit down, tap your card, and you're verified. The driver gets a live view of which seats are paid up, and the bus only leaves when everyone on board is sorted. No manual headcount, no bottleneck at the door.

Everything runs in C++ using plain data structures (arrays, linked lists and queues) and OOP, with no database involved.

---

## The Big Picture

Here is how a passenger's journey flows through the system.

```mermaid
flowchart LR
    subgraph IN["What happens on the bus"]
        A["Passenger sits down"]
        B["Passenger taps their card"]
    end

    subgraph CORE["TapNGo (built in C++)"]
        C["Seat Tracker<br/>keeps tabs on every seat"]
        D["Card Checker<br/>confirms the fare is paid"]
        E["Driver's Dashboard<br/>shows the seat map and decides when to go"]
    end

    subgraph STORE["In-memory records"]
        F[("Seat list and event log<br/>arrays, linked lists, queue")]
    end

    subgraph OUT["What the driver sees"]
        G["Live seat map<br/>grey / red / green"]
        H["Go or hold decision"]
    end

    A --> C
    B --> D
    C -->|"someone is sitting here, not paid yet"| D
    D -->|"card is valid, seat is now verified"| C
    C --> F
    D --> F
    C --> E
    E --> G
    E --> H
```

---

## Life of a Seat

Every seat on the bus is always in one of three moods.

```mermaid
stateDiagram-v2
    state "Empty" as Empty
    state "Occupied, not yet verified" as Unverified
    state "Occupied and verified" as Verified

    [*] --> Empty
    Empty --> Unverified: someone sits down
    Unverified --> Verified: card tapped and accepted
    Unverified --> Empty: they get up
    Verified --> Empty: they get off
```

---

## Can We Leave Yet?

Before the bus moves, it quickly asks itself one question: is anyone sitting here without having paid?

```mermaid
flowchart TD
    S(["Driver is ready to depart"]) --> L["Check every seat"]
    L --> Q{"Is anyone seated<br/>but not verified?"}
    Q -->|"Yes"| W["Hold on a moment<br/>those seats show up red on the dashboard"]
    Q -->|"No"| G["All clear, the bus can go"]
    W --> L
    G --> LOG["Note it in the log"]
```

---

## Who Does What

| Team member | Role | Task completed | Part of the system |
|---|---|---|---|
| Karnika Jain | Lead | Seat management classes, seat state logic, and OOP architecture | Seat Tracker |
| Anirudh Bahuguna | Developer | Card Verifier, and connecting fare verification to seat state updates | Card Checker |
| Aaditya Budakoti | Data and Testing | Data management, seat state validation, and test cases | Seat Tracker and testing |
| Aparajita Pant | Developer and Docs | Departure readiness logic, driver status panel, and module integration | Driver's Dashboard |

---

## What We Built It With

C++ (with the STL), Visual Studio Code, and Git/GitHub to keep the four of us in sync.
