/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_actor_fire_or_shoot_800d973c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
cached_id_8015f5a0 = 0x8015f5a0;
data_8040db38 = 0x8040db38;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
empty_text_8038956c = 0x8038956c;
post_8015fc58 = 0x8015fc58;
schedule_800d8ed8 = 0x800d8ed8;
shoot_800ec6a8 = 0x800ec6a8;
strcmp = 0x802ef234;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d26c_actor_fire_or_shoot_800d973c 0x800d973c : { *(.text.d26c_actor_fire_or_shoot_800d973c) }
  .sdata 0x804aeb40 (NOLOAD) : {
    . = 0x0; fire_id_804aeb40 = .;
    . = 0x28; done_id_804aeb68 = .;
    . = 0x2c14; arena_804b1754 = .;
    . = 0x2c48; audio_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
