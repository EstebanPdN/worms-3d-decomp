/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_notify_global_800fde64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fde98 = 0x800fde98;
fn_800fdf58 = 0x800fdf58;
fn_8016f650 = 0x8016f650;
fn_801720fc = 0x801720fc;
fn_8019a2a8 = 0x8019a2a8;
lbl_803a54e4 = 0x803a54e4;
SECTIONS {
  .text.w3d_s20_notify_global_800fde64 0x800fde64 : { *(.text.w3d_s20_notify_global_800fde64) }
  .text.w3d_s20_notify_global_800fdf24 0x800fdf24 : { *(.text.w3d_s20_notify_global_800fdf24) }
  .text.w3d_s20_forward_table_entry_8016a538 0x8016a538 : { *(.text.w3d_s20_forward_table_entry_8016a538) }
  .text.w3d_s20_get_selected_80172050 0x80172050 : { *(.text.w3d_s20_get_selected_80172050) }
  .text.w3d_s20_has_record_80199f38 0x80199f38 : { *(.text.w3d_s20_has_record_80199f38) }
  .sdata 0x804aaf64 (NOLOAD) : {
    . = 0x0; lbl_804aaf64 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
