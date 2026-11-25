/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f2b_motion_segment_80153cf0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
apply_80153f80 = 0x80153f80;
elapsed_80178df0 = 0x80178df0;
set_801492ec = 0x801492ec;
SECTIONS {
  .text.f2b_motion_segment_80153cf0 0x80153cf0 : { *(.text.f2b_motion_segment_80153cf0) }
  .sdata 0x804afdec (NOLOAD) : {
    . = 0x0; service_804afdec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
