/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11a_query_hit_delta_800418ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
direction_80427414 = 0x80427414;
origin_80427408 = 0x80427408;
output_80427450 = 0x80427450;
records_804273ec = 0x804273ec;
swept_800400f0 = 0x800400f0;
SECTIONS {
  .text.w3d_cx11a_query_hit_delta_800418ac 0x800418ac : { *(.text.w3d_cx11a_query_hit_delta_800418ac) }
  .rodata 0x803747b8 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; hit_804aa95e = .;
    . = 0x6e32; tick_804b1790 = .;
    . = 0x6e56; method_804b17b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
