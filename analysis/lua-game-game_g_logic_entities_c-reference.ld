/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_logic_type_get_800c4e78)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_display_set_mode_80304b84 = 0x80304b84;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_heap_release = 0x80209920;
w3d_int_vector_insert_80344380 = 0x80344380;
w3d_int_vector_reserve_803445d8 = 0x803445d8;
w3d_logic_base_destroy_801628ec = 0x801628ec;
w3d_logic_base_handle_8016293c = 0x8016293c;
w3d_logic_base_init_801628b0 = 0x801628b0;
w3d_logic_type_80360a80 = 0x80360a80;
w3d_logic_type_80360ab0 = 0x80360ab0;
w3d_message_allocate_801613f0 = 0x801613f0;
w3d_message_post_current = 0x8016239c;
w3d_movie_lookup_800c6100 = 0x800c6100;
w3d_movie_start_800c6698 = 0x800c6698;
w3d_owner_list_remove = 0x8020fd2c;
w3d_pool_busy_8043e448 = 0x8043e448;
w3d_pool_ids_8043e438 = 0x8043e438;
w3d_pool_item_destroy_800f74d0 = 0x800f74d0;
w3d_pool_item_storage_800f7528 = 0x800f7528;
w3d_pool_slots_804a85d8 = 0x804a85d8;
w3d_state_register = 0x8020fd04;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_default = 0x803426b8;
w3d_string_release = 0x80341588;
w3d_vtable_8040db38 = 0x8040db38;
w3d_vtable_8040fa28 = 0x8040fa28;
w3d_vtable_8040fa68 = 0x8040fa68;
SECTIONS {
  .text.w3d_logic_type_get_800c4e78 0x800c4e78 : { *(.text.w3d_logic_type_get_800c4e78) }
  .text.w3d_logic_unlink_800c4e84 0x800c4e84 : { *(.text.w3d_logic_unlink_800c4e84) }
  .text.w3d_logic_create_800c4ec8 0x800c4ec8 : { *(.text.w3d_logic_create_800c4ec8) }
  .text.w3d_logic_release_800c4f28 0x800c4f28 : { *(.text.w3d_logic_release_800c4f28) }
  .text.w3d_logic_retain_800c4f84 0x800c4f84 : { *(.text.w3d_logic_retain_800c4f84) }
  .text.w3d_logic_construct_800c4f9c 0x800c4f9c : { *(.text.w3d_logic_construct_800c4f9c) }
  .text.w3d_logic_destroy_800c5064 0x800c5064 : { *(.text.w3d_logic_destroy_800c5064) }
  .text.w3d_logic_handle_800c5100 0x800c5100 : { *(.text.w3d_logic_handle_800c5100) }
  .text.w3d_logic_hook_800c539c 0x800c539c : { *(.text.w3d_logic_hook_800c539c) }
  .text.w3d_pool_free_800c58a8 0x800c58a8 : { *(.text.w3d_pool_free_800c58a8) }
  .text.w3d_logic_type_get_800c5fdc 0x800c5fdc : { *(.text.w3d_logic_type_get_800c5fdc) }
  .text.w3d_logic_unlink_800c5fe8 0x800c5fe8 : { *(.text.w3d_logic_unlink_800c5fe8) }
  .text.w3d_logic_create_800c602c 0x800c602c : { *(.text.w3d_logic_create_800c602c) }
  .text.w3d_logic_release_800c608c 0x800c608c : { *(.text.w3d_logic_release_800c608c) }
  .text.w3d_logic_retain_800c60e8 0x800c60e8 : { *(.text.w3d_logic_retain_800c60e8) }
  .text.w3d_logic_construct_800c62dc 0x800c62dc : { *(.text.w3d_logic_construct_800c62dc) }
  .text.w3d_logic_destroy_800c6344 0x800c6344 : { *(.text.w3d_logic_destroy_800c6344) }
  .text.w3d_movie_detach_800c6640 0x800c6640 : { *(.text.w3d_movie_detach_800c6640) }
  .text.w3d_movie_play_named_800c6660 0x800c6660 : { *(.text.w3d_movie_play_named_800c6660) }
  .text.w3d_movie_update_800c6878 0x800c6878 : { *(.text.w3d_movie_update_800c6878) }
  .text.w3d_movie_stop_800c6920 0x800c6920 : { *(.text.w3d_movie_stop_800c6920) }
  .text.w3d_movie_shutdown_800c6b50 0x800c6b50 : { *(.text.w3d_movie_shutdown_800c6b50) }
  .sdata 0x804aadfc (NOLOAD) : {
    . = 0x0; w3d_pool_instance_804aadfc = .;
    . = 0x10; w3d_movie_instance_804aae0c = .;
    . = 0x39e8; w3d_message_804ae7e4 = .;
    . = 0x4304; w3d_heap_804af100 = .;
    . = 0x6958; w3d_message_storage_804b1754 = .;
    . = 0x698c; w3d_game_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
