/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_choice_setup_802a4cbc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D24lStringPCc = 0x8020bb54;
fn_8028496c = 0x8028496c;
fn_802a520c = 0x802a520c;
fn_802a62bc = 0x802a62bc;
fn_802a671c = 0x802a671c;
fn_802a6878 = 0x802a6878;
fn_802a6b30 = 0x802a6b30;
fn_802a6fa8 = 0x802a6fa8;
fn_802a73d4 = 0x802a73d4;
fn_802a7490 = 0x802a7490;
fn_802a7500 = 0x802a7500;
fn_802a7550 = 0x802a7550;
fn_802a75ec = 0x802a75ec;
fn_802a77a4 = 0x802a77a4;
fn_802a79d8 = 0x802a79d8;
lbl_8045e788 = 0x8045e788;
w3d_cached_message_id_8015f5a0 = 0x8015f5a0;
w3d_engine_get_context_80165254 = 0x80165254;
w3d_forward_800fd62c = 0x800fd62c;
w3d_handle_set_name_8015adf4 = 0x8015adf4;
w3d_lookup_800fc1b0 = 0x800fc1b0;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_header_80341884 = 0x80341884;
w3d_string_init_8020c5c0 = 0x8020c5c0;
w3d_string_release_80341588 = 0x80341588;
w3d_sub_init_802b0b84 = 0x802b0b84;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.d24l_choice_setup_802a4cbc 0x802a4cbc : { *(.text.d24l_choice_setup_802a4cbc) }
  .rodata 0x803d6018 : { *(.rodata) }
  .sdata 0x804abbac (NOLOAD) : {
    . = 0x0; lbl_804abbac = .;
    . = 0x532c; lbl_804b0ed8 = .;
    . = 0x5334; lbl_804b0ee0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
