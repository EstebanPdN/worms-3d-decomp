/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_holder_dtor_801dde90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80411590 = 0x80411590;
lbl_80416a10 = 0x80416a10;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_actor_node_destroy = 0x80210990;
w3d_auto_80210abc = 0x80210abc;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_k8b_holder_dtor_801dde90 0x801dde90 : { *(.text.w3d_k8b_holder_dtor_801dde90) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
