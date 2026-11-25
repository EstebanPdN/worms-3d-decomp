/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_handle_message_80037bac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80037d14 = 0x80037d14;
FUN_800382f4 = 0x800382f4;
FUN_80038354 = 0x80038354;
w3d_auto_8015fb34 = 0x8015fb34;
w3d_message_id_equals_cache = 0x8015f65c;
w3d_release_interface_800382a8 = 0x800382a8;
SECTIONS {
  .text.s19_handle_message_80037bac 0x80037bac : { *(.text.s19_handle_message_80037bac) }
  .sdata 0x804ad050 (NOLOAD) : {
    . = 0x0; lbl_804ad050 = .;
    . = 0x8; lbl_804ad058 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
