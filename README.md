# Doodle Jump - Raylib Game

A platform game developed using the Raylib library.

## Features

- Platform jumping mechanics
- High jumps with trampolines
- Avoid monsters
- Projectile shooting system
- Score tracking and high score
- Menu system

## Requirements

- Raylib library
- C compiler (GCC)
- Make

## Building

### Method 1: Using Build Script (Easiest)

In PowerShell:

```powershell
.\build.ps1
```

Or in Command Prompt:

```cmd
build.bat
```

### Method 2: Using Makefile

To build using Makefile on Windows:

```bash
make
```

If raylib is installed in a different location, edit the `RAYLIB_PATH` variable in the Makefile:

```makefile
RAYLIB_PATH ?= C:/raylib/raylib
```

### Method 3: Manual Build

If the above methods don't work, build manually:

```bash
gcc main.c src/graphics.c src/audio.c src/player.c src/platform.c src/trampoline.c src/monster.c src/ball.c src/menu.c src/game.c -o game.exe -I. -IC:/raylib/raylib/src -IC:/raylib/raylib/src/external -LC:/raylib/raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm -std=c99
```

**Note:** Replace the raylib installation path (`C:/raylib/raylib`) with your own system's path.

### Running the Game

After building, run the game with:

```bash
game.exe
```

or

```bash
.\game.exe
```

## Controls

- **Left/Right Arrow Keys**: Move player
- **Key 1**: Shoot projectile up-left
- **Key 2**: Shoot projectile straight up
- **Key 3**: Shoot projectile up-right
- **Left Mouse Button**: Start game from menu / Play again after game over

## Project Structure

```
raylib-game/
├── src/
│   ├── config.h          # Constants and definitions
│   ├── types.h           # Struct definitions
│   ├── graphics.h/c      # Graphics loading
│   ├── audio.h/c         # Audio loading
│   ├── player.h/c        # Player logic
│   ├── platform.h/c      # Platform logic
│   ├── trampoline.h/c    # Trampoline logic
│   ├── monster.h/c       # Monster logic
│   ├── ball.h/c          # Projectile logic
│   ├── menu.h/c          # Menu screen
│   └── game.h/c          # Game logic
├── images/               # Image assets
├── sound/                # Audio assets
├── main.c                # Main program
├── Makefile              # Build file
├── build.ps1             # PowerShell build script
└── build.bat             # Batch build script
```

## Asset Files

Required image and audio files should be in the `images/` and `sound/` folders:

**images/** folder:
- `karakter.png` - Player character
- `platform.png` - Platform sprite
- `trampoline.png` - Trampoline sprite
- `monsters.png` - Monster sprite
- `background.png` - Game background
- `endgamebackground.png` - Game over background
- `menubackground.png` - Menu background

**sound/** folder:
- `background.mp3` - Background music
- `deathsound.mp3` - Death sound

## License

This project is developed for educational purposes.
