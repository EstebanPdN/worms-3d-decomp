/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800f70f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8002A914 = 0x8002a914;
fn_8002ADDC = 0x8002addc;
fn_8002AE70 = 0x8002ae70;
fn_8002AF78 = 0x8002af78;
fn_800C53A0 = 0x800c53a0;
fn_800E082C = 0x800e082c;
fn_800FC230 = 0x800fc230;
fn_800FC43C = 0x800fc43c;
fn_801074F0 = 0x801074f0;
fn_80107A90 = 0x80107a90;
fn_80125FF8 = 0x80125ff8;
fn_8015F5A0 = 0x8015f5a0;
fn_8015F65C = 0x8015f65c;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_80164FC8 = 0x80164fc8;
fn_80165254 = 0x80165254;
fn_801797B4 = 0x801797b4;
fn_802097EC = 0x802097ec;
fn_80341584 = 0x80341584;
lbl_8038C970 = 0x8038c970;
lbl_8038CA68 = 0x8038ca68;
lbl_80399AC8 = 0x80399ac8;
lbl_8040DB38 = 0x8040db38;
lbl_80410560 = 0x80410560;
SECTIONS {
  .text.w3d_auto_800f70f0 0x800f70f0 : { *(.text.w3d_auto_800f70f0) }
  .text.w3d_auto_800f7530 0x800f7530 : { *(.text.w3d_auto_800f7530) }
  .text.w3d_auto_800fe364 0x800fe364 : { *(.text.w3d_auto_800fe364) }
  .text.w3d_auto_800fe500 0x800fe500 : { *(.text.w3d_auto_800fe500) }
  .text.w3d_auto_80106d04 0x80106d04 : { *(.text.w3d_auto_80106d04) }
  .sdata 0x804af0e8 (NOLOAD) : {
    . = 0x0; lbl_804AF0E8 = .;
    . = 0x18; lbl_804AF100 = .;
    . = 0x5c; lbl_804AF144 = .;
    . = 0x64; lbl_804AF14C = .;
    . = 0x130; lbl_804AF218 = .;
    . = 0x140; lbl_804AF228 = .;
    . = 0x148; lbl_804AF230 = .;
    . = 0x266c; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
