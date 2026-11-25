/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx7a_active_worm_select_8004c29c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
name_803772bc = 0x803772bc;
property_800fc1f0 = 0x800fc1f0;
select_8004c2f0 = 0x8004c2f0;
SECTIONS {
  .text.w3d_cx7a_active_worm_select_8004c29c 0x8004c29c : { *(.text.w3d_cx7a_active_worm_select_8004c29c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
