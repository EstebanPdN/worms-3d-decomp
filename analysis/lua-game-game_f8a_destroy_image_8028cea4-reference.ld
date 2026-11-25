/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(_._17F8aImage_8028cea4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._16F8aBase_8015ff2c = 0x8015ff2c;
_._18F8aMember_802afc40 = 0x802afc40;
vt_8041c120 = 0x8041c120;
vt_8041c170 = 0x8041c170;
SECTIONS {
  .text._._17F8aImage_8028cea4 0x8028cea4 : { *(.text._._17F8aImage_8028cea4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
