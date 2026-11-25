/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_ai_scale_exposure_8000b7dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8000b2f8 = 0x8000b2f8;
w3d_f32_80369c68 = 0x80369c68;
w3d_f32_80369c6c = 0x80369c6c;
w3d_f32_80369c98 = 0x80369c98;
w3d_fn_8000a280 = 0x8000a280;
w3d_fn_800168b0 = 0x800168b0;
w3d_fn_8021d100 = 0x8021d100;
SECTIONS {
  .text.w3d_ai_scale_exposure_8000b7dc 0x8000b7dc : { *(.text.w3d_ai_scale_exposure_8000b7dc) }
  .text.w3d_ai_add_amount_cost_8000b86c 0x8000b86c : { *(.text.w3d_ai_add_amount_cost_8000b86c) }
  .rodata 0x80369c90 : { *(.rodata) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; w3d_ai_tuning_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
