/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27h_inventory_setup_800a57b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__6StringPCc = 0x8020bb54;
alliance_inventory_800fcdb8 = 0x800fcdb8;
propagate_tag_801ea4c8 = 0x801ea4c8;
release_header_8020bb2c = 0x8020bb2c;
spawn_800a5a94 = 0x800a5a94;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
team_800fc82c = 0x800fc82c;
team_counts_80381260 = 0x80381260;
team_inventory_800fcc9c = 0x800fcc9c;
team_names_803f4c40 = 0x803f4c40;
text_803811ec = 0x803811ec;
text_80381204 = 0x80381204;
text_8038121c = 0x8038121c;
unsigned_read_800fc330 = 0x800fc330;
worm_800fc710 = 0x800fc710;
worm_inventory_800fca64 = 0x800fca64;
SECTIONS {
  .text.d27h_inventory_setup_800a57b0 0x800a57b0 : { *(.text.d27h_inventory_setup_800a57b0) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; g_services_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
