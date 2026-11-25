/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_r25a_initialize_actor_80124edc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__15Member_80126184 = 0x80126184;
fn_80161014 = 0x80161014;
fn_801a01f0 = 0x801a01f0;
fn_801ef174 = 0x801ef174;
fn_801f2758 = 0x801f2758;
fn_802cd99c = 0x802cd99c;
fn_802ce5ec = 0x802ce5ec;
fn_802ce9d8 = 0x802ce9d8;
fn_802dd028 = 0x802dd028;
lbl_80365788 = 0x80365788;
lbl_80410bd8 = 0x80410bd8;
SECTIONS {
  .text.w3d_r25a_initialize_actor_80124edc 0x80124edc : { *(.text.w3d_r25a_initialize_actor_80124edc) }
  .text.w3d_r25a_create_named_userdata_8019e710 0x8019e710 : { *(.text.w3d_r25a_create_named_userdata_8019e710) }
  .text.w3d_r25a_release_list_entries_801ad060 0x801ad060 : { *(.text.w3d_r25a_release_list_entries_801ad060) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
