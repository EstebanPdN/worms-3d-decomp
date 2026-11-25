/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_801c2e2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efd34 = 0x801efd34;
fn_801efd98 = 0x801efd98;
fn_801efec4 = 0x801efec4;
fn_801f23bc = 0x801f23bc;
fn_801f254c = 0x801f254c;
lbl_803ac7b4 = 0x803ac7b4;
lbl_803ac7c4 = 0x803ac7c4;
lbl_803ac7d4 = 0x803ac7d4;
lbl_803ac7e0 = 0x803ac7e0;
lbl_803ac7f0 = 0x803ac7f0;
lbl_803ac7fc = 0x803ac7fc;
lbl_803ac808 = 0x803ac808;
lbl_8045d480 = 0x8045d480;
lbl_8045d494 = 0x8045d494;
lbl_8045d4a8 = 0x8045d4a8;
lbl_8045d4bc = 0x8045d4bc;
lbl_8045d4d0 = 0x8045d4d0;
lbl_8045d4e4 = 0x8045d4e4;
lbl_8045d4f8 = 0x8045d4f8;
lbl_8045e2b4 = 0x8045e2b4;
lbl_8045e494 = 0x8045e494;
lbl_8045ed1c = 0x8045ed1c;
lbl_8045ed34 = 0x8045ed34;
lbl_8045ed7c = 0x8045ed7c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_801c2e2c 0x801c2e2c : { *(.text.w3d_s10_register_properties_801c2e2c) }
  .sdata 0x804b0484 (NOLOAD) : {
    . = 0x0; lbl_804b0484 = .;
    . = 0x4; lbl_804b0488 = .;
    . = 0x8; lbl_804b048c = .;
    . = 0xc; lbl_804b0490 = .;
    . = 0x10; lbl_804b0494 = .;
    . = 0x14; lbl_804b0498 = .;
    . = 0x18; lbl_804b049c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
