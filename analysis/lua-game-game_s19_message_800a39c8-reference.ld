/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_handle_message_800a39c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800a3ac4 = 0x800a3ac4;
FUN_800a3d0c = 0x800a3d0c;
FUN_800a3e84 = 0x800a3e84;
s19_visibility_hide_800a3bb4 = 0x800a3bb4;
s19_visibility_show_800a3bec = 0x800a3bec;
s8_show_flags_800a3fa0 = 0x800a3fa0;
w3d_auto_8016293c = 0x8016293c;
w3d_message_cache_equals = 0x8015f620;
SECTIONS {
  .text.s19_handle_message_800a39c8 0x800a39c8 : { *(.text.s19_handle_message_800a39c8) }
  .sdata 0x804ae18c (NOLOAD) : {
    . = 0x0; lbl_804ae18c = .;
    . = 0x8; lbl_804ae194 = .;
    . = 0x10; lbl_804ae19c = .;
    . = 0x18; lbl_804ae1a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
