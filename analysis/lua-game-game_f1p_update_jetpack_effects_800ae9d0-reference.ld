/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_update_jetpack_effects_800ae9d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
end_803821e8 = 0x803821e8;
start_8038214c = 0x8038214c;
SECTIONS {
  .text.w3d_update_jetpack_effects_800ae9d0 0x800ae9d0 : { *(.text.w3d_update_jetpack_effects_800ae9d0) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
