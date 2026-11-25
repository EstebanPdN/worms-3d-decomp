/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32i_results_table_build_80111820)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
array_lock_801ef048 = 0x801ef048;
as_table_80341584 = 0x80341584;
class_80419e68 = 0x80419e68;
class_80419e88 = 0x80419e88;
colours_8044d254 = 0x8044d254;
create_8020b680 = 0x8020b680;
f_8039a464 = 0x8039a464;
f_8039a4c8 = 0x8039a4c8;
list_append_801ef174 = 0x801ef174;
list_begin_801ef380 = 0x801ef380;
n_8039a0e0 = 0x8039a0e0;
n_8039a448 = 0x8039a448;
n_8039a478 = 0x8039a478;
n_8039a490 = 0x8039a490;
n_8039a4bc = 0x8039a4bc;
read_setting_800fc1b0 = 0x800fc1b0;
result_800fc914 = 0x800fc914;
strcmp = 0x802ef234;
string_append_8020bf2c = 0x8020bf2c;
string_finish_8020c5c4 = 0x8020c5c4;
string_format_8020c510 = 0x8020c510;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_8020bb2c = 0x8020bb2c;
string_release_80341588 = 0x80341588;
table_get_80179598 = 0x80179598;
SECTIONS {
  .text.d32i_results_table_build_80111820 0x80111820 : { *(.text.d32i_results_table_build_80111820) }
  .rodata 0x8039a4cc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
