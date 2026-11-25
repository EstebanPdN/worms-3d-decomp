/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_properties_801c0914)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eb834 = 0x801eb834;
fn_801ebf38 = 0x801ebf38;
fn_801efd34 = 0x801efd34;
fn_801efec4 = 0x801efec4;
fn_801f2100 = 0x801f2100;
fn_801f23bc = 0x801f23bc;
fn_801f25b0 = 0x801f25b0;
lbl_803ab0f8 = 0x803ab0f8;
lbl_803ab108 = 0x803ab108;
lbl_803ab160 = 0x803ab160;
lbl_803abf88 = 0x803abf88;
lbl_803ac3ec = 0x803ac3ec;
lbl_803ac3f8 = 0x803ac3f8;
lbl_803ac410 = 0x803ac410;
lbl_803ac438 = 0x803ac438;
lbl_803ac478 = 0x803ac478;
lbl_803ac4ac = 0x803ac4ac;
lbl_8045d264 = 0x8045d264;
lbl_8045d278 = 0x8045d278;
lbl_8045d28c = 0x8045d28c;
lbl_8045d2a0 = 0x8045d2a0;
lbl_8045d2b4 = 0x8045d2b4;
lbl_8045d2c8 = 0x8045d2c8;
lbl_8045e23c = 0x8045e23c;
lbl_8045e2b4 = 0x8045e2b4;
lbl_8045e47c = 0x8045e47c;
lbl_8045ed1c = 0x8045ed1c;
lbl_8045ed7c = 0x8045ed7c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_properties_801c0914 0x801c0914 : { *(.text.w3d_s20_register_properties_801c0914) }
  .sdata 0x804b0418 (NOLOAD) : {
    . = 0x0; lbl_804b0418 = .;
    . = 0x4; lbl_804b041c = .;
    . = 0x8; lbl_804b0420 = .;
    . = 0xc; lbl_804b0424 = .;
    . = 0x10; lbl_804b0428 = .;
    . = 0x14; lbl_804b042c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
