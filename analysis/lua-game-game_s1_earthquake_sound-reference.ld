/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80062640)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_f32_80379a8c = 0x80379a8c;
w3d_f32_80379a90 = 0x80379a90;
w3d_f32_80379aa0 = 0x80379aa0;
w3d_f32_80379aa4 = 0x80379aa4;
w3d_fn_801f6c2c = 0x801f6c2c;
w3d_str_80379a80 = 0x80379a80;
SECTIONS {
  .text.w3d_fn_80062640 0x80062640 : { *(.text.w3d_fn_80062640) }
  .text.w3d_fn_800627a4 0x800627a4 : { *(.text.w3d_fn_800627a4) }
  .text.w3d_fn_80062884 0x80062884 : { *(.text.w3d_fn_80062884) }
  .text.w3d_fn_80062950 0x80062950 : { *(.text.w3d_fn_80062950) }
  .rodata 0x80379a98 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_environment_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
