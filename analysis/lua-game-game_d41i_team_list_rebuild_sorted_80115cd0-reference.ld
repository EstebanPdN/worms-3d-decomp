/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d41i_team_list_rebuild_sorted_80115cd0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
array_lock_801ef048 = 0x801ef048;
as_table_80341584 = 0x80341584;
class_80419e68 = 0x80419e68;
create_8020b680 = 0x8020b680;
definition_801797b4 = 0x801797b4;
list_append_801ef174 = 0x801ef174;
list_begin_801ef380 = 0x801ef380;
locked_8028496c = 0x8028496c;
n_8039a78c = 0x8039a78c;
read_key_800fc2b0 = 0x800fc2b0;
read_setting_800fc1b0 = 0x800fc1b0;
s_8039a7a0 = 0x8039a7a0;
strcmp = 0x802ef234;
string_assign_8020bd38 = 0x8020bd38;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_8020bb2c = 0x8020bb2c;
table_get_80179598 = 0x80179598;
SECTIONS {
  .text.d41i_team_list_rebuild_sorted_80115cd0 0x80115cd0 : { *(.text.d41i_team_list_rebuild_sorted_80115cd0) }
  .sdata 0x804abbac (NOLOAD) : {
    . = 0x0; lbl_804abbac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
