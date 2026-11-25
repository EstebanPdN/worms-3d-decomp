/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f14b_static_groups_801f5e08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8045e62c = 0x8045e62c;
lbl_8045e63c = 0x8045e63c;
lbl_8045e64c = 0x8045e64c;
lbl_8045e65c = 0x8045e65c;
lbl_8045e678 = 0x8045e678;
lbl_8045e690 = 0x8045e690;
SECTIONS {
  .text.f14b_static_groups_801f5e08 0x801f5e08 : { *(.text.f14b_static_groups_801f5e08) }
  .rodata 0x803b15e8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
