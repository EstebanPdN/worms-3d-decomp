/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_status_refresh_8021e054)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__15String_803426b8 = 0x803426b8;
load_80178c48 = 0x80178c48;
query_800fc6dc = 0x800fc6dc;
read_800fc1f0 = 0x800fc1f0;
release_header_8020bb2c = 0x8020bb2c;
stamp_80162ba8 = 0x80162ba8;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
text_803b4708 = 0x803b4708;
title_80165018 = 0x80165018;
view_8015aa04 = 0x8015aa04;
SECTIONS {
  .text.w3d_d26k_status_refresh_8021e054 0x8021e054 : { *(.text.w3d_d26k_status_refresh_8021e054) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; global_804aa8c8 = .;
    . = 0x11f8; global_804abac0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
