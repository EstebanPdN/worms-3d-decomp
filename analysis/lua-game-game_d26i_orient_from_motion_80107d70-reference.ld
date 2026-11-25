/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26i_orient_from_motion_80107d70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
last_8044beb4 = 0x8044beb4;
w3d_s20_set_vectors_8018993c = 0x8018993c;
SECTIONS {
  .text.d26i_orient_from_motion_80107d70 0x80107d70 : { *(.text.d26i_orient_from_motion_80107d70) }
  .rodata 0x80399b18 : { *(.rodata) }
  .sdata 0x804af1f0 (NOLOAD) : {
    . = 0x0; have_last_804af1f0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
