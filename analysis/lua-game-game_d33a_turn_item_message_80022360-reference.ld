/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d33a_turn_item_message_80022360)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s19_dtor_80021468 = 0x80021468;
s_8036c464 = 0x8036c464;
t_8040dbe8 = 0x8040dbe8;
t_8040dcc8 = 0x8040dcc8;
tsonnet_b33_arena_801613f0 = 0x801613f0;
w3d_auto_80022634 = 0x80022634;
w3d_auto_80022964 = 0x80022964;
w3d_auto_800229ec = 0x800229ec;
w3d_auto_8015fb34 = 0x8015fb34;
w3d_message_id_equals_cache = 0x8015f65c;
w3d_message_post_current = 0x8016239c;
w3d_motion_message_construct_80131a84 = 0x80131a84;
SECTIONS {
  .text.w3d_d33a_turn_item_message_80022360 0x80022360 : { *(.text.w3d_d33a_turn_item_message_80022360) }
  .sdata 0x804aa6e0 (NOLOAD) : {
    . = 0x0; g_804aa6e0 = .;
    . = 0x4; g_804aa6e4 = .;
    . = 0x1e8; g_804aa8c8 = .;
    . = 0x2348; id_804aca28 = .;
    . = 0x2350; id_804aca30 = .;
    . = 0x2358; id_804aca38 = .;
    . = 0x7074; g_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
