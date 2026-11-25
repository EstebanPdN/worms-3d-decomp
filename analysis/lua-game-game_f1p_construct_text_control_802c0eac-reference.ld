/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_construct_text_control_802c0eac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015fef0 = 0x8015fef0;
fn_803426b8 = 0x803426b8;
one_803d84b8 = 0x803d84b8;
vt_8041c8a0 = 0x8041c8a0;
z_803d84bc = 0x803d84bc;
zero_803d84b4 = 0x803d84b4;
SECTIONS {
  .text.w3d_construct_text_control_802c0eac 0x802c0eac : { *(.text.w3d_construct_text_control_802c0eac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
