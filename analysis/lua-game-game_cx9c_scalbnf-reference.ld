/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9c_scalbnf_802e8c1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx9c_copysignf_802e9e78 = 0x802e9e78;
SECTIONS {
  .text.w3d_cx9c_scalbnf_802e8c1c 0x802e8c1c : { *(.text.w3d_cx9c_scalbnf_802e8c1c) }
  .sdata 0x804ac310 (NOLOAD) : {
    . = 0x0; cx9c_constant_804ac310 = .;
    . = 0x4; cx9c_constant_804ac314 = .;
    . = 0x8; cx9c_constant_804ac318 = .;
    . = 0xc; cx9c_constant_804ac31c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
