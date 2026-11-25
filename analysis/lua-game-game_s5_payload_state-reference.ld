/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_payload_state_init_800cc8a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80210abc = 0x80210abc;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_ctor_8015fef0 = 0x8015fef0;
w3d_payload_vtable_8040fbc8 = 0x8040fbc8;
w3d_pending_init_802109dc = 0x802109dc;
w3d_task_deferred_clear = 0x80210afc;
SECTIONS {
  .text.w3d_payload_state_init_800cc8a0 0x800cc8a0 : { *(.text.w3d_payload_state_init_800cc8a0) }
  .text.w3d_payload_state_destroy_800cc908 0x800cc908 : { *(.text.w3d_payload_state_destroy_800cc908) }
  .text.w3d_payload_pending_clear_800ccd54 0x800ccd54 : { *(.text.w3d_payload_pending_clear_800ccd54) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
