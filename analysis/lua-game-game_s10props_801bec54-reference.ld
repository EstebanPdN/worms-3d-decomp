/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_801bec54)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efd34 = 0x801efd34;
fn_801efff0 = 0x801efff0;
fn_801f2614 = 0x801f2614;
lbl_803abe00 = 0x803abe00;
lbl_803abe10 = 0x803abe10;
lbl_803abe24 = 0x803abe24;
lbl_803abe30 = 0x803abe30;
lbl_803abe40 = 0x803abe40;
lbl_8045d1ec = 0x8045d1ec;
lbl_8045d200 = 0x8045d200;
lbl_8045d214 = 0x8045d214;
lbl_8045d228 = 0x8045d228;
lbl_8045d23c = 0x8045d23c;
lbl_8045e584 = 0x8045e584;
lbl_8045ed1c = 0x8045ed1c;
lbl_8045ed94 = 0x8045ed94;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_801bec54 0x801bec54 : { *(.text.w3d_s10_register_properties_801bec54) }
  .sdata 0x804b0400 (NOLOAD) : {
    . = 0x0; lbl_804b0400 = .;
    . = 0x4; lbl_804b0404 = .;
    . = 0x8; lbl_804b0408 = .;
    . = 0xc; lbl_804b040c = .;
    . = 0x10; lbl_804b0410 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
