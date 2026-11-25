/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc36a_low_gravity_800c1a14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc36a_allocate_801613f0 = 0x801613f0;
cc36a_assign_800fc4c8 = 0x800fc4c8;
cc36a_default_8038308c = 0x8038308c;
cc36a_effect_80383078 = 0x80383078;
cc36a_effect_call_800e5ca4 = 0x800e5ca4;
cc36a_finish_8015fd1c = 0x8015fd1c;
cc36a_initialize_80125fdc = 0x80125fdc;
cc36a_key_8015f5a0 = 0x8015f5a0;
cc36a_multiplier_80383060 = 0x80383060;
cc36a_on_8038304c = 0x8038304c;
cc36a_position_800c1b20 = 0x800c1b20;
cc36a_post_8016239c = 0x8016239c;
cc36a_read_800fc270 = 0x800fc270;
cc36a_scale_80383090 = 0x80383090;
cc36a_type_8040db38 = 0x8040db38;
SECTIONS {
  .text.cc36a_low_gravity_800c1a14 0x800c1a14 : { *(.text.cc36a_low_gravity_800c1a14) }
  .sdata 0x804ae684 (NOLOAD) : {
    . = 0x0; cc36a_cache_804ae684 = .;
    . = 0x10; cc36a_cache_804ae694 = .;
    . = 0x30d0; cc36a_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
