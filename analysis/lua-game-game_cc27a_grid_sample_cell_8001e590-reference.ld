/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc27a_grid_sample_cell_8001e590)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc27a_byte_8001dff8 = 0x8001dff8;
cc27a_high_8001e1a0 = 0x8001e1a0;
cc27a_hop_8001e2dc = 0x8001e2dc;
cc27a_low_8001e11c = 0x8001e11c;
cc27a_sample_8001e7e0 = 0x8001e7e0;
SECTIONS {
  .text.cc27a_grid_sample_cell_8001e590 0x8001e590 : { *(.text.cc27a_grid_sample_cell_8001e590) }
  .rodata 0x8036b850 : { *(.rodata) }
  .sdata 0x804aa78c (NOLOAD) : {
    . = 0x0; cc27a_drop_804aa78c = .;
    . = 0x4; cc27a_step_804aa790 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
