/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800f74d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8004E460 = 0x8004e460;
fn_8004E4F8 = 0x8004e4f8;
fn_800A8D00 = 0x800a8d00;
fn_800D776C = 0x800d776c;
fn_800D7788 = 0x800d7788;
fn_800D77A8 = 0x800d77a8;
fn_800E58FC = 0x800e58fc;
fn_800FCEC8 = 0x800fcec8;
fn_80101018 = 0x80101018;
fn_80102028 = 0x80102028;
fn_8010BDC8 = 0x8010bdc8;
fn_8010BEBC = 0x8010bebc;
fn_8010BFB0 = 0x8010bfb0;
fn_8010C494 = 0x8010c494;
fn_8010C62C = 0x8010c62c;
fn_8010CA34 = 0x8010ca34;
fn_8010CCAC = 0x8010ccac;
fn_8010D0A0 = 0x8010d0a0;
fn_8010D230 = 0x8010d230;
fn_8010D630 = 0x8010d630;
fn_8015F5A0 = 0x8015f5a0;
fn_80162024 = 0x80162024;
fn_80178C48 = 0x80178c48;
fn_80178C54 = 0x80178c54;
fn_80209920 = 0x80209920;
SECTIONS {
  .text.w3d_auto_800f74d0 0x800f74d0 : { *(.text.w3d_auto_800f74d0) }
  .text.w3d_auto_800f87f4 0x800f87f4 : { *(.text.w3d_auto_800f87f4) }
  .text.w3d_auto_800fcea0 0x800fcea0 : { *(.text.w3d_auto_800fcea0) }
  .text.w3d_auto_800fdc34 0x800fdc34 : { *(.text.w3d_auto_800fdc34) }
  .text.w3d_auto_800fde98 0x800fde98 : { *(.text.w3d_auto_800fde98) }
  .text.w3d_auto_800fe4b4 0x800fe4b4 : { *(.text.w3d_auto_800fe4b4) }
  .text.w3d_auto_800ffb28 0x800ffb28 : { *(.text.w3d_auto_800ffb28) }
  .text.w3d_auto_80102004 0x80102004 : { *(.text.w3d_auto_80102004) }
  .text.w3d_auto_80107a90 0x80107a90 : { *(.text.w3d_auto_80107a90) }
  .text.w3d_auto_80108224 0x80108224 : { *(.text.w3d_auto_80108224) }
  .text.w3d_auto_80109ab8 0x80109ab8 : { *(.text.w3d_auto_80109ab8) }
  .text.w3d_auto_80109b0c 0x80109b0c : { *(.text.w3d_auto_80109b0c) }
  .text.w3d_auto_80109bb4 0x80109bb4 : { *(.text.w3d_auto_80109bb4) }
  .text.w3d_auto_80109bc4 0x80109bc4 : { *(.text.w3d_auto_80109bc4) }
  .text.w3d_auto_8010a904 0x8010a904 : { *(.text.w3d_auto_8010a904) }
  .text.w3d_auto_8010cbcc 0x8010cbcc : { *(.text.w3d_auto_8010cbcc) }
  .text.w3d_auto_8010cc3c 0x8010cc3c : { *(.text.w3d_auto_8010cc3c) }
  .text.w3d_auto_8010d7c4 0x8010d7c4 : { *(.text.w3d_auto_8010d7c4) }
  .text.w3d_auto_8010d834 0x8010d834 : { *(.text.w3d_auto_8010d834) }
  .text.w3d_auto_80118230 0x80118230 : { *(.text.w3d_auto_80118230) }
  .text.w3d_auto_80118268 0x80118268 : { *(.text.w3d_auto_80118268) }
  .text.w3d_auto_80118288 0x80118288 : { *(.text.w3d_auto_80118288) }
  .text.w3d_auto_80118e54 0x80118e54 : { *(.text.w3d_auto_80118e54) }
  .text.w3d_auto_80118e98 0x80118e98 : { *(.text.w3d_auto_80118e98) }
  .text.w3d_auto_8011d470 0x8011d470 : { *(.text.w3d_auto_8011d470) }
  .sdata 0x804aaecc (NOLOAD) : {
    . = 0x0; lbl_804AAECC = .;
    . = 0x4234; lbl_804AF100 = .;
    . = 0x4270; lbl_804AF13C = .;
    . = 0x4280; lbl_804AF14C = .;
    . = 0x4290; lbl_804AF15C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
