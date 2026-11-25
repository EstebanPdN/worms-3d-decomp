/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31d_lights_remove_80157a30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
format_803442b4 = 0x803442b4;
SECTIONS {
  .text.w3d_d31d_lights_remove_80157a30 0x80157a30 : { *(.text.w3d_d31d_lights_remove_80157a30) }
  .rodata 0x803a2c04 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; world_804b1788 = .;
    . = 0x64; engine_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
