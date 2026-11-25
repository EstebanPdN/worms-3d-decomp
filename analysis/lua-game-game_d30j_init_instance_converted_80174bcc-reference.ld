/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30j_init_instance_converted_80174bcc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3StrPCc = 0x8020bb54;
lbl_80364694 = 0x80364694;
lbl_80413b28 = 0x80413b28;
lbl_804144f8 = 0x804144f8;
lbl_80414940 = 0x80414940;
strcat = 0x802ef108;
w3d_auto_80179aec = 0x80179aec;
w3d_empty_8034bf48 = 0x8034bf48;
w3d_k5b_iface_array_field_append_801ef174 = 0x801ef174;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d30j_init_instance_converted_80174bcc 0x80174bcc : { *(.text.d30j_init_instance_converted_80174bcc) }
  .rodata 0x803a67e4 : { *(.rodata) }
  .sdata 0x804ab59c (NOLOAD) : {
    . = 0x0; lbl_804ab59c = .;
    . = 0x60; lbl_804ab5fc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
