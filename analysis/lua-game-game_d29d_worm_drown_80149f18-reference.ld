/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29d_worm_drown_80149f18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._6Handle = 0x80178474;
active_80178c48 = 0x80178c48;
alloc_801613f0 = 0x801613f0;
clear_links_8014df84 = 0x8014df84;
engine_80165254 = 0x80165254;
falling_8014fcac = 0x8014fcac;
get_80158dc4 = 0x80158dc4;
get_803426b4 = 0x803426b4;
int_message_800a82f0 = 0x800a82f0;
item_800fc710 = 0x800fc710;
log_80022e20 = 0x80022e20;
message_id_8015f5a0 = 0x8015f5a0;
owner_8014c488 = 0x8014c488;
post_8016239c = 0x8016239c;
query_800fc6dc = 0x800fc6dc;
set_80158dcc = 0x80158dcc;
set_state_801492ec = 0x801492ec;
splash_800e5ca4 = 0x800e5ca4;
sqrt_802e82c0 = 0x802e82c0;
str_803a0e2c = 0x803a0e2c;
str_803a1308 = 0x803a1308;
str_803a131c = 0x803a131c;
str_803a1328 = 0x803a1328;
triple_8045e788 = 0x8045e788;
type_80361860 = 0x80361860;
type_803618f0 = 0x803618f0;
value_80178df0 = 0x80178df0;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.d29d_worm_drown_80149f18 0x80149f18 : { *(.text.d29d_worm_drown_80149f18) }
  .rodata 0x803a1338 : { *(.rodata) }
  .sdata 0x804ab400 (NOLOAD) : {
    . = 0x0; turns_804ab400 = .;
    . = 0x4760; cache_804afb60 = .;
    . = 0x4768; cache_804afb68 = .;
    . = 0x4858; cache_804afc58 = .;
    . = 0x4930; cache_804afd30 = .;
    . = 0x4938; cache_804afd38 = .;
    . = 0x6354; heap_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
