/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_bound_8009dd10)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800A7E14 = 0x800a7e14;
fn_800EFD60 = 0x800efd60;
fn_800F29FC = 0x800f29fc;
fn_800F339C = 0x800f339c;
fn_800F342C = 0x800f342c;
fn_800F34A0 = 0x800f34a0;
fn_800F6AFC = 0x800f6afc;
fn_8015F518 = 0x8015f518;
fn_80160038 = 0x80160038;
fn_801629F8 = 0x801629f8;
fn_80165254 = 0x80165254;
fn_80209920 = 0x80209920;
lbl_80360EA0 = 0x80360ea0;
lbl_80360F60 = 0x80360f60;
lbl_803617D0 = 0x803617d0;
lbl_803618F0 = 0x803618f0;
lbl_803814DC = 0x803814dc;
lbl_8038C230 = 0x8038c230;
lbl_8038C23C = 0x8038c23c;
lbl_8038C248 = 0x8038c248;
lbl_8038C260 = 0x8038c260;
lbl_8038C278 = 0x8038c278;
lbl_8038C294 = 0x8038c294;
lbl_8038C2AC = 0x8038c2ac;
lbl_803E8290 = 0x803e8290;
lbl_803E8300 = 0x803e8300;
SECTIONS {
  .text.s8_bound_8009dd10 0x8009dd10 : { *(.text.s8_bound_8009dd10) }
  .text.s8_bound_800a7ea0 0x800a7ea0 : { *(.text.s8_bound_800a7ea0) }
  .text.s8_bound_800f0c6c 0x800f0c6c : { *(.text.s8_bound_800f0c6c) }
  .text.s8_bound_800f2f28 0x800f2f28 : { *(.text.s8_bound_800f2f28) }
  .text.s8_bound_800f6e28 0x800f6e28 : { *(.text.s8_bound_800f6e28) }
  .sdata 0x804af024 (NOLOAD) : {
    . = 0x0; lbl_804AF024 = .;
    . = 0x1; lbl_804AF025 = .;
    . = 0x2; lbl_804AF026 = .;
    . = 0x3; lbl_804AF027 = .;
    . = 0x4; lbl_804AF028 = .;
    . = 0xc; lbl_804AF030 = .;
    . = 0x14; lbl_804AF038 = .;
    . = 0x1c; lbl_804AF040 = .;
    . = 0x24; lbl_804AF048 = .;
    . = 0x2c; lbl_804AF050 = .;
    . = 0x34; lbl_804AF058 = .;
    . = 0x598; lbl_804AF5BC = .;
    . = 0x2828; lbl_804B184C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
