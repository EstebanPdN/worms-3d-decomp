/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29c_part_team_tint_800da4e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
active_8038976c = 0x8038976c;
cast_80179598 = 0x80179598;
empty_80343584 = 0x80343584;
entry_800fd388 = 0x800fd388;
forward_800e5cf0 = 0x800e5cf0;
identity_80341584 = 0x80341584;
part_8038977c = 0x8038977c;
query_800fc6dc = 0x800fc6dc;
readInt_800fc1f0 = 0x800fc1f0;
readRes_800fc1b0 = 0x800fc1b0;
reserve_801ef048 = 0x801ef048;
SECTIONS {
  .text.d29c_part_team_tint_800da4e4 0x800da4e4 : { *(.text.d29c_part_team_tint_800da4e4) }
  .rodata 0x80389798 : { *(.rodata) }
  .sdata 0x804aae7c (NOLOAD) : {
    . = 0x0; group_804aae7c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
