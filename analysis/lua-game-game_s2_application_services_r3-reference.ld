/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_application_trace_801266d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_application_construct_80126bfc = 0x80126bfc;
w3d_auto_801ffea8 = 0x801ffea8;
w3d_auto_80207ca4 = 0x80207ca4;
w3d_empty_80128084 = 0x80128084;
w3d_fn_800fc230 = 0x800fc230;
w3d_fn_80127ba0 = 0x80127ba0;
w3d_fn_8015ad40 = 0x8015ad40;
w3d_fn_8015ba70 = 0x8015ba70;
w3d_fn_8015bf74 = 0x8015bf74;
w3d_fn_8015c118 = 0x8015c118;
w3d_fn_8015c540 = 0x8015c540;
w3d_fn_801fcc48 = 0x801fcc48;
w3d_fn_80347324 = 0x80347324;
w3d_obj_80361f88 = 0x80361f88;
w3d_obj_803625c0 = 0x803625c0;
w3d_obj_803655bc = 0x803655bc;
w3d_obj_8036564c = 0x8036564c;
w3d_obj_8036567c = 0x8036567c;
w3d_obj_803656dc = 0x803656dc;
w3d_obj_80366938 = 0x80366938;
w3d_obj_80410c48 = 0x80410c48;
w3d_str_8039bbe8 = 0x8039bbe8;
w3d_str_8039bbfc = 0x8039bbfc;
w3d_str_8039bc00 = 0x8039bc00;
w3d_str_8039bc10 = 0x8039bc10;
w3d_str_8039bc1c = 0x8039bc1c;
w3d_str_8039bc28 = 0x8039bc28;
w3d_str_8039bc2c = 0x8039bc2c;
w3d_str_8039bd5c = 0x8039bd5c;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_application_trace_801266d0 0x801266d0 : { *(.text.w3d_application_trace_801266d0) }
  .text.w3d_application_entry_801267f8 0x801267f8 : { *(.text.w3d_application_entry_801267f8) }
  .text.w3d_application_destroy_80126d1c 0x80126d1c : { *(.text.w3d_application_destroy_80126d1c) }
  .text.w3d_application_load_language_80127b48 0x80127b48 : { *(.text.w3d_application_load_language_80127b48) }
  .sdata 0x804b0640 (NOLOAD) : {
    . = 0x0; w3d_obj_804b0640 = .;
    . = 0x1148; w3d_obj_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
