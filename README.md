# 🎮 Lord of the Broken — ConsoleRPG

> A real-time, narrative-driven RPG built entirely in C++17 for the Windows terminal — no game engine, no frameworks, pure C++ and Win32.

---

## 📖 Overview

**Lord of the Broken** is a real-time console RPG set in a dark fantasy world of Beyonders — supernatural humans who ascend power sequences called **Pathways**. The player chooses their Pathway, picks a **Sealed Artifact**, and battles corrupted creatures in a grid-based combat arena — all rendered live in the terminal.

Every system in this project — the game loop, combat engine, enemy AI, renderer, and UI navigation — was designed and built from scratch in C++.

---

## 🎬 Gameplay

The player wakes up to chaos outside their window. A city-wide supernatural alert is in effect. They grab one of three Sealed Artifacts and rush out — only to be ambushed by a mutated creature in the hallway.

From there, it's real-time combat: move, attack, dodge telegraphed enemy strikes, manage HP and XP, and use your Pathway's ultimate ability to turn the fight.

---

## ⚔️ Combat System

The combat arena is a live grid rendered in the terminal. Both the player and enemy act in real time.

| Key | Action |
|-----|--------|
| Arrow Keys | Move on the grid |
| `Q` | Attack (range varies by Pathway) |
| `E` | Ultimate ability (costs 15 XP) |
| `Z` | Activate Sealed Artifact (costs 10 XP) |
| `H` | Heal +2 HP (costs 5 XP) |
| `Esc` | Exit combat |

**Enemy behaviour:** The enemy telegraphs its attack by marking the target tile `'o'` for one second before impact `'X'`. Dodging rewards XP; taking the hit costs HP.

---

## 🌀 Pathways

Each Pathway gives the player a distinct attack range and a unique ultimate ability, fundamentally changing how combat is approached.

| Pathway | Attack Range | Ultimate |
|---------|-------------|---------|
| **Fool** | Diagonal tiles | Instantly destroys the enemy |
| **Error** | Cardinal cross (4 directions) | Swap positions with the enemy |
| **Door** | Entire row and column | Banish the enemy to the farthest tile on the grid |

---

## 🏺 Sealed Artifacts

Before combat, the player chooses one artifact to carry. Each has a unique active effect triggered in combat.

| Artifact | Effect |
|----------|--------|
| **Sea God Scepter** | Deals 1 damage per second for 6 seconds (damage over time aura) |
| **Staff of Stars** | Channel the copied abilities of other Beyonders |
| **Life's Cane** | Harness powers of reproduction and mutation |

---

## 🏗️ Technical Details

### Systems Built From Scratch

**Game Loop**
Tick-based loop with `Sleep(30)` rate control, cleanly separated into input → update → render phases per frame.

**Real-Time Input**
Non-blocking keyboard input via `_kbhit()` and `_getch()`, allowing the player and enemy to act simultaneously without waiting on input.

**Enemy AI**
Manhattan distance pathfinding — the enemy calculates the dominant axis toward the player each tick and steps accordingly, with a configurable move delay.

**Telegraph & Impact System**
A two-phase attack system with independent timers: a 1-second warning phase (`'o'`) followed by a 250ms impact phase (`'X'`), implemented using `GetTickCount()` deltas.

**Console Renderer**
Full arena re-render each frame using `system("cls")` with Win32 color attributes for hit feedback. Inline menu renderer uses `SetConsoleCursorPosition` to update in-place without clearing the screen.

**Navigation System**
A reusable, overloaded `RunNavigation()` function that powers every menu in the game — supports both full-screen and inline rendering modes, horizontal and vertical layouts.

**Typewriter Text Engine**
Character-by-character narrative output with configurable millisecond delay for cinematic story delivery.

### Architecture

```
ConsoleRPG/
├── main.cpp                  — Entry point and top-level flow
├── StartMenu.cpp/h           — Start menu
├── CharacterCreation.cpp/h   — Name input, gender and pathway selection
├── Game.cpp/h                — Story narrative and scene management
├── Combat.cpp/h              — Game loop, player update, enemy update
├── Renderer.cpp/h            — Arena, menu, and typewriter rendering
├── NavigationSystem.cpp/h    — Reusable keyboard navigation system
├── Entities.h                — Enemy struct
├── PlayerData.h              — Player state (HP, XP, Pathway, Artifact)
├── CharacterAttributes.h     — Enums: Gender, Pathway, SealedArtifacts
└── Position.h                — Shared grid position struct
```

---

## 🛠️ Tech Stack

| | |
|---|---|
| **Language** | C++17 |
| **Platform** | Windows |
| **APIs** | Win32 (`windows.h`), `conio.h` |
| **Compiler** | g++ / MinGW64 |
| **Build** | `mingw32-make` |

---

## 🚀 Build & Run

**Requires:** MinGW64 with `g++` on your PATH

```bash
git clone https://github.com/YOUR_USERNAME/ConsoleRPG.git
cd ConsoleRPG
mingw32-make
./build-Debug/bin/ConsoleRPG.exe
```

> ⚠️ Windows only — relies on Win32 console APIs
