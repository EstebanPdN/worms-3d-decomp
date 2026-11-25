/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_array_801b6ce8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efd98 = 0x801efd98;
fn_801efec4 = 0x801efec4;
lbl_803ab2e8 = 0x803ab2e8;
lbl_803ab330 = 0x803ab330;
lbl_803ab360 = 0x803ab360;
lbl_8045cf94 = 0x8045cf94;
lbl_8045cfa8 = 0x8045cfa8;
lbl_8045cfbc = 0x8045cfbc;
lbl_8045cfd0 = 0x8045cfd0;
lbl_8045ed34 = 0x8045ed34;
lbl_8045ed7c = 0x8045ed7c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_array_801b6ce8 0x801b6ce8 : { *(.text.w3d_s10_register_array_801b6ce8) }
  .text.w3d_s10_register_array_801b736c 0x801b736c : { *(.text.w3d_s10_register_array_801b736c) }
  .text.w3d_s10_register_array_801b75b8 0x801b75b8 : { *(.text.w3d_s10_register_array_801b75b8) }
  .text.w3d_s10_register_array_801b7804 0x801b7804 : { *(.text.w3d_s10_register_array_801b7804) }
  .sdata 0x804b0388 (NOLOAD) : {
    . = 0x0; lbl_804b0388 = .;
    . = 0x4; lbl_804b038c = .;
    . = 0x8; lbl_804b0390 = .;
    . = 0xc; lbl_804b0394 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
