/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_bind_text_control_properties_802c28a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc1b0 = 0x800fc1b0;
fn_802c37e4 = 0x802c37e4;
fn_80342a74 = 0x80342a74;
fn_80342a78 = 0x80342a78;
key_803d85a0 = 0x803d85a0;
key_803d85b4 = 0x803d85b4;
SECTIONS {
  .text.w3d_bind_text_control_properties_802c28a0 0x802c28a0 : { *(.text.w3d_bind_text_control_properties_802c28a0) }
  .sdata 0x804abb54 (NOLOAD) : {
    . = 0x0; current_804abb54 = .;
    . = 0x8; counter_804abb5c = .;
    . = 0xc; offset_804abb60 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
