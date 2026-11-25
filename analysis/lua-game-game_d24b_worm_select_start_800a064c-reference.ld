/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_worm_select_start_800a064c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_identity_803426b4 = 0x803426b4;
w3d_identity_80342a78 = 0x80342a78;
w3d_resource_property_800fc1b0 = 0x800fc1b0;
w3d_string_803808b0 = 0x803808b0;
w3d_string_803808c4 = 0x803808c4;
w3d_subscribe_80162024 = 0x80162024;
w3d_worm_select_800a04d4 = 0x800a04d4;
w3d_worm_select_update_800a12c0 = 0x800a12c0;
SECTIONS {
  .text.w3d_d24b_worm_select_start_800a064c 0x800a064c : { *(.text.w3d_d24b_worm_select_start_800a064c) }
  .sdata 0x804ae12c (NOLOAD) : {
    . = 0x0; w3d_message_804ae12c = .;
    . = 0x8; w3d_message_804ae134 = .;
    . = 0x10; w3d_message_804ae13c = .;
    . = 0x18; w3d_message_804ae144 = .;
    . = 0x20; w3d_message_804ae14c = .;
    . = 0x28; w3d_message_804ae154 = .;
    . = 0x30; w3d_message_804ae15c = .;
    . = 0x38; w3d_message_804ae164 = .;
    . = 0x40; w3d_message_804ae16c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
