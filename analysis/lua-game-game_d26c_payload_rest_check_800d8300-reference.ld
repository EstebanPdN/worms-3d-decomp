/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_payload_rest_check_800d8300)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
ctx_80165254 = 0x80165254;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
file_80389260 = 0x80389260;
id_equals_8015f65c = 0x8015f65c;
land_800d8b4c = 0x800d8b4c;
leave_800eb6e4 = 0x800eb6e4;
may_rest_800d8f8c = 0x800d8f8c;
report_80022e20 = 0x80022e20;
rest_text_8038923c = 0x8038923c;
type_80361860 = 0x80361860;
type_803618f0 = 0x803618f0;
SECTIONS {
  .text.d26c_payload_rest_check_800d8300 0x800d8300 : { *(.text.d26c_payload_rest_check_800d8300) }
  .rodata 0x80389280 : { *(.rodata) }
  .sdata 0x804aeaf8 (NOLOAD) : {
    . = 0x0; rest_id_804aeaf8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
