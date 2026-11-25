/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc34a_explosion_properties_8008c718)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc34a_alloc_801613f0 = 0x801613f0;
cc34a_find_8008bad0 = 0x8008bad0;
cc34a_init_800666b4 = 0x800666b4;
cc34a_name_8037e010 = 0x8037e010;
cc34a_name_8037e028 = 0x8037e028;
cc34a_name_8037e040 = 0x8037e040;
cc34a_name_8037e060 = 0x8037e060;
cc34a_name_8037e07c = 0x8037e07c;
cc34a_name_8037e098 = 0x8037e098;
cc34a_name_8037e0b4 = 0x8037e0b4;
cc34a_post_8016239c = 0x8016239c;
cc34a_readfloat_800fc270 = 0x800fc270;
cc34a_readtext_800fc2b0 = 0x800fc2b0;
SECTIONS {
  .text.cc34a_explosion_properties_8008c718 0x8008c718 : { *(.text.cc34a_explosion_properties_8008c718) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; cc34a_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
