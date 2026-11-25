/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_801c4450)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efdfc = 0x801efdfc;
fn_801efff0 = 0x801efff0;
fn_801f23bc = 0x801f23bc;
fn_801f254c = 0x801f254c;
lbl_803aca2c = 0x803aca2c;
lbl_803aca34 = 0x803aca34;
lbl_803aca3c = 0x803aca3c;
lbl_803aca40 = 0x803aca40;
lbl_803aca44 = 0x803aca44;
lbl_8045d5ac = 0x8045d5ac;
lbl_8045d5c0 = 0x8045d5c0;
lbl_8045d5d4 = 0x8045d5d4;
lbl_8045d5e8 = 0x8045d5e8;
lbl_8045d5fc = 0x8045d5fc;
lbl_8045e2b4 = 0x8045e2b4;
lbl_8045e494 = 0x8045e494;
lbl_8045ed4c = 0x8045ed4c;
lbl_8045ed94 = 0x8045ed94;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_801c4450 0x801c4450 : { *(.text.w3d_s10_register_properties_801c4450) }
  .sdata 0x804b04c0 (NOLOAD) : {
    . = 0x0; lbl_804b04c0 = .;
    . = 0x4; lbl_804b04c4 = .;
    . = 0x8; lbl_804b04c8 = .;
    . = 0xc; lbl_804b04cc = .;
    . = 0x10; lbl_804b04d0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
