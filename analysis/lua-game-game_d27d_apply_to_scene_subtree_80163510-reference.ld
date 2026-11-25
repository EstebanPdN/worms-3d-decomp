/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27d_apply_to_scene_subtree_80163510)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
type_803617d0 = 0x803617d0;
type_80361860 = 0x80361860;
type_803618f0 = 0x803618f0;
w3d_actor_from_handle = 0x8034b974;
w3d_engine_get_context = 0x80165254;
SECTIONS {
  .text.d27d_apply_to_scene_subtree_80163510 0x80163510 : { *(.text.d27d_apply_to_scene_subtree_80163510) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; scene_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
