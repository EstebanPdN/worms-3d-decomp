/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(mx16sa_locked_names_8006b8a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_801613f0 = 0x801613f0;
attach_80164514 = 0x80164514;
locked_name2_8037bb18 = 0x8037bb18;
locked_name3_8037bb28 = 0x8037bb28;
locked_name_8037bb04 = 0x8037bb04;
message_id_8015f5a0 = 0x8015f5a0;
message_table_8040db38 = 0x8040db38;
post_8016239c = 0x8016239c;
query_text_800fc2b0 = 0x800fc2b0;
service_8020b680 = 0x8020b680;
service_key_8040fa58 = 0x8040fa58;
set_mode_8006ab48 = 0x8006ab48;
SECTIONS {
  .text.mx16sa_locked_names_8006b8a0 0x8006b8a0 : { *(.text.mx16sa_locked_names_8006b8a0) }
  .sdata 0x804ad7ac (NOLOAD) : {
    . = 0x0; cached_id_804ad7ac = .;
    . = 0x3fa8; pool_804b1754 = .;
    . = 0x3fdc; runtime_804b1788 = .;
    . = 0x3fe0; manager_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
