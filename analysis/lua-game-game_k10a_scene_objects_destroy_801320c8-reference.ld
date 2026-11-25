/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_scene_objects_destroy_801320c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_handle_member_destroy = 0x80126230;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_vtable_80410e80 = 0x80410e80;
SECTIONS {
  .text.w3d_k10a_scene_objects_destroy_801320c8 0x801320c8 : { *(.text.w3d_k10a_scene_objects_destroy_801320c8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
