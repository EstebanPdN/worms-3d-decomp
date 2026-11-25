/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc36a_movie_start_800c6698)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc36a_allocate_801613f0 = 0x801613f0;
cc36a_choose_800c61d8 = 0x800c61d8;
cc36a_key_8015f5a0 = 0x8015f5a0;
cc36a_post_8016239c = 0x8016239c;
cc36a_type_8040db38 = 0x8040db38;
SECTIONS {
  .text.cc36a_movie_start_800c6698 0x800c6698 : { *(.text.cc36a_movie_start_800c6698) }
  .sdata 0x804ae7e4 (NOLOAD) : {
    . = 0x0; cc36a_cache_804ae7e4 = .;
    . = 0x2f70; cc36a_service_804b1754 = .;
    . = 0x2fa4; cc36a_system_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
