/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80020548)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80022704 = 0x80022704;
fn_8015F518 = 0x8015f518;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_801628B0 = 0x801628b0;
lbl_8036C228 = 0x8036c228;
lbl_8036C23C = 0x8036c23c;
lbl_8036C250 = 0x8036c250;
lbl_8036C264 = 0x8036c264;
lbl_8036C278 = 0x8036c278;
lbl_8036C28C = 0x8036c28c;
lbl_8036C2A4 = 0x8036c2a4;
lbl_8036C2BC = 0x8036c2bc;
lbl_8036C2CC = 0x8036c2cc;
lbl_8036C2E4 = 0x8036c2e4;
lbl_8036C300 = 0x8036c300;
lbl_8040DB08 = 0x8040db08;
lbl_8040DB38 = 0x8040db38;
lbl_8040DDF8 = 0x8040ddf8;
SECTIONS {
  .text.w3d_auto_80020548 0x80020548 : { *(.text.w3d_auto_80020548) }
  .text.w3d_auto_800216f8 0x800216f8 : { *(.text.w3d_auto_800216f8) }
  .text.w3d_auto_80021f2c 0x80021f2c : { *(.text.w3d_auto_80021f2c) }
  .text.w3d_auto_80021f94 0x80021f94 : { *(.text.w3d_auto_80021f94) }
  .text.w3d_auto_80022028 0x80022028 : { *(.text.w3d_auto_80022028) }
  .text.w3d_auto_800226d0 0x800226d0 : { *(.text.w3d_auto_800226d0) }
  .text.w3d_auto_80022c2c 0x80022c2c : { *(.text.w3d_auto_80022c2c) }
  .text.w3d_auto_8002324c 0x8002324c : { *(.text.w3d_auto_8002324c) }
  .text.w3d_auto_800267a4 0x800267a4 : { *(.text.w3d_auto_800267a4) }
  .sdata 0x804aa7a4 (NOLOAD) : {
    . = 0x0; lbl_804AA7A4 = .;
    . = 0x4; lbl_804AA7A8 = .;
    . = 0x30; lbl_804AA7D4 = .;
    . = 0x2228; lbl_804AC9CC = .;
    . = 0x2230; lbl_804AC9D4 = .;
    . = 0x2238; lbl_804AC9DC = .;
    . = 0x2240; lbl_804AC9E4 = .;
    . = 0x2248; lbl_804AC9EC = .;
    . = 0x2250; lbl_804AC9F4 = .;
    . = 0x2258; lbl_804AC9FC = .;
    . = 0x2260; lbl_804ACA04 = .;
    . = 0x2268; lbl_804ACA0C = .;
    . = 0x2270; lbl_804ACA14 = .;
    . = 0x2278; lbl_804ACA1C = .;
    . = 0x2368; lbl_804ACB0C = .;
    . = 0x6fb0; lbl_804B1754 = .;
    . = 0x6fbc; lbl_804B1760 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
