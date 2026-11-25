/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_properties_801c3454)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ec52c = 0x801ec52c;
fn_801efd98 = 0x801efd98;
fn_801efec4 = 0x801efec4;
lbl_803ab6bc = 0x803ab6bc;
lbl_803ac824 = 0x803ac824;
lbl_803ac858 = 0x803ac858;
lbl_803ac888 = 0x803ac888;
lbl_803ac8b0 = 0x803ac8b0;
lbl_8045d50c = 0x8045d50c;
lbl_8045d520 = 0x8045d520;
lbl_8045ed34 = 0x8045ed34;
lbl_8045ed7c = 0x8045ed7c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_properties_801c3454 0x801c3454 : { *(.text.w3d_s20_register_properties_801c3454) }
  .sdata 0x804b04a0 (NOLOAD) : {
    . = 0x0; lbl_804b04a0 = .;
    . = 0x4; lbl_804b04a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
