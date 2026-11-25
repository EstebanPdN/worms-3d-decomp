/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_render_set_target_801680ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_803031d0 = 0x803031d0;
w3d_render_hook_8016814c = 0x8016814c;
w3d_s20_set_blend_mode_8016830c = 0x8016830c;
SECTIONS {
  .text.w3d_k4b_render_set_target_801680ec 0x801680ec : { *(.text.w3d_k4b_render_set_target_801680ec) }
  .sdata 0x804ab4fc (NOLOAD) : {
    . = 0x0; lbl_804ab4fc = .;
    . = 0x4bec; lbl_804b00e8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
