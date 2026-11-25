/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k2a_fade_step_8002c118)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_8002bc14 = 0x8002bc14;
w3d_f32_8037263c = 0x8037263c;
w3d_f32_80372640 = 0x80372640;
SECTIONS {
  .text.k2a_fade_step_8002c118 0x8002c118 : { *(.text.k2a_fade_step_8002c118) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
