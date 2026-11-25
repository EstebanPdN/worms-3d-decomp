/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_payload_play_effect_800ed9c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Pos = 0x80343740;
alloc_801613f0 = 0x801613f0;
base_800edbbc = 0x800edbbc;
ctx_80165254 = 0x80165254;
desc_801797b4 = 0x801797b4;
effect_800e5ca4 = 0x800e5ca4;
empty_80341584 = 0x80341584;
key_8038b620 = 0x8038b620;
msg_id_8015f5a0 = 0x8015f5a0;
post_8015fc58 = 0x8015fc58;
read_800fc230 = 0x800fc230;
spawn_800e5cf0 = 0x800e5cf0;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
vt_8040db38 = 0x8040db38;
write_800fc43c = 0x800fc43c;
xform_80181e3c = 0x80181e3c;
SECTIONS {
  .text.d27c_payload_play_effect_800ed9c8 0x800ed9c8 : { *(.text.d27c_payload_play_effect_800ed9c8) }
  .rodata 0x8038b630 : { *(.rodata) }
  .sdata 0x804aef38 (NOLOAD) : {
    . = 0x0; msgid_804aef38 = .;
    . = 0x281c; heap_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
