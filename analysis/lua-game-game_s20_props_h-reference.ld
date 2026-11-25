/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_range_property_801bd79c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efec4 = 0x801efec4;
fn_801f0504 = 0x801f0504;
lbl_803abbac = 0x803abbac;
lbl_803abbd0 = 0x803abbd0;
lbl_803abbd8 = 0x803abbd8;
lbl_8045d19c = 0x8045d19c;
lbl_8045ed7c = 0x8045ed7c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_range_property_801bd79c 0x801bd79c : { *(.text.w3d_s20_register_range_property_801bd79c) }
  .sdata 0x804b03f0 (NOLOAD) : {
    . = 0x0; lbl_804b03f0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
