/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_properties_801bb74c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ebbb8 = 0x801ebbb8;
fn_801efec4 = 0x801efec4;
lbl_803ab678 = 0x803ab678;
lbl_803ab6a0 = 0x803ab6a0;
lbl_8045d14c = 0x8045d14c;
lbl_8045ed7c = 0x8045ed7c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_properties_801bb74c 0x801bb74c : { *(.text.w3d_s20_register_properties_801bb74c) }
  .sdata 0x804b03e0 (NOLOAD) : {
    . = 0x0; lbl_804b03e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
