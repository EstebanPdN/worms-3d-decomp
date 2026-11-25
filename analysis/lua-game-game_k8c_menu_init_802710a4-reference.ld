/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8c_menu_init_802710a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc1b0 = 0x800fc1b0;
fn_802cc4f0 = 0x802cc4f0;
w3d_f32_803cc46c = 0x803cc46c;
w3d_str_803cc450 = 0x803cc450;
w3d_str_803cc460 = 0x803cc460;
SECTIONS {
  .text.w3d_k8c_menu_init_802710a4 0x802710a4 : { *(.text.w3d_k8c_menu_init_802710a4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
