/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29b_water_light_800919d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80414840 = 0x80414840;
lbl_80431ea0 = 0x80431ea0;
lbl_8045e788 = 0x8045e788;
sqrt_802e82c0 = 0x802e82c0;
w3d_array_ref_lock_801ef048 = 0x801ef048;
w3d_create_8020b680 = 0x8020b680;
w3d_find_peer_800be8f8 = 0x800be8f8;
SECTIONS {
  .text.w3d_d29b_water_light_800919d4 0x800919d4 : { *(.text.w3d_d29b_water_light_800919d4) }
  .rodata 0x8037e868 : { *(.rodata) }
  .sdata 0x804aab84 (NOLOAD) : {
    . = 0x0; lbl_804aab84 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
