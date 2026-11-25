/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d19d_mesh_fade_clip_80181884)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_buffer_manager_poll_state = 0x80198160;
w3d_f32_803a785c = 0x803a785c;
w3d_mesh_instance_update_child_8017a07c = 0x8017a07c;
w3d_slots_request_801983cc = 0x801983cc;
w3d_slots_shared = 0x803439d8;
SECTIONS {
  .text.d19d_mesh_fade_clip_80181884 0x80181884 : { *(.text.d19d_mesh_fade_clip_80181884) }
  .sdata 0x804ab5fc (NOLOAD) : {
    . = 0x0; w3d_scene_list_804ab5fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
