/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_transition_setup_options_80124668)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_8020b680 = 0x8020b680;
w3d_obj_8040e078 = 0x8040e078;
w3d_obj_80415c10 = 0x80415c10;
w3d_obj_80416560 = 0x80416560;
SECTIONS {
  .text.w3d_transition_setup_options_80124668 0x80124668 : { *(.text.w3d_transition_setup_options_80124668) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
