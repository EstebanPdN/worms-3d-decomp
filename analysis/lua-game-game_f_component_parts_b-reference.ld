/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_component_construct_80068570)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_destroy = 0x80161050;
w3d_actor_base_initialize = 0x80161014;
w3d_actor_handle_member_destroy = 0x80126230;
w3d_base_construct_8015fef0 = 0x8015fef0;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_base_destroy_801628ec = 0x801628ec;
w3d_component_vtable_8040ef28 = 0x8040ef28;
w3d_component_vtable_8040f310 = 0x8040f310;
w3d_component_vtable_8040f5a8 = 0x8040f5a8;
w3d_component_vtable_8040f868 = 0x8040f868;
w3d_handle_storage_release = 0x802134fc;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_default = 0x803426b8;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_component_construct_80068570 0x80068570 : { *(.text.w3d_component_construct_80068570) }
  .text.w3d_component_destroy_80098c2c 0x80098c2c : { *(.text.w3d_component_destroy_80098c2c) }
  .text.w3d_component_construct_800a50a8 0x800a50a8 : { *(.text.w3d_component_construct_800a50a8) }
  .text.w3d_component_destroy_800a50f4 0x800a50f4 : { *(.text.w3d_component_destroy_800a50f4) }
  .text.w3d_component_destroy_800beeb0 0x800beeb0 : { *(.text.w3d_component_destroy_800beeb0) }
  .sdata 0x804aaa9c (NOLOAD) : {
    . = 0x0; w3d_component_active_804aaa9c = .;
    . = 0x138; w3d_component_instance_804aabd4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
