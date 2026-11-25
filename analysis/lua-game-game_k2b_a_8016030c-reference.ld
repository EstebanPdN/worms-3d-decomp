/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_input_owner_construct_8016030c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ctor_801628b0 = 0x801628b0;
w3d_vtable_804116a8 = 0x804116a8;
SECTIONS {
  .text.w3d_k2b_input_owner_construct_8016030c 0x8016030c : { *(.text.w3d_k2b_input_owner_construct_8016030c) }
  .rodata 0x803a4650 : { *(.rodata) }
  .sdata 0x804b17f0 (NOLOAD) : {
    . = 0x0; w3d_input_804b17f0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
