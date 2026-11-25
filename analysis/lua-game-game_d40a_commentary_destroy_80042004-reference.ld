/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(_._19Commentary_80042004)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._23CommentaryBase_8015ff2c = 0x8015ff2c;
vt_8040e938 = 0x8040e938;
w3d_storage_release_802134fc = 0x802134fc;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text._._19Commentary_80042004 0x80042004 : { *(.text._._19Commentary_80042004) }
  .sdata 0x804aa984 (NOLOAD) : {
    . = 0x0; g_804aa984 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
