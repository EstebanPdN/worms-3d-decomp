/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx15a_score_splash_80011c58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
damage_800105cc = 0x800105cc;
lookup_80341694 = 0x80341694;
radius_80010608 = 0x80010608;
score_80011950 = 0x80011950;
SECTIONS {
  .text.w3d_cx15a_score_splash_80011c58 0x80011c58 : { *(.text.w3d_cx15a_score_splash_80011c58) }
  .rodata 0x8036a3d8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
