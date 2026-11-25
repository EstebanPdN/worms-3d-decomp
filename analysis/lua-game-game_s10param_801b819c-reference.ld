/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_array_801b819c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efd34 = 0x801efd34;
fn_801efd98 = 0x801efd98;
fn_801efe60 = 0x801efe60;
fn_801efec4 = 0x801efec4;
fn_801efff0 = 0x801efff0;
fn_801f2100 = 0x801f2100;
lbl_803ab330 = 0x803ab330;
lbl_803ab360 = 0x803ab360;
lbl_803ab6bc = 0x803ab6bc;
lbl_803ab708 = 0x803ab708;
lbl_803b66c0 = 0x803b66c0;
lbl_803bb23c = 0x803bb23c;
lbl_803bbe08 = 0x803bbe08;
lbl_8045cfe4 = 0x8045cfe4;
lbl_8045cff8 = 0x8045cff8;
lbl_8045d00c = 0x8045d00c;
lbl_8045d160 = 0x8045d160;
lbl_8045d174 = 0x8045d174;
lbl_8045d188 = 0x8045d188;
lbl_8045e23c = 0x8045e23c;
lbl_8045ed1c = 0x8045ed1c;
lbl_8045ed34 = 0x8045ed34;
lbl_8045ed58 = 0x8045ed58;
lbl_8045ed7c = 0x8045ed7c;
lbl_8045ed94 = 0x8045ed94;
lbl_80464a7c = 0x80464a7c;
lbl_80464a90 = 0x80464a90;
lbl_80464c84 = 0x80464c84;
lbl_80464c98 = 0x80464c98;
lbl_80464cd4 = 0x80464cd4;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_array_801b819c 0x801b819c : { *(.text.w3d_s10_register_array_801b819c) }
  .text.w3d_s10_register_array_801b83ec 0x801b83ec : { *(.text.w3d_s10_register_array_801b83ec) }
  .text.w3d_s10_register_array_801b863c 0x801b863c : { *(.text.w3d_s10_register_array_801b863c) }
  .text.w3d_s10_register_array_801bb9a8 0x801bb9a8 : { *(.text.w3d_s10_register_array_801bb9a8) }
  .text.w3d_s10_register_array_801bbd84 0x801bbd84 : { *(.text.w3d_s10_register_array_801bbd84) }
  .text.w3d_s10_register_array_801bbfd4 0x801bbfd4 : { *(.text.w3d_s10_register_array_801bbfd4) }
  .text.w3d_s10_register_array_802268e4 0x802268e4 : { *(.text.w3d_s10_register_array_802268e4) }
  .text.w3d_s10_register_array_80226b34 0x80226b34 : { *(.text.w3d_s10_register_array_80226b34) }
  .text.w3d_s10_register_array_8023bb28 0x8023bb28 : { *(.text.w3d_s10_register_array_8023bb28) }
  .text.w3d_s10_register_array_8023bd78 0x8023bd78 : { *(.text.w3d_s10_register_array_8023bd78) }
  .text.w3d_s10_register_array_8023c2ec 0x8023c2ec : { *(.text.w3d_s10_register_array_8023c2ec) }
  .sdata 0x804b0398 (NOLOAD) : {
    . = 0x0; lbl_804b0398 = .;
    . = 0x4; lbl_804b039c = .;
    . = 0x8; lbl_804b03a0 = .;
    . = 0x4c; lbl_804b03e4 = .;
    . = 0x50; lbl_804b03e8 = .;
    . = 0x54; lbl_804b03ec = .;
    . = 0x44c; lbl_804b07e4 = .;
    . = 0x450; lbl_804b07e8 = .;
    . = 0x4b0; lbl_804b0848 = .;
    . = 0x4b4; lbl_804b084c = .;
    . = 0x4c0; lbl_804b0858 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
