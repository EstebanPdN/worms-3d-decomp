/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802cd128)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80209920 = 0x80209920;
fn_8020BF2C = 0x8020bf2c;
fn_80212FD4 = 0x80212fd4;
fn_803413D8 = 0x803413d8;
fn_80343DF8 = 0x80343df8;
fn_803536D0 = 0x803536d0;
fn_8035EF1C = 0x8035ef1c;
SECTIONS {
  .text.w3d_auto_802cd128 0x802cd128 : { *(.text.w3d_auto_802cd128) }
  .text.w3d_auto_8034714c 0x8034714c : { *(.text.w3d_auto_8034714c) }
  .text.w3d_auto_80353880 0x80353880 : { *(.text.w3d_auto_80353880) }
  .text.w3d_auto_8035f16c 0x8035f16c : { *(.text.w3d_auto_8035f16c) }
  .sdata 0x804abce0 (NOLOAD) : {
    . = 0x0; lbl_804ABCE0 = .;
    . = 0x4364; lbl_804B0044 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
