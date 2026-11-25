/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35a10_request_pair_80015f80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35a10_allocate_8001523c = 0x8001523c;
sol35a10_allocate_80212fd4 = 0x80212fd4;
sol35a10_construct_80015c6c = 0x80015c6c;
sol35a10_copy_802eee50 = 0x802eee50;
sol35a10_release_802134fc = 0x802134fc;
SECTIONS {
  .text.sol35a10_request_pair_80015f80 0x80015f80 : { *(.text.sol35a10_request_pair_80015f80) }
  .sdata 0x804aa6c0 (NOLOAD) : {
    . = 0x0; sol35a10_context_804aa6c0 = .;
    . = 0x34; sol35a10_active_804aa6f4 = .;
    . = 0x3c; sol35a10_markers_804aa6fc = .;
    . = 0x90; sol35a10_specs_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
