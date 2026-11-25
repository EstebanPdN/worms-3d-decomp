/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30e_load_sample_801dd0e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8036564c = 0x8036564c;
lbl_803b0110 = 0x803b0110;
lbl_803b0118 = 0x803b0118;
strstr = 0x802efd14;
w3d_auto_801df1e4 = 0x801df1e4;
w3d_auto_801df1f0 = 0x801df1f0;
w3d_auto_801df20c = 0x801df20c;
w3d_constant_801df10c = 0x801df10c;
w3d_constant_801df114 = 0x801df114;
w3d_r24b_invoke_ready_callback_8020fcb4 = 0x8020fcb4;
w3d_s21_append_ref_801ddf5c = 0x801ddf5c;
w3d_s21_copy_from_801df11c = 0x801df11c;
w3d_s21_get_item_801de10c = 0x801de10c;
w3d_s21_has_name_801ddff4 = 0x801ddff4;
w3d_s21_index_of_name_801de080 = 0x801de080;
w3d_set_801df1dc = 0x801df1dc;
w3d_set_801df234 = 0x801df234;
w3d_set_801df280 = 0x801df280;
w3d_setf_801df1fc = 0x801df1fc;
w3d_setf_801df204 = 0x801df204;
SECTIONS {
  .text.w3d_d30e_load_sample_801dd0e8 0x801dd0e8 : { *(.text.w3d_d30e_load_sample_801dd0e8) }
  .rodata 0x803b01bc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
