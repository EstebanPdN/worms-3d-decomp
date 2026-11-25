/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_net_connect_8021adb8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__15String_803426b8 = 0x803426b8;
alloc_801613f0 = 0x801613f0;
base_8015fd1c = 0x8015fd1c;
format_8020c510 = 0x8020c510;
key_8041ca50 = 0x8041ca50;
key_8041cb08 = 0x8041cb08;
lookup_8020b680 = 0x8020b680;
msgid_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
read_800fc230 = 0x800fc230;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
table_8040db38 = 0x8040db38;
text_800fc2b0 = 0x800fc2b0;
text_803b3c14 = 0x803b3c14;
text_803b3c24 = 0x803b3c24;
text_803b3c34 = 0x803b3c34;
text_803b3c48 = 0x803b3c48;
write_800fc550 = 0x800fc550;
SECTIONS {
  .text.w3d_d26k_net_connect_8021adb8 0x8021adb8 : { *(.text.w3d_d26k_net_connect_8021adb8) }
  .sdata 0x804b06fc (NOLOAD) : {
    . = 0x0; cache_804b06fc = .;
    . = 0x80; cache_804b077c = .;
    . = 0x1058; global_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
