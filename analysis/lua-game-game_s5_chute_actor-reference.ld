/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_chute_actor_destroy_800daad8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_destroy = 0x80161050;
w3d_chute_vtable_8040fe40 = 0x8040fe40;
w3d_f32_803898e0 = 0x803898e0;
w3d_str_803898d4 = 0x803898d4;
SECTIONS {
  .text.w3d_chute_actor_destroy_800daad8 0x800daad8 : { *(.text.w3d_chute_actor_destroy_800daad8) }
  .text.w3d_chute_smooth_value_800dc0b4 0x800dc0b4 : { *(.text.w3d_chute_smooth_value_800dc0b4) }
  .text.w3d_chute_visual_create_800dc184 0x800dc184 : { *(.text.w3d_chute_visual_create_800dc184) }
  .text.w3d_chute_visual_hide_800dc20c 0x800dc20c : { *(.text.w3d_chute_visual_hide_800dc20c) }
  .rodata 0x803898bc : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_chute_context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
