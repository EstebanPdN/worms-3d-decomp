/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_camera_jetpack_actions_80056178)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
action_name_8037835c = 0x8037835c;
action_name_803785a8 = 0x803785a8;
action_name_803785c4 = 0x803785c4;
action_name_803785e0 = 0x803785e0;
action_name_803785fc = 0x803785fc;
action_name_80378618 = 0x80378618;
action_name_80378634 = 0x80378634;
action_name_80378650 = 0x80378650;
action_name_80378668 = 0x80378668;
action_name_80378680 = 0x80378680;
action_name_80378698 = 0x80378698;
action_name_803786b0 = 0x803786b0;
action_name_803786c4 = 0x803786c4;
action_name_803786d8 = 0x803786d8;
action_name_803786ec = 0x803786ec;
action_name_80378700 = 0x80378700;
action_name_80378714 = 0x80378714;
action_name_8037872c = 0x8037872c;
action_name_80378740 = 0x80378740;
action_name_80378758 = 0x80378758;
action_name_80378778 = 0x80378778;
action_name_80378798 = 0x80378798;
action_name_803787b4 = 0x803787b4;
action_name_803787d0 = 0x803787d0;
action_name_803787ec = 0x803787ec;
action_name_80378808 = 0x80378808;
action_name_80378824 = 0x80378824;
action_name_80378840 = 0x80378840;
action_name_80378854 = 0x80378854;
action_name_80378868 = 0x80378868;
action_name_80378880 = 0x80378880;
action_name_8037889c = 0x8037889c;
action_name_803788bc = 0x803788bc;
w3d_allocate_80212fd4 = 0x80212fd4;
w3d_copy_802eee50 = 0x802eee50;
w3d_name_8015f518 = 0x8015f518;
w3d_pool_allocate_802098d8 = 0x802098d8;
w3d_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_d24g_camera_jetpack_actions_80056178 0x80056178 : { *(.text.w3d_d24g_camera_jetpack_actions_80056178) }
  .rodata 0x803788dc : { *(.rodata) }
  .sdata 0x804ae280 (NOLOAD) : {
    . = 0x0; w3d_pool_804ae280 = .;
    . = 0x3508; w3d_context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
