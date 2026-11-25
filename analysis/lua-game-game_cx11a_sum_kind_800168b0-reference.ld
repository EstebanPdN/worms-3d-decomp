/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11a_sum_kind_800168b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
factor_8036a68c = 0x8036a68c;
transformA_802e83cc = 0x802e83cc;
transformB_802e8094 = 0x802e8094;
zero_8036a688 = 0x8036a688;
SECTIONS {
  .text.w3d_cx11a_sum_kind_800168b0 0x800168b0 : { *(.text.w3d_cx11a_sum_kind_800168b0) }
  .sdata 0x804aa6fc (NOLOAD) : {
    . = 0x0; entries_804aa6fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
