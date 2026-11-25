# Worms 3D Decomp

I started recovering the European GameCube version of *Worms 3D* so I could bring it to New Nintendo 3DS. This is my recovery work, the function tracker I used along the way, and my native Apple Silicon port. Both ports read game data from your own disc.

[Explore the function map](https://estebanpdn.github.io/worms-3d-decomp/) · [Download the Mac app](https://github.com/EstebanPdN/worms-3d-decomp/releases/tag/macos-preview-01) · [Worms 3DS](https://github.com/EstebanPdN/worms-3ds)

This project was developed with the help of [OpenAI Codex](https://openai.com/codex/) and [Claude Code](https://claude.com/product/claude-code). Learn more about the development process [here](AI_DEVELOPMENT.md).

## How much have I recovered?

**17,214 functions covering 3,017,696 of 3,523,296 instruction bytes (85.64980064%)** for disc ID `GWMP8P`, revision 0. My ledger counts a function once its linked instructions match the reference build. The denominator is the size of all nonempty text sections in the original DOL, including the startup section. A short function contributes fewer bytes than a long one. Data, textures, levels, music, scripts, and playability are outside this percentage.

| Source recorded in my ledger | Functions | Exact instruction bytes |
| --- | ---: | ---: |
| My project's matching units, including generated families and automatic decompilation | 16,719 | 2,928,436 |
| Lua runtime and library build variants | 383 | 67,016 |
| Public Lua, newlib and zlib sources matched directly | 112 | 22,244 |
| **All admitted units** | **17,214** | **3,017,696** |

The first row covers **83.11637739%** of the original text. It identifies where the matching implementation lives. It includes 7,722 functions in the generated-family directory and 1,811 in the automatic decompilation directory. I use those figures to track the work on my project. The records do not measure how many bytes I typed by hand. The original game and the libraries retain their own authorship.

You can check every recorded address, length and SHA-256 against your own disc. The verifier rejects overlaps and recomputes the denominator from the DOL header. This repeats the accounting and the disc comparison. The historical PowerPC compiler and per-unit ELF evidence used to admit a match are separate from the native Mac build.

```sh
python3 tools/verify_progress.py "/path/to/GWMP8P/sys/main.dol"
```

## Run on macOS

1. Use an Apple Silicon Mac with macOS 27 or later and a Metal-capable display environment. Install SDL3 with Apple Silicon Homebrew using `brew install sdl3`. The executable loads SDL3 from `/opt/homebrew/opt/sdl3/lib/libSDL3.0.dylib`.
2. Extract your own European GameCube disc into a folder. Using [nodtool](https://github.com/encounter/nod/releases/tag/v2.0.0-alpha.12), run `nodtool extract "Worms 3D.rvz" "GWMP8P"`. The same command accepts a clean GameCube ISO. Keep the full `files/` and `sys/` directories together. The expected SHA-256 of `sys/main.dol` is `bb1b36b9bbb806688e616208254907ae2af59d2e191ff839b3a046a6c2c6f514`.
3. Download and unzip **Worms-3D-macOS-arm64.zip**. Open **Worms 3D.app** and select the extracted folder. To pass it on launch, use the command below. The preview is ad-hoc signed. macOS may ask you to approve opening a downloaded app in **Privacy & Security**.

```sh
open -a "./Worms 3D.app" --args "$PWD/GWMP8P"
```

Press **Return** at the title. Use the **arrow keys** to navigate, **Space** for A and **left Shift** for B. Click the lower screen for touch controls. On a controller the right face button is A and the lower face button is B. Save data lives under `~/Library/Application Support/Worms3D/`.

## Build the Mac app

I used Apple Clang on Apple Silicon, Python 3, zsh and Homebrew SDL3. Install the Xcode command-line tools and select an SDK that supports macOS 27. The build compiles the recovered units as native arm64 code, emits LLVM IR for the linker, then links the platform code against SDL3 and Metal. Allow several GB of temporary space.

```sh
git clone https://github.com/EstebanPdN/worms-3d-decomp.git
cd worms-3d-decomp
brew install sdl3
python3 tools/verify_progress.py "/path/to/GWMP8P/sys/main.dol"
zsh port/build.sh "/path/to/GWMP8P"
zsh port/package-macos.sh
open -a "./port/build/Worms 3D.app" --args "/path/to/GWMP8P"
```

The default output directory is `port/build/`. The app includes my port code and twelve interface graphics drawn for the port. It reads original textures, scripts, levels, audio and DOL data from your extracted folder. I left the optional *Ultimate Mayhem* asset packs out of this preview.

## Where to find the code

- [Matching source](source/matching) and [unit definitions](config/GWMP8P/game-units) contain the C/C++ implementations, reference entry points and per-unit settings.
- [Recovery ledger](analysis/recovery-ledger.json) and [reference linker scripts](analysis) record the function identities, lengths, instruction hashes and placements. Historical `build/lua-*-source` names in the ledger refer to intermediate Lua builds. The upstream Lua distribution and the converted native sources are in [source/vendor](source/vendor) and [port/core/lua](port/core/lua).
- [Native core](port/core), [platform layer](port/platform) and [conversion and linking tools](port/tools) build the Mac version. Some unmatched routines still use mechanically translated C++ or stubs. They do not increase the exact-match total.
- [Tracker source and public data](docs) are the HTML, JavaScript, styles and function map served by GitHub Pages. To run the site locally, use `python3 -m http.server 8000 --directory docs` and open `http://localhost:8000/`.

## Credits

I recovered and organized the matching units, built the tracker and developed the native ports. Team17 developed *Worms 3D*. The game, artwork, audio and trademarks belong to their respective rights holders.

Lua, zlib, newlib, STLport and the GCC STL contributors wrote the libraries used in this work. Their copyright notices, license terms and source provenance are retained with the [vendor sources](source/vendor). SDL3 is provided separately by the SDL project. I used Ghidra for function discovery and REA for instruction analysis. Nunito and Lilita One carry their respective SIL Open Font License notices in [the tracker assets](docs/assets).
