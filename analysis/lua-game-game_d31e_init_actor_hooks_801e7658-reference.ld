/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31e_init_actor_hooks_801e7658)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
fn_801e716c = 0x801e716c;
fn_801e7270 = 0x801e7270;
free_802134fc = 0x802134fc;
lbl_8045e080 = 0x8045e080;
memcmp_802eedc0 = 0x802eedc0;
memcpy_802eee50 = 0x802eee50;
memmove_802eeef4 = 0x802eeef4;
w3d_actor_type_first_8020fe00 = 0x8020fe00;
w3d_actor_type_next_8020fe18 = 0x8020fe18;
w3d_auto_801fff3c = 0x801fff3c;
w3d_d24k_heap_resize_80213750 = 0x80213750;
w3d_d25e_find_interface_801fca00 = 0x801fca00;
w3d_s21_find_item_class_801e8f64 = 0x801e8f64;
SECTIONS {
  .text.w3d_d31e_init_actor_hooks_801e7658 0x801e7658 : { *(.text.w3d_d31e_init_actor_hooks_801e7658) }
  .sdata 0x804b18dc (NOLOAD) : {
    . = 0x0; lbl_804b18dc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
