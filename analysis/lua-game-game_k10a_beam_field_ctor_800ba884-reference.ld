/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_beam_field_ctor_800ba884)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8002c2f8 = 0x8002c2f8;
w3d_actor_base_initialize = 0x80161014;
w3d_heap_allocate = 0x802098d8;
w3d_vtable_8040f828 = 0x8040f828;
SECTIONS {
  .text.w3d_k10a_beam_field_ctor_800ba884 0x800ba884 : { *(.text.w3d_k10a_beam_field_ctor_800ba884) }
  .rodata 0x80382b10 : { *(.rodata) }
  .sdata 0x804af5bc (NOLOAD) : {
    . = 0x0; w3d_pool_804af5bc = .;
    . = 0x2224; w3d_beam_field_804b17e0 = .;
    . = 0x2270; w3d_beam_a_804b182c = .;
    . = 0x2274; w3d_beam_b_804b1830 = .;
    . = 0x2278; w3d_beam_c_804b1834 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
