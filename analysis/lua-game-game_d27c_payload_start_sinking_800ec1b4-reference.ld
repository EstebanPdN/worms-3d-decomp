/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_payload_start_sinking_800ec1b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
empty_80342a74 = 0x80342a74;
init_80126000 = 0x80126000;
keyMax_8038b538 = 0x8038b538;
keyMin_8038b520 = 0x8038b520;
mesh_800ed9c8 = 0x800ed9c8;
msg_id_8015f5a0 = 0x8015f5a0;
post_8015fc58 = 0x8015fc58;
post_8016239c = 0x8016239c;
read_800fc270 = 0x800fc270;
sqrt_802e82c0 = 0x802e82c0;
value_80178df0 = 0x80178df0;
vt_8040db38 = 0x8040db38;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d27c_payload_start_sinking_800ec1b4 0x800ec1b4 : { *(.text.d27c_payload_start_sinking_800ec1b4) }
  .rodata 0x8038b550 : { *(.rodata) }
  .sdata 0x804aeef0 (NOLOAD) : {
    . = 0x0; idA_804aeef0 = .;
    . = 0x8; idB_804aeef8 = .;
    . = 0x2864; heap_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
