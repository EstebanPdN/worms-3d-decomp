/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_slot_matches_global_80015400)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80035714 = 0x80035714;
s8_index_query_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.s19_slot_matches_global_80015400 0x80015400 : { *(.text.s19_slot_matches_global_80015400) }
  .text.s19_grid_cell_ref4_800203a0 0x800203a0 : { *(.text.s19_grid_cell_ref4_800203a0) }
  .text.s19_grid_cell_ref8_800203cc 0x800203cc : { *(.text.s19_grid_cell_ref8_800203cc) }
  .text.s19_bitgrid_set_8002c6dc 0x8002c6dc : { *(.text.s19_bitgrid_set_8002c6dc) }
  .text.s19_bitgrid_clear_8002c70c 0x8002c70c : { *(.text.s19_bitgrid_clear_8002c70c) }
  .text.s19_limit_forward_800356e0 0x800356e0 : { *(.text.s19_limit_forward_800356e0) }
  .sdata 0x804aa6cc (NOLOAD) : {
    . = 0x0; lbl_804aa6cc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
