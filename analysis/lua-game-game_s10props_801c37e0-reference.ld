/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_801c37e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efec4 = 0x801efec4;
fn_801eff8c = 0x801eff8c;
fn_801f23bc = 0x801f23bc;
lbl_803ac8cc = 0x803ac8cc;
lbl_803ac8dc = 0x803ac8dc;
lbl_803ac8e8 = 0x803ac8e8;
lbl_803fe594 = 0x803fe594;
lbl_8045d534 = 0x8045d534;
lbl_8045d548 = 0x8045d548;
lbl_8045d55c = 0x8045d55c;
lbl_8045e004 = 0x8045e004;
lbl_8045e2b4 = 0x8045e2b4;
lbl_8045ed7c = 0x8045ed7c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_801c37e0 0x801c37e0 : { *(.text.w3d_s10_register_properties_801c37e0) }
  .sdata 0x804b04a8 (NOLOAD) : {
    . = 0x0; lbl_804b04a8 = .;
    . = 0x4; lbl_804b04ac = .;
    . = 0x8; lbl_804b04b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
