/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27d_worm_linked_step_80151ea4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
activate_800ac278 = 0x800ac278;
alloc_801613f0 = 0x801613f0;
deactivate_800aba08 = 0x800aba08;
init_80131b50 = 0x80131b50;
lookup_80164fc8 = 0x80164fc8;
msg_id_8015f5a0 = 0x8015f5a0;
pointAt_800d75f0 = 0x800d75f0;
post_8016239c = 0x8016239c;
reset_8015286c = 0x8015286c;
sqrt_802e82c0 = 0x802e82c0;
tangentAt_800d76dc = 0x800d76dc;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.d27d_worm_linked_step_80151ea4 0x80151ea4 : { *(.text.d27d_worm_linked_step_80151ea4) }
  .rodata 0x803a1a30 : { *(.rodata) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; tuning_804aa6d8 = .;
    . = 0x5518; cacheB_804afbf0 = .;
    . = 0x55b8; cacheA_804afc90 = .;
    . = 0x707c; heap_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
