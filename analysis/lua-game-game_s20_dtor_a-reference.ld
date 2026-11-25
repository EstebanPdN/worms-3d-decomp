/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_destroy_list_owner_80165af0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801a18f8 = 0x801a18f8;
fn_801fe1f8 = 0x801fe1f8;
fn_80210120 = 0x80210120;
fn_80210990 = 0x80210990;
fn_802134fc = 0x802134fc;
fn_802dd884 = 0x802dd884;
fn_8034ba74 = 0x8034ba74;
lbl_80411a30 = 0x80411a30;
lbl_80411a88 = 0x80411a88;
lbl_80411c10 = 0x80411c10;
lbl_80411c88 = 0x80411c88;
lbl_80413830 = 0x80413830;
lbl_80413858 = 0x80413858;
lbl_804139c0 = 0x804139c0;
lbl_804139e0 = 0x804139e0;
SECTIONS {
  .text.w3d_s20_destroy_list_owner_80165af0 0x80165af0 : { *(.text.w3d_s20_destroy_list_owner_80165af0) }
  .text.w3d_s20_destroy_registered_80166f5c 0x80166f5c : { *(.text.w3d_s20_destroy_registered_80166f5c) }
  .text.w3d_s20_destroy_lua_ref_8019e600 0x8019e600 : { *(.text.w3d_s20_destroy_lua_ref_8019e600) }
  .text.w3d_s20_destroy_service_801a1cf0 0x801a1cf0 : { *(.text.w3d_s20_destroy_service_801a1cf0) }
  .sdata 0x804ab74c (NOLOAD) : {
    . = 0x0; lbl_804ab74c = .;
    . = 0x6138; lbl_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
