/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__13D33sNameTable)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__12D33sNameList = 0x800c4598;
__8D33sBase = 0x801628b0;
__8D33sName = 0x803426b8;
__vt_13D33sNameTable = 0x8040ef98;
d33s_name_defaults_8042e700 = 0x8042e700;
memset = 0x802eefe0;
SECTIONS {
  .text.__13D33sNameTable 0x80069c8c : { *(.text.__13D33sNameTable) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; d33s_name_table_804aaabc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
