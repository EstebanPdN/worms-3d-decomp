/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_static_init_801651e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_callback_target_80162ce8 = 0x80162ce8;
w3d_obj_80361950 = 0x80361950;
w3d_obj_803e88cc = 0x803e88cc;
w3d_s21_construct_8020fbd0 = 0x8020fbd0;
w3d_service_get_802ee7dc = 0x802ee7dc;
SECTIONS {
  .text.w3d_k2b_static_init_801651e8 0x801651e8 : { *(.text.w3d_k2b_static_init_801651e8) }
  .sdata 0x804b00c4 (NOLOAD) : {
    . = 0x0; w3d_global_804b00c4 = .;
    . = 0x4; w3d_global_804b00c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
