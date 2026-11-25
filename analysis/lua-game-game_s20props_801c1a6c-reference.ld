/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_properties_801c1a6c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eb834 = 0x801eb834;
fn_801efd34 = 0x801efd34;
fn_801efd98 = 0x801efd98;
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
lbl_803ac65c = 0x803ac65c;
lbl_8045d354 = 0x8045d354;
lbl_8045d368 = 0x8045d368;
lbl_8045d37c = 0x8045d37c;
lbl_8045d390 = 0x8045d390;
lbl_8045d3a4 = 0x8045d3a4;
lbl_8045d3b8 = 0x8045d3b8;
lbl_8045e23c = 0x8045e23c;
lbl_8045e2b4 = 0x8045e2b4;
lbl_8045e47c = 0x8045e47c;
lbl_8045ed1c = 0x8045ed1c;
lbl_8045ed34 = 0x8045ed34;
lbl_8045ed7c = 0x8045ed7c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_properties_801c1a6c 0x801c1a6c : { *(.text.w3d_s20_register_properties_801c1a6c) }
  .sdata 0x804b0448 (NOLOAD) : {
    . = 0x0; lbl_804b0448 = .;
    . = 0x4; lbl_804b044c = .;
    . = 0x8; lbl_804b0450 = .;
    . = 0xc; lbl_804b0454 = .;
    . = 0x10; lbl_804b0458 = .;
    . = 0x14; lbl_804b045c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
