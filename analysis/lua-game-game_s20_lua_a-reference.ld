/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_query_object_8019dd80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8019e68c = 0x8019e68c;
fn_801ea470 = 0x801ea470;
fn_801ef174 = 0x801ef174;
fn_802cde08 = 0x802cde08;
fn_802ddd14 = 0x802ddd14;
lbl_803a991c = 0x803a991c;
SECTIONS {
  .text.w3d_s20_query_object_8019dd80 0x8019dd80 : { *(.text.w3d_s20_query_object_8019dd80) }
  .text.w3d_s20_load_script_8019e1a8 0x8019e1a8 : { *(.text.w3d_s20_load_script_8019e1a8) }
  .text.w3d_s20_forward_user_values_8019e7e8 0x8019e7e8 : { *(.text.w3d_s20_forward_user_values_8019e7e8) }
  .text.w3d_s20_apply_user_value_8019f9ec 0x8019f9ec : { *(.text.w3d_s20_apply_user_value_8019f9ec) }
  .sdata 0x804ab728 (NOLOAD) : {
    . = 0x0; lbl_804ab728 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
