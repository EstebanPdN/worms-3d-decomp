/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27h_jetpack_start_800aaf5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
cached_id_8015f5a0 = 0x8015f5a0;
cast_80342a74 = 0x80342a74;
create_hud_8020b680 = 0x8020b680;
hud_properties_8011adf8 = 0x8011adf8;
hud_set_visible_8011afac = 0x8011afac;
message_init_800c1620 = 0x800c1620;
message_post_8016239c = 0x8016239c;
n_80381a48 = 0x80381a48;
n_80381a58 = 0x80381a58;
n_80381a6c = 0x80381a6c;
n_80381a80 = 0x80381a80;
n_80381a90 = 0x80381a90;
n_80381a9c = 0x80381a9c;
n_80381ab8 = 0x80381ab8;
n_80381ad4 = 0x80381ad4;
n_80381ae8 = 0x80381ae8;
n_80381b00 = 0x80381b00;
n_80381b18 = 0x80381b18;
n_80381b38 = 0x80381b38;
n_80381b50 = 0x80381b50;
n_80381b6c = 0x80381b6c;
n_80381b88 = 0x80381b88;
n_80381ba4 = 0x80381ba4;
n_80381bbc = 0x80381bbc;
n_80381bd4 = 0x80381bd4;
n_80381bf0 = 0x80381bf0;
read_int_800fc1f0 = 0x800fc1f0;
read_setting_800fc1b0 = 0x800fc1b0;
set_fuel_800ac11c = 0x800ac11c;
submit_80164514 = 0x80164514;
subscribe_80162024 = 0x80162024;
type_80410a10 = 0x80410a10;
SECTIONS {
  .text.d27h_jetpack_start_800aaf5c 0x800aaf5c : { *(.text.d27h_jetpack_start_800aaf5c) }
  .sdata 0x804ae328 (NOLOAD) : {
    . = 0x0; cache_804ae328 = .;
    . = 0x8; cache_804ae330 = .;
    . = 0x10; cache_804ae338 = .;
    . = 0x18; cache_804ae340 = .;
    . = 0x20; cache_804ae348 = .;
    . = 0x28; cache_804ae350 = .;
    . = 0x30; cache_804ae358 = .;
    . = 0x38; cache_804ae360 = .;
    . = 0x40; cache_804ae368 = .;
    . = 0x48; cache_804ae370 = .;
    . = 0x50; cache_804ae378 = .;
    . = 0x108c; g_804af3b4 = .;
    . = 0x342c; g_arena_804b1754 = .;
    . = 0x3464; g_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
