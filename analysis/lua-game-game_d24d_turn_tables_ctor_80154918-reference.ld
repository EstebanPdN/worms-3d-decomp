/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__15d24d_TurnTables)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__13d24d_TurnBase = 0x801628b0;
_vt.15d24d_TurnTables = 0x80410f40;
SECTIONS {
  .text.__15d24d_TurnTables 0x80154918 : { *(.text.__15d24d_TurnTables) }
  .sdata 0x804ab400 (NOLOAD) : {
    . = 0x0; d24d_turn_instance_804ab400 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
