# ConsoleRPG

A C++ console RPG set in a dark fantasy world of Beyonders — featuring real-time grid-based combat, pathway abilities, sealed artifacts, and a narrative-driven story told entirely through the terminal.

---

## About

ConsoleRPG is a Phase 1 learning project focused on building a fully playable RPG from scratch in C++ using only the Windows console. The game draws lore inspiration from the *Lord of the Mysteries* universe, where humans ascend power sequences called **Pathways** and wield mysterious **Sealed Artifacts**.

The player wakes up to chaos outside their window, chooses a Sealed Artifact to carry, and is immediately thrown into real-time combat against a mutated enemy creature.

---

## Features

- **Character Creation** — Choose your name, gender, and Pathway
- **Three Pathways**, each with unique combat abilities:
  - `Fool` — Diagonal strike range
  - `Error` — Cardinal (cross) strike range; Ultimate swaps positions with the enemy
  - `Door` — Full row/column strike range; Ultimate banishes the enemy to the farthest tile
- **Three Sealed Artifacts** to choose from:
  - `Sea God Scepter` — Channels lightning domain power (damage over time aura)
  - `Staff of Stars` — Copies abilities of other Beyonders
  - `Life's Cane` — Harnesses reproduction and mutation powers
- **Real-time grid combat** with enemy telegraph/attack system
- **HP and XP system** — spend XP to heal, use ultimate abilities, or activate your artifact
- **Typewriter-style narrative text** for story delivery
- **Keyboard-driven menu navigation** with arrow keys

---

## Controls (Combat)

| Key        | Action                        |
|------------|-------------------------------|
| Arrow Keys | Move player                   |
| `Q`        | Attack                        |
| `E`        | Use Ultimate (costs 15 XP)    |
| `Z`        | Activate Sealed Artifact (costs 10 XP) |
| `H`        | Heal (costs 5 XP, +2 HP)      |
| `Esc`      | Exit combat                   |

---

## Tech Stack

- **Language:** C++17
- **Platform:** Windows (uses `windows.h`, `conio.h`)
- **Compiler:** g++ via MinGW64
- **Build System:** `mingw32-make`
- **IDE:** CodeLite (or any IDE with MinGW support)

---

## Project Structure

```
ConsoleRPG/
├── main.cpp
├── Game.cpp / Game.h
├── Combat.cpp / Combat.h
├── Renderer.cpp / Renderer.h
├── NavigationSystem.cpp / NavigationSystem.h
├── CharacterCreation.cpp / CharacterCreation.h
├── CharacterAttributes.cpp / CharacterAttributes.h
├── PlayerData.h
├── Entities.h
└── Position.h
```

---

## Build Instructions

1. Make sure **MinGW64** is installed and `g++` is on your PATH
2. Open the project in CodeLite (or configure your own Makefile)
3. Build with:
```bash
mingw32-make
```
4. Run the output:
```bash
./build-Debug/bin/ConsoleRPG.exe
```

---

## Status

> Phase 1 — Active Development. Core combat loop and character creation are functional. Story and additional enemies are in progress.

---

## Learning Goals

This project is part of a personal game development learning journey. Phase 1 focuses on:
- C++ fundamentals (structs, enums, references, header/source separation)
- Real-time input handling in the console
- Simple AI (enemy pathfinding toward the player)
- Game loop architecture
