/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(_._9D26bWater)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._17D26bList_801f2758 = 0x801f2758;
w3d_handle_delete_802134fc = 0x802134fc;
w3d_heap_free_80209920 = 0x80209920;
w3d_lists_clear_80078db8 = 0x80078db8;
w3d_table_8040f150 = 0x8040f150;
w3d_water_clear_8008eb98 = 0x8008eb98;
SECTIONS {
  .text._._9D26bWater 0x8009081c : { *(.text._._9D26bWater) }
  .sdata 0x804aab68 (NOLOAD) : {
    . = 0x0; w3d_flag_804aab68 = .;
    . = 0x327c; w3d_heap_804adde4 = .;
    . = 0x6c98; w3d_buffer_804b1800 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
