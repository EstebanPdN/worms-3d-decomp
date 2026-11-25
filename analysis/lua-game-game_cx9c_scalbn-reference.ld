/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9c_scalbn_802e8a28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx9c_copysign_802e9e20 = 0x802e9e20;
SECTIONS {
  .text.w3d_cx9c_scalbn_802e8a28 0x802e8a28 : { *(.text.w3d_cx9c_scalbn_802e8a28) }
  .sdata 0x804ac2f0 (NOLOAD) : {
    . = 0x0; cx9c_constant_804ac2f0 = .;
    . = 0x8; cx9c_constant_804ac2f8 = .;
    . = 0x10; cx9c_constant_804ac300 = .;
    . = 0x18; cx9c_constant_804ac308 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
