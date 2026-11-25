/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_send_float_800a7ca0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800faa44 = 0x800faa44;
FUN_801613f0 = 0x801613f0;
w3d_engine_get_context = 0x80165254;
w3d_message_float_init = 0x80069a0c;
w3d_message_post_current = 0x8016239c;
SECTIONS {
  .text.s19_send_float_800a7ca0 0x800a7ca0 : { *(.text.s19_send_float_800a7ca0) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
