/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_properties_801c1004)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eb834 = 0x801eb834;
fn_801ebf38 = 0x801ebf38;
fn_801ecc6c = 0x801ecc6c;
fn_801efd34 = 0x801efd34;
fn_801efec4 = 0x801efec4;
fn_801f2100 = 0x801f2100;
fn_801f23bc = 0x801f23bc;
fn_801f254c = 0x801f254c;
lbl_803ab0f8 = 0x803ab0f8;
lbl_803ab108 = 0x803ab108;
lbl_803ab160 = 0x803ab160;
lbl_803abf88 = 0x803abf88;
lbl_803ac3ec = 0x803ac3ec;
lbl_803ac3f8 = 0x803ac3f8;
lbl_803ac4f0 = 0x803ac4f0;
lbl_803ac514 = 0x803ac514;
lbl_803ac53c = 0x803ac53c;
lbl_803ac564 = 0x803ac564;
lbl_803ac58c = 0x803ac58c;
lbl_8045d2dc = 0x8045d2dc;
lbl_8045d2f0 = 0x8045d2f0;
lbl_8045d304 = 0x8045d304;
lbl_8045d318 = 0x8045d318;
lbl_8045d32c = 0x8045d32c;
lbl_8045d340 = 0x8045d340;
lbl_8045e23c = 0x8045e23c;
lbl_8045e2b4 = 0x8045e2b4;
lbl_8045e494 = 0x8045e494;
lbl_8045ed1c = 0x8045ed1c;
lbl_8045ed7c = 0x8045ed7c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_properties_801c1004 0x801c1004 : { *(.text.w3d_s20_register_properties_801c1004) }
  .sdata 0x804b0430 (NOLOAD) : {
    . = 0x0; lbl_804b0430 = .;
    . = 0x4; lbl_804b0434 = .;
    . = 0x8; lbl_804b0438 = .;
    . = 0xc; lbl_804b043c = .;
    . = 0x10; lbl_804b0440 = .;
    . = 0x14; lbl_804b0444 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
