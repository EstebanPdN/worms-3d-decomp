/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80049c3c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_handle_member_set_bounds = 0x80126278;
w3d_auto_8004ce38 = 0x8004ce38;
w3d_auto_8015fc58 = 0x8015fc58;
w3d_cached_message_id = 0x8015f5a0;
w3d_fn_8004b958 = 0x8004b958;
w3d_fn_8004bdf8 = 0x8004bdf8;
w3d_fn_8004d1c4 = 0x8004d1c4;
w3d_fn_801613f0 = 0x801613f0;
w3d_scene_timer_is_one_8006e71c = 0x8006e71c;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_fn_80049c3c 0x80049c3c : { *(.text.w3d_fn_80049c3c) }
  .sdata 0x804ad400 (NOLOAD) : {
    . = 0x0; w3d_id_804ad400 = .;
    . = 0x4354; w3d_queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
