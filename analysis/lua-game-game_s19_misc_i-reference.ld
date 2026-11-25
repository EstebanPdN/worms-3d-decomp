/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_check_pair_80015434)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80015400 = 0x80015400;
lbl_8040e310 = 0x8040e310;
w3d_actor_base_initialize = 0x80161014;
w3d_auto_800154b4 = 0x800154b4;
SECTIONS {
  .text.s19_check_pair_80015434 0x80015434 : { *(.text.s19_check_pair_80015434) }
  .text.s19_actor_init_8002a914 0x8002a914 : { *(.text.s19_actor_init_8002a914) }
  .sdata 0x804aa6d0 (NOLOAD) : {
    . = 0x0; lbl_804aa6d0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
