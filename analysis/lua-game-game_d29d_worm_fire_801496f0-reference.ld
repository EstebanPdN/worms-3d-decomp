/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29d_worm_fire_801496f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._6Handle = 0x80178474;
alloc_801613f0 = 0x801613f0;
auto_80151128 = 0x80151128;
avail_800fcea0 = 0x800fcea0;
clear_links_8014df84 = 0x8014df84;
create_8020b680 = 0x8020b680;
desc_8040e398 = 0x8040e398;
desc_8040ed18 = 0x8040ed18;
desc_8040eed8 = 0x8040eed8;
desc_8040f0d0 = 0x8040f0d0;
desc_8040f1e8 = 0x8040f1e8;
desc_8040f380 = 0x8040f380;
desc_8040f680 = 0x8040f680;
desc_8040f8d8 = 0x8040f8d8;
desc_8040f998 = 0x8040f998;
desc_8040fbf8 = 0x8040fbf8;
desc_8040fc38 = 0x8040fc38;
desc_80410258 = 0x80410258;
desc_80410418 = 0x80410418;
desc_80410550 = 0x80410550;
desc_80410628 = 0x80410628;
desc_80410840 = 0x80410840;
desc_80410940 = 0x80410940;
desc_80410f70 = 0x80410f70;
get_800fc330 = 0x800fc330;
item_800fc710 = 0x800fc710;
link_8014dcbc = 0x8014dcbc;
logic_800c31f4 = 0x800c31f4;
message_id_8015f5a0 = 0x8015f5a0;
owner_8014c488 = 0x8014c488;
post_8016239c = 0x8016239c;
query_800fc6dc = 0x800fc6dc;
send_80164514 = 0x80164514;
send_to_8015fc58 = 0x8015fc58;
set_fire_80153dfc = 0x80153dfc;
table2_803eb700 = 0x803eb700;
table2_803eb710 = 0x803eb710;
table_803eb63c = 0x803eb63c;
third_80150b6c = 0x80150b6c;
type_80368328 = 0x80368328;
use_8002b070 = 0x8002b070;
use_8009c820 = 0x8009c820;
use_800ee904 = 0x800ee904;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.d29d_worm_fire_801496f0 0x801496f0 : { *(.text.d29d_worm_fire_801496f0) }
  .sdata 0x804aab4c (NOLOAD) : {
    . = 0x0; owner_804aab4c = .;
    . = 0x504c; cache_804afb98 = .;
    . = 0x507c; cache_804afbc8 = .;
    . = 0x516c; cache_804afcb8 = .;
    . = 0x518c; cache_804afcd8 = .;
    . = 0x5274; cache_804afdc0 = .;
    . = 0x6c08; heap_804b1754 = .;
    . = 0x6c40; service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
