/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_node_position)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_owner_list_remove = 0x8020fd2c;
w3d_query_interface_8020b460 = 0x8020b460;
w3d_sprite_set_class_80361c28 = 0x80361c28;
w3d_sprite_set_construct_80186b5c = 0x80186b5c;
w3d_sprite_set_destruct_80187380 = 0x80187380;
w3d_sprite_set_interfaces_803a7ae4 = 0x803a7ae4;
w3d_state_register = 0x8020fd04;
SECTIONS {
  .text.w3d_node_position 0x8018697c : { *(.text.w3d_node_position) }
  .text.w3d_node_rotation 0x80186984 : { *(.text.w3d_node_rotation) }
  .text.w3d_node_scale 0x8018698c : { *(.text.w3d_node_scale) }
  .text.w3d_node_flag 0x80186994 : { *(.text.w3d_node_flag) }
  .text.w3d_node_type 0x801869a0 : { *(.text.w3d_node_type) }
  .text.w3d_node_attachment 0x801869a8 : { *(.text.w3d_node_attachment) }
  .text.w3d_node_child_count 0x801869b0 : { *(.text.w3d_node_child_count) }
  .text.w3d_node_has_parent 0x801869c4 : { *(.text.w3d_node_has_parent) }
  .text.w3d_node_parent 0x801869dc : { *(.text.w3d_node_parent) }
  .text.w3d_sprite_set_get_class 0x801869e4 : { *(.text.w3d_sprite_set_get_class) }
  .text.w3d_sprite_set_unlink 0x801869f0 : { *(.text.w3d_sprite_set_unlink) }
  .text.w3d_sprite_set_create 0x80186a34 : { *(.text.w3d_sprite_set_create) }
  .text.w3d_sprite_set_interfaces 0x80186a94 : { *(.text.w3d_sprite_set_interfaces) }
  .text.w3d_sprite_set_release 0x80186aa0 : { *(.text.w3d_sprite_set_release) }
  .text.w3d_sprite_set_add_ref 0x80186afc : { *(.text.w3d_sprite_set_add_ref) }
  .text.w3d_sprite_set_query_interface 0x80186b14 : { *(.text.w3d_sprite_set_query_interface) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
