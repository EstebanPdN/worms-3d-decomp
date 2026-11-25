/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g5a_turns_cleanup_80154aa8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_801628ec = 0x801628ec;
free_802134fc = 0x802134fc;
vtable_80410f40 = 0x80410f40;
SECTIONS {
  .text.g5a_turns_cleanup_80154aa8 0x80154aa8 : { *(.text.g5a_turns_cleanup_80154aa8) }
  .sdata 0x804ab400 (NOLOAD) : {
    . = 0x0; singleton_804ab400 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
