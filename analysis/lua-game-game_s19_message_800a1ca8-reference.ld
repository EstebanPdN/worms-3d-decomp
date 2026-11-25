/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_handle_message_800a1ca8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800a20cc = 0x800a20cc;
w3d_auto_8015fb34 = 0x8015fb34;
w3d_message_id_equals_cache = 0x8015f65c;
SECTIONS {
  .text.s19_handle_message_800a1ca8 0x800a1ca8 : { *(.text.s19_handle_message_800a1ca8) }
  .sdata 0x804ae184 (NOLOAD) : {
    . = 0x0; lbl_804ae184 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
