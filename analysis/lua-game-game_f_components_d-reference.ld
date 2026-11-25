/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_component_list_get_80097600)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_base_construct_8015fef0 = 0x8015fef0;
w3d_base_destroy_8003de80 = 0x8003de80;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_base_handle_message_8003df40 = 0x8003df40;
w3d_base_handle_message_8015fb34 = 0x8015fb34;
w3d_component_construct_800980ac = 0x800980ac;
w3d_component_construct_80098bb8 = 0x80098bb8;
w3d_component_destroy_80098c2c = 0x80098c2c;
w3d_component_list_803605a0 = 0x803605a0;
w3d_component_list_803605d0 = 0x803605d0;
w3d_component_list_80360600 = 0x80360600;
w3d_component_start_80097980 = 0x80097980;
w3d_component_start_80098240 = 0x80098240;
w3d_component_stop_80097c5c = 0x80097c5c;
w3d_component_vtable_8040f290 = 0x8040f290;
w3d_component_vtable_8040f2d0 = 0x8040f2d0;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_owner_list_remove = 0x8020fd2c;
w3d_state_register = 0x8020fd04;
SECTIONS {
  .text.w3d_component_list_get_80097600 0x80097600 : { *(.text.w3d_component_list_get_80097600) }
  .text.w3d_component_unlink_8009760c 0x8009760c : { *(.text.w3d_component_unlink_8009760c) }
  .text.w3d_component_create_80097650 0x80097650 : { *(.text.w3d_component_create_80097650) }
  .text.w3d_component_release_800976b0 0x800976b0 : { *(.text.w3d_component_release_800976b0) }
  .text.w3d_component_retain_8009770c 0x8009770c : { *(.text.w3d_component_retain_8009770c) }
  .text.w3d_component_construct_80097724 0x80097724 : { *(.text.w3d_component_construct_80097724) }
  .text.w3d_component_destroy_80097774 0x80097774 : { *(.text.w3d_component_destroy_80097774) }
  .text.w3d_component_handle_message_800977d4 0x800977d4 : { *(.text.w3d_component_handle_message_800977d4) }
  .text.w3d_component_list_get_80097f88 0x80097f88 : { *(.text.w3d_component_list_get_80097f88) }
  .text.w3d_component_unlink_80097f94 0x80097f94 : { *(.text.w3d_component_unlink_80097f94) }
  .text.w3d_component_create_80097fd8 0x80097fd8 : { *(.text.w3d_component_create_80097fd8) }
  .text.w3d_component_release_80098038 0x80098038 : { *(.text.w3d_component_release_80098038) }
  .text.w3d_component_retain_80098094 0x80098094 : { *(.text.w3d_component_retain_80098094) }
  .text.w3d_component_destroy_8009810c 0x8009810c : { *(.text.w3d_component_destroy_8009810c) }
  .text.w3d_component_handle_message_8009816c 0x8009816c : { *(.text.w3d_component_handle_message_8009816c) }
  .text.w3d_component_stop_8009836c 0x8009836c : { *(.text.w3d_component_stop_8009836c) }
  .text.w3d_component_list_get_80098a94 0x80098a94 : { *(.text.w3d_component_list_get_80098a94) }
  .text.w3d_component_unlink_80098aa0 0x80098aa0 : { *(.text.w3d_component_unlink_80098aa0) }
  .text.w3d_component_create_80098ae4 0x80098ae4 : { *(.text.w3d_component_create_80098ae4) }
  .text.w3d_component_release_80098b44 0x80098b44 : { *(.text.w3d_component_release_80098b44) }
  .text.w3d_component_retain_80098ba0 0x80098ba0 : { *(.text.w3d_component_retain_80098ba0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
