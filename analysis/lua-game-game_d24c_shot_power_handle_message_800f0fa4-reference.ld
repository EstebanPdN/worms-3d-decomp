/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24c_shot_power_handle_message_800f0fa4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_801613f0 = 0x801613f0;
base_8015fb34 = 0x8015fb34;
context_80165254 = 0x80165254;
id_equals_8015f65c = 0x8015f65c;
init_800f1200 = 0x800f1200;
message_id_8015f5a0 = 0x8015f5a0;
message_vtable_8040db38 = 0x8040db38;
post_8016239c = 0x8016239c;
restricted_800ef788 = 0x800ef788;
SECTIONS {
  .text.d24c_shot_power_handle_message_800f0fa4 0x800f0fa4 : { *(.text.d24c_shot_power_handle_message_800f0fa4) }
  .sdata 0x804aaf04 (NOLOAD) : {
    . = 0x0; actor_804aaf04 = .;
    . = 0x415c; b_804af060 = .;
    . = 0x4164; m1_804af068 = .;
    . = 0x4174; m0_804af078 = .;
    . = 0x417c; m3_804af080 = .;
    . = 0x4184; a_804af088 = .;
    . = 0x418c; m2_804af090 = .;
    . = 0x6850; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
