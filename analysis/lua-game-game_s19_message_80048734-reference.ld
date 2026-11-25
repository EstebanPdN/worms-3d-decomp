/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_handle_message_80048734)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80048840 = 0x80048840;
FUN_80048a90 = 0x80048a90;
w3d_auto_80048fac = 0x80048fac;
w3d_auto_8015fb34 = 0x8015fb34;
w3d_engine_get_context = 0x80165254;
w3d_fn_80048ec4 = 0x80048ec4;
w3d_fn_80048f1c = 0x80048f1c;
w3d_message_id_equals_cache = 0x8015f65c;
SECTIONS {
  .text.s19_handle_message_80048734 0x80048734 : { *(.text.s19_handle_message_80048734) }
  .sdata 0x804ad2e8 (NOLOAD) : {
    . = 0x0; lbl_804ad2e8 = .;
    . = 0x8; lbl_804ad2f0 = .;
    . = 0x28; lbl_804ad310 = .;
    . = 0x30; lbl_804ad318 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
