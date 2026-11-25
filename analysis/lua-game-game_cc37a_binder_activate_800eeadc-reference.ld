/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc37a_binder_activate_800eeadc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc37a_active_8038bd9c = 0x8038bd9c;
cc37a_alloc_801613f0 = 0x801613f0;
cc37a_cached_8015f5a0 = 0x8015f5a0;
cc37a_config_801797b4 = 0x801797b4;
cc37a_context_80165254 = 0x80165254;
cc37a_delay_800c53a0 = 0x800c53a0;
cc37a_first_800eedc8 = 0x800eedc8;
cc37a_notify_800fdc80 = 0x800fdc80;
cc37a_post_8016239c = 0x8016239c;
cc37a_read_800fc1f0 = 0x800fc1f0;
cc37a_second_800ef568 = 0x800ef568;
cc37a_touch_80341584 = 0x80341584;
cc37a_type_8040db38 = 0x8040db38;
cc37a_worm_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.cc37a_binder_activate_800eeadc 0x800eeadc : { *(.text.cc37a_binder_activate_800eeadc) }
  .sdata 0x804aeff4 (NOLOAD) : {
    . = 0x0; cc37a_key_804aeff4 = .;
    . = 0x28; cc37a_key_804af01c = .;
    . = 0x2760; cc37a_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
