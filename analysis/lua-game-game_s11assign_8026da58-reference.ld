/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8026da58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800F339C = 0x800f339c;
fn_800F342C = 0x800f342c;
fn_80162C18 = 0x80162c18;
fn_8020BD38 = 0x8020bd38;
lbl_803CBD18 = 0x803cbd18;
lbl_803CBD7C = 0x803cbd7c;
SECTIONS {
  .text.w3d_auto_8026da58 0x8026da58 : { *(.text.w3d_auto_8026da58) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804B1788 = .;
    . = 0x64; lbl_804B17EC = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
