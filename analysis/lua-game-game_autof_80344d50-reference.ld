/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80344d50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800DE900 = 0x800de900;
fn_801E80F0 = 0x801e80f0;
fn_801FE1F8 = 0x801fe1f8;
fn_80351804 = 0x80351804;
lbl_8040FF88 = 0x8040ff88;
lbl_80413A50 = 0x80413a50;
lbl_8041C9F8 = 0x8041c9f8;
SECTIONS {
  .text.w3d_auto_80344d50 0x80344d50 : { *(.text.w3d_auto_80344d50) }
  .text.w3d_auto_803518f8 0x803518f8 : { *(.text.w3d_auto_803518f8) }
  .text.w3d_auto_80352f00 0x80352f00 : { *(.text.w3d_auto_80352f00) }
  .text.w3d_auto_8035653c 0x8035653c : { *(.text.w3d_auto_8035653c) }
  .text.w3d_auto_8035812c 0x8035812c : { *(.text.w3d_auto_8035812c) }
  .text.w3d_auto_8035f3ac 0x8035f3ac : { *(.text.w3d_auto_8035f3ac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
