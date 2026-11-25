/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_read_team_item_8021bb9c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
find_8021eb70 = 0x8021eb70;
get_8021ed0c = 0x8021ed0c;
key_80418de0 = 0x80418de0;
lookup_8020b680 = 0x8020b680;
props_80240994 = 0x80240994;
type_80366ca8 = 0x80366ca8;
SECTIONS {
  .text.w3d_d26k_read_team_item_8021bb9c 0x8021bb9c : { *(.text.w3d_d26k_read_team_item_8021bb9c) }
  .sdata 0x804af594 (NOLOAD) : {
    . = 0x0; global_804af594 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
