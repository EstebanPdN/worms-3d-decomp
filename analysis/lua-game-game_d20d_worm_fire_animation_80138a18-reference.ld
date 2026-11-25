/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d20d_worm_fire_animation_80138a18)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80139234 = 0x80139234;
k4a_weapon_attach_trail_8013f5c4 = 0x8013f5c4;
s8_index_query_800fc6dc = 0x800fc6dc;
w3d_auto_800fc330 = 0x800fc330;
w3d_auto_8013f08c = 0x8013f08c;
w3d_auto_8013f2a4 = 0x8013f2a4;
w3d_empty_80343584 = 0x80343584;
w3d_f32_8039f628 = 0x8039f628;
w3d_f32_8039f62c = 0x8039f62c;
w3d_f32_8039f630 = 0x8039f630;
w3d_s20_forward_global_800e5ca4 = 0x800e5ca4;
w3d_str_8039f4f4 = 0x8039f4f4;
w3d_str_8039f5bc = 0x8039f5bc;
w3d_str_8039f5c8 = 0x8039f5c8;
w3d_str_8039f5d8 = 0x8039f5d8;
w3d_str_8039f5e4 = 0x8039f5e4;
w3d_str_8039f5f0 = 0x8039f5f0;
w3d_str_8039f5fc = 0x8039f5fc;
w3d_str_8039f604 = 0x8039f604;
w3d_str_8039f60c = 0x8039f60c;
w3d_str_8039f618 = 0x8039f618;
w3d_weapon_names_803eb63c = 0x803eb63c;
w3d_worm_play_named_801359ec = 0x801359ec;
SECTIONS {
  .text.d20d_worm_fire_animation_80138a18 0x80138a18 : { *(.text.d20d_worm_fire_animation_80138a18) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
