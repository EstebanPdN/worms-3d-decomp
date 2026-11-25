/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f11b_sphere_query_begin_8003fc70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
begin_804273ec = 0x804273ec;
f11b_sphere_overlap_next_8003ffb8 = 0x8003ffb8;
moving_800400f0 = 0x800400f0;
origin_80427408 = 0x80427408;
velocity_80427414 = 0x80427414;
zero_80374730 = 0x80374730;
SECTIONS {
  .text.f11b_sphere_query_begin_8003fc70 0x8003fc70 : { *(.text.f11b_sphere_query_begin_8003fc70) }
  .sdata 0x804aa950 (NOLOAD) : {
    . = 0x0; source_804aa950 = .;
    . = 0x4; mask_804aa954 = .;
    . = 0x8; active_804aa958 = .;
    . = 0xc; cursor_804aa95c = .;
    . = 0x10; excluded_804aa960 = .;
    . = 0x14; stationary_804aa964 = .;
    . = 0x6e40; unknown_804b1790 = .;
    . = 0x6e60; radius2_804b17b0 = .;
    . = 0x6e64; next_804b17b4 = .;
    . = 0x6e68; radius_804b17b8 = .;
    . = 0x6e6c; mode_804b17bc = .;
    . = 0x6e70; speed2_804b17c0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
