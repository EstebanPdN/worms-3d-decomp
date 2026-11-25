/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc20a_worm_reaction_animation_8013ff58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80162C20 = 0x80162c20;
w3d_auto_8013fecc = 0x8013fecc;
w3d_empty_80343584 = 0x80343584;
w3d_f32_8039fe38 = 0x8039fe38;
w3d_f32_8039fe3c = 0x8039fe3c;
w3d_fn_800fc6dc = 0x800fc6dc;
w3d_fn_801359ec = 0x801359ec;
w3d_fn_80139158 = 0x80139158;
w3d_get_800a830c = 0x800a830c;
w3d_mesh_instance_is_playing = 0x80181ccc;
SECTIONS {
  .text.w3d_cc20a_worm_reaction_animation_8013ff58 0x8013ff58 : { *(.text.w3d_cc20a_worm_reaction_animation_8013ff58) }
  .sdata 0x804ab2dc (NOLOAD) : {
    . = 0x0; w3d_global_804ab2dc = .;
    . = 0x4; w3d_global_804ab2e0 = .;
    . = 0x28; w3d_global_804ab304 = .;
    . = 0x34; w3d_global_804ab310 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
