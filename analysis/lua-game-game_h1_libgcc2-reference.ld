/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__do_global_ctors)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ctor_list_8035f3e0 = 0x8035f3e0;
w3d_main_initialized_8047dd1c = 0x8047dd1c;
SECTIONS {
  .text.__do_global_ctors 0x802f356c : { *(.text.__do_global_ctors) }
  .text.__main 0x802f35fc : { *(.text.__main) }
  .text.__ashldi3 0x802f3634 : { *(.text.__ashldi3) }
  .text.__ashrdi3 0x802f3674 : { *(.text.__ashrdi3) }
  .text.__cmpdi2 0x802f36b4 : { *(.text.__cmpdi2) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
