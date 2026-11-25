/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_801b5f24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efec4 = 0x801efec4;
fn_801f2164 = 0x801f2164;
fn_801f2358 = 0x801f2358;
lbl_803ab0e0 = 0x803ab0e0;
lbl_803ab0f0 = 0x803ab0f0;
lbl_803ab0f8 = 0x803ab0f8;
lbl_803ab100 = 0x803ab100;
lbl_803ab108 = 0x803ab108;
lbl_8045cee0 = 0x8045cee0;
lbl_8045cef4 = 0x8045cef4;
lbl_8045cf08 = 0x8045cf08;
lbl_8045cf1c = 0x8045cf1c;
lbl_8045cf30 = 0x8045cf30;
lbl_8045e1dc = 0x8045e1dc;
lbl_8045e2cc = 0x8045e2cc;
lbl_8045ed7c = 0x8045ed7c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_801b5f24 0x801b5f24 : { *(.text.w3d_s10_register_properties_801b5f24) }
  .sdata 0x804b0364 (NOLOAD) : {
    . = 0x0; lbl_804b0364 = .;
    . = 0x4; lbl_804b0368 = .;
    . = 0x8; lbl_804b036c = .;
    . = 0xc; lbl_804b0370 = .;
    . = 0x10; lbl_804b0374 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
