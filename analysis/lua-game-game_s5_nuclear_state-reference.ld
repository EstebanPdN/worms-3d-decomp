/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_nuclear_destroy_800d24e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_801797b4 = 0x801797b4;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80341584 = 0x80341584;
w3d_engine_get_context = 0x80165254;
w3d_int_message_init_80125fdc = 0x80125fdc;
w3d_message_allocate_801613f0 = 0x801613f0;
w3d_message_post_current = 0x8016239c;
w3d_message_vtable_8040db38 = 0x8040db38;
w3d_nuclear_base_destroy_8002a978 = 0x8002a978;
w3d_nuclear_base_detach_8002ae70 = 0x8002ae70;
w3d_nuclear_base_step_8002ad9c = 0x8002ad9c;
w3d_nuclear_vtable_8040fc48 = 0x8040fc48;
w3d_pool_release_800c56b8 = 0x800c56b8;
w3d_str_803887bc = 0x803887bc;
w3d_timer_set_800fde64 = 0x800fde64;
SECTIONS {
  .text.w3d_nuclear_destroy_800d24e0 0x800d24e0 : { *(.text.w3d_nuclear_destroy_800d24e0) }
  .text.w3d_nuclear_detach_800d2790 0x800d2790 : { *(.text.w3d_nuclear_detach_800d2790) }
  .text.w3d_nuclear_step_800d2848 0x800d2848 : { *(.text.w3d_nuclear_step_800d2848) }
  .sdata 0x804aae44 (NOLOAD) : {
    . = 0x0; w3d_nuclear_utility_804aae44 = .;
    . = 0x3b88; w3d_nuclear_name_804ae9cc = .;
    . = 0x3b90; w3d_nuclear_name_804ae9d4 = .;
    . = 0x6910; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
