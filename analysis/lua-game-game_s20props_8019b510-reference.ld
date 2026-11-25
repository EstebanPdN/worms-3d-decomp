/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_properties_8019b510)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eb674 = 0x801eb674;
fn_801ece2c = 0x801ece2c;
fn_801efec4 = 0x801efec4;
lbl_803a9578 = 0x803a9578;
lbl_803a95ac = 0x803a95ac;
lbl_803a95e0 = 0x803a95e0;
lbl_803a9614 = 0x803a9614;
lbl_803a9648 = 0x803a9648;
lbl_803a9680 = 0x803a9680;
lbl_803a96a8 = 0x803a96a8;
lbl_8045cd20 = 0x8045cd20;
lbl_8045ed7c = 0x8045ed7c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_properties_8019b510 0x8019b510 : { *(.text.w3d_s20_register_properties_8019b510) }
  .sdata 0x804b02fc (NOLOAD) : {
    . = 0x0; lbl_804b02fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
