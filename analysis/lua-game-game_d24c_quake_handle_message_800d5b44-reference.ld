/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_quake_handle_message_800d5b44)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8015fb34 = 0x8015fb34;
h1_800d6424 = 0x800d6424;
h2_800d6788 = 0x800d6788;
h3_800d67d8 = 0x800d67d8;
h4_800d6904 = 0x800d6904;
id_equals_8015f65c = 0x8015f65c;
start_800d5d44 = 0x800d5d44;
stop_800d5f98 = 0x800d5f98;
SECTIONS {
  .text.d24c_quake_handle_message_800d5b44 0x800d5b44 : { *(.text.d24c_quake_handle_message_800d5b44) }
  .sdata 0x804aea58 (NOLOAD) : {
    . = 0x0; a_804aea58 = .;
    . = 0x8; b_804aea60 = .;
    . = 0x10; c_804aea68 = .;
    . = 0x20; d_804aea78 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
