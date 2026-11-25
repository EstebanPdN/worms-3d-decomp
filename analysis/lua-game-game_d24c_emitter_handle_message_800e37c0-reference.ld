/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_emitter_handle_message_800e37c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8015fb34 = 0x8015fb34;
id_equals_8015f65c = 0x8015f65c;
identity_80341584 = 0x80341584;
post_800de7f0 = 0x800de7f0;
settings_801797b4 = 0x801797b4;
start_800e3e8c = 0x800e3e8c;
stop_800e41d8 = 0x800e41d8;
transplant_800dfd8c = 0x800dfd8c;
value_80125ff8 = 0x80125ff8;
SECTIONS {
  .text.d24c_emitter_handle_message_800e37c0 0x800e37c0 : { *(.text.d24c_emitter_handle_message_800e37c0) }
  .sdata 0x804aed44 (NOLOAD) : {
    . = 0x0; a_804aed44 = .;
    . = 0x8; b_804aed4c = .;
    . = 0x28; c_804aed6c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
