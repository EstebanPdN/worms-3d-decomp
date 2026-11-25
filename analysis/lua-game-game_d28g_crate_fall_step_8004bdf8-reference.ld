/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28g_crate_fall_step_8004bdf8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
bounce_8043ae38 = 0x8043ae38;
f6b_crate_step_8004c138 = 0x8004c138;
msg_data_8040db38 = 0x8040db38;
s19_dispatch_indexed_800bd920 = 0x800bd920;
sqrt_802e82c0 = 0x802e82c0;
sweep_800b0824 = 0x800b0824;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_80178df0 = 0x80178df0;
w3d_cached_message_id = 0x8015f5a0;
w3d_d25g_body_bounce_8004ce58 = 0x8004ce58;
w3d_fn_8004cd08 = 0x8004cd08;
w3d_message_post_current = 0x8016239c;
SECTIONS {
  .text.w3d_d28g_crate_fall_step_8004bdf8 0x8004bdf8 : { *(.text.w3d_d28g_crate_fall_step_8004bdf8) }
  .rodata 0x80377294 : { *(.rodata) }
  .sdata 0x804ad3b8 (NOLOAD) : {
    . = 0x0; msg_slot_804ad3b8 = .;
    . = 0x439c; arena_804b1754 = .;
    . = 0x43ac; hits_804b1764 = .;
    . = 0x43cc; flag_804b1784 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
