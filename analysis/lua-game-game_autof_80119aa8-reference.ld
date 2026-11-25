/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80119aa8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800FC230 = 0x800fc230;
fn_800FC6DC = 0x800fc6dc;
fn_8012609C = 0x8012609c;
fn_80128080 = 0x80128080;
fn_80128084 = 0x80128084;
fn_801359EC = 0x801359ec;
fn_8013B3B8 = 0x8013b3b8;
fn_8013BD0C = 0x8013bd0c;
fn_8015BCB0 = 0x8015bcb0;
fn_8015BD08 = 0x8015bd08;
fn_8015F518 = 0x8015f518;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_80162C20 = 0x80162c20;
fn_801817E0 = 0x801817e0;
fn_80181CCC = 0x80181ccc;
fn_802097EC = 0x802097ec;
fn_8020EE9C = 0x8020ee9c;
lbl_8039ABC4 = 0x8039abc4;
lbl_8039ABD8 = 0x8039abd8;
lbl_8039C9C4 = 0x8039c9c4;
lbl_8039C9D4 = 0x8039c9d4;
lbl_8039C9E4 = 0x8039c9e4;
lbl_8039E280 = 0x8039e280;
lbl_8039E294 = 0x8039e294;
lbl_8039FB70 = 0x8039fb70;
lbl_8039FB78 = 0x8039fb78;
lbl_8039FBDC = 0x8039fbdc;
lbl_8039FBE0 = 0x8039fbe0;
lbl_8039FBF8 = 0x8039fbf8;
lbl_8039FBFC = 0x8039fbfc;
lbl_8039FC98 = 0x8039fc98;
lbl_8039FC9C = 0x8039fc9c;
lbl_8040DB38 = 0x8040db38;
lbl_8044FAD4 = 0x8044fad4;
SECTIONS {
  .text.w3d_auto_80119aa8 0x80119aa8 : { *(.text.w3d_auto_80119aa8) }
  .text.w3d_auto_80126100 0x80126100 : { *(.text.w3d_auto_80126100) }
  .text.w3d_auto_80127708 0x80127708 : { *(.text.w3d_auto_80127708) }
  .text.w3d_auto_80128088 0x80128088 : { *(.text.w3d_auto_80128088) }
  .text.w3d_auto_80129920 0x80129920 : { *(.text.w3d_auto_80129920) }
  .text.w3d_auto_80131984 0x80131984 : { *(.text.w3d_auto_80131984) }
  .text.w3d_auto_80131b50 0x80131b50 : { *(.text.w3d_auto_80131b50) }
  .text.w3d_auto_80131ba0 0x80131ba0 : { *(.text.w3d_auto_80131ba0) }
  .text.w3d_auto_8013b91c 0x8013b91c : { *(.text.w3d_auto_8013b91c) }
  .text.w3d_auto_8013ddfc 0x8013ddfc : { *(.text.w3d_auto_8013ddfc) }
  .text.w3d_auto_8013e0a0 0x8013e0a0 : { *(.text.w3d_auto_8013e0a0) }
  .text.w3d_auto_8013e340 0x8013e340 : { *(.text.w3d_auto_8013e340) }
  .text.w3d_auto_8013e600 0x8013e600 : { *(.text.w3d_auto_8013e600) }
  .sdata 0x804ab100 (NOLOAD) : {
    . = 0x0; lbl_804AB100 = .;
    . = 0xc4; lbl_804AB1C4 = .;
    . = 0x3a0; lbl_804AB4A0 = .;
    . = 0x4254; lbl_804AF354 = .;
    . = 0x44a0; lbl_804AF5A0 = .;
    . = 0x44bc; lbl_804AF5BC = .;
    . = 0x44c4; lbl_804AF5C4 = .;
    . = 0x44cc; lbl_804AF5CC = .;
    . = 0x4698; lbl_804AF798 = .;
    . = 0x46a0; lbl_804AF7A0 = .;
    . = 0x46a8; lbl_804AF7A8 = .;
    . = 0x6654; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
