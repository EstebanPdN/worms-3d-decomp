/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_send_range_800a7d18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800fb1b8 = 0x800fb1b8;
FUN_801613f0 = 0x801613f0;
w3d_engine_get_context = 0x80165254;
w3d_message_post_current = 0x8016239c;
w3d_value_range_init_80069a30 = 0x80069a30;
SECTIONS {
  .text.s19_send_range_800a7d18 0x800a7d18 : { *(.text.s19_send_range_800a7d18) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
