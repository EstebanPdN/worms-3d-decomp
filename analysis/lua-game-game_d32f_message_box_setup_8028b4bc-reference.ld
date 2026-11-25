/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32f_message_box_setup_8028b4bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc1b0 = 0x800fc1b0;
fn_800fc230 = 0x800fc230;
fn_800fd62c = 0x800fd62c;
fn_8015f5a0 = 0x8015f5a0;
fn_80162024 = 0x80162024;
fn_80178c48 = 0x80178c48;
fn_80178d1c = 0x80178d1c;
fn_8028ba38 = 0x8028ba38;
fn_8028c290 = 0x8028c290;
fn_8028c64c = 0x8028c64c;
fn_8028c71c = 0x8028c71c;
fn_802b0b84 = 0x802b0b84;
fn_803426b4 = 0x803426b4;
fn_80342a78 = 0x80342a78;
fn_80343df4 = 0x80343df4;
lbl_803cfc58 = 0x803cfc58;
lbl_803cfc98 = 0x803cfc98;
w3d_engine_get_context_80165254 = 0x80165254;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_format = 0x8020c510;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.d32f_message_box_setup_8028b4bc 0x8028b4bc : { *(.text.d32f_message_box_setup_8028b4bc) }
  .sdata 0x804b0c7c (NOLOAD) : {
    . = 0x0; lbl_804b0c7c = .;
    . = 0x8; lbl_804b0c84 = .;
    . = 0x10; lbl_804b0c8c = .;
    . = 0x20; lbl_804b0c9c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
