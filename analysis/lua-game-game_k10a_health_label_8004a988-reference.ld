/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_health_label_8004a988)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sprintf = 0x802ec254;
w3d_auto_800fc2b0 = 0x800fc2b0;
w3d_auto_800fc330 = 0x800fc330;
w3d_fn_8004b3f0 = 0x8004b3f0;
w3d_string_append = 0x8020bf2c;
SECTIONS {
  .text.w3d_k10a_health_label_8004a988 0x8004a988 : { *(.text.w3d_k10a_health_label_8004a988) }
  .rodata 0x80376f88 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
