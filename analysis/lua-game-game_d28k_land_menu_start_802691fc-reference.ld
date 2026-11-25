/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28k_land_menu_start_802691fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__15String_803426b8 = 0x803426b8;
__15String_803426b8PCc = 0x8020bb54;
acquire_80162024 = 0x80162024;
apply_8026c8a8 = 0x8026c8a8;
build_8026a16c = 0x8026a16c;
cached_8015f5a0 = 0x8015f5a0;
cast_8034357c = 0x8034357c;
cast_80343df4 = 0x80343df4;
engine_80165254 = 0x80165254;
format_8020c510 = 0x8020c510;
land_callback_80269994 = 0x80269994;
load_8015adf4 = 0x8015adf4;
lookup_800fc1b0 = 0x800fc1b0;
panel_802b0b84 = 0x802b0b84;
random_8026cd1c = 0x8026cd1c;
read_800fc230 = 0x800fc230;
save_8026bdf0 = 0x8026bdf0;
store_80173f88 = 0x80173f88;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
text_803cb850 = 0x803cb850;
text_803cb874 = 0x803cb874;
text_803cb884 = 0x803cb884;
text_803cb89c = 0x803cb89c;
text_803cb8ac = 0x803cb8ac;
text_803cb8bc = 0x803cb8bc;
text_803cb8d0 = 0x803cb8d0;
value_80178f54 = 0x80178f54;
watch_800fd62c = 0x800fd62c;
write_800fc43c = 0x800fc43c;
zero_803cb8f4 = 0x803cb8f4;
SECTIONS {
  .text.w3d_d28k_land_menu_start_802691fc 0x802691fc : { *(.text.w3d_d28k_land_menu_start_802691fc) }
  .sdata 0x804b0ac4 (NOLOAD) : {
    . = 0x0; cache_804b0ac4 = .;
    . = 0x8; cache_804b0acc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
