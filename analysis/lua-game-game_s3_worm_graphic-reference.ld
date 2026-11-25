/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_worm_graphic_random_animation)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80162C20 = 0x80162c20;
w3d_auto_8013fecc = 0x8013fecc;
w3d_empty_80343584 = 0x80343584;
w3d_f32_8039fe40 = 0x8039fe40;
w3d_f32_8039fe44 = 0x8039fe44;
w3d_fn_800e5bb8 = 0x800e5bb8;
w3d_fn_800fc1f0 = 0x800fc1f0;
w3d_fn_800fc6dc = 0x800fc6dc;
w3d_fn_801359ec = 0x801359ec;
w3d_fn_80139158 = 0x80139158;
w3d_get_800a830c = 0x800a830c;
w3d_mesh_instance_is_playing = 0x80181ccc;
w3d_str_8039fe48 = 0x8039fe48;
SECTIONS {
  .text.w3d_worm_graphic_random_animation 0x8014009c : { *(.text.w3d_worm_graphic_random_animation) }
  .text.w3d_worm_graphic_set_blink 0x801401d8 : { *(.text.w3d_worm_graphic_set_blink) }
  .text.w3d_worm_graphic_release_effect 0x80140240 : { *(.text.w3d_worm_graphic_release_effect) }
  .sdata 0x804ab2f0 (NOLOAD) : {
    . = 0x0; w3d_global_804ab2f0 = .;
    . = 0xa4; w3d_global_804ab394 = .;
    . = 0xa8; w3d_global_804ab398 = .;
    . = 0xac; w3d_global_804ab39c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
