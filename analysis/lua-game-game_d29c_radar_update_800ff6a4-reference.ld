/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29c_radar_update_800ff6a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
count_8008c34c = 0x8008c34c;
empty_8034380c = 0x8034380c;
flags_80189704 = 0x80189704;
lookup_8008c360 = 0x8008c360;
positions_80189518 = 0x80189518;
setCount_8018920c = 0x8018920c;
sizes_8018963c = 0x8018963c;
sqrt_802e82c0 = 0x802e82c0;
teams_80189828 = 0x80189828;
value_80178df0 = 0x80178df0;
vector_80178ec4 = 0x80178ec4;
SECTIONS {
  .text.d29c_radar_update_800ff6a4 0x800ff6a4 : { *(.text.d29c_radar_update_800ff6a4) }
  .rodata 0x80398380 : { *(.rodata) }
  .sdata 0x804aab4c (NOLOAD) : {
    . = 0x0; players_804aab4c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
