/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27d_worm_spot_clear_8014a9f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
clock_801264fc = 0x801264fc;
construct_801f725c = 0x801f725c;
finish_80126524 = 0x80126524;
level_80178df0 = 0x80178df0;
lookup_8003f240 = 0x8003f240;
sqrt_802e82c0 = 0x802e82c0;
start_80126384 = 0x80126384;
test_800b0824 = 0x800b0824;
tracePoint_8043ae20 = 0x8043ae20;
SECTIONS {
  .text.d27d_worm_spot_clear_8014a9f8 0x8014a9f8 : { *(.text.d27d_worm_spot_clear_8014a9f8) }
  .rodata 0x803a1370 : { *(.rodata) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; kind_804aa95e = .;
    . = 0x6e06; traceFrac_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
