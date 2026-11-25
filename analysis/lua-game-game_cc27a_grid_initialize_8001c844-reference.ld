/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc27a_grid_initialize_8001c844)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc27a_base_801628b0 = 0x801628b0;
cc27a_lookup_800fc1b0 = 0x800fc1b0;
cc27a_max_8036b6c4 = 0x8036b6c4;
cc27a_min_8036b6b4 = 0x8036b6b4;
cc27a_table_8040dac8 = 0x8040dac8;
cc27a_water_8036b6a8 = 0x8036b6a8;
SECTIONS {
  .text.cc27a_grid_initialize_8001c844 0x8001c844 : { *(.text.cc27a_grid_initialize_8001c844) }
  .rodata 0x8036b6d4 : { *(.rodata) }
  .sdata 0x804b1758 (NOLOAD) : {
    . = 0x0; cc27a_grid_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
