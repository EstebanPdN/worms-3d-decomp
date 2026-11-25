/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_countdown_handler_8025d9c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8016293c = 0x8016293c;
same_8015f65c = 0x8015f65c;
started_8025ddb8 = 0x8025ddb8;
stopped_8025deec = 0x8025deec;
SECTIONS {
  .text.w3d_d26k_countdown_handler_8025d9c4 0x8025d9c4 : { *(.text.w3d_d26k_countdown_handler_8025d9c4) }
  .sdata 0x804b0918 (NOLOAD) : {
    . = 0x0; cache_804b0918 = .;
    . = 0x8; cache_804b0920 = .;
    . = 0x10; cache_804b0928 = .;
    . = 0x18; cache_804b0930 = .;
    . = 0x20; cache_804b0938 = .;
    . = 0x28; cache_804b0940 = .;
    . = 0x30; cache_804b0948 = .;
    . = 0x38; cache_804b0950 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
