/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_payload_stop_800ea530)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_801613f0 = 0x801613f0;
base_800edbbc = 0x800edbbc;
member_80126230 = 0x80126230;
memcpy = 0x802eee50;
message_id_8015f5a0 = 0x8015f5a0;
msg_init_801190b4 = 0x801190b4;
name_8038b3dc = 0x8038b3dc;
post_8016239c = 0x8016239c;
write_800fc43c = 0x800fc43c;
SECTIONS {
  .text.d24c_payload_stop_800ea530 0x800ea530 : { *(.text.d24c_payload_stop_800ea530) }
  .sdata 0x804aef28 (NOLOAD) : {
    . = 0x0; cache_804aef28 = .;
    . = 0x282c; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
