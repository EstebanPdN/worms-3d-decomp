/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8026cb70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015F5A0 = 0x8015f5a0;
fn_80162024 = 0x80162024;
fn_8026CC60 = 0x8026cc60;
fn_80275F18 = 0x80275f18;
fn_802761B8 = 0x802761b8;
fn_802EF198 = 0x802ef198;
SECTIONS {
  .text.w3d_auto_8026cb70 0x8026cb70 : { *(.text.w3d_auto_8026cb70) }
  .text.w3d_auto_8026cb9c 0x8026cb9c : { *(.text.w3d_auto_8026cb9c) }
  .text.w3d_auto_8026cbc8 0x8026cbc8 : { *(.text.w3d_auto_8026cbc8) }
  .text.w3d_auto_8026cbf4 0x8026cbf4 : { *(.text.w3d_auto_8026cbf4) }
  .text.w3d_auto_8026f9d0 0x8026f9d0 : { *(.text.w3d_auto_8026f9d0) }
  .text.w3d_auto_802734bc 0x802734bc : { *(.text.w3d_auto_802734bc) }
  .text.w3d_auto_802785d8 0x802785d8 : { *(.text.w3d_auto_802785d8) }
  .sdata 0x804abb9c (NOLOAD) : {
    . = 0x0; lbl_804ABB9C = .;
    . = 0x4; lbl_804ABBA0 = .;
    . = 0x4f84; lbl_804B0B20 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
