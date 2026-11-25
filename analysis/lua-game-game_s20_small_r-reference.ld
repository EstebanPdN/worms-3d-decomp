/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_enable_slot_flag_8016c014)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80177eb0 = 0x80177eb0;
fn_80178df0 = 0x80178df0;
fn_8019eed4 = 0x8019eed4;
fn_801ef174 = 0x801ef174;
fn_801ef380 = 0x801ef380;
fn_802cd99c = 0x802cd99c;
fn_802cda44 = 0x802cda44;
fn_802ce264 = 0x802ce264;
fn_80307e24 = 0x80307e24;
fn_80342a74 = 0x80342a74;
lbl_803a99f8 = 0x803a99f8;
SECTIONS {
  .text.w3d_s20_enable_slot_flag_8016c014 0x8016c014 : { *(.text.w3d_s20_enable_slot_flag_8016c014) }
  .text.w3d_s20_forward_owner_801750f4 0x801750f4 : { *(.text.w3d_s20_forward_owner_801750f4) }
  .text.w3d_s20_get_float_80176a44 0x80176a44 : { *(.text.w3d_s20_get_float_80176a44) }
  .text.w3d_s20_check_lua_function_8019f838 0x8019f838 : { *(.text.w3d_s20_check_lua_function_8019f838) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
