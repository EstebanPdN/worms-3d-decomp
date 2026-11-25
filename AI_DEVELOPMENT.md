# Development process

This document describes the local Worms 3D source-recovery project. The original
Worms 3D game was developed by Team17; this project does not attribute that game
to Codex.

Codex assists with tool orchestration, instruction analysis, reconstructed C,
verification scripts and documentation. REA and Ghidra provide retained binary
observations. Original instructions, compiler-built ELF comparisons and
independent behavioral contracts decide which recovered functions are admitted.
Readable pseudocode, inferred names and generated code are not completion proof.

Original game inputs and private evidence remain local. Exact instruction
coverage, bounded behavioral reconstruction, a complete source build and native
platform acceptance are tracked separately. Unknown dependencies remain explicit.
