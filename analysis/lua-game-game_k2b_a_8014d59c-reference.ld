/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_is_near_ground_8014d59c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ground_probe_800b0824 = 0x800b0824;
w3d_motion_get_contact_point = 0x8014c4cc;
SECTIONS {
  .text.w3d_k2b_is_near_ground_8014d59c 0x8014d59c : { *(.text.w3d_k2b_is_near_ground_8014d59c) }
  .rodata 0x803a1630 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; w3d_global_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
