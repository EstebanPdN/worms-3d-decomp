/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d46i_clock_tick_8011c89c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
cached_id_8015f5a0 = 0x8015f5a0;
mode_value_80178d1c = 0x80178d1c;
n_8039afd0 = 0x8039afd0;
post_8016239c = 0x8016239c;
read_int_800fc230 = 0x800fc230;
set_hot_seat_8011d78c = 0x8011d78c;
set_post_8011d804 = 0x8011d804;
set_retreat_8011d850 = 0x8011d850;
set_round_8011d7d8 = 0x8011d7d8;
set_turn_8011d89c = 0x8011d89c;
value_80178c48 = 0x80178c48;
vtable_8040db38 = 0x8040db38;
write_int_800fc43c = 0x800fc43c;
SECTIONS {
  .text.w3d_d46i_clock_tick_8011c89c 0x8011c89c : { *(.text.w3d_d46i_clock_tick_8011c89c) }
  .sdata 0x804aabe8 (NOLOAD) : {
    . = 0x0; paused_804aabe8 = .;
    . = 0x47f0; cache_804af3d8 = .;
    . = 0x4808; cache_804af3f0 = .;
    . = 0x4820; cache_804af408 = .;
    . = 0x4830; cache_804af418 = .;
    . = 0x4848; cache_804af430 = .;
    . = 0x6b6c; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
