/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24d_application_main_8015ad40)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._14d24d_Arguments = 0x8015b2a4;
__14d24d_Arguments = 0x8015b254;
__main = 0x802f35fc;
d24d_arguments_set_8015b330 = 0x8015b330;
d24d_heap_format_803a4260 = 0x803a4260;
printf = 0x802ebfbc;
w3d_application_entry_801267f8 = 0x801267f8;
w3d_auto_8015c3f4 = 0x8015c3f4;
w3d_auto_8020b3bc = 0x8020b3bc;
w3d_auto_8020b414 = 0x8020b414;
w3d_heap_morecore = 0x801fdfc8;
SECTIONS {
  .text.d24d_application_main_8015ad40 0x8015ad40 : { *(.text.d24d_application_main_8015ad40) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
