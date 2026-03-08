# 🎮 Lord of the Broken — ConsoleRPG

> A real-time, narrative-driven RPG built entirely in the Windows terminal using C++17 — no game engine, no libraries, just raw C++ and the Win32 console API.

---

## 📖 Overview

**Lord of the Broken** is a C++ console RPG inspired by the *Lord of the Mysteries* universe. Players ascend a **Pathway** — a supernatural power sequence — choose a **Sealed Artifact**, and are thrown into real-time grid-based combat against corrupted Beyonder creatures.

The project was built from scratch as part of a personal game development learning journey, with the goal of understanding how games work at a low level — game loops, real-time input, rendering, entity systems, and state management — all without relying on any game engine or third-party framework.

---

## ✨ Features

### 🧠 Systems Built From Scratch
- **Real-time game loop** with `Sleep(30)` tick-rate control
- **Keyboard-driven UI navigation** system with two schemes — Horizontal and Vertical — both supporting arrow key input and live cursor rendering via `▶`
- **Typewriter text renderer** for narrative delivery, character by character with configurable delay
- **Console arena renderer** with Win32 color highlighting (red flash on enemy hit)
- **Enemy telegraph & attack system** — enemy signals its attack tile `'o'` for 1 second before impact `'X'`, punishing stationary players and rewarding XP for dodging

### ⚔️ Combat System
| Key | Action |
|-----|--------|
| Arrow Keys | Move player on the grid |
| `Q` | Attack (range depends on Pathway) |
| `E` | Use Ultimate ability (costs 15 XP) |
| `Z` | Activate Sealed Artifact (costs 10 XP) |
| `H` | Heal +2 HP (costs 5 XP) |
| `Esc` | Exit combat |

### 🌀 Three Pathways — Each Changes Your Playstyle
| Pathway | Attack Range | Ultimate |
|---------|-------------|---------|
| **Fool** | Diagonal tiles only | Instantly kills the enemy |
| **Error** | Cardinal cross (up/down/left/right) | Swap positions with the enemy |
| **Door** | Entire row and column | Teleport enemy to the farthest possible tile |

### 🏺 Three Sealed Artifacts
| Artifact | Power |
|----------|-------|
| **Sea God Scepter** | Deals 1 damage per second for 6 seconds (damage over time aura) |
| **Staff of Stars** | Copy and channel the abilities of other Beyonders |
| **Life's Cane** | Harness powers of reproduction and mutation |

### 👤 Character Creation
- Custom character name (up to 250 characters, with real-time length counter and overflow warning)
- Gender selection
- Pathway selection
- Confirmation screen before finalising

---

## 🏗️ Architecture

The project is split into focused, single-responsibility modules:

```
ConsoleRPG/
├── main.cpp                  — Entry point, start menu, top-level flow
├── StartMenu.cpp/h           — Start menu rendering and choice enum
├── CharacterCreation.cpp/h   — Name input, gender/pathway selection
├── Game.cpp/h                — Story narrative and game flow
├── Combat.cpp/h              — Game loop, player & enemy update logic
├── Renderer.cpp/h            — Arena rendering, menu rendering, typewriter text
├── NavigationSystem.cpp/h    — Reusable keyboard navigation for all menus
├── Entities.h                — Enemy struct definition
├── PlayerData.h              — PlayerData struct (HP, XP, Pathway, Artifact)
├── CharacterAttributes.h     — Enums: Gender, Pathway, SealedArtifacts
└── Position.h                — Shared Position struct (row, col)
```

Key design decisions:
- **`Position` is isolated** in its own header to break the circular dependency between `Combat.h` and `Entities.h`
- **`RunNavigation` is overloaded** — one version for full-screen menus (clears screen per tick), another for inline menus that renders in-place using `SetConsoleCursorPosition` without clearing the screen
- **Enemy AI** uses Manhattan distance pathfinding — moves one step per tick toward the player along the dominant axis

---

## 🛠️ Tech Stack

| | |
|---|---|
| **Language** | C++17 |
| **Platform** | Windows |
| **APIs Used** | `windows.h` (console color, cursor positioning, timing), `conio.h` (raw keyboard input) |
| **Compiler** | g++ via MinGW64 |
| **Build System** | `mingw32-make` |

---

## 🚀 Build & Run

**Requirements:** MinGW64 with g++ on your PATH

```bash
# Clone the repo
git clone https://github.com/YOUR_USERNAME/ConsoleRPG.git
cd ConsoleRPG

# Build
mingw32-make

# Run
./build-Debug/bin/ConsoleRPG.exe
```

> ⚠️ Windows only — relies on Win32 console APIs (`windows.h`, `conio.h`)

---

## 🎯 What I Learned Building This

- How a **real-time game loop** works — separating input, update, and render phases
- Managing **game state** across multiple systems without a framework
- Handling **raw keyboard input** with `_kbhit()` and `_getch()` for non-blocking reads
- Using **Win32 console APIs** for cursor positioning, color output, and tick-based timing with `GetTickCount()`
- Designing **reusable systems** — the navigation system works for every menu in the game with a single function
- Debugging **circular header dependencies** and structuring includes correctly in multi-file C++ projects
- Thinking through **data ownership** — when to pass by value vs reference, and when `const` matters

---

## 📌 Status

> ✅ **Completed — Phase 1 Learning Project**
> This project is complete as a self-contained learning milestone. All core systems — combat, navigation, character creation, and rendering — are fully functional. It is intentionally preserved in its current state as a snapshot of Phase 1 game development learning.
