/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8006d4cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8020b648 = 0x8020b648;
w3d_cached_message_id = 0x8015f5a0;
w3d_fn_801613f0 = 0x801613f0;
w3d_fn_80164514 = 0x80164514;
w3d_fn_80164fc8 = 0x80164fc8;
w3d_fn_80198744 = 0x80198744;
w3d_fn_8020b680 = 0x8020b680;
w3d_message_post_current = 0x8016239c;
w3d_slots_shared = 0x803439d8;
w3d_table_803ebc18 = 0x803ebc18;
w3d_table_803eee68 = 0x803eee68;
w3d_type_80410980 = 0x80410980;
w3d_type_80411a20 = 0x80411a20;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_fn_8006d4cc 0x8006d4cc : { *(.text.w3d_fn_8006d4cc) }
  .text.w3d_fn_8006d550 0x8006d550 : { *(.text.w3d_fn_8006d550) }
  .text.w3d_fn_8006df98 0x8006df98 : { *(.text.w3d_fn_8006df98) }
  .sdata 0x804aa840 (NOLOAD) : {
    . = 0x0; w3d_sound_id_804aa840 = .;
    . = 0x3014; w3d_message_804ad854 = .;
    . = 0x6f14; w3d_queue_804b1754 = .;
    . = 0x6f48; w3d_environment_804b1788 = .;
    . = 0x6f4c; w3d_manager_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
