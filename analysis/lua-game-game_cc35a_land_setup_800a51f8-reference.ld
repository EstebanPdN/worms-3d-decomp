/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc35a_land_setup_800a51f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc35a_alloc_801613f0 = 0x801613f0;
cc35a_finish_800a5390 = 0x800a5390;
cc35a_format_8020c510 = 0x8020c510;
cc35a_id_8015f5a0 = 0x8015f5a0;
cc35a_message_8010a8e0 = 0x8010a8e0;
cc35a_property_800fc2b0 = 0x800fc2b0;
cc35a_route_80164514 = 0x80164514;
cc35a_send_8015fc58 = 0x8015fc58;
cc35a_text_80381004 = 0x80381004;
cc35a_text_80381014 = 0x80381014;
cc35a_text_80381020 = 0x80381020;
cc35a_type_8020b680 = 0x8020b680;
cc35a_type_8040f7c8 = 0x8040f7c8;
cc35a_type_8040f818 = 0x8040f818;
cc35a_type_8040fb28 = 0x8040fb28;
cc35a_type_80410680 = 0x80410680;
cc35a_type_80410d70 = 0x80410d70;
SECTIONS {
  .text.cc35a_land_setup_800a51f8 0x800a51f8 : { *(.text.cc35a_land_setup_800a51f8) }
  .sdata 0x804ae240 (NOLOAD) : {
    . = 0x0; cc35a_cache_804ae240 = .;
    . = 0x8; cc35a_cache_804ae248 = .;
    . = 0x3514; cc35a_arena_804b1754 = .;
    . = 0x354c; cc35a_service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
