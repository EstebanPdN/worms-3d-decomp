/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_import_descriptors_8017c904)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8017c464 = 0x8017c464;
fn_8017f000 = 0x8017f000;
fn_80182778 = 0x80182778;
fn_8018a218 = 0x8018a218;
fn_8020b680 = 0x8020b680;
lbl_80412970 = 0x80412970;
lbl_80412a90 = 0x80412a90;
lbl_80412ed0 = 0x80412ed0;
SECTIONS {
  .text.s9_import_descriptors_8017c904 0x8017c904 : { *(.text.s9_import_descriptors_8017c904) }
  .text.s9_import_descriptors_8017cafc 0x8017cafc : { *(.text.s9_import_descriptors_8017cafc) }
  .text.s9_import_descriptors_8017cbec 0x8017cbec : { *(.text.s9_import_descriptors_8017cbec) }
  .sdata 0x804ab5e8 (NOLOAD) : {
    . = 0x0; lbl_804ab5e8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
