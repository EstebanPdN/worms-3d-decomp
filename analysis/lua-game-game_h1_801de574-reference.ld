/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_h1_node_owner_destroy_801de574)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80209758 = 0x80209758;
fn_80217940 = 0x80217940;
w3d_actor_node_destroy = 0x80210990;
w3d_vtable_80416a90 = 0x80416a90;
SECTIONS {
  .text.w3d_h1_node_owner_destroy_801de574 0x801de574 : { *(.text.w3d_h1_node_owner_destroy_801de574) }
  .text.w3d_h1_visit_with_context_802097ac 0x802097ac : { *(.text.w3d_h1_visit_with_context_802097ac) }
  .sdata 0x804b0688 (NOLOAD) : {
    . = 0x0; w3d_sda_visit_context_804b0688 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
