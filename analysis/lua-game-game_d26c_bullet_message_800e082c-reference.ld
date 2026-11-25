/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_bullet_message_800e082c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8015fb34 = 0x8015fb34;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
id_equals_8015f65c = 0x8015f65c;
link_800dfd8c = 0x800dfd8c;
start_800e1420 = 0x800e1420;
stop_800e1cbc = 0x800e1cbc;
value_80125ff8 = 0x80125ff8;
SECTIONS {
  .text.d26c_bullet_message_800e082c 0x800e082c : { *(.text.d26c_bullet_message_800e082c) }
  .sdata 0x804aece0 (NOLOAD) : {
    . = 0x0; id_804aece0 = .;
    . = 0x8; id_804aece8 = .;
    . = 0x10; id_804aecf0 = .;
    . = 0x20; id_804aed00 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
