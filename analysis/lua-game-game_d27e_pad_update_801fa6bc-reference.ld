/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27e_pad_update_801fa6bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
motor_80302104 = 0x80302104;
pads_8045e824 = 0x8045e824;
SECTIONS {
  .text.w3d_d27e_pad_update_801fa6bc 0x801fa6bc : { *(.text.w3d_d27e_pad_update_801fa6bc) }
  .rodata 0x803b1b20 : { *(.rodata) }
  .sdata 0x804ab910 (NOLOAD) : {
    . = 0x0; delay_804ab910 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
