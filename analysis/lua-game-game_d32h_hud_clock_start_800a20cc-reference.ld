/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32h_hud_clock_start_800a20cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
cached_8015f5a0 = 0x8015f5a0;
castA_80342a74 = 0x80342a74;
castD_80343df4 = 0x80343df4;
castF_80342fa4 = 0x80342fa4;
castM_8034380c = 0x8034380c;
castN_80342a78 = 0x80342a78;
castT_803426b4 = 0x803426b4;
colour_800fc370 = 0x800fc370;
colours_80189760 = 0x80189760;
data_80189828 = 0x80189828;
layout_800a30bc = 0x800a30bc;
load_8015adf4 = 0x8015adf4;
lock_80189450 = 0x80189450;
property_800fc1b0 = 0x800fc1b0;
resize_8018920c = 0x8018920c;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
subscribe_80162024 = 0x80162024;
uvs_8018963c = 0x8018963c;
value_80178ec4 = 0x80178ec4;
vector_800fc2f0 = 0x800fc2f0;
SECTIONS {
  .text.d32h_hud_clock_start_800a20cc 0x800a20cc : { *(.text.d32h_hud_clock_start_800a20cc) }
  .rodata 0x80380a2c : { *(.rodata) }
  .sdata 0x804ae184 (NOLOAD) : {
    . = 0x0; message_804ae184 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
