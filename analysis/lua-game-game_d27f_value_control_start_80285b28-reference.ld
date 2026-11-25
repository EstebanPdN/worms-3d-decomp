/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27f_value_control_start_80285b28)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_acquire_message_80162024 = 0x80162024;
fn_8028640c = 0x8028640c;
fn_802b0b84 = 0x802b0b84;
lbl_80286d14 = 0x80286d14;
w3d_auto_80178c48 = 0x80178c48;
w3d_auto_80178d1c = 0x80178d1c;
w3d_cached_message_id = 0x8015f5a0;
w3d_cc17b_service_forward_800fd62c = 0x800fd62c;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_constructor_native_c_80342a78 = 0x80342a78;
w3d_empty_803426b4 = 0x803426b4;
w3d_engine_get_context = 0x80165254;
w3d_f11a_setup_selection_80286100 = 0x80286100;
w3d_f15a_select_value_80286b40 = 0x80286b40;
SECTIONS {
  .text.d27f_value_control_start_80285b28 0x80285b28 : { *(.text.d27f_value_control_start_80285b28) }
  .sdata 0x804b0bac (NOLOAD) : {
    . = 0x0; lbl_804b0bac = .;
    . = 0x8; lbl_804b0bb4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
