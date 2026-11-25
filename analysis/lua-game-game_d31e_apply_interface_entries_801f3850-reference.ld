/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31e_apply_interface_entries_801f3850)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801f3a00 = 0x801f3a00;
lbl_803b0dbc = 0x803b0dbc;
memcmp = 0x802eedc0;
w3d_auto_801fff3c = 0x801fff3c;
w3d_d25e_find_interface_801fca00 = 0x801fca00;
w3d_s21_find_item_class_801e8f64 = 0x801e8f64;
SECTIONS {
  .text.w3d_d31e_apply_interface_entries_801f3850 0x801f3850 : { *(.text.w3d_d31e_apply_interface_entries_801f3850) }
  .sdata 0x804b18dc (NOLOAD) : {
    . = 0x0; lbl_804b18dc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
