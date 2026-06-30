# 🎲 DadoSim — Dice Roll Simulator in C++ 🎲

A command-line dice simulator written in C++.
Rolls a 6-sided die N times, saves the visual history to one file, and automatically generates statistics with a bar chart in another.

---

## Features

- Rolls a 6-sided die as many times as you choose
- **Normal mode**: saves each roll with its ASCII representation in `out/historial_*.txt`
- **Fast mode**: skips the ASCII art and only saves statistics, ideal for millions of rolls
- Generates `out/estadistica_*.txt` with a bar chart and the percentage for each face
- Measures and displays the total simulation time in milliseconds
- Output files are timestamped so they don't overwrite each other between runs (Unix/epoch time)

---

## Example Output

**History** (`out/historial_*.txt`):
```
Rolled a 3!
╭───────────╮
│  ●        │
│     ●     │
│        ●  │
╰───────────╯

Rolled a 1!
╭───────────╮
│           │
│     ●     │
│           │
╰───────────╯
```

**Statistics** (`out/estadistica_*.txt`):
```
Roll statistics:
Face 1: |||||||||||.....................................................................  11%
Face 2: |||||||||||||||.................................................................  15%
Face 3: |||||||||||||||||...............................................................  17%
Face 4: |||||||||||||||||||.............................................................  19%
Face 5: ||||||||||||||||||..............................................................  18%
Face 6: ||||||||||||||||||||............................................................  20%
Total simulation time: 3 ms
```

---

## Requirements

- C++17 compiler or higher (g++ recommended)

## Commands
```
- make program        # Compiles the program (creates the "out" folder if it doesn't exist)
- make clean          # Deletes all files inside the "out" folder
```

---

## Build

```bash
make (program)
```

This generates the `program.exe` executable.

---

## Usage

```
./program.exe       # Runs the program
```

The program will ask you:
1. The number of rolls you want to simulate
2. Whether you want to use fast mode (`Y`) or normal/slow mode (`N`)

Output files are automatically created in the `out/` folder.

---

## Project Structure

```
Dices/
├── include/
│   ├── dado.hh     # DadoInfo struct, ASCII faces, and declarations
│   └── menu.hh     # Console startup menu
├── src/
│   └── dado.cc     # Implementation: roll die, statistics
├── out/            # Generated files (history and statistics)
├── main.cc         # Entry point
└── Makefile
```

---


## Author

Martin (@martinmol2007)